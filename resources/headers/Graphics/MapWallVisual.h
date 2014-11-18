#pragma once
#include "Game\GameObjects\MapWall.h"
#include "root.h"

// Debug Klasse zum darstellen des Box-Colliders
class MapWallVisual : public MapWall
{
public:
	MapWallVisual(Vektoria::CHVector boxColliderSize);
	~MapWallVisual();

private:

	Vektoria::CGeoCube mCubeGeo;
	Vektoria::CMaterial mCubeMaterial;

};