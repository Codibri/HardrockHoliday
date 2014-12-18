#include "Graphics\PlayerVisual.h"


PlayerVisual::PlayerVisual(Vektoria::CPlacement* rotationPlacement, CPlacement* posPlacement) : Visual(rotationPlacement)
{
	loadMaterial();
	loadMesh();
	
	// Kugel um halben durchmesser anheben
	posPlacement->TranslateY(0.1);



}


PlayerVisual::~PlayerVisual()
{
}


void PlayerVisual::update(float deltaMillis, float time){
	// stuff...


}

void PlayerVisual::loadMaterial(){
	mPlayerMaterial.MakeTextureImage("GameResources\\Levels\\level1\\player\\boulder_COLOR.jpg");
	//mPlayerMaterial.MakeTextureBump("GameResources\\Textures\\boulder_NRM.png");
	mPlayerMaterial.MakeTextureSpecular("GameResources\\Levels\\level1\\player\\boulder_GLOW.jpg");
	mPlayerMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\player\\boulder_GLOW.jpg");
	//mPlayerMaterial.SetShadingOff();
}

void PlayerVisual::loadMesh(){
	//mPlayerMesh.Init(0.1, &mPlayerMaterial, 12, 12);
	//_placement->AddGeo(&mPlayerMesh);
	
	CFileWavefront objLoader = CFileWavefront();
	mObjPlayerMesh = objLoader.LoadGeo("GameResources\\Levels\\level1\\player\\level1_boulder.obj");
	mObjPlayerMesh->SetMaterial(&mPlayerMaterial);
	_placement->AddGeo(mObjPlayerMesh);
	


}

