#pragma once
#include "geoellipsoid.h"

#include "DistributedGlobal.h"

namespace Vektoria
{

class CGeoSphere : 
    public CGeoEllipsoid
{
public:
	CGeoSphere(void);
	~CGeoSphere(void);
    virtual const char* ClassName(void) { return "CGeoSphere"; }

	void Init(float fRadius, CMaterial * pmaterial, int iLongitude= 24, int iLattitude = 12, int eMapping = S_GEOELLIPSOIDMAPPING_CYLINDRICAL); // Erzeugt Kugel

};

}