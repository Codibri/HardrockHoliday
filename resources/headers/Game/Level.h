#pragma once

#include "Root.h"
#include "MapPart.h"
#include "Game\GameObjects\Player.h"
#include <memory>

using namespace Vektoria;

class Level
{

public:
	Level();
	~Level();

	virtual void initialize(Vektoria::CScene* scene);

	void attachAllMapPartsToScene(Vektoria::CScene* scene);
	void switchOffAllMapParts();
	void switchOnAllMapParts();

	Player* getPlayer();

	MapPart* getNextMapPart();

private:

	int mMapPartLoadIndex;

	Player mPlayer;

	std::vector<MapPart*> mMapParts;

protected:
	
	void addMapPart(MapPart* p);

};

