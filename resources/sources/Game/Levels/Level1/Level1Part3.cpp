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
	wall1->getPlacement()->TranslateDelta(locationFromBlender(0.36763, 0.29241, 0.19869));
	addGameObject(wall1);

	auto wall2 = new MapWall(scaleFromBlender(0.219, 0.192, 0.184));
	wall2->getPlacement()->RotateY(DEGREES_TO_RADIANS(-40.343));
	wall2->getPlacement()->TranslateDelta(locationFromBlender(0.0339, 4.16097, 0.13247));
	addGameObject(wall2);
	
	auto wall3 = new MapWall(scaleFromBlender(0.219, 0.418, 0.172));
	wall3->getPlacement()->TranslateDelta(locationFromBlender(-0.33976, 5.33336, 0.10314));
	addGameObject(wall3);

	auto wall4 = new MapWall(scaleFromBlender(0.239, 0.418, 0.172));
	wall4->getPlacement()->TranslateDelta(locationFromBlender(0.39903, 5.33336, 0.10314));
	addGameObject(wall4);

	// Löcher
	// vorne links
	auto trap1 = new LochFalle(scaleFromBlender(0.028, 0.22, 0.427));
	trap1->getPlacement()->TranslateDelta(locationFromBlender(-0.17359, 1.67233, -0.29155));
	addGameObject(trap1);
	auto trap2 = new LochFalle(scaleFromBlender(0.106, 0.79, 0.427));
	trap2->getPlacement()->TranslateDelta(locationFromBlender(-0.30768, 2.17949, -0.29155));
	addGameObject(trap2);
	auto trap3 = new LochFalle(scaleFromBlender(0.09, 0.675, 0.427));
	trap3->getPlacement()->TranslateDelta(locationFromBlender(-0.46724, 2.28908, -0.29155));
	addGameObject(trap3);

	// vorne rechts
	auto trap4 = new LochFalle(scaleFromBlender(0.028, 0.216, 0.427));
	trap4->getPlacement()->TranslateDelta(locationFromBlender(0.15291, 1.69257, -0.29155));
	addGameObject(trap4);
	auto trap5 = new LochFalle(scaleFromBlender(0.107, 0.776, 0.427));
	trap5->getPlacement()->TranslateDelta(locationFromBlender(0.28693, 2.19057, -0.29155));
	addGameObject(trap5);
	auto trap6 = new LochFalle(scaleFromBlender(0.091, 0.663, 0.427));
	trap6->getPlacement()->TranslateDelta(locationFromBlender(0.47908, 2.29818, -0.28155));
	addGameObject(trap6);
	// hinten links
	auto trap7 = new LochFalle(scaleFromBlender(0.16, 0.327, 0.237));
	trap7->getPlacement()->TranslateDelta(locationFromBlender(-0.29817, 6.18142, -0.11089));
	addGameObject(trap7);
	auto trap8 = new LochFalle(scaleFromBlender(0.127, 0.591, 0.247));
	trap8->getPlacement()->TranslateDelta(locationFromBlender(-0.37803, 7.12334, -0.11089));
	addGameObject(trap8);
	// hinten rechts
	auto trap9 = new LochFalle(scaleFromBlender(0.155, 0.304, 0.23));
	trap9->getPlacement()->TranslateDelta(locationFromBlender(0.32393, 6.1813, -0.11089));
	addGameObject(trap9);
	auto trap10 = new LochFalle(scaleFromBlender(0.121, 0.614, 0.236));
	trap10->getPlacement()->TranslateDelta(locationFromBlender(0.42273, 7.11998, -0.11089));
	addGameObject(trap10);

}