#pragma once

#include "root.h"
#include "Game\PhysicalGameObject.h"
#include "Physics\BoxCollider.h"

// Logik für Wand als Map Grenze

class MapWall : public PhysicalGameObject
{
public:
	// Collider Typ wird durch GameObjecttyp festegelegt -> MapWall = BoxCollider
	// Position und rotation wird durch GameObject::mRootPlacement bestimmt
	// Größe der Box in x, y und z Richtung wird im Ctor angegeben
	MapWall(Vektoria::CHVector boxColliderSize);


	~MapWall();

	// wird vom Level aufgerufen wenn zugehöriger Mappart aktiv
	void update(float deltaTime, float time) override;

	// This will be called once after collision with another collider.
	void onCollision(phyX::RigidBodyOwner* other, float timeDelta) override;
};
