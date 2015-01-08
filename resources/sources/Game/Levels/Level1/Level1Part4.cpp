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
	//mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part4\\part_GLOW.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Textures\\black_image.jpg");
	
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part4::initGameObjects(){
	// Wände
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);

	auto wall1 = new MapWall(scaleFromBlender(0.18, 0.132, 0.222));
	wall1->getPlacement()->RotateY(DEGREES_TO_RADIANS(-40.091));
	wall1->getPlacement()->TranslateDelta(locationFromBlender(-0.0263, 3.991, 0.06516));
	addGameObject(wall1);
	auto wall2 = new MapWall(scaleFromBlender(0.18, 0.132, 0.222));
	wall2->getPlacement()->RotateY(DEGREES_TO_RADIANS(-88.763));
	wall2->getPlacement()->TranslateDelta(locationFromBlender(-0.12179, 4.19475, 0.06516));
	addGameObject(wall2);

	auto wall3 = new MapWall(scaleFromBlender(0.164, 0.178, 0.3));
	wall3->getPlacement()->RotateY(DEGREES_TO_RADIANS(-24.773));
	wall3->getPlacement()->TranslateDelta(locationFromBlender(0.12245, 5.86111, 0.06503));
	addGameObject(wall3);
	auto wall4 = new MapWall(scaleFromBlender(0.163, 0.13, 0.3));
	wall4->getPlacement()->RotateY(DEGREES_TO_RADIANS(3.933));
	wall4->getPlacement()->TranslateDelta(locationFromBlender(0.16841, 6.07759, 0.06503));
	addGameObject(wall4);

	//Löcher
	auto trap1 = new LochFalle(scaleFromBlender(0.069, 0.459, 0.311));
	trap1->getPlacement()->TranslateDelta(locationFromBlender(-0.21016, 0.85125, -0.16438));
	addGameObject(trap1);

	auto trap2 = new LochFalle(scaleFromBlender(0.069, 0.459, 0.311));
	trap2->getPlacement()->TranslateDelta(locationFromBlender(0.22509, 0.85125, -0.16438));
	addGameObject(trap2);

	auto trap3 = new LochFalle(scaleFromBlender(0.069, 0.352, 0.277));
	trap3->getPlacement()->TranslateDelta(locationFromBlender(-0.43887, 2.26921, -0.16438));
	addGameObject(trap3);

	auto trap4 = new LochFalle(scaleFromBlender(0.069, 0.352, 0.277));
	trap4->getPlacement()->TranslateDelta(locationFromBlender(0.00089, 2.26921, -0.16438));
	addGameObject(trap4);

	auto trap5 = new LochFalle(scaleFromBlender(0.069, 0.352, 0.277));
	trap5->getPlacement()->TranslateDelta(locationFromBlender(0.43437, 2.26921, -0.16438));
	addGameObject(trap5);

	auto trap6 = new LochFalle(scaleFromBlender(0.387, 0.113, 0.277));
	trap6->getPlacement()->TranslateDelta(locationFromBlender(0.27106, 3.56288, -0.16438));
	addGameObject(trap6);

	auto trap7 = new LochFalle(scaleFromBlender(0.387, 0.161, 0.277));
	trap7->getPlacement()->TranslateDelta(locationFromBlender(-0.17866, 5.46395, -0.16438));
	addGameObject(trap7);


	auto trap8 = new LochFalle(scaleFromBlender(0.191, 0.148, 0.277));
	trap8->getPlacement()->TranslateDelta(locationFromBlender(0.35852, 6.9843, -0.16438));
	addGameObject(trap8);
	auto trap9 = new LochFalle(scaleFromBlender(0.387, 0.161, 0.277));
	trap9->getPlacement()->TranslateDelta(locationFromBlender(0.3045, 7.269, -0.16438));
	addGameObject(trap9);
	
}