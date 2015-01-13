#include "Game\MapPartManager.h"


MapPartManager::MapPartManager()
{
	mLastMapPartLoaded = false;
	mCheck = false;
}


MapPartManager::~MapPartManager()
{
}


void MapPartManager::setScene(CScene* scene){
	mScenePtr = scene;
}

void MapPartManager::initWithActiveLevel(Level* level, Vektoria::CRoot* root){
	mActiveLevelPtr = level;

	preRenderMapParts(root);

	// Ersten MapPart laden und zur Scene hinzufügen
	mFirstActiveMapPart = mActiveLevelPtr->getNextMapPart();
	//mScenePtr->AddPlacement(mFirstActiveMapPart->getPlacement());
	mFirstActiveMapPart->getPlacement()->SwitchOn();

	// Falls weitere Mapparts vorhanden: zweiten Mapparte ladens
	if (!mFirstActiveMapPart->getIsLastMapPartOfLevel()){
		mSecondActiveMapPart = mActiveLevelPtr->getNextMapPart();
		//mSecondActiveMapPart->getPlacement()->TranslateZDelta(-MAP_PART_SIZE);
		//mScenePtr->AddPlacement(mSecondActiveMapPart->getPlacement());
		mSecondActiveMapPart->getPlacement()->SwitchOn();
	}
	
	

}

const void MapPartManager::preRenderMapParts(Vektoria::CRoot* r) const {
	// Alle Parts an Szene anhängen und switchOff aufrufen
	mActiveLevelPtr->attachAllMapPartsToScene(mScenePtr);
	mActiveLevelPtr->switchOnAllMapParts();
	float f = 0.001f;
	r->Tick(f);
	mActiveLevelPtr->switchOffAllMapParts();
}



void MapPartManager::update(float deltaMillis, float fTime) {

	float playerZPos = mActiveLevelPtr->getPlayer()
		->getPlacement()->GetTranslation().z;

	// Wenn sich der Spieler in der Mitte eines MapPartsbefinden soll 
	// der Nächste Mappart geladen werden
	if (checkLoadNextMapPart(playerZPos)){
		switchMapsParts();
	}

}

/*
*	Tick nur die aktiven GameObjects/Mapparts und den Player
*/
void MapPartManager::tickActiveObjects(float deltaMillis, float time) const {
	// Spieler ticken
	mActiveLevelPtr->getPlayer()->update(deltaMillis, time);
	// Aktive MapParts ticken
	mFirstActiveMapPart->tick(deltaMillis, time);
	mSecondActiveMapPart->tick(deltaMillis, time);

}


/*
*	Prüft ob sch der Spieler in der Mitte eines MapParts befindet
*
*/
const bool MapPartManager::checkLoadNextMapPart(float absoluteZPos){
	int activePartProgress = (int)-absoluteZPos % MapPart::MAP_PART_SIZE;
	if (activePartProgress == 1 && mCheck){
		mCheck = false;
		return true;
	}
	else if (activePartProgress > 1){
		mCheck = true;
	}
	return false;

}


/*
*	Entfernt den hinteren aktive Mappart aus der Szene 
*   und lädt den nächsten
*/
void MapPartManager::switchMapsParts(){

	// Placement aus sczene entfernen
	//mScenePtr->m_placements.Sub(mFirstActiveMapPart->getPlacement());
	//Placement ausschalten
	mFirstActiveMapPart->getPlacement()->SwitchOff();


	// Hinterer Mappart nun erster
	mFirstActiveMapPart = mSecondActiveMapPart;

	// Vorne Neuen MapPart laden
	loadNextMapPart();

	
}

/*
*	Fügt den nächsten Mappart zur Szene hinzu
*
*/
void MapPartManager::loadNextMapPart(){

	mSecondActiveMapPart = mActiveLevelPtr->getNextMapPart();

	// neuen MapPart an sezene anhängen
	//mSecondActiveMapPart->getPlacement()->TranslateZDelta(-MAP_PART_SIZE * 2);

	// Placement anschalten statt an scene anhängen
	//mScenePtr->AddPlacement(mSecondActiveMapPart->getPlacement());
	mSecondActiveMapPart->getPlacement()->SwitchOn();
}


void MapPartManager::checkIfLastMapPart(MapPart* part){
	if (part->getIsLastMapPartOfLevel())
		mLastMapPartLoaded = true;
}