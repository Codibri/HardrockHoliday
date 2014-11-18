#include "Graphics\PlayerVisual.h"


PlayerVisual::PlayerVisual(Vektoria::CPlacement *p) : Visual(p)
{
	loadMaterial();
	loadMesh();
}


PlayerVisual::~PlayerVisual()
{
}


void PlayerVisual::update(float deltaMillis, float time){
	// stuff...


}

void PlayerVisual::loadMaterial(){
	mPlayerMaterial.MakeTextureImage("GameResources\\Textures\\boulder_COLOR.png");
	//mPlayerMaterial.MakeTextureBump("GameResources\\Textures\\boulder_NRM.png");
	mPlayerMaterial.MakeTextureSpecular("GameResources\\textures\\boulder_SPEC.png");
	mPlayerMaterial.MakeTextureGlow("GameResources\\textures\\boulder_GLOW.png");
}

void PlayerVisual::loadMesh(){
	mPlayerMesh.Init(0.15, &mPlayerMaterial, 12, 12);
	_placement->AddGeo(&mPlayerMesh);

}

