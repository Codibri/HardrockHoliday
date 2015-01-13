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

	// Boden Für Alle MapParts
	auto normalGround = new Ground(Vektoria::CHVector(2, 2.0, 42));
	normalGround->setName("NormalGround");
	normalGround->GetRigidBody()->GetCollider()->SetLayer(normalGround->getName());
	normalGround->getPlacement()->Translate(0, -1.0, -20);
	addGameObject(normalGround);
	// Fallenboden Für Alle MapParts
	auto pitGround = new Ground(Vektoria::CHVector(10, 2.0, 42));
	pitGround->setName("PitGround");
	pitGround->GetRigidBody()->GetCollider()->SetLayer(pitGround->getName());
	pitGround->getPlacement()->Translate(0, -1.5, -20);
	addGameObject(pitGround);

	PhysicsModule* physicsModule = ENGINE_PHYSICS;
	physicsModule->SetLayerProperty("NormalGround", "PitGround", false);
	physicsModule->SetLayerProperty("Player", "NormaleGround", true);
	physicsModule->SetLayerProperty("Player", "PitGround", false);
	

	// Mapbegrenzung
	auto wallLeft = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallLeft->getPlacement()->Translate(-1.1f, 0.25f, -4.0f);
	addGameObject(wallLeft);

	auto wallRight = new MapWall(Vektoria::CHVector(1.0f, 0.5f, 8.0f));
	wallRight->getPlacement()->Translate(1.1f, 0.25f, -4.0f);
	addGameObject(wallRight);

	// Fallen und Wände
	addGameObjectsFromFile("GameResources\\Levels\\level1\\part1\\gameobjects_part1.txt");

}


