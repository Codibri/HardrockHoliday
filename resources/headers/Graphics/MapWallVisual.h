#pragma once

#include "root.h"
#include "Graphics\Visual.h"

// Debug Klasse zum darstellen des Box-Colliders
class MapWallVisual : public Visual
{
public:
	MapWallVisual(Vektoria::CHVector boxColliderSize, Vektoria::CPlacement *p);
	~MapWallVisual();

private:

	Vektoria::CGeoCube mCubeGeo;
	Vektoria::CMaterial mCubeMaterial;

};