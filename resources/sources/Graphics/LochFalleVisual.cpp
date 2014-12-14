#include "Graphics\LochFalleVisual.h"


LochFalleVisual::LochFalleVisual(Vektoria::CHVector boxColliderSize, Vektoria::CPlacement *p)
	: Visual(p)
{

	mCubeMaterial.SetTransparencyOn();
	mCubeMaterial.MakeTextureImage("GameResources\\Levels\\level1\\collidervisual_COLOR.png");
	//mCubeMaterial.SetShadingOff();
	//boxColliderSize *= 0.5;
	mCubeGeo.Init(boxColliderSize, &mCubeMaterial);
	_placement->AddGeo(&mCubeGeo);
}


LochFalleVisual::~LochFalleVisual()
{
}

