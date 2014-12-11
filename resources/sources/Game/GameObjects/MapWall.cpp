#include "Game\GameObjects\MapWall.h"
#include "Graphics\MapWallVisual.h"

MapWall::MapWall(Vektoria::CHVector boxColliderSize) : PhysicalGameObject(Vektoria::CPlacement(), new phyX::BoxCollider(this, boxColliderSize, 1, true, false), 1, false)
{
	_visual = new MapWallVisual(boxColliderSize, &_position);
}


MapWall::~MapWall()
{
}

void MapWall::update(float deltaTime, float time)
{
	PhysicalGameObject::update(deltaTime, time);
}