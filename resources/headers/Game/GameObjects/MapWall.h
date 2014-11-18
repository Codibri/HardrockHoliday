#pragma once

#include "root.h"
#include "Game\PhysicalGameObject.h"

// Logik f�r Wand als Map Grenze

class MapWall : public PhysicalGameObject
{
public:
	// Collider Typ wird durch GameObjecttyp festegelegt -> MapWall = BoxCollider
	// Position und rotation wird durch GameObject::mRootPlacement bestimmt
	// Gr��e der Box in x, y und z Richtung wird im Ctor angegeben
	MapWall(Vektoria::CHVector boxColliderSize);


	~MapWall();

	// wird vom Level aufgerufen wenn zugeh�riger Mappart aktiv
	virtual void update(float deltaTime, float time) override;
};