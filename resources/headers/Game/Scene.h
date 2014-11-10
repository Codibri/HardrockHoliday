#pragma once

#include "Game\Level.h"
#include "Game\MapPartManager.h"
#include "Resources\LevelLoader.h"
#include "Camera.h"
#include "root.h"
#include "Util.h"

#include <memory>

class Scene
{
public:
	Scene();
	~Scene();

	void init(CScene* scene, CRoot* root);

	void loadLevel(int lvlNr);

	void tick(float deltaMillis, float ftime);

	void initViewport(Vektoria::CViewport* viewport);

private:

	Vektoria::CScene* mVectoriaScene;
	Vektoria::CRoot* mRoot;
	
	Camera mCamera;

	std::unique_ptr<Level>	 mActiveLevel;
	MapPartManager mMapPartManager;
	LevelLoader mLevelLoader;
};

