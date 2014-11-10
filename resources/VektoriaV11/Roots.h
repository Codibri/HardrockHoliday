#pragma once
#include "Root.h"

class CRoots
{
public:
	CRoots();
	~CRoots();
	CRoots operator=(CRoots roots);

	void Init();
	void Tick(float fTimeDelta);
	void Fini();

	CRoot * Make(CScenes scenes, CComputers computers);
	void Kill(CRoot * proot);

	CRoot * m_prootFirst;
	CRoot * m_prootLast;
	int m_iRoots;
};
