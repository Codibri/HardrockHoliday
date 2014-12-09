#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

/****************************************

Wrapper class to handle the CPhysics-singleton in this project

To insert a collider inherit from RigidbodyOwner and select the collider and attributes you want.
If an instance of the object gets created it's automatically inserted to the CPhysiX until the
instance gets destroyed.
For set the trigger events call GetRigidBody() to the get the Rigidbody of the object and call
collider to get the collider of the rigidbody. There you can set the Trigger events.

@(#)Author: Alexander Thoma

▄████▄  ▒█████  ▓█████▄ ▓█████ ▒██   ██▒
▒██▀ ▀█ ▒██▒  ██▒▒██▀ ██▌▓█   ▀ ▒▒ █ █ ▒░
▒▓█    ▄▒██░  ██▒░██   █▌▒███   ░░  █   ░
▒▓▓▄ ▄██▒██   ██░░▓█▄   ▌▒▓█  ▄  ░ █ █ ▒
▒ ▓███▀ ░ ████▓▒░░▒████▓ ░▒████▒▒██▒ ▒██▒
░ ░▒ ▒  ░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░▒▒ ░ ░▓ ░
░  ▒    ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░░░   ░▒ ░
░       ░ ░ ░ ▒   ░ ░  ░    ░    ░    ░
░ ░         ░ ░     ░       ░  ░ ░    ░
░
****************************************/

#include "Physics\CPhysiX.h"
#include "Engine\EngineModule.h"

class PhysicsModule : public EngineModule
{
public:
	PhysicsModule();
	~PhysicsModule();

	//all the physic stuff gets done here (e.g. collision detection, impulse and force influence)
	void postUpdate(float deltaTime, float time) override;
	
	//on EndTick the collision gets calculated
	void PostRenderUpdate(float fTimeDelta);

	//refreshes the octree of the physic and reinserts all existing colliders(use this e.g. at level start)
	void RefreshPhysiX();

	//adds a phyiclayer and returns the layernumber of the layer, if this layer already exists it returns its layernumber
	int AddPhysiXLayer(std::string layer);

	//identifies layer by layernumber and returns its name
	std::string TranslateLayer(unsigned int LayerNumber);

	//returns layernumber of the layer, if the layer doesn't exist it returns -1
	int GetLayerNumber(std::string layerName);

	//sets collision between the two layers, if both can collide with eachother value is true, if not it's false
	bool SetLayerProperty(std::string layer, std::string layer1, bool collision);

	//prints the layermatrix where you can see the collision conditions
	void PrintLayerMatrix();

private:

	phyX::CPhysiX* m_physics;
};

#endif