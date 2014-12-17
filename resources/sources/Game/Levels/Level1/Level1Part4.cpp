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

	
}