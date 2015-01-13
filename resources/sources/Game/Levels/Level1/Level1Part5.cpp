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
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallLeft->getPlacement()->Translate(-1.1f, 0.25f, -4.0f);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallRight->getPlacement()->Translate(1.1f, 0.25f, -4.0f);
	addGameObject(wallRight);

	// Level Ende
	auto levelEnd = new LevelEnd(scaleFromBlender(0.341f, 0.086f, 0.341f));
	levelEnd->getPlacement()->Translate(locationFromBlender(0.00143f, 8.34882f, 0.09395f));
	addGameObject(levelEnd);

	// Fallen und Wände
	addGameObjectsFromFile("GameResources\\Levels\\level1\\part5\\gameobjects_part5.txt");

}