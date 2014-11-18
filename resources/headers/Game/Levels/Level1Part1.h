#pragma once
#include "Game\MapPart.h"
#include "Game\GameObjects\LochFalle.h"
#include "Game\GameObjects\MapWall.h"
#include "root.h"

class Level1Part1 : public MapPart
{
public:
	Level1Part1();
	~Level1Part1();

private:
	


	void loadMaterial();
	void initGameObjects();
};

