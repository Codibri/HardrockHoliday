#pragma once
#include "TriangleStrip.h"
#include "Face.h"

namespace Vektoria
{

class CRenderApi;

#define S_GEOELLIPSOIDMAPPING_CYLINDRICAL			0
#define S_GEOELLIPSOIDMAPPING_QUADROCYLINDRICAL		1
#define S_GEOELLIPSOIDMAPPING_BICYLINDRICAL			2
#define S_GEOELLIPSOIDMAPPING_QUADROBICYLINDRICAL	3
#define S_GEOELLIPSOIDMAPPING_ORTHOGRAPHIC			4
#define S_GEOELLIPSOIDMAPPING_BIORTHOGRAPHIC		5
#define S_GEOELLIPSOIDMAPPINGS						6

class CGeoEllipsoid :
	public CTriangleStrip
{
public:
	CGeoEllipsoid(void);
	~CGeoEllipsoid(void);
    virtual const char* ClassName(void) { return "CGeoEllipsoid"; }

	int GetVertexIndex(int iLo, int iLa);

	void Init(CHVector vSize, CMaterial * pmaterial, int iLongitude = 24, int iLattitude = 12, int iLattitudeMin=0, int iLattitudeMax = INT_MAX, int eMapping = S_GEOELLIPSOIDMAPPING_CYLINDRICAL); // Initialisiert eine ellisoide Geometrie 

	CHVector m_vSize;
	CVertex * m_avertex;

	int m_iLongitude;
	int m_iLattitude;
};

}