#pragma once
#include "Game\Level.h"

class MapPartManager
{

private:

	CScene* mScenePtr;

	Level* mActiveLevelPtr;


	MapPart* mFirstActiveMapPart;
	MapPart* mSecondActiveMapPart;

	
	bool mLastMapPartLoaded;
	const void preRenderMapParts(Vektoria::CRoot* r) const;
	const bool checkLoadNextMapPart(float absoluteZPos);
	void switchMapsParts();
	void loadNextMapPart();
	void checkIfLastMapPart(MapPart* part);
	bool mCheck;

public:
	MapPartManager();
	~MapPartManager();

	void setScene(CScene* scene);
	void initWithActiveLevel(Level* level, Vektoria::CRoot* root);
	void update(float deltaMillis, float fTime);
	void tickActiveObjects(float deltaMillis, float time) const;
};

