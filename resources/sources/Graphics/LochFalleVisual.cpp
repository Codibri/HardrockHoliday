#include "Graphics\LochFalleVisual.h"


LochFalleVisual::LochFalleVisual(Vektoria::CHVector boxColliderSize) 
	 : LochFalle(boxColliderSize)
{

	mCubeMaterial.SetTransparencyOn();
	mCubeMaterial.MakeTextureImage("GameResources\\Levels\\level1\\collidervisual_COLOR.png");
	//mCubeMaterial.SetShadingOff();
	boxColliderSize *= 0.5;
	mCubeGeo.Init(boxColliderSize, &mCubeMaterial);
	getPlacement()->AddGeo(&mCubeGeo);
}


LochFalleVisual::~LochFalleVisual()
{
}

