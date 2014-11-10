#pragma once

#include "Sprite.h"

//------------------------------------
// CSprites, Pluralklasse von CSprite
// 
// Autor    : Prof. Dr. Tobias Breiner
// Ort      : Pfungstadt, 11.10.2011
// Copyright: Moyzelle Vektoria
//------------------------------------

class CSprites
{
public:
	CSprites();
	~CSprites();
	CSprites operator=(CSprites sprites);

	void Init();
	void Tick(float & fTimeDelta);
	void Fini();

	void Add(CSprite * psprite);
	bool Sub(CSprite * psprite);

	CSprite * Make(CPixImage * ppiximage, CFloatRect & floatrect);
	bool Kill(CSprite * psprite);

	void SetViewport(CViewport * pviewport);

	CSprite ** m_apsprite;
	int m_iSpriteAllocs;
	int m_iAllocBlock;
	int m_iSprites;
	CViewport * m_pviewport;
};
