
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Engine\VektoriaCoreElements.h"


VektoriaCoreElements::VektoriaCoreElements()
{}


VektoriaCoreElements::~VektoriaCoreElements()
{}


void VektoriaCoreElements::initialize(HWND hWnd, Vektoria::CSplash* splash)
{
	root.Init(splash);

	frame.Init(hWnd);

	root.AddScene(&scene);

	root.AddFrameHere(&frame);

	viewport = nullptr;
}