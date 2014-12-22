#include "Game\GameObjects\Lochfalle.h"
#include "Graphics\LochfalleVisual.h"
#include "Game\GameObjects\Player.h"

LochFalle::LochFalle(Vektoria::CHVector boxColliderSize) : PhysicalGameObject(Vektoria::CPlacement(), "LochFalle", PhysicalProperties(new phyX::BoxCollider(this, boxColliderSize, 1, true, true), 1, false))
{
	_visual = new LochFalleVisual(boxColliderSize, &_position);
}


LochFalle::~LochFalle()
{}


void LochFalle::update(float deltaTime, float time)
{
	PhysicalGameObject::update(deltaTime, time);
}


void LochFalle::onCollision(phyX::RigidBodyOwner* other, float timeDelta)
{}

