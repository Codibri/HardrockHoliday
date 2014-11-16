#include "Game\Levels\Level1Part4.h"


Level1Part4::Level1Part4() : MapPart(4)
{
	loadMesh("GameResources\\Levels\\level1\\part4\\part.obj");

	loadMaterial();

	initGameObjects();

	addGameObject(mFalle1Ptr);
	addGameObject(mFalle2Ptr);
}


Level1Part4::~Level1Part4()
{
}

void Level1Part4::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part4\\part_COLOR.png");
	mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part4\\part_GLOW.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part4::initGameObjects(){

	mFalle1Ptr = new LochFalleVisual(Vektoria::CHVector(1.0, 0.5, 1.0));
	mFalle1Ptr->getPlacement()->Translate(0, 0, -3);

	mFalle2Ptr = new LochFalleVisual(Vektoria::CHVector(1.0, 0.5, 1.0));
	mFalle2Ptr->getPlacement()->Translate(0, 0, -6);

}