#include "Game\Levels\Level1Part4.h"


Level1Part4::Level1Part4() : MapPart(4)
{
	loadMesh("GameResources\\Levels\\level1\\part4\\part.obj");

	loadMaterial();

	initGameObjects();

	
}


Level1Part4::~Level1Part4()
{
}

void Level1Part4::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part4\\part_COLOR.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Levels\\level1\\part4\\part_SPEC.png");
	mGroundMaterial.MakeTextureBump("GameResources\\Levels\\level1\\part4\\part_NRM.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part4::initGameObjects(){
	// Map-Begrenzung
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallLeft->getPlacement()->Translate(-1.1f, 0.25f, -4.0f);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallRight->getPlacement()->Translate(1.1f, 0.25f, -4.0f);
	addGameObject(wallRight);

	// Fallen und W�nde
	addGameObjectsFromFile("GameResources\\Levels\\level1\\part4\\gameobjects_part4.txt");
	
}