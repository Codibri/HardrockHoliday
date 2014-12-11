
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Game\PhysicalGameObject.h"


PhysicalGameObject::PhysicalGameObject(Vektoria::CPlacement position, phyX::Collider* collider, float mass, bool hasGravity) : GameObject(position), phyX::RigidBodyOwner(&_position, collider, mass, hasGravity)
{}


PhysicalGameObject::~PhysicalGameObject()
{}


void PhysicalGameObject::onCollision(phyX::Collider* collidingObject)
{}


void PhysicalGameObject::duringCollision(phyX::Collider* collidingObject)
{}

