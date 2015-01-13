#include "Game\Levels\Level1Part3.h"


Level1Part3::Level1Part3() : MapPart(3)
{
	loadMesh("GameResources\\Levels\\level1\\part3\\part.obj");

	loadMaterial();

	initGameObjects();

}


Level1Part3::~Level1Part3()
{
}

void Level1Part3::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part3\\part_COLOR.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Levels\\level1\\part3\\part_SPEC.png");
	mGroundMaterial.MakeTextureBump("GameResources\\Levels\\level1\\part3\\part_NRM.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part3::initGameObjects(){

	// Mapbegrenzung
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallLeft->getPlacement()->Translate(-1.1f, 0.25f, -4.0f);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallRight->getPlacement()->Translate(1.1f, 0.25f, -4.0f);
	addGameObject(wallRight);

	// Fallen und Wände
	addGameObjectsFromFile("GameResources\\Levels\\level1\\part3\\gameobjects_part3.txt");

}