#include "Graphics\MapWallVisual.h"


MapWallVisual::MapWallVisual(Vektoria::CHVector boxColliderSize, Vektoria::CPlacement *p)
	: Visual(p)
{

	mCubeMaterial.SetTransparencyOn();
	mCubeMaterial.MakeTextureImage("GameResources\\Levels\\level1\\collidervisualwall_COLOR.png");
	//mCubeMaterial.SetShadingOff();
	//boxColliderSize *= 0.5;
	
	Vektoria::CHVector visualBoxSize = boxColliderSize * 0.5; // In Vektoria werden Cubes doppelt so groß dargestellt

	mCubeGeo.Init(visualBoxSize, &mCubeMaterial);
	if (SHOW_GAME_OBJECT_COLLIDERS)
		_placement->AddGeo(&mCubeGeo);
}


MapWallVisual::~MapWallVisual()
{
}
