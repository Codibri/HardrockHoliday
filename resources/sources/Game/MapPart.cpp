#include "Game\MapPart.h"

const int MapPart::MAP_PART_SIZE = 8.0;



MapPart::MapPart(int nr)
{
	mIsLastMapPartOfLevel = false;
	mPartNr = nr;
}


MapPart::~MapPart()
{
}


// tickt alle Gameobjects durch
void MapPart::tick(float deltaMillis, float time){
	for (auto&& r : mGameObjects){
		r->update(deltaMillis, time);
	}
}


Vektoria::CPlacement*  MapPart::getPlacement(){
	return &mRootPlacement;
}


bool MapPart::getIsLastMapPartOfLevel(){
	return mIsLastMapPartOfLevel;
}


void MapPart::setIsLastMapPartOfLevel(){
	mIsLastMapPartOfLevel = true;
}

void MapPart::addGameObject(GameObject* obj){
	mGameObjects.push_back(std::unique_ptr<GameObject>(obj));

	// GameObject an MapPart Root anhängen
	mRootPlacement.AddPlacement(obj->getPlacement());
}

void MapPart::addGameObjectsFromFile(std::string fileName){

	GameObjectLoader loader;
	auto gos = loader.LoadGameObjects(fileName);
	for each(auto gameObject in gos){
		addGameObject(gameObject);
	}

}


void MapPart::loadMesh(std::string objFilePath){
	Vektoria::CFileWavefront loader = Vektoria::CFileWavefront();

	mGroundMesh = loader.LoadGeo((char*)objFilePath.c_str());
	
	rs::TangentSpaceHelper::calculateTangentsAndBitangents(mGroundMesh);

	mGroundMesh->SetMaterial(&mGroundMaterial);

	mRootPlacement.AddGeo(mGroundMesh);
}