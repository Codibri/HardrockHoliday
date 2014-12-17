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
	//mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part3\\part_GLOW.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Textures\\black_image.jpg");

	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part3::initGameObjects(){

	// Wände
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);

	auto wall1 = new MapWall(scaleFromBlender(0.313, 0.202, 0.179));
	wall1->getPlacement()->RotateY(DEGREES_TO_RADIANS(-16.758));
	wall1->getPlacement()->TranslateDelta(locationFromBlender(0.33489, 0.26962, 0.1903));
	addGameObject(wall1);

	auto wall2 = new MapWall(scaleFromBlender(0.219, 0.192, 0.184));
	wall2->getPlacement()->RotateY(DEGREES_TO_RADIANS(-40.343));
	wall2->getPlacement()->TranslateDelta(locationFromBlender(0.0339, 4.16097, 0.13247));
	addGameObject(wall2);
	
	// TODO
	//auto wall3 = new MapWall(scaleFromBlender(0.219, 0.192, 0.184));
	//wall2->getPlacement()->TranslateDelta(locationFromBlender(0.0339, 4.16097, 0.13247));
	//addGameObject(wall2);

}