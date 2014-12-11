#include "Game\Levels\Level1Part1.h"



Level1Part1::Level1Part1() : MapPart(1)
{
	loadMesh("GameResources\\Levels\\level1\\part1\\level1_part1.obj");

	loadMaterial();

	initGameObjects();

}


Level1Part1::~Level1Part1()
{
}

void Level1Part1::loadMaterial(){

	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part1\\part_COLOR.png");
	//mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part1\\part_GLOW.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Textures\\black_image.jpg");
	mGroundMaterial.SetShadingOff();
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part1::initGameObjects(){

	// Löcher
	auto falle1 = new LochFalle(Vektoria::CHVector(0.5, 1.0, 1.0));
	falle1->getPlacement()->Translate(-0.29319, 0.0, -1.75256);
	addGameObject(falle1);

	auto falle2 = new LochFalle(Vektoria::CHVector(0.5, 1.0, 1.0));
	falle2->getPlacement()->Translate(0.32445, 0, -3.89241);
	addGameObject(falle2);

	auto falle3 = new LochFalle(Vektoria::CHVector(0.5, 1.0, 1.0));
	falle3->getPlacement()->Translate(0.24613, 0, -6.97389);
	addGameObject(falle3);

	// Wände
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);


}


