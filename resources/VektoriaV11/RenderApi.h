#pragma once
#include "HMat.h"
#include "Material.h"
#include <Windows.h>
#include "Emitter.h"

//---------------------------------------------------
// CRenderApi
//
// Autoren: Florian Schnell & Prof. Dr. Tobias Breiner
// Letzte Änderung: 2012-06-05
//---------------------------------------------------

//#define POSTPROCESSING_ON // Gerade in Arbeit (TB)

namespace Vektoria
{
enum ERenderApi
{
	eRenderApi_Null,
	eRenderApi_DirectX11_Shadermodel41,
	eRenderApi_DirectX11_Shadermodel50
};

#define DRAWOBJECT_OPAQUE 0
#define DRAWOBJECT_TRANSPARENT 1
#define DRAWOBJECT_OVERLAY 2
#define DRAWOBJECT_BACKGROUND 3


enum RTYPE
{
	POLY,
	TRIANGLE_LIST,
	TRIANGLE_STRIP_INDEXED,
	DRAWABLE,
	LIGHT
};

class CDrawable;

struct RHND
{
	RTYPE type;
	unsigned int id;
  union
  {
	  unsigned int indexBufferId;
    CDrawable *pdrawable;
  };
};

class CViewport;
class CVertex;
class CTriangleList;
class CTriangleStrip;
class CLight;

//TODO: implement lightning!
class CRenderApi
{
public:
	CRenderApi(void);
	~CRenderApi(void);

	// Geburt, Leben und Sterben:
	virtual void Init(HWND hwnd, int iWidthWindow, int iHeightWindow, ERenderApi renderapi) = 0;
	virtual void Tick() = 0;
	virtual void Fini() = 0;

	// Viewport-Methoden:
	virtual void AddViewport(CViewport *pviewport) = 0;
	virtual void BeginRenderViewport(CHMat & mProjection, CHMat & mView, CHMat & mViewInv, CViewport &viewport) = 0;
	virtual void EndRenderViewport() = 0;
	virtual void ChangeRenderState(CViewport *pviewport) = 0;

	// Schatten:
	virtual void ResizeShadowMap(int iWidth, int iHeight) = 0;
	virtual void BeginRenderShadow(CLight *plight, CViewport *pviewport) = 0;
	virtual void EndRenderShadow() = 0;

	// Postprozess:
#ifdef POSTPROCESSING_ON
	virtual void Postprocessing(CViewport *pviewport) = 0;
#endif
	// Materialien:
	virtual void CreateMaterial(CMaterial * pmaterial) = 0;
	virtual void UpdateMaterial(CMaterial * pmaterial) = 0;
	virtual void UpdateMaterialAni(CMaterial * pmaterial) = 0;
	virtual bool DeleteMaterial(CMaterial * pmaterial) = 0;

	// Viewports:
	virtual void ChangeRenderStateShadow(CViewport *pviewport) = 0;
	virtual void ChangeResolution(CViewport *pviewport) = 0;

	// Licht:
	virtual RHND CreateLight(CLight *plight) = 0;
	virtual void DestroyLight(RHND hLight) = 0;

	// Triangle Strip/List Handling:
	virtual RHND CreateTriangleList(CTriangleList *ptriangleList) = 0;
	virtual RHND CreateTriangleStrip(CTriangleStrip *ptriangleStrip) = 0;
	virtual void UpdateTriangleList(CTriangleList *ptriangleList, RHND & handle) = 0;
	virtual void UpdateTriangleStrip(CTriangleStrip *ptriangleStrip, RHND & handle) = 0;

	// Zeichnen:
	virtual void Draw(RHND & handle, int & idTexture,float fDistanceToCameraSquare, int iKind, CHMat & mGlobal, CLight **pLightsAffect, unsigned int iLightsAffectCount) = 0;
	virtual void FreeHandle(RHND handle) = 0;

	// Particles:
	virtual void AddEmitter(CEmitter * pEmitter) = 0;
	virtual void UpdateEmitterData(CEmitter * pEmitter) = 0;

};

}