#pragma once

#include "Game\PhysicalGameObject.h"
#include "Graphics\LevelEndVisual.h"
#include "Physics\BoxCollider.h"
#include "Root.h"

class LevelEnd : public PhysicalGameObject {

public:
	LevelEnd(Vektoria::CHVector boxColliderSize);
	~LevelEnd();

};