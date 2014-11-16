#include "Game\Levels\Level1Part5.h"


Level1Part5::Level1Part5() : MapPart(5)
{
	loadMesh("GameResources\\Levels\\level1\\part5\\part.obj");

	loadMaterial();

	initGameObjects();

	addGameObject(mFalle1Ptr);
	addGameObject(mFalle2Ptr);
}


Level1Part5::~Level1Part5()
{
}

void Level1Part5::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part5\\part_COLOR.png");
	mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part5\\part_GLOW.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part5::initGameObjects(){

	mFalle1Ptr = new LochFalleVisual(Vektoria::CHVector(1.0, 0.5, 1.0));
	mFalle1Ptr->getPlacement()->Translate(0, 0, -3);

	mFalle2Ptr = new LochFalleVisual(Vektoria::CHVector(1.0, 0.5, 1.0));
	mFalle2Ptr->getPlacement()->Translate(0, 0, -6);

}