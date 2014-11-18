#include "Game\Levels\Level1Part1.h"



Level1Part1::Level1Part1() : MapPart(1)
{
	loadMesh("GameResources\\Levels\\level1\\part1\\part.obj");

	loadMaterial();

	initGameObjects();

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
	addGameObject(mFalle1Ptr);

	mFalle2Ptr = new LochFalleVisual(Vektoria::CHVector(1, 0.5, 0.5));
	mFalle2Ptr->getPlacement()->Translate(0, 0, -6);
	addGameObject(mFalle2Ptr);


	auto wallLeft = new MapWallVisual(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWallVisual(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);


}


