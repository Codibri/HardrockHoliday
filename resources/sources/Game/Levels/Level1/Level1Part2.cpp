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
	//mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part2\\part_GLOW.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Textures\\black_image.jpg");
	mGroundMaterial.SetShadingOff();
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part2::initGameObjects(){

	auto falle1 = new LochFalle(Vektoria::CHVector(1.0, 1.0, 1.0));
	falle1->getPlacement()->Translate(0, 0, 0);
	this->addGameObject(falle1);

	// Wände
	auto wallLeft = new MapWall(Vektoria::CHVector(2.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-2.6, 0.25, 0.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(2.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(2.6, 0.25, 0.0);
	addGameObject(wallRight);

}