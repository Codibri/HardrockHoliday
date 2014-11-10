#include "Graphics\PlayerVisual.h"


PlayerVisual::PlayerVisual() : Player(Vektoria::CPlacement())
{}


PlayerVisual::PlayerVisual(Vektoria::CPlacement position) : Player(position)
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
	mPlayerMaterial.MakeTextureImage("textures\\boulder_COLOR.png");
	mPlayerMaterial.MakeTextureBump("textures\\boulder_NRM.png");
	mPlayerMaterial.MakeTextureSpecular("textures\\boulder_SPEC.png");
	mPlayerMaterial.MakeTextureGlow("textures\\boulder_SPEC.png");
}

void PlayerVisual::loadMesh(){
	mPlayerMesh.Init(0.25, &mPlayerMaterial, 12, 12);
	_position.AddGeo(&mPlayerMesh);
}

