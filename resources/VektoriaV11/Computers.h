#pragma once
#include "Computer.h"

//------------------------------------
// CComputers, Pluralklasse von CComputer
// 
// Autor: Prof. Dr. Tobias Breiner
// Pfungstadt, 11.10.2011
//------------------------------------

class CComputers
{
public:
	CComputers();
	~CComputers();
	CComputers operator=(CComputers computers);

	void SetRoot(CRoot * proot);

	void Init();
	void Tick(float & fTimeDelta);
	void Fini();

	void Add(CComputer * pcomputer);
	bool Sub(CComputer * pcomputer);

	CComputer * Make(bool bThis);
	bool Kill(CComputer * pcomputer);

	CComputer ** m_apcomputer;
	int m_iComputerAllocs;
	int m_iAllocBlock;
	int m_iComputers;
	CRoot * m_proot;
};
