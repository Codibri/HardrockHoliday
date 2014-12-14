
/*by Alexander Weiß, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Game\PhysicalGameObject.h"


PhysicalGameObject::PhysicalGameObject(Vektoria::CPlacement position, const std::string& name, phyX::Collider* collider, float mass, bool hasGravity) :
	GameObject(position, name), phyX::RigidBodyOwner(&_position, collider, mass, hasGravity)
{
	this->GetRigidBody()->GetCollider()->OnCollisionEnter += phyX_utilties::Member2FuncPtr(&PhysicalGameObject::onCollision, this);
}


PhysicalGameObject::~PhysicalGameObject()
{}


void PhysicalGameObject::onCollision(phyX::RigidBodyOwner* other, float timeDelta)
{}


void PhysicalGameObject::duringCollision(phyX::RigidBodyOwner* other, float timeDelta)
{}

