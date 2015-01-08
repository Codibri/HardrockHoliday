
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef GLOBAL_RESOURCES_H
#define GLOBAL_RESOURCES_H

#include "VektoriaCoreElements.h"

// Add all resources here that should be available through the engine to all objects in the program. Seldom use appreciated...
struct GlobalResources
{
	HWND hWnd;
	Vektoria::CSplash* splash;
	VektoriaCoreElements vektoriaCoreElements;
	bool endThisMess;
};

#endif