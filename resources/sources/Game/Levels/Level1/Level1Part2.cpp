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
	// Wände
	auto wall1 = new MapWall(scaleFromBlender(0.143, 0.143, 0.143));
	wall1->getPlacement()->RotateY(DEGREES_TO_RADIANS(46.332));
	wall1->getPlacement()->TranslateDelta(locationFromBlender(0, 0.46861, 0.08028));
	addGameObject(wall1);

	auto wall2 = new MapWall(scaleFromBlender(0.207, 0.667, 0.207));
	wall2->getPlacement()->TranslateDelta(locationFromBlender(0, 1.15952, 0.0));
	addGameObject(wall2);

	auto wall3 = new MapWall(scaleFromBlender(0.131, 0.555, 0.159));
	wall3->getPlacement()->TranslateDelta(locationFromBlender(0.0, 2.00814, 0.0));
	addGameObject(wall3);


	//Löcher
	auto trap1 = new MapWall(scaleFromBlender(0.091, 0.555, 0.159));
	trap1->getPlacement()->TranslateDelta(locationFromBlender(0.0, 2.00814, 0.0));
	addGameObject(trap1);
}