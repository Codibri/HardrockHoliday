#pragma once
#include "Renderframes.h"

//---------------------------------------------------
// CComputer: Klasse f�r Rendercomputer, welche in einer Szenengraph-Hierarchie eingebunden werden k�nnen 
//
// Autor: Prof. Dr. Tobias Breiner
// Letzte �nderung: 2011-08-07
//---------------------------------------------------

class CComputer
{
public:
	CComputer();
	~CComputer();
	CComputer operator=(CComputer computer);
	void Copy(CComputer computer);

	void SetRoot(CRoot * proot);

	void Init(bool bThis);
	void Tick(float & fTimeDelta);
	void Fini();

	void AddRenderframe(CRenderframe * prenderframe);

	CRenderframes m_renderframes;
	bool m_bThis;
	CRoot * m_proot;
};