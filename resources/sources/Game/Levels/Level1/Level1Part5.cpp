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

	

}