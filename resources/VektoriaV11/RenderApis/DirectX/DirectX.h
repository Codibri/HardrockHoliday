#pragma once

//------------------------------------------------------------------
// CDirectX: Klasse zur DirectX-Anbindung
//
// Autor: Florian Schnell & Prof. Dr. Tobias Breiner
// Letzte Änderung: 2012-06-05
//-------------------------------------------------------------------
// #define DEBUG_LABOR_ERROR

#ifdef DEBUG_LABOR_ERROR
#define D3D_DEBUG_INFO // Führte bei manchen Rechnern (insbesondere Laborrechner) zum Absturz!!! Musste es leider rausnehmen, kann aber leicht wieder durch ein define angeschaltet werden (TB)
#endif

#include "../../RenderApi.h"
#include "../../Vertex.h"
#include "../../HMat.h"
#include "BufferMap.h"

#include "../../Shadercache.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <D3DCompiler.h>
#include <d3dx10.h>
#include <Windows.h>
#include <xnamath.h>
#include <D3D11shader.h>
#include <vector>
#include <thread>

#pragma comment (lib, "d3d11.lib")

// if we are debugging, then change compiling mode for shader  // Führte bei manchen Rechnern (insbesondere Laborrechner) zum Absturz!!! Musste es leider rausnehmen (TB) 
/*
@TB: Try to install the Windows 8 SDK on those PCs. At least that fixed the issue for me. (MR)
D3D11_CREATE_DEVICE_DEBUG:
"To use this flag, you must have D3D11*SDKLayers.dll installed; otherwise, device creation fails. To get D3D11_1SDKLayers.dll, install the SDK for Windows 8."
*/
#ifdef _DEBUG

#pragma comment (lib, "d3dx11d.lib")
#pragma comment (lib, "d3dx10d.lib")

#ifdef DEBUG_LABOR_ERROR
#define SHADER_COMPILEFLAGS D3D10_SHADER_DEBUG | D3D10_SHADER_SKIP_OPTIMIZATION | D3D10_SHADER_SKIP_VALIDATION | D3D10_SHADER_OPTIMIZATION_LEVEL0 // rausgenommen, s.o. (TB)
#define DIRECTX_DEVICE_FLAGS D3D11_CREATE_DEVICE_DEBUG // rausgenommen, s.o. (TB)
#else
#define SHADER_COMPILEFLAGS D3D10_SHADER_OPTIMIZATION_LEVEL0
#define DIRECTX_DEVICE_FLAGS 0
#endif

#else

#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")

#define SHADER_COMPILEFLAGS D3D10_SHADER_OPTIMIZATION_LEVEL0
#define DIRECTX_DEVICE_FLAGS 0
#endif

// object count to allocate when out of memory
#define I_ALLOCBLOCK 1000

struct ID3DX11Scan;

namespace Vektoria
{
//	const CShaderCache::ECreateType g_createType = CShaderCache::ECreateType::eCreateTypeForceCompile;
//	const CShaderCache::ECreateType g_createType = CShaderCache::ECreateType::eCreateTypeCompileChanges;
	const CShaderCache::ECreateType g_createType = CShaderCache::ECreateType::eCreateTypeUseCached;
	const CShaderCache::EShaderAutoRecompileType g_compileType = CShaderCache::eShaderAutoRecompileDisabled;
//	const CShaderCache::EShaderAutoRecompileType g_compileType = CShaderCache::eShaderAutoRecompileEnabled;

class CViewport;
class CMaterial;
class CCamera;
class TriangleList;
class TriangleStrip;
class Light;
class ParallelLight;
class PointLight;
class SpotLight;
class CParticleRenderer;
class CDXUtilities;


struct VERTEX
{
	FLOAT fx, fy, fz;								// Position
	FLOAT fxNormal, fyNormal, fzNormal;				// Normale 
	FLOAT fxTangent, fyTangent, fzTangent;			// Tangente 
	FLOAT fxBitangent, fyBitangent, fzBitangent;	// Bitangente
	FLOAT fu, fv;									// uv-Mapping fuers Texturing
};

struct LIGHT_STRUCTURE
{
	FLOAT fx, fy, fz;	// Position
	UINT type;			// Light source type (parallel, point, spot)
	D3DXCOLOR color;	// Light's color
	FLOAT dx, dy, dz;	// Direction
	FLOAT fInnerCosAngle;
	FLOAT fOuterCosAngle;
	FLOAT fAttenuationConstant;
	FLOAT fAttenuationLinear;
	FLOAT fAttenuationQuadratic;
	BOOL bCauseShadow;
	BOOL bSoftShadow;
	BOOL bCascadedShadow;
	XMFLOAT4X4 mLightViewProj;
};


// changed data type to xmfloat4x4, because
// xmmatrix cant be used in class (memory alignment on x86!)
struct POSTPROCESSING_SHADER_CONSTANTS
{
	XMFLOAT4X4 mWorldViewProjection;
};


struct OBJECT_SHADER_CONSTANTS
{
	XMFLOAT4X4 mWorld;
	XMFLOAT4X4 mView;
	XMFLOAT4X4 mViewInv;
	XMFLOAT4X4 mProjection;
	UINT iLightsAffectIndices[4];
	UINT iLightsAffectCount;
	int iBuffer[3];
};

// constant buffer structure for shadow map
struct SHADOWMAP_SHADER_CONSTANTS
{
	XMFLOAT4X4 mWorld;
	XMFLOAT4X4 mLightView;
	int iBuffer1[16];
	XMFLOAT4X4 mProjection;
	int iBuffer2[8];
};

struct DRAW_OBJECT
{
	RHND handle; 
	int idTexture;
	float fDistanceToCameraSquare;
	CHMat mGlobal;
	unsigned int iLightsAffectIndices[4];
	unsigned int iLightsAffectCount;
};

#define MAT_ALLOCS 1024
struct TEXTUREINFO
{
	char acPath[MAX_PATH];
	ID3D11ShaderResourceView *ptex;
	int iUsedByMaterials;
};

struct MATERIALINFO
{
	int iImage;
	int iGlow;
	int iSpecular;
	int iBump;
	int iEnvironment;
	int iPOM;
	int iThickness;
	bool bChanged;
};

struct MATERIALPARAMETERS
{
	D3DXCOLOR d3dxcolor;			// Materialfarbe Ambient
	float fSpecularSharpness;
	float fDiffuseSharpness;
	float fBumpStrength;
	float frTransparency;
	D3DXCOLOR d3dxcolorSSS;			// Materialfarbe des Subsurface
	D3DXCOLOR f4SSSBRDFParams;		// Parameter für BRDF/SSS
	// keine Ahnung, warum so eine seltsame Parameteruebergabe zu Shader: 
	unsigned int iTexFlags[96];
	//  0 = Image,		   4 = Glow,			 8 = Specular,		 12 = Bump
	// 16 = ImageBlack,	  20 = GlowAsImgae,	    24 = SpecularAsImage,28 = HeightAsImage
	// 32 = ImageWhite,	  36 = GlowWhite,		40 = SpecularWhite,	 44 = Height
	// 48 = ShadingOn ,   52 = GlowAsAmbient    56 = ChromaKeying,   60 = Environment
	// 64 = POM			  68 = TexBRDF		    72 = TexSSS
	// 80 =	ixPos         84 = iyPos            88 = ixPics          92 = iyPics

	// WARNING: Always keep this at the end. If you don't, something will explode!
	// TODO: Proper solution: Make a individual texture based, shader independent storage and place the texture address mode there. (MR)
	ETextureAddressMode eTextureAddressMode;
	D3DXVECTOR3 offset; // cb must be multiple of 16 bytes
};

struct POSTPROCESSING_BUFFER
{ 
	D3DXCOLOR d3dxcolor;			
	float fParam0;
	float fParam1;
	float fBlurStrength;
	float frCamFocus;
	// keine Ahnung, warum so eine seltsame Parameteruebergabe zu Shader: 
	unsigned int iFlags[64];		
	//  0 = Blur,		 4 = MotionBlur,	  8 = DistanceBlur	,	12 =
	// 16 = LightGlow,	20 = HighlightGlow,	 24 = Filmex		,	28 = 
	// 32 = GodRays,	36 = GlowWhite,		 40 = SpecularWhite ,	44 = 
	// 48 = RedStereo , 52 = GreenBlueStereo 56 =				,   60 = 
	
};



struct VIEWPORTSTYLE_BUFFER
{
	D3DXCOLOR d3dxcolorOutline;		// Kontur-Viewportfarbe
	D3DXCOLOR d3dxcolorFogParams;		// Nebel-Parameter
	XMFLOAT4X4 mColorModification; // Farbveraenderungsmatrix
	unsigned int eStyle[64];		
	//  0 = Colorize,		 4 = HalfTransparent,	 8 = Toon,				12 = Blue,
	// 16 = Half,		20 = Tele,			24 = IllustrativeArt,	28 = 

};

enum EShaderType
{
	eCompute  = 0x01,
	eVertex   = 0x02,
	eHull     = 0x04,
	eDomain   = 0x08,
	eGeometry = 0x10,
	ePixel    = 0x20,
};

static void * ppNULL[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT] = { NULL };

struct SShader
{
	union
	{
		ID3D11ComputeShader  *pComputeShader;
		ID3D11VertexShader   *pVertexShader;
		ID3D11HullShader     *pHullShader;
		ID3D11DomainShader   *pDomainShader;
		ID3D11GeometryShader *pGeometryShader;
		ID3D11PixelShader    *pPixelShader;
	};
	ID3D11InputLayout *pinputLayout;
	EShaderType type;
};

class CDirectX : public CRenderApi
{
	friend class CParticleRenderer;
	friend class CDXUtilities;
protected:
	CParticleRenderer *m_pParticleRenderer;
	CDXUtilities *m_pUtils;
	IDXGISwapChain *m_pswapchain;

	// Hauptvariablen:
	CViewport *m_pcurrentViewort;
	IDXGISwapChain *m_pswapChain;
	ID3D11Device *m_pdevice;
	ID3D11DeviceContext *m_pdevicecontext;
	ID3D11RenderTargetView *m_prendertargetviewBackBuffer;

	ID3D11Buffer *m_pbufferViewportStyle;

	LIGHT_STRUCTURE *m_plightstructure; // new TB 2013_09_27;

	// I need those for soft particles. I thought it is better to store them in this class instead of the particle renderer since someone else might need that as well later. (MR)
	float m_fNearClipping; 
	float m_fFarClipping;  
	int m_iActiveViewportHeight;
	int m_iActiveViewportWidth;

	SShader *m_pShader;
	D3D11_BUFFER_DESC m_bufferdescVertex;
	ID3D11Buffer *m_pVBuffer;
	ID3D11Buffer *m_pbufferLights;
	ID3D11ShaderResourceView *m_pshaderresourceviewLights;
	VERTEX *m_pvertexGeo;
	BufferMap m_buffermap;
	OBJECT_SHADER_CONSTANTS m_objectshaderconstants;
	OBJECT_SHADER_CONSTANTS m_objectshaderconstantsParallelProjection;
	ID3D11SamplerState *m_psamplerstateLinearWrap;
	ID3D11SamplerState *m_psamplerstateLinearClamp;
	ID3D11SamplerState *m_psamplerstateLinearMirror;
	ID3D11InfoQueue * m_pInformationQueue;
	int m_iCurMsg;
	ID3D11Query * m_pEventQuery;

	// Depth Stencil:
	ID3D11DepthStencilView *m_pdepthstencilview;
	ID3D11Texture2D *m_ptextureDepthStencil;
	ID3D11ShaderResourceView * m_psrvDepthStencil;

	// Hauptshader: 
	ID3D11PixelShader *m_ppixelshader;
	ID3D11VertexShader *m_pvertexshader;
	ID3D11InputLayout *m_pinputlayout;
	D3D11_INPUT_ELEMENT_DESC* m_pinputLayoutDesc;
	ID3D11Buffer *m_pbufferProjectionMatrix;
	ID3D11Buffer *m_pbufferTexInfo;
	ID3D11Buffer *m_pbufferGPU;
	MATERIALPARAMETERS * m_amaterialparameters;
	VIEWPORTSTYLE_BUFFER m_viewportstylebuffer;
	D3D11_RASTERIZER_DESC * m_arasterizerdesc;
	ID3D11RasterizerState ** m_aprasterizerstate;
	ID3D11SamplerState * m_psamplerstateActive;

	// Shadowmapping
	SHADOWMAP_SHADER_CONSTANTS m_shadowmapshaderconstants;
	ID3D11Buffer *m_pbufferProjectionMatrixShadowMap;
	ID3D11VertexShader *m_pvertexshaderShadowMap;
	ID3D11PixelShader *m_ppixelshaderShadowMap;
	ID3D11Texture2D *m_ptextureShadowMap;
	ID3D11DepthStencilView *m_pdepthstencilviewShadowMap;
	ID3D11ShaderResourceView *m_pshaderresourceviewShadowMap;
	ID3D11SamplerState *m_psamplerstateShadow;

	
	// Anderes:
	void copyCHMatToXMFLOAT4X4(CHMat *source, XMFLOAT4X4 *target);
	void copyXMFLOAT4X4ToCHMat(XMFLOAT4X4 *source, CHMat *target);


#ifdef POSTPROCESSING_ON
	// Postprozess-Shader-Variablen:
	ID3D11VertexShader *m_pvertexshaderPostprocessing;
	ID3D11PixelShader *m_ppixelshaderPostprocessing;
	ID3D11InputLayout *m_pinputlayoutPostprocessing;
	ID3D11Buffer *m_pbufferProjectionMatrixPostprocessing;
	ID3D11Buffer *m_pbufferTexInfoPostprocessing;
	POSTPROCESSING_BUFFER m_viewportstylebufferPostprocessing;
	D3D11_RASTERIZER_DESC * m_arasterizerdescPostprocessing;
	ID3D11RasterizerState ** m_aprasterizerstatePostprocessing;
	
#endif
	// contains all lights
	std::vector<CLight*>m_vplightShadowCaster;	// TODO: make this an array
	CLight **m_pplight;
	int m_iLights;

	int TexturePathExists(char *acPath);
	bool CreateTexture(CTexture * ptexture, bool bDefaultWhite, int & iTexture);

	void PassToGPU(RHND & handle, int & idTexture);
	void SetObjectDrawingParameters(CHMat &m, const unsigned int * pLightsAffectIndices, const unsigned int iLightsAffectCount);
	void SetSpriteDrawingParameters(CHMat &m);

	unsigned int GetMSAAQuality(unsigned int uiSamples, DXGI_FORMAT format);

	void InitShaderPostprocessing();

public:
	ERenderApi m_eRenderApi;

	// Texturen:
	int m_iTextures;
	int m_iTextureAllocs;
	TEXTUREINFO * m_atextureinfo;

	ID3D11Texture2D *m_ptextureBackBuffer;
	CDirectX();
	void ChangeRenderStatePostprocessing(CViewport *pviewport);
	void Postprocessing(CViewport *pviewport);

	CDXUtilities* CDirectX::Utils();
	// Die heilige Dreifaltigkeit der Gameentwickler: 
	void Init(HWND hwnd, int iWidthWindow, int iHeightWindow, ERenderApi eRenderApi);
	void Tick();
	void Fini();

	// Viewport-Methoden:
	void AddViewport(CViewport *pviewport);
	void BeginRenderViewport(CHMat & mProjection, CHMat & mView, CHMat & mViewInv, CViewport &viewport);
	void EndRenderViewport();
	void ChangeRenderState(CViewport *pviewport);
	void ChangeRenderStateShadow(CViewport *pviewport);
	void ChangeResolution(CViewport *pviewport);

	// lighting
	RHND CreateLight(CLight *plight);
	void DestroyLight(RHND hLight);

	// shadows
	void ResizeShadowMap(int iPixelsWidth, int iPixelsHeight);
	void BeginRenderShadow(CLight *plight, CViewport *pviewport);
	void RenderShadowMap(RHND &handle, CHMat &mGlobal);
	void EndRenderShadow();

	// triangle strip handling
	void UpdateTriangleList(CTriangleList *ptrianglelist, RHND & phandle);
	void UpdateTriangleStrip(CTriangleStrip *ptrianglestrip, RHND & phandle);
	RHND CreateTriangleList(CTriangleList *ptrianglelist);
	RHND CreateTriangleStrip(CTriangleStrip *ptrianglestrip);

	// custom buffer handling
	RHND CreateBuffer(CDrawable *pdrawable, void *pData, D3D11_BUFFER_DESC &bd, int *pIndices = 0, int iindicesCount = 0);
	HRESULT CreateSRVFromFile(char const *pFileName, ID3D11ShaderResourceView **ppSRV);
	HRESULT CreateSamplerState(D3D11_SAMPLER_DESC const *pSamplerDesc, ID3D11SamplerState **ppSamplerState);
	void FreeHandle(RHND handle);
	void CopyBuffer(ID3D11Buffer *pDest, ID3D11Buffer *pSrc);

	// drawing
	void SetShaderResources(int iShaderTypes, int iStartSlot, int iCount, ID3D11ShaderResourceView **apSRVs = 0);
	void SetShaderSamplers(int iShaderTypes, int iStartSlot, int iCount, ID3D11SamplerState **apSamplers = 0);
	void Draw(RHND & handle, int & idTexture,float fDistanceToCameraSquare, int iKind, CHMat & mGlobal, CLight **aplightAffect, unsigned int iLightsAffectCount);
	void CreateMaterial(CMaterial * pmaterial);
	void UpdateMaterial(CMaterial * pmaterial); 		
	void UpdateMaterialAni(CMaterial * pmaterial);

	bool DeleteMaterial(CMaterial * pmaterial);
	bool DeleteTexture(int iTexture);

	// shading
	int CreateShader(WCHAR *pFilename, LPCSTR pFunctionname, LPCSTR pShaderModel, EShaderType type, D3D11_INPUT_ELEMENT_DESC const *pied = 0, int iiedCount = 0, bool bforceCompile = false);
	void SetShader(int iShader, ID3D11ShaderResourceView **aSRVs = 0, int iSRVs = 0);
	void UnsetShader(EShaderType etype, int iSRVs);


	// computing
	ID3D11ShaderResourceView *GetLightsSRV() { return m_pshaderresourceviewLights; }
	void SetConstantBuffers(ID3D11Buffer **apConstantBuffers, int iStartSlot, int iCount, int iShaderTypes = -1);
	void RunComputeShader(int iCS, ID3D11UnorderedAccessView ** aUAVs, int iUAVs, ID3D11ShaderResourceView ** aSRVs, int iSRVs, int aThreadGroups[3], UINT *piUAVElementCounts = 0);
	void RunComputeShaderIndirect(int iCS, ID3D11UnorderedAccessView ** aUAVs, int iUAVs, ID3D11ShaderResourceView ** aSRVs, int iSRVs, ID3D11Buffer * pbThreadGroups, UINT uiAlignedOffsetForArgs, UINT *piUAVElementCounts = 0);
	void TransferFromGPU(ID3D11Resource * pResource, int iSubresource, BYTE * pBuffer, int iSize);
	void TransferToGPU(ID3D11Resource * pResource, int iSubresource, BYTE * pBuffer, int iSize, bool bUseStagingBuffer = false);
	HRESULT CreateStructuredBuffer(UINT uElementSize, UINT uCount, VOID * pInitData, ID3D11Buffer ** pBufOut, bool bOrdered);
	HRESULT CreateTypedBuffer(UINT uElementSize, UINT uCount, VOID* pInitData, ID3D11Buffer ** pBufOut, ID3D11UnorderedAccessView ** pUAVOut, bool bOrdered);
	HRESULT CreateConstantBuffer(UINT uElementSize, UINT uCount, VOID * pInitData, ID3D11Buffer ** pBufOut);
	HRESULT CreateBufferUAV(RHND handle, ID3D11UnorderedAccessView ** pUAVOut);
	HRESULT CreateBufferUAV(ID3D11Buffer * pBuffer, ID3D11UnorderedAccessView ** pUAVOut, bool bAppendBuffer = false, bool bCounterIfNotAppend = false);
	HRESULT CreateBufferSRV(ID3D11Buffer * pBuffer, ID3D11ShaderResourceView ** pSRVOut);
	HRESULT CreateScan(ID3DX11Scan **ppScan, int iMaxElementScanSize);

	//particles
	void AddEmitter(CEmitter * pEmitter);
	void UpdateEmitterData(CEmitter * pEmitter);
	//debugging
	void CreateInformationQueue();
	bool GetNextMessage(char * pMsg, unsigned int uiSize);
	DXGI_ADAPTER_DESC QueryGraphicsCard();
	void InitProfiling();
	void WaitForShaderExecution();

	int m_iShaders;
	int m_iViewports;

	// feel free to enhance this method so that passing a buffer is OPTIONAL (don't remove it completely). (MR)
	UINT GetStructureCount(ID3D11UnorderedAccessView * UAV, ID3D11Buffer * buffer, UINT uiDstAlignedByteOffset = 0);
protected:
	// void DrawPoly(ID3D11Buffer *pbuffer);
	void DrawTriangleList(ID3D11Buffer *pbuffer);
	void DrawTriangleStrip(ID3D11Buffer *pbuffer, ID3D11Buffer *indexBuffer);
	void DrawDrawable(ID3D11Buffer *buffer, ID3D11Buffer *indexBuffer, CDrawable *pdrawable);
	void Mergesort(DRAW_OBJECT * adrawobject, unsigned int iStart, unsigned int iEnd);

	void InitBackBuffer();
	void InitShader();
	ID3D11SamplerState * GetSamplerStateBasedOnTextureAddressMode(ETextureAddressMode eTextureAddressMode);

	// Für Postprozessingeffekte (gerade in Arbeit) (TB):
#ifdef POSTPROCESSING_ON
	D3D11_TEXTURE2D_DESC * m_atexdescPostprocessing; 
	ID3D11Texture2D **m_aptexturePostprocessing; // Textur, in die das fertig gerenderte Bild zwischengespeichert wird, dort unterliegt es einem Postprozess und wird danach erst in den Backbuffer geschrieben
	ID3D11RenderTargetView ** m_aprendertargetviewPostprocessing;
	ID3D11ShaderResourceView ** m_apshaderresourceviewPostprocessing;
	D3D11_RENDER_TARGET_VIEW_DESC * m_arendertargetviewdescPostprocessing;
	D3D11_SHADER_RESOURCE_VIEW_DESC * m_ashaderresourceviewdescPostprocessing;
#endif




	bool m_bFirstDraw;

	D3D11_TEXTURE2D_DESC m_texdescStencil;
	D3D11_DEPTH_STENCIL_VIEW_DESC m_depthstencilviewdesc;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_shaderresourceviewdesc;

	D3D11_TEXTURE2D_DESC * m_atexdescShadow;
	D3D11_VIEWPORT * m_aviewport;
	D3D11_VIEWPORT * m_aviewportShadow;

	unsigned int m_uiSampleCount; 
	unsigned int m_uiSampleQuality;

	D3D_FEATURE_LEVEL m_featurelevel;

	MATERIALINFO *m_amaterialinfo;
	int m_iMaterials;
	int m_iMaterialAllocs;

	// Variablen, um Objekte fuer die Transparenz bzw. Spites zu sortieren:
	DRAW_OBJECT * m_adrawobjectBackground;
	DRAW_OBJECT * m_adrawobjectSprite;
	DRAW_OBJECT * m_adrawobjectOpaque;
	DRAW_OBJECT * m_adrawobjectTransparent;
	DRAW_OBJECT * m_adrawobjectTransparentHelp;
	int m_iAllocatedBackgroundObjects;
	int m_iAllocatedSpriteObjects;
	int m_iAllocatedOpaqueObjects;
	int m_iAllocatedTransparentObjects;
	int m_iBackgroundObjects;
	int m_iSpriteObjects;
	int m_iOpaqueObjects;
	int m_iTransparentObjects;
	bool m_bInit;

	int m_iShadowMapWidth;
	int m_iShadowMapHeight;

	CHMat m_mProjectionOverlay;
	CHMat m_mViewOverlay;
	CHMat m_mWorldOverlay;

	CShaderCache* m_pShaderCache;
};

}