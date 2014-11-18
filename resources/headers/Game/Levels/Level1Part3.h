#pragma once
#include "Game\MapPart.h"
#include "Game\GameObjects\LochFalle.h"
#include "Game\GameObjects\MapWall.h"
class Level1Part3 :
	public MapPart
{
public:
	Level1Part3();
	~Level1Part3();

private:


	void loadMaterial();
	void initGameObjects();
};

