#pragma once
#include "Game\MapPart.h"
#include "Game\GameObjects\LochFalle.h"
#include "Game\GameObjects\MapWall.h"
class Level1Part2 :
	public MapPart
{
public:
	Level1Part2();
	~Level1Part2();

private:



	void loadMaterial();
	void initGameObjects();
};

