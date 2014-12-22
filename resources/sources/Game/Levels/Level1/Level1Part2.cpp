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
	mGroundMaterial.MakeTextureSpecular("GameResources\\Textures\\black_image.jpg");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part2::initGameObjects(){
	// Wände

	auto wallLeft = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallLeft->getPlacement()->Translate(-1.1, 0.25, -4.0);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0, 0.5, 8.0));
	wallRight->getPlacement()->Translate(1.1, 0.25, -4.0);
	addGameObject(wallRight);

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

	auto wall4 = new MapWall(scaleFromBlender(0.358, -0.65, 0.239));
	wall4->getPlacement()->TranslateDelta(locationFromBlender(0.0949, 6.33945, 0.10739));
	addGameObject(wall4);

	//Löcher
	auto trap1 = new LochFalle(scaleFromBlender(0.069, 0.416, 0.207));
	trap1->getPlacement()->TranslateDelta(locationFromBlender(0.53894, 2.42047, 0.0));
	addGameObject(trap1);

	auto trap2 = new LochFalle(scaleFromBlender(0.182, 0.473, 0.296));
	trap2->getPlacement()->TranslateDelta(locationFromBlender(-0.50068, 3.84584, -0.06581));
	addGameObject(trap2);
	auto trap3 = new LochFalle(scaleFromBlender(0.118, 0.342, 0.308));
	trap3->getPlacement()->TranslateDelta(locationFromBlender(-0.27805, 3.84584, -0.08013));
	addGameObject(trap3);


	auto trap4 = new LochFalle(scaleFromBlender(0.358, 0.173, 0.487));
	trap4->getPlacement()->TranslateDelta(locationFromBlender(0.20733, 5.37637, -0.22546));
	addGameObject(trap4);

	
	


}