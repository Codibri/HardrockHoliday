#pragma once

#include "root.h"
#include "Utility\TangentSpaceHelper.h"
#include "Utility\GameObjectLoader.h"
#include "GameObject.h"
#include <memory>

#define DEGREES_TO_RADIANS(angle) ((angle) / 180.0 * M_PI)

class MapPart
{
public:
	MapPart(int nr);
	~MapPart();

	static const int MAP_PART_SIZE;

	virtual void tick(float deltaMillis, float time);
	Vektoria::CPlacement* getPlacement();

	bool getIsLastMapPartOfLevel();
	void setIsLastMapPartOfLevel();
private:

	bool mIsLastMapPartOfLevel;
	int mPartNr;
	std::vector<std::unique_ptr<GameObject>> mGameObjects;


protected:
	Vektoria::CPlacement mRootPlacement;
	Vektoria::CTriangleList* mGroundMesh;
	Vektoria::CMaterial mGroundMaterial;

	void loadMesh(std::string objFilePath);
	void addGameObject(GameObject* obj);

	void addGameObjectsFromFile(std::string fileName);

	static Vektoria::CHVector scaleFromBlender(float x, float y, float z){
		Vektoria::CHVector result(x * 2.0f, z * 2.0f, y * 2.0f);
		return result;
	}

	static Vektoria::CHVector locationFromBlender(float x, float y, float z){
		return Vektoria::CHVector(x, z, -y);
	}
};

