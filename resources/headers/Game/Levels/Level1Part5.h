#pragma once
#include "Game\MapPart.h"
#include "Game\GameObjects\LochFalle.h"
#include "Game\GameObjects\MapWall.h"
#include "Game\GameObjects\LevelEnd.h"

class Level1Part5 :
	public MapPart
{
public:
	Level1Part5();
	~Level1Part5();


private:

	void loadMaterial();
	void initGameObjects();
};

