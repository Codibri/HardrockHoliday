#include "Game\Levels\Level1Part2.h"


Level1Part2::Level1Part2() : MapPart(2)
{
	loadMesh("GameResources\\Levels\\level1\\part2\\part.obj");
	
	loadMaterial();

	initGameObjects();

	addGameObject(mFalle1Ptr);
	addGameObject(mFalle2Ptr);
}


Level1Part2::~Level1Part2()
{
}

void Level1Part2::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part2\\part_COLOR.png");
	mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part2\\part_GLOW.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part2::initGameObjects(){

	mFalle1Ptr = new LochFalleVisual(Vektoria::CHVector(1.0, 0.5, 1.0));
	mFalle1Ptr->getPlacement()->Translate(0, 0, -3);

	mFalle2Ptr = new LochFalleVisual(Vektoria::CHVector(1.0, 0.5, 1.0));
	mFalle2Ptr->getPlacement()->Translate(0, 0, -6);

}