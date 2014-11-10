#pragma once
#include "Node.h"
#include "Color.h"
#include "RenderApi.h"
#include "Geo.h"

//---------------------------------------------------
// CLight: Klasse für Lichter
//
// Autoren: Prof. Dr. Tobias Breiner, Florian Schnell
// Letzte Änderung: 2012-06-05
//---------------------------------------------------

// specifies the maximum of lightsources that can be created
#define LIGHTS_MAX 100

namespace Vektoria
{

struct LIGHTTEST_RESULT
{
	float fIntensity;
	CLight *pLight;
};

struct LIGHTTEST_RESULTLIST
{
	unsigned int iCount;
	LIGHTTEST_RESULT lrResults[4];
};

class CDrawable;
class CLight : public CNode
{
	friend class CLights;
	friend class CParallelLights;
	friend class CPointLights;
	friend class CSpotLights;
private: 
	void Tick(CHMat & m, float & fTimeDelta);

public:
	static unsigned int s_iLightCount;
	static CLight **s_ppLights;
	static void FindLights(CGeo *geo);
  static void FindLights(CDrawable *drawable);

	CLight();
	~CLight();
	CLight operator=(CLight light);
	void Copy(CLight light);

	void Init(CColor pcolor);
	void Fini();

	virtual void UpdateAABB();


	// parameters every light should have
	CColor m_color;
	bool m_bActivated;
	float m_fAttenuationConstant;
	float m_fAttenuationLinear;
	float m_fAttenuationQuadratic;

	// shadow casting
	bool m_bCauseShadow;
	CHMat m_mProjection;
	CHMat m_mView;
	void SetShadowMapResolution(int iPixelsWidth, int iPixelsHeight);
	int m_iShadowMapWidth;
	int m_iShadowMapHeight;

	RHND m_handle;

private:
  static int FindLights(CHVector &vPosition, CLight **apLightsAffect);
};

}