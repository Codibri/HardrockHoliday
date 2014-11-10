#include "Game\Level.h"


Level::Level() 
{
	mMapPartLoadIndex = 0;
	
}


Level::~Level()
{
}


void Level::initialize(Vektoria::CScene* scene){

}



PlayerVisual* Level::getPlayer(){
	return &mPlayer;
}



MapPart* Level::getNextMapPart(){

	if (mMapParts.size() - 1 > mMapPartLoadIndex){
		MapPart* part = mMapParts[mMapPartLoadIndex++];
		return part;
	}

	else if (mMapParts.size() - 1 == mMapPartLoadIndex){
		mMapParts[mMapPartLoadIndex]->setIsLastMapPartOfLevel();
		return mMapParts[mMapPartLoadIndex];
	}

	std::cerr << "MapPart.getNextMapPart(): Error, no Mapparts initialized.";
}

void Level::addMapPart(MapPart* p){
	mMapParts.push_back(p);
}


