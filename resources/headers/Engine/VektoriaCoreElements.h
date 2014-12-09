
/*by Alexander Weiﬂ, 2014
_____           _ _ _          _
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
\____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef VEKTORIA_CORE_ELEMENTS_H
#define VEKTORIA_CORE_ELEMENTS_H

#include "Root.h"


class VektoriaCoreElements
{
public:
	VektoriaCoreElements();
	~VektoriaCoreElements();

	void initialize(HWND hWnd, Vektoria::CSplash* splash);

	Vektoria::CRoot root;
	Vektoria::CFrame frame;
	Vektoria::CViewport viewport;
	Vektoria::CScene scene;
};

#endif