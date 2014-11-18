#pragma once
#include "Game\MapPart.h"
#include "Game\GameObjects\LochFalle.h"
#include "Game\GameObjects\MapWall.h"
class Level1Part4 :
	public MapPart
{
public:
	Level1Part4();
	~Level1Part4();

private:



	void loadMaterial();
	void initGameObjects();
};

