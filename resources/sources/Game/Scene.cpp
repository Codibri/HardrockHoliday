#include "Game\Scene.h"




Scene::Scene()
{
	
}

Scene::~Scene()
{
}

void Scene::init(CScene* scene, CRoot* root){
	
	mVectoriaScene = scene;
	mRoot = root;
	mMapPartManager.setScene(mVectoriaScene);

}


void Scene::initViewport(Vektoria::CFrame *frame){
	
	mCamera.initViewPort(1.7f, frame);
	
}


void Scene::loadLevel(int lvlNr){

	mActiveLevel = mLevelLoader.loadLevel(lvlNr);
	mActiveLevel->initialize(mVectoriaScene);

	mCamera.setPlayerPlacement(mActiveLevel->getPlayer());

	mVectoriaScene->AddPlacement(mActiveLevel->getPlayer()->getPlacement());
	
	mMapPartManager.initWithActiveLevel(mActiveLevel.get(), mRoot);

	// Könnte dann von der Statemachine über Scene->getTimer() 
	// aufgerufen werden
	//mTimer.Reset();
	//mTimer.Show();
	//mTimer.Start();
}


void Scene::tick(float deltaMillis, float ftime){
	
	// aktive map parts updaten
	mMapPartManager.update(deltaMillis, ftime);
	
	// aktive GameObjects ticken
	mMapPartManager.tickActiveObjects(deltaMillis, ftime);

	// rendern
	mRoot->Tick(deltaMillis);
	
}