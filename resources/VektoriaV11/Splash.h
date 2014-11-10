#pragma once
#include "Windows.h"

//-------------------------------------------
// CSplash: Klasse für ein Spläschfenstersche
//
// Autor    : Prof. Dr. Tobias Breiner
// Ort      : Pfungstadt, 11.04.2014
// Copyright: Moyzelle Vektoria
//-------------------------------------------

namespace Vektoria
{


	class CSplash
	{
		friend class CRoot;
	public:
		CSplash();
		virtual ~CSplash();

		void Init(HWND hwnd, HINSTANCE hinstance);

		void Hide();
		void Show();

		bool m_bShow;

	private:
		int CalcKey(char * szPath);

		UINT m_idTimer;
		HWND m_hwndParent;
		HWND m_hwndSplash;
		bool m_bShowed;
	};

}