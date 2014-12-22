
/*by Alexander Weiﬂ, 2014
 _____           _ _ _          _ 
/  __ \         | (_) |        (_)
| /  \/ ___   __| |_| |__  _ __ _ 
| |    / _ \ / _` | | '_ \| '__| |
| \__/\ (_) | (_| | | |_) | |  | |
 \____/\___/ \__,_|_|_.__/|_|  |_|*/

#ifndef GROUND_H
#define GROUND_H

#include "Game\PhysicalGameObject.h"

class Ground : public PhysicalGameObject
{
public:
	Ground(Vektoria::CHVector boxColliderSize);
	~Ground();

	void update(float deltaTime, float time) override;
};

#endif