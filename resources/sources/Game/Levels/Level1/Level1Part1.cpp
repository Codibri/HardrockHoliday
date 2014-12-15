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

	// L�cher
	auto falle1 = new LochFalle(Vektoria::CHVector(0.25, 1.0, 0.5));
	falle1->getPlacement()->Translate(-0.29319, -0.5, -1.75256);
	addGameObject(falle1);

	auto falle2 = new LochFalle(Vektoria::CHVector(0.25, 1.0, 0.5));
	falle2->getPlacement()->Translate(0.32445, -0.5, -3.89241);
	addGameObject(falle2);

	auto falle3 = new LochFalle(Vektoria::CHVector(0.25, 1.0, 0.5));
	falle3->getPlacement()->Translate(0.24613, -0.5, -6.97389);
	addGameObject(falle3);

	// W�nde
	auto wallLeft = new MapWall(Vektoria::CHVector(2.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-2.6, 0.25, 0.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(2.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(2.6, 0.25, 0.0);
	addGameObject(wallRight);


}


