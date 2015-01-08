#include "Utility\GameObjectLoader.h"

std::vector<GameObject*> GameObjectLoader::LoadGameObjects(std::string  gameObjectsFile){

	std::vector<GameObject*> objectVector;

	std::ifstream inputStream{ gameObjectsFile };
	
	if (inputStream.is_open()){

		ObjectType type = UNKNOWN;
		Vektoria::CHVector translation;
		Vektoria::CHVector rotation;
		Vektoria::CHVector scale;

		std::string line;
		while (std::getline(inputStream, line)){
			
			if (line[0] == '+'){
				if (type != UNKNOWN){
					GameObject* go = createGameObject(translation, rotation, scale, type);
					if (go != nullptr)
						objectVector.push_back(go);
				}		
				type = getGameObjectType(line);
			}
			else if (line[0] == 't'){
				sscanf(line.c_str(), "t : %f; %f; %f", &translation.x, &translation.y, &translation.z);	
			} 
			else if (line[0] == 'r'){
				sscanf(line.c_str(), "r : %f; %f; %f", &rotation.x, &rotation.y, &rotation.z);
			}
			else if (line[0] == 's'){
				sscanf(line.c_str(), "s : %f; %f; %f", &scale.x, &scale.y, &scale.z);
			}

		}
		
	}

	inputStream.close();
	return objectVector;
}

GameObjectLoader::ObjectType GameObjectLoader::getGameObjectType(std::string& line)
{
	std::string  wallTypes[] = { "Wall", "wall", "Wand", "wand" };
	std::string  trapTypes[] = { "Falle", "falle", "trap", "Trap", "loch", "Loch" };
	bool isWall = false;
	bool isTrap = false;
	
	for each (std::string value in wallTypes)
	{
		if (line.find(value) != std::string::npos) {
			return WALL;
		}
	}
	for each (std::string value in trapTypes)
	{
		if (line.find(value) != std::string::npos) {
			return TRAP;
		}
	}
}

GameObject* GameObjectLoader::createGameObject(Vektoria::CHVector translation,
	Vektoria::CHVector rotation, Vektoria::CHVector scale, ObjectType type)
{
	GameObject* resultPtr;
	switch (type)
	{
	case GameObjectLoader::WALL:
		resultPtr = new MapWall(scaleFromBlender(scale));
		break;
	case GameObjectLoader::TRAP:
		resultPtr = new LochFalle(scaleFromBlender(scale));
		break;
	default:
		return nullptr;
	}
	resultPtr->getPlacement()->RotateY(rotation.z);
	resultPtr->getPlacement()->TranslateDelta(locationFromBlender(translation));
    return resultPtr;	
}




Vektoria::CHVector  GameObjectLoader::scaleFromBlender(Vektoria::CHVector scale){
	Vektoria::CHVector result(scale.x * 2.0, scale.z * 2.0, scale.y * 2.0);
	return result;
}

Vektoria::CHVector  GameObjectLoader::locationFromBlender(Vektoria::CHVector location){
	return Vektoria::CHVector(location.x, location.z, -location.y);
}



