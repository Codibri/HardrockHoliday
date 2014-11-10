#pragma once
#include "Renderframes.h"

//---------------------------------------------------
// CComputer: Klasse für Rendercomputer, welche in einer Szenengraph-Hierarchie eingebunden werden können 
//
// Autor: Prof. Dr. Tobias Breiner
// Letzte Änderung: 2011-08-07
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