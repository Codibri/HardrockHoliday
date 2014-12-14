#include "Graphics\MapWallVisual.h"


MapWallVisual::MapWallVisual(Vektoria::CHVector boxColliderSize, Vektoria::CPlacement *p)
	: Visual(p)
{

	//mCubeMaterial.SetTransparencyOn();
	mCubeMaterial.MakeTextureImage("GameResources\\Levels\\level1\\collidervisualwall_COLOR.png");
	//mCubeMaterial.SetShadingOff();
	//boxColliderSize *= 0.5;
	mCubeGeo.Init(boxColliderSize, &mCubeMaterial);
	_placement->AddGeo(&mCubeGeo);
}


MapWallVisual::~MapWallVisual()
{
}
