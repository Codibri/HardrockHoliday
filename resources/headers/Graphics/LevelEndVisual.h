#pragma once

#include "Graphics\Visual.h"
#include "root.h"


class LevelEndVisual : public Visual {
public:
	LevelEndVisual(Vektoria::CHVector colliderSize, Vektoria::CPlacement *p);
	~LevelEndVisual();

private:

	Vektoria::CGeoCube mLevelEndGeo;
	Vektoria::CMaterial mLevelEndMaterial;
};