#include "Graphics\PlayerVisual.h"


PlayerVisual::PlayerVisual(Vektoria::CPlacement* rotationPlacement, CPlacement* posPlacement) : Visual(rotationPlacement)
{
	loadMaterial();
	loadMesh();
	
	mPosPlacement = posPlacement;
	mLastPositionPlacement = CPlacement();
	mLastPositionPlacement.TranslateZ(0.1);

	// Kugel um halben durchmesser anheben
	mPosPlacement->TranslateY(0.1);

	// Spotlight
	mSpotLightPlacment.AddSpotLight(&mSpotLight);
	mSpotLightPlacment.Translate(-0.2, 15.7, 7);
	mSpotLight.Init(CColor(1.0, 1.0, 1.0), 0.105F, 0.227F);
	mSpotLight.SetMaxDistance(120.0F);
	mSpotLight.SetMinDistance(0.0F);
	mSpotLight.SetSoftShadowOn();
	mSpotLight.SetShadowMapResolution(8096, 8096);
	mPosPlacement->AddPlacement(&mSpotLightPlacment);

}


PlayerVisual::~PlayerVisual()
{
}


void PlayerVisual::update(float deltaMillis, float time){
	// Spotlight position updaten
	mOrigin = CHVector(0, 0, 0, 1);
	mOrigin = _placement ->m_amGlobal[0] * mOrigin;
	mSpotLightPlacment.SetPointing(&mOrigin);

	// Kugel drehen
	CHVector moveDirection = mPosPlacement->GetTranslation() - mLastPositionPlacement.GetTranslation();
	moveDirection.Norm();
	_placement->RotateDelta(CHVector(moveDirection.z, 0, -moveDirection.x), deltaMillis * 1.2);
	mLastPositionPlacement.Translate(mPosPlacement->GetTranslation());

}

void PlayerVisual::loadMaterial(){
	mPlayerMaterial.MakeTextureImage("GameResources\\Levels\\level1\\player\\boulder_COLOR.jpg");
	mPlayerMaterial.MakeTextureBump("GameResources\\Levels\\level1\\player\\boulder_BUMP.jpg");
	mPlayerMaterial.MakeTextureSpecular("GameResources\\Levels\\level1\\player\\boulder_SPEC.jpg");
	mPlayerMaterial.MakeTextureGlow("GameResources\\Levels\\level1\\player\\boulder_GLOW.jpg");

}

void PlayerVisual::loadMesh(){
	CFileWavefront objLoader = CFileWavefront();
	mObjPlayerMesh = objLoader.LoadGeo("GameResources\\Levels\\level1\\player\\level1_boulder.obj");
	mObjPlayerMesh->SetMaterial(&mPlayerMaterial);
	rs::TangentSpaceHelper::calculateTangentsAndBitangents(mObjPlayerMesh);
	CHMat m; m.RotateX(-1.0); m.RotateY(1.7);
	mObjPlayerMesh->Transform(m);
	_placement->AddGeo(mObjPlayerMesh);
}

