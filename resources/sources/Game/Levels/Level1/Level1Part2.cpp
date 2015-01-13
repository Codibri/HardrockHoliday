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
	mGroundMaterial.MakeTextureSpecular("GameResources\\Levels\\level1\\part2\\part_SPEC.png");
	mGroundMaterial.MakeTextureBump("GameResources\\Levels\\level1\\part2\\part_NRM.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part2::initGameObjects(){
	
	// Mapbegrenzung
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallLeft->getPlacement()->Translate(-1.1f, 0.25f, -4.0f);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallRight->getPlacement()->Translate(1.1f, 0.25f, -4.0f);
	addGameObject(wallRight);

	// Fallen und Wände
	addGameObjectsFromFile("GameResources\\Levels\\level1\\part2\\gameobjects_part2.txt");

}