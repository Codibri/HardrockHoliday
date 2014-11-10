#pragma once

#include "Game\Level.h"
#include "Game\Levels\Level1.h"
#include <iostream>
#include <memory>


class LevelLoader
{


public:
	LevelLoader();
	~LevelLoader();

	std::unique_ptr<Level> loadLevel(int lvlNr);

private:

};

