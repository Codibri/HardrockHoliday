#pragma once

#include "root.h"
#include "Utility\TangentSpaceHelper.h"
#include "GameObject.h"
#include <memory>


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
};

