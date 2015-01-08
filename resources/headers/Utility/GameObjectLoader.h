#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <regex>
#include <string>
#include <sstream>
#include <iostream>

#include <Game\GameObject.h>

#include "Game\GameObjects\LochFalle.h"
#include "Game\GameObjects\MapWall.h"


class GameObjectLoader {

	enum ObjectType {
		WALL,
		TRAP,
		UNKNOWN
	};

public:
	
	std::vector<GameObject*> LoadGameObjects(std::string  gameObjectsFile);

private:

	ObjectType getGameObjectType(std::string& line);

	GameObject* createGameObject(Vektoria::CHVector translation,
		Vektoria::CHVector rotation, Vektoria::CHVector scale, ObjectType type);

	Vektoria::CHVector scaleFromBlender(Vektoria::CHVector scale);
	Vektoria::CHVector locationFromBlender(Vektoria::CHVector location);
	
};