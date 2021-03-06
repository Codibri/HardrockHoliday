#pragma once

#include "Placement.h"
#include "Cameras.h"

//------------------------------------
// CPlacements, Pluralklasse von CPlacement
// Copyright: Prof. Dr. Tobias Breiner
// Pfungstadt, 11.10.2011
//------------------------------------

namespace Vektoria
{

class CPlacements
{
public:
	CPlacements();
	~CPlacements();
	CPlacements operator=(CPlacements placements);

	void Init();
	void Tick(CHMat & m, float & fTimeDelta, bool & bTick);
	void Fini();


	void Add(CPlacement * pplacement);
	bool Sub(CPlacement * pplacement);

	CPlacement * Make();
	bool Kill(CPlacement * pplacement);

	void Draw(CCamera * pcamera, CHMat & mGlobalFather);

	void SearchForCameras(CCameras * pcameras);
	CPlacement ** m_applacement;
	int m_iPlacementAllocs;
	int m_iAllocBlock;
	int m_iPlacements;

	void SetRoot(CRoot * proot);
	CRoot * m_proot;
};

}