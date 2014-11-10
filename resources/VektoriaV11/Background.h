#pragma once
#include "Sprite.h"

//------------------------------------
// CBackground
//
// Autor    : Prof. Dr. Tobias Breiner
// Ort      : Pfungstadt, 11.10.2011
// Copyright: Moyzelle Vektoria
//------------------------------------

namespace Vektoria
{

	class CViewport;

	class CBackground : public CSprite
	{
	public:
		CBackground();
		~CBackground();
		CBackground operator=(CBackground background);

		void Tick(float & fTimeDelta);

	};

}