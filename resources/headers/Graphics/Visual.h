#pragma once

#include "root.h"

class Visual {

public:

	Visual(Vektoria::CPlacement *p);
	~Visual();

	virtual void update(float deltaMillis, float time);

protected:

	Vektoria::CPlacement* _placement;
	
};