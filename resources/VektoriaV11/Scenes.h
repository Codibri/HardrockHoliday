#pragma once

#include "Scene.h"

//------------------------------------
// CScenes, Pluralklasse von CScene
// 
// Autor    : Prof. Dr. Tobias Breiner
// Ort      : Pfungstadt, 29.03.2012
// Copyright: Moyzelle Vektoria
//------------------------------------

namespace Vektoria
{

class CScenes
{
public:
	CScenes();
	~CScenes();
	CScenes operator=(CScenes scenes);

	void Init();
	void Tick(float & fTimeDelta);
	void Fini();



	void Add(CScene * pscene);
	bool Sub(CScene * pscene);

	void Draw(CCamera * pcamera);



	CScene * Make();
	bool Kill(CScene * pscene);

	CScene ** m_apscene;
	int m_iSceneAllocs;
	int m_iAllocBlock;
	int m_iScenes;
	void SetRoot(CRoot * m_proot);
	CRoot * m_proot;
};

}