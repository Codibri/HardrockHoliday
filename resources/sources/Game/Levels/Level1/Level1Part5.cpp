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
	//mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part5\\part_GLOW.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Textures\\black_image.jpg");

	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part5::initGameObjects(){

	// Wände
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);

	auto wall1 = new MapWall(scaleFromBlender(0.133, 0.162, 0.2));
	wall1->getPlacement()->RotateY(DEGREES_TO_RADIANS(31.939));
	wall1->getPlacement()->TranslateDelta(locationFromBlender(-0.08893, 3.72845, 0.15527));
	addGameObject(wall1);
	auto wall2 = new MapWall(scaleFromBlender(0.133, 0.162, 0.2));
	wall2->getPlacement()->RotateY(DEGREES_TO_RADIANS(-26.838));
	wall2->getPlacement()->TranslateDelta(locationFromBlender(-0.0935, 3.88911, 0.15527));
	addGameObject(wall2);

	auto wall3 = new MapWall(scaleFromBlender(0.133, 0.126, 0.2));
	wall3->getPlacement()->TranslateDelta(locationFromBlender(0.14584, 5.42352, 0.15527));
	addGameObject(wall3);

	auto wall4 = new MapWall(scaleFromBlender(0.133, 0.509, 0.2));
	wall4->getPlacement()->TranslateDelta(locationFromBlender(-0.32279, 6.15118, 0.15527));
	addGameObject(wall4);

	auto wall5 = new MapWall(scaleFromBlender(0.133, 0.222, 0.2));
	wall5->getPlacement()->TranslateDelta(locationFromBlender(-0.77181, 7.09151, 0.15527));
	addGameObject(wall5);

	auto wall6 = new MapWall(scaleFromBlender(0.141, 0.394, 0.2));
	wall6->getPlacement()->RotateY(DEGREES_TO_RADIANS(-45.181));
	wall6->getPlacement()->TranslateDelta(locationFromBlender(-0.53028, 7.55564, 0.15527));
	addGameObject(wall6);

	auto wall7 = new MapWall(scaleFromBlender(0.133, 0.247, 0.2));
	wall7->getPlacement()->TranslateDelta(locationFromBlender(-0.28447, 7.99562, 0.15527));
	addGameObject(wall7);

	auto wall8 = new MapWall(scaleFromBlender(0.133, 0.247, 0.2));
	wall8->getPlacement()->TranslateDelta(locationFromBlender(0.2513, 7.93539, 0.15527));
	addGameObject(wall8);

	// Löcher
	auto trap1 = new LochFalle(scaleFromBlender(0.322, 0.423, 0.322));
	trap1->getPlacement()->TranslateDelta(locationFromBlender(-0.32419, 0.73792, 0.0));
	addGameObject(trap1);
	auto trap2 = new LochFalle(scaleFromBlender(0.155, 0.556, 0.322));
	trap2->getPlacement()->TranslateDelta(locationFromBlender(-0.40017, 1.71824, 0.0));
	addGameObject(trap2);

	auto trap3 = new LochFalle(scaleFromBlender(0.099, 0.915, 0.322));
	trap3->getPlacement()->TranslateDelta(locationFromBlender(0.41613, 1.25356, 0.0));
	addGameObject(trap3);
	auto trap4 = new LochFalle(scaleFromBlender(0.076, 0.124, 0.322));
	trap4->getPlacement()->TranslateDelta(locationFromBlender(0.19855, 1.53342, 0.0));
	addGameObject(trap4);
	auto trap5 = new LochFalle(scaleFromBlender(0.187, 0.304, 0.322));
	trap5->getPlacement()->TranslateDelta(locationFromBlender(0.17829, 1.85897, 0.0));
	addGameObject(trap5);

	auto trap6 = new LochFalle(scaleFromBlender(0.36, 0.131, 0.322));
	trap6->getPlacement()->TranslateDelta(locationFromBlender(0.23455, 3.32997, 0.0));
	addGameObject(trap6);

	auto trap7 = new LochFalle(scaleFromBlender(0.417, 0.273, 0.322));
	trap7->getPlacement()->TranslateDelta(locationFromBlender(-0.24336, 4.99784, 0.0));
	addGameObject(trap7);
	auto trap8 = new LochFalle(scaleFromBlender(-0.048, 0.081, 0.322));
	trap8->getPlacement()->TranslateDelta(locationFromBlender(0.20912, 4.92985, 0.0));
	addGameObject(trap8);

	auto trap9 = new LochFalle(scaleFromBlender(0.098, 0.25, 0.322));
	trap9->getPlacement()->TranslateDelta(locationFromBlender(0.50171, 6.17155, 0.0));
	addGameObject(trap9);
	auto trap10 = new LochFalle(scaleFromBlender(0.088, 0.175, 0.322));
	trap10->getPlacement()->RotateY(DEGREES_TO_RADIANS(58.881));
	trap10->getPlacement()->TranslateDelta(locationFromBlender(0.31525, 6.09434, 0.0));
	addGameObject(trap10);
	auto trap11 = new LochFalle(scaleFromBlender(0.098, 0.773, 0.322));
	trap11->getPlacement()->TranslateDelta(locationFromBlender(0.22112, 6.88833, 0.0));
	addGameObject(trap11);
	auto trap12 = new LochFalle(scaleFromBlender(0.191, 0.158, 0.322));
	trap12->getPlacement()->RotateY(DEGREES_TO_RADIANS(54.901));
	trap12->getPlacement()->TranslateDelta(locationFromBlender(0.06522, 7.13149, 0.0));
	addGameObject(trap12);
	auto trap13 = new LochFalle(scaleFromBlender(0.141, 0.173, 0.322));
	trap13->getPlacement()->RotateY(DEGREES_TO_RADIANS(-19.568));
	trap13->getPlacement()->TranslateDelta(locationFromBlender(0.233, 7.50554, 0.0));
	addGameObject(trap13);

}