#include "Graphics\MapWallVisual.h"


MapWallVisual::MapWallVisual(Vektoria::CHVector boxColliderSize)
	: MapWall(boxColliderSize)
{

	mCubeMaterial.SetTransparencyOn();
	mCubeMaterial.MakeTextureImage("GameResources\\Levels\\level1\\collidervisualwall_COLOR.png");
	//mCubeMaterial.SetShadingOff();
	boxColliderSize *= 0.5;
	mCubeGeo.Init(boxColliderSize, &mCubeMaterial);
	getPlacement()->AddGeo(&mCubeGeo);
}


MapWallVisual::~MapWallVisual()
{
}
