#include "Graphics\LevelEndVisual.h"


LevelEndVisual::LevelEndVisual(Vektoria::CHVector colliderSize, Vektoria::CPlacement *p) : Visual(p)
{
	
	mLevelEndMaterial.MakeTextureImage("GameResources\\Levels\\level1\\levelend_COLOR.png");
	
	Vektoria::CHVector visualBoxSize = colliderSize * 0.5; // In Vektoria werden Cubes doppelt so groß dargestellt

	mLevelEndGeo.Init(visualBoxSize, &mLevelEndMaterial);

	_placement->AddGeo(&mLevelEndGeo);
}

LevelEndVisual::~LevelEndVisual()
{
}


