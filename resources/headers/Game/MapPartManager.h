#pragma once
#include "Game\Level.h"

class MapPartManager
{

private:

	CScene* mScenePtr;

	Level* mActiveLevelPtr;

	MapPart* mFirstActiveMapPart;
	MapPart* mSecondActiveMapPart;


	bool playerIsAtMapPartMid(float absoluteZPos);
	void switchMapsParts();
	void loadNextMapPart();
	void checkIfLastMapPart(MapPart* part);
	
	const float MAP_PART_SIZE = 8.0;

	bool mLastMapPartLoaded;



	//Test
	bool mCheck;

public:
	MapPartManager();
	~MapPartManager();

	void setScene(CScene* scene);

	void initWithActiveLevel(Level* level, Vektoria::CRoot* root);

	void update(float deltaMillis, float fTime);

	void tickActiveObjects(float deltaMillis, float time);
};

