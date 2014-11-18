#include "Game\Levels\Level1Part2.h"


Level1Part2::Level1Part2() : MapPart(2)
{
	loadMesh("GameResources\\Levels\\level1\\part2\\part.obj");
	
	loadMaterial();

	initGameObjects();

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

	auto falle1 = new LochFalle(Vektoria::CHVector(1.0, 0.5, 1.0));
	falle1->getPlacement()->Translate(0, 0, -3);
	addGameObject(falle1);

	auto falle2 = new LochFalle(Vektoria::CHVector(1.0, 0.5, 1.0));
	falle2->getPlacement()->Translate(0, 0, -6);
	addGameObject(falle2);

	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);

}