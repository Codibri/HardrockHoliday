#pragma once

//------------------------------------------------------------------
// NullRenderer: Klasse zur DirectX-Anbindung
//
// Autor: Prof. Dr. Tobias Breiner 
// Letzte Änderung: 2012-06-05
//-------------------------------------------------------------------

#include "../../RenderApi.h"

namespace Vektoria
{

class CNullRenderer : public CRenderApi
{
public:
	CNullRenderer(void);
	~CNullRenderer(void);

	// Geburt, Leben und Sterben:
	void Init(HWND hwnd, int iWidthWindow, int iHeightWindow, ERenderApi eRenderApi);
	void Tick();
	void Fini();

	// Viewport:
	void AddViewport(CViewport *pviewport);
	void BeginRenderViewport(CHMat & mProjection, CHMat & mView,  CHMat & mViewInv, CViewport &mViewport);
	void EndRenderViewport();
	void ChangeRenderState(CViewport *pviewport);
	void ChangeResolution(CViewport *pviewport);
	#ifdef POSTPROCESSING_ON
		void Postprocessing(CViewport *pviewport);
	#endif;

	// Schatten:
	void ResizeShadowMap(int iWidth, int iHeight);
	void BeginRenderShadow(CLight *plight, CViewport *pViewport);
	void EndRenderShadow();
	void ChangeRenderStateShadow(CViewport *pviewport);

	// Texturen und Materialien:
	void CreateMaterial(CMaterial * pmaterial);
	void UpdateMaterial(CMaterial * pmaterial); 		
	void UpdateMaterialAni(CMaterial * pmaterial);
	bool DeleteMaterial(CMaterial * pmaterial);

	// Licht:
	RHND CreateLight(CLight *plight);
	void DestroyLight(RHND hLight);


	// Geometrie:
	RHND CreateTriangleList(CTriangleList *ptriangleList);
	RHND CreateTriangleStrip(CTriangleStrip *ptriangleStrip);
	void UpdateTriangleList(CTriangleList *ptrianglelist, RHND & handle);
	void UpdateTriangleStrip(CTriangleStrip *ptrianglestrip, RHND & handle);
	void FreeHandle(RHND handle);
	void Draw(RHND & handle, int & idTexture,float fDistanceToCameraSquare, int iKind, CHMat & mGlobal, CLight **pLightsAffect, unsigned int iLightsAffectCount);
	
	// Particles: 
	void AddEmitter(CEmitter * pEmitter);
	void UpdateEmitterData(CEmitter * pEmitter);
};

}