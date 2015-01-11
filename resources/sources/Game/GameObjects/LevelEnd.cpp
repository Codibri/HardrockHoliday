#include "Game\GameObjects\LevelEnd.h"


LevelEnd::LevelEnd(Vektoria::CHVector boxColliderSize)
	: PhysicalGameObject(Vektoria::CPlacement(), "LevelEnd",
	PhysicalProperties(new phyX::BoxCollider(this, boxColliderSize, 1, true, true), 1, false))
{
	_visual = new LevelEndVisual(boxColliderSize, getPlacement());
}

LevelEnd::~LevelEnd()
{
}