#include "Game\GameObjects\MapWall.h"
#include "Graphics\MapWallVisual.h"

MapWall::MapWall(Vektoria::CHVector boxColliderSize) : PhysicalGameObject()
{
	_visual = new MapWallVisual(boxColliderSize, &_position);
}


MapWall::~MapWall()
{
}

void MapWall::update(float deltaTime, float time){

}