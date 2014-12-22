#pragma once
#include "root.h"
#include "Game\PhysicalGameObject.h"
#include "Physics\BoxCollider.h"

// Logik für Lochfallen

class LochFalle : public PhysicalGameObject
{
public:
	// Collider Typ wird durch GameObjecttyp festegelegt -> LochFalle = BoxCollider
	// Position und rotation wird durch GameObject::mRootPlacement bestimmt
	// Größe der Box in x, y und z Richtung wird im Ctor angegeben
	LochFalle(Vektoria::CHVector boxColliderSize);


	~LochFalle();

	// wird vom Level aufgerufen wenn zugehöriger Mappart aktiv
	void update(float deltaTime, float time) override;

	// This will be called once after collision with another collider.
	void onCollision(phyX::RigidBodyOwner* other, float timeDelta) override;
};

