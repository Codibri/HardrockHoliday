#include "Resources\LevelLoader.h"


LevelLoader::LevelLoader()
{
}


LevelLoader::~LevelLoader()
{
}


std::unique_ptr<Level> LevelLoader::loadLevel(int lvlNr){
	switch (lvlNr){
	case 1:
		return std::unique_ptr<Level>(new Level1());
		break;
	default:
		std::cerr << "LevelLoader::loadLevel(): Invalid level nr.";
		break;
	}

	return nullptr;
}