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
	mGroundMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\part4\\part_GLOW.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part4::initGameObjects(){

	auto falle1 = new LochFalle(Vektoria::CHVector(1.0, 0.5, 1.0));
	falle1->getPlacement()->Translate(0, 0, -3);
	addGameObject(falle1);

	auto falle2 = new LochFalle(Vektoria::CHVector(1.0, 0.5, 1.0));
	falle2->getPlacement()->Translate(0, 0, -6);
	addGameObject(falle2);

}