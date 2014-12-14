#include "Game\GameObjects\MapWall.h"
#include "Graphics\MapWallVisual.h"
#include "Game\GameObjects\Player.h"


MapWall::MapWall(Vektoria::CHVector boxColliderSize) : PhysicalGameObject(Vektoria::CPlacement(), "MapWall", new phyX::BoxCollider(this, boxColliderSize, 1 , true, false), 1000, false)
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


void MapWall::onCollision(phyX::RigidBodyOwner* other, float timeDelta)
{}