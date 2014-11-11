#include "Graphics\PlayerVisual.h"


PlayerVisual::PlayerVisual() : Player()
{
	loadMaterial();
	loadMesh();
}


PlayerVisual::~PlayerVisual()
{
}


void PlayerVisual::update(float deltaMillis, float time){
	// stuff...


	// Player logik ticken
	Player::update(deltaMillis, time);
}

void PlayerVisual::loadMaterial(){
	mPlayerMaterial.MakeTextureImage("GameResources\\Textures\\boulder_COLOR.png");
	//mPlayerMaterial.MakeTextureBump("GameResources\\Textures\\boulder_NRM.png");
	mPlayerMaterial.MakeTextureSpecular("GameResources\\textures\\boulder_SPEC.png");
	mPlayerMaterial.MakeTextureGlow("GameResources\\T\\boulder_SPEC.png");
}

void PlayerVisual::loadMesh(){
	mPlayerMesh.Init(0.15, &mPlayerMaterial, 12, 12);
	getPlacement()->AddGeo(&mPlayerMesh);
	getPlacement()->TranslateY(0.15);
}

