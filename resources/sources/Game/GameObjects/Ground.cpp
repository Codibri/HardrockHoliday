
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#include "Game\GameObjects\Ground.h"
#include "Physics\BoxCollider.h"


Ground::Ground(Vektoria::CHVector boxColliderSize) : PhysicalGameObject(Vektoria::CPlacement(), "Ground", new phyX::BoxCollider(this, boxColliderSize, 1, true, false), 1000, false)
{}


Ground::~Ground()
{}


void Ground::update(float timeDelta, float time)
{
	PhysicalGameObject::update(timeDelta, time);
}