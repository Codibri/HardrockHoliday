
//by Alexander Weiﬂ, 2014

#ifndef GLOBAL_RESOURCES_H
#define GLOBAL_RESOURCES_H

#include "Root.h"


// add all resources here that should be available through the engine to all objects in the program. Seldom use appreciated...
struct GlobalResources
{
	HWND hWnd;
	Vektoria::CSplash* splash;
};

#endif