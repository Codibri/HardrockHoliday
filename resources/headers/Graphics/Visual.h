#pragma once

#include "root.h"


#define SHOW_GAME_OBJECT_COLLIDERS 1



class Visual {

public:

	Visual(Vektoria::CPlacement *p);
	~Visual();

	virtual void update(float deltaMillis, float time);

protected:

	Vektoria::CPlacement* _placement;
	
};