#pragma once

#include "Light.h"
#include "HMat.h"

//------------------------------------
// CLights, Pluralklasse von CLight
// Copyright: Prof. Dr. Tobias Breiner
// Pfungstadt, 11.10.2011
//------------------------------------

namespace Vektoria
{

class CLights
{
public:
	CLights();
	~CLights();
	CLights operator=(CLights lights);

	void Init();
	void Tick(CHMat &m,float & fTimeDelta);
	void Fini();

	void Add(CLight * plight);
	bool Sub(CLight * plight);

	CLight * Make(CColor pcolor);
//	CLight * Make(CColor pcolor, CRenderApi *prenderapi);
	bool Kill(CLight * plight);

	CLight ** m_aplight;
	int m_iLightAllocs;
	int m_iAllocBlock;
	int m_iLights;
};

}