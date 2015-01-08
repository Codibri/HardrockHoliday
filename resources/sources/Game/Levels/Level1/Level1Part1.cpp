#include "Game\Levels\Level1Part1.h"
#include "Engine\EngineMakros.h"
#include "Engine\Engine.h"



Level1Part1::Level1Part1() : MapPart(1)
{
	loadMesh("GameResources\\Levels\\level1\\part1\\level1_part1.obj");

	loadMaterial();

	initGameObjects();

}


Level1Part1::~Level1Part1()
{
}

void Level1Part1::loadMaterial(){
	mGroundMaterial.MakeTextureImage("GameResources\\Levels\\level1\\part1\\part_COLOR.png");
	mGroundMaterial.MakeTextureSpecular("GameResources\\Levels\\level1\\part1\\part_SPEC.png");
	mGroundMaterial.MakeTextureBump("GameResources\\Levels\\level1\\part1\\part_NRM.png");
	mGroundMesh->SetMaterial(&mGroundMaterial);
}


void Level1Part1::initGameObjects(){

	// Boden
	auto normalGround = new Ground(Vektoria::CHVector(2, 2.0, 42));
	normalGround->setName("NormalGround");
	normalGround->GetRigidBody()->GetCollider()->SetLayer(normalGround->getName());
	normalGround->getPlacement()->Translate(0, -1.0, -20);
	addGameObject(normalGround);

	auto pitGround = new Ground(Vektoria::CHVector(2, 2.0, 25));
	pitGround->setName("PitGround");
	pitGround->GetRigidBody()->GetCollider()->SetLayer(pitGround->getName());
	pitGround->getPlacement()->Translate(0, -1.5, 0);
	addGameObject(pitGround);

	PhysicsModule* physicsModule = ENGINE_PHYSICS;
	physicsModule->SetLayerProperty("NormalGround", "PitGround", false);
	physicsModule->SetLayerProperty("Player", "NormaleGround", true);
	physicsModule->SetLayerProperty("Player", "PitGround", false);

	std::cout << "Lade Gameobjects part1" << std::endl;

	addGameObjectsFromFile("GameResources\\Levels\\level1\\part1\\gameobjects_part1.txt");

	/*
	// Löcher
	auto falle1 = new LochFalle(scaleFromBlender(0.201, 0.408, 0.378));
	falle1->getPlacement()->Translate(locationFromBlender(-0.3211, 1.75064, -0.17448));
	addGameObject(falle1);

	auto falle2 = new LochFalle(scaleFromBlender(0.195, 0.396, 0.367));
	falle2->getPlacement()->Translate(locationFromBlender(0.35178, 3.89644, -0.17448));
	addGameObject(falle2);

	auto falle3 = new LochFalle(scaleFromBlender(0.195, 0.396, 0.367));
	falle3->getPlacement()->Translate(locationFromBlender(0.29663, 6.96836, -0.17448));
	addGameObject(falle3);
	
	

	auto wall1 = new MapWall(scaleFromBlender(0.287, 0.584, 0.541));
	wall1->getPlacement()->RotateY(DEGREES_TO_RADIANS(-44.6));
	wall1->getPlacement()->TranslateDelta(locationFromBlender(-0.52594, 5.10817, 0.04398));
	addGameObject(wall1);

	*/

}


