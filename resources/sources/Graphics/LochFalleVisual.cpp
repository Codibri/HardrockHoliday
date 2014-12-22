#include "Graphics\LochFalleVisual.h"


LochFalleVisual::LochFalleVisual(Vektoria::CHVector boxColliderSize, Vektoria::CPlacement *p)
	: Visual(p)
{

	mCubeMaterial.SetTransparencyOn();
	mCubeMaterial.MakeTextureImage("GameResources\\Levels\\level1\\collidervisual_COLOR.png");
	//mCubeMaterial.SetShadingOff();
	//boxColliderSize *= 0.5;

	Vektoria::CHVector visualBoxSize = boxColliderSize * 0.5; // In Vektoria werden Cubes doppelt so groß dargestellt

	mCubeGeo.Init(visualBoxSize, &mCubeMaterial);
	_placement->AddGeo(&mCubeGeo);
}


LochFalleVisual::~LochFalleVisual()
{
}

