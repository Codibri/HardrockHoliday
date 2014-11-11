#include "Game\Levels\Level1Part1.h"



Level1Part1::Level1Part1() : MapPart(1)
{
	loadMesh("GameResources\\Levels\\level1\\part1\\part.obj");

	loadMaterial();

	initGameObjects();

	addGameObject(mFalle1Ptr);
	addGameObject(mFalle2Ptr);
}

Level1Part1::~Level1Part1()
{
}

void Level1Part1::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part1\\part_COLOR.png");
	mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part1\\part_GLOW.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part1::initGameObjects(){

	mFalle1Ptr = new LochFalleVisual(Vektoria::CHVector(0.5, 0.5, 1));
	mFalle1Ptr->getPlacement()->Translate(0, 0, -3);

	mFalle2Ptr = new LochFalleVisual(Vektoria::CHVector(1, 0.5, 0.5));
	mFalle2Ptr->getPlacement()->Translate(0, 0, -6);

}


