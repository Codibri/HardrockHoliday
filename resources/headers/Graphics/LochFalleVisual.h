#pragma once

#include "root.h"
#include "Graphics\Visual.h"

// Debug Klasse zum darstellen der Box-Colliders
class LochFalleVisual : public Visual
{
public:
	LochFalleVisual(Vektoria::CHVector boxColliderSize, Vektoria::CPlacement *p);
	~LochFalleVisual();

private:

	Vektoria::CGeoCube mCubeGeo;
	Vektoria::CMaterial mCubeMaterial;
	
};

