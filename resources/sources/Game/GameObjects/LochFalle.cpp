#include "Game\GameObjects\Lochfalle.h"
#include "Graphics\LochfalleVisual.h"


LochFalle::LochFalle(Vektoria::CHVector boxColliderSize) : PhysicalGameObject()
{
	_visual = new LochFalleVisual(boxColliderSize, &_position);
}


LochFalle::~LochFalle()
{
}

void LochFalle::update(float deltaTime, float time){

}
