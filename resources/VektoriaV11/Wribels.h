#pragma once

#include "Wribel.h"

//------------------------------------
// CWribels, Pluralklasse von CWribel
// 
// Autor    : Prof. Dr. Tobias Breiner
// Ort      : Pfungstadt, 01.06.2013
// Copyright: Moyzelle Vektoria
//------------------------------------

namespace Vektoria
{

	class CWribels
	{
	public:
		CWribels();
		~CWribels();
		CWribels operator=(CWribels wribels);

		void Init();
		void Tick(CHMat & mGlobalFather, float & fTimeDelta, bool bTick);
		void Fini();

		void Add(CWribel * pwribel);
		bool Sub(CWribel * pwribel);

		CWribel * Make(CFloatRect & floatrect, int ixChars, CWritingFont * pwritingfont);
		bool Kill(CWribel * pwribel);

		void Draw(CCamera * pcamera, CHMat & mGlobalFather);

		CWribel ** m_apwribel;
		int m_iWribelAllocs;
		int m_iAllocBlock;
		int m_iWribels;
	};
}