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

	auto falle1 = new LochFalle(Vektoria::CHVector(0.5, 0.5, 1));
	falle1->getPlacement()->Translate(0, 0, -3);
	addGameObject(falle1);

	auto falle2 = new LochFalle(Vektoria::CHVector(1, 0.5, 0.5));
	falle2->getPlacement()->Translate(0, 0, -6);
	addGameObject(falle2);

	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);


}


