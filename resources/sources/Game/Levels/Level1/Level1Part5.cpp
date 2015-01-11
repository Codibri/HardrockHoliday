#include "Game\Levels\Level1Part5.h"


Level1Part5::Level1Part5() : MapPart(5)
{
	loadMesh("GameResources\\Levels\\level1\\part5\\part.obj");

	loadMaterial();

	initGameObjects();

;
}


Level1Part5::~Level1Part5()
{
}

void Level1Part5::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part5\\part_COLOR.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Levels\\level1\\part5\\part_SPEC.png");
	mGroundMaterial.MakeTextureBump("GameResources\\Levels\\level1\\part5\\part_NRM.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part5::initGameObjects(){

	// Map-Begrenzung
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);

	// Level Ende
	auto levelEnd = new LevelEnd(scaleFromBlender(0.341, 0.086, 0.341));
	levelEnd->getPlacement()->Translate(locationFromBlender(0.00143, 8.34882, 0.09395));
	addGameObject(levelEnd);

	// Fallen und W�nde
	addGameObjectsFromFile("GameResources\\Levels\\level1\\part5\\gameobjects_part5.txt");

}