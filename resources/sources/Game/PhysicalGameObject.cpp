
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Game\PhysicalGameObject.h"


PhysicalGameObject::PhysicalGameObject(Vektoria::CPlacement position ) : GameObject(position)
{}


PhysicalGameObject::~PhysicalGameObject()
{}


void PhysicalGameObject::onCollision(Collider* collidingObject)
{}


void PhysicalGameObject::duringCollision(Collider* collidingObject)
{}

