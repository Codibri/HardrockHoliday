#include "Game\Levels\Level1.h"


Level1::Level1()
{
	addMapParts();
}


Level1::~Level1()
{
	
}


void Level1::initialize(Vektoria::CScene* scene){

	// Licht
	mLight1.Init(CHVector(0, 2, -2), CColor(0.7f, 0.7f, 0.7f));
	
	scene->AddParallelLight(&mLight1);

	// Himmel
	loadSkyBox(scene);
}


void Level1::addMapParts(){
	this->addMapPart(mPart1.get());
	this->addMapPart(mPart2.get());
	this->addMapPart(mPart3.get());
	this->addMapPart(mPart4.get());
	this->addMapPart(mPart5.get());
}


void Level1::loadSkyBox(Vektoria::CScene* scene){
	CFileWavefront loader;
	mSkyDome = std::unique_ptr<CGeo>(loader.LoadGeo("GameResources\\Levels\\level1\\sky.obj"));
	mSkyMaterial.MakeTextureSky("GameResources\\Levels\\level1\\sky.png");
	mSkyDome->SetMaterial(&mSkyMaterial);
	mSkyPlacement.AddGeo(mSkyDome.get());
	mSkyPlacement.SetSky();
	scene->AddPlacement(&mSkyPlacement);
}

