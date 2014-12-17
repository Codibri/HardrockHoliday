#include "Graphics\PlayerVisual.h"


PlayerVisual::PlayerVisual(Vektoria::CPlacement* rotationPlacement, CPlacement* posPlacement) : Visual(rotationPlacement)
{
	loadMaterial();
	loadMesh();
	
	// Kugel um halben durchmesser anheben
	posPlacement->TranslateY(0.1);

	
	mSpotLightPlacment.AddSpotLight(&mSpotLight);
	mSpotLightPlacment.Translate(0.0, 10.0, 0);
	mSpotLight.Init(CColor(1.0, 1.0, 1.0), 0.035F, 0.077F);
	mSpotLight.SetMaxDistance(100.0F);
	mSpotLight.SetMinDistance(0.0F);
	mSpotLight.SetSoftShadowOn();
	mSpotLight.SetShadowMapResolution(8096, 8096);


	posPlacement->AddPlacement(&mSpotLightPlacment);


	/*
	m_zpSpotLight.AddSpotLight(&m_zlSpot);
	m_zpSpotLight.Translate(30, 100, 30);
	m_vUrsprung = CHVector(0, 0, 0, 1);
	m_zpSpotLight.SetPointing(&m_vUrsprung);


	m_zlSpot.Init(CColor(1.0F, 1.0F, 1.0F), 0.05F, 0.07F);
	m_zlSpot.SetMaxDistance(100.0F);
	m_zlSpot.SetMinDistance(44.0F);
	m_zlSpot.SetSoftShadowOn();
	m_zlSpot.SetShadowMapResolution(8096, 8096);
	*/
}


PlayerVisual::~PlayerVisual()
{
}


void PlayerVisual::update(float deltaMillis, float time){
	// stuff...
	mOrigin = CHVector(0, 0, 0, 1);

	mOrigin = _placement ->m_amGlobal[0] * mOrigin;

	mSpotLightPlacment.SetPointing(&mOrigin);


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

