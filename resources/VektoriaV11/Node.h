////////////////////////////////////////////////////
/// @file: Node.h
/// @author: Florian Schnell, Matthias Sommer
/// @last change: 2013-06-15
/// ** Copyright (c) Vektoria **
////////////////////////////////////////////////////
#pragma once

#include "Intersectable.h"
#include "AABB.h"
#include "Vertex.h"
#include "HMat.h"
#include "Nodes.h"
#include "HVector.h"

namespace Vektoria
{

class CGeoCube;
class CRoot;
class CPlacement;

#define TEXT_BUFFER 256

#define S_KINDSUB_UNDEFINED 0
#define S_KINDSUB_GEOWALL 1
#define S_KINDSUB_GEOWINDOW 2
#define S_KINDSUB_GEOWING 3
#define S_KINDSUB_GEOCYLINDER 4
#define S_KINDSUB_GEOSPHERE 5
#define S_KINDSUB_GEODOME 6
#define S_KINDSUB_GEOTUBE 7
#define S_KINDSUB_GEOSLICE 8
#define S_KINDSUB_GEOTETRAEDER 9
#define S_KINDSUB_GEOIKOSAEDER 10
#define S_KINDSUB_GEOCUBE 11
#define S_KINDSUB_GEOCONE 12
#define S_KINDSUB_GEOELLIPSOID 13
#define S_KINDSUB_GEOSKYBOX 30

#define S_THING_UNDEFINED 0
#define S_GEOTRIANGLELIST 14
#define S_GEOTRIANGLESTRIP 15
#define S_CAMERA 20
#define S_POINT_LIGHT 21
#define S_PARALLEL_LIGHT 22
#define S_SPOT_LIGHT 23
#define S_SOUND 24
#define S_EMITTER 25
#define S_DRAWABLE 26
#define S_PLACEMENT 30
#define S_WRIBEL 31

static unsigned int g_id = 0; // Fortlaufende Zählung der Knotenobjekte, mir fällt leider keine besser Möglichkeit ein, als eine globale Variable

class CNode : CIntersectable
{
	friend class CNodes;
public: 
	void Tick(CHMat &a_mGlobal, float &a_fTimeDelta);

public:
	CNode(void);
	~CNode(void);
	virtual const char* ClassName(void) { return "CNode"; } //Gibt den Namen der Klasse zurück

	void Copy(CNode & pnode);
	// Standard Methods
	void Init(void);
	void Draw(float a_fDistanceToCameraSquare, CHMat &a_mGlobal); //Zeichnet die AABB des Knotenobjektes, wenn m_bVisualHelpersEnabled auf true gestellt wurde
	void Fini(void);


	// Bounding Boxes
    CHMat   m_mGlobal;
    bool    m_bAABBOn; // Boolsches Flag, um die AABB des Knotens aus (false) bzw. an (true) zu schalten
    bool    m_bVisualHelpersEnabled; // Boolsches Flag, um die Visualisierung der AABB aus (false) bzw. an (true) zu schalten
    CAABB   m_aabbBounds; // Axis Aligned Bounding Box

	bool    m_bAABBUpdateNeeded; //TODO:

	virtual void UpdateAABB(void) = 0; // Aktualisiert die AABB für diesen Node
	void UpdateAABBs(void); // Aktualisiert die AABB für diesen Node und seine gesamte Unterhierarchie
     CAABB GetBoundingBox(void);

	void AddVertexToAABB(CVertex &a_pVertex); // Encompass Vertex
    void AddVectorToAABB(CHVector &a_pVector); // Encompass Vector
	void AddAABBToAABB(CAABB &a_pAABB); // Encompass AAABB

	void EnableAABB(void); // Schaltet AABBs für diesen Node an
	void DisableAABB(void); // Schaltet AABBs für diesen Node aus
    void EnableAABBs(void); // Schaltet AABBs für diesen Node und seine gesamte Unterhierarchie an
    void DisableAABBs(void); // Schaltet AABBs für diesen Node und seine gesamte Unterhierarchie aus

    void EnbaleVisualHelper(void); // Schaltet die Visualisierung der AABB nur für diesen Node an
    void DisableVisualHelper(void); // Schaltet die Visualisierung der AABB nur für diesen Node aus
    void EnableVisualHelpers(void); // Schaltet die Visualisierung der AABBs für diesen Node und seine gesamte Unterhierarchie an
    void DisableVisualHelpers(void); // Schaltet die Visualisierung der AABBs für diesen Node und seine gesamte Unterhierarchie aus
	

    // Picking (Ray/AABB Intersection: Schnitt mit Bounding Box)
	bool Intersects(CHVector &a_vOrigin, CHVector &a_vRayDirection, CIntersectable** r_pFound, float* r_fDistance); // Führt eine Ray/AABB Intersection für diesen Node und seine gesamte Unterhierarchy durch und gibt bei erfolgreicher Intersection den Knoten der zuerst gefunden wurde über r_pFound zurück.
    //bool Intersects(CHVector &a_vOrigin, CHVector &a_vRayDirection, CNode** r_pFound); // Führt eine Ray/AABB Intersection für diesen Node und seine gesamte Unterhierarchy durch und gibt bei erfolgreicher Intersection den Knoten der zuerst gefunden wurde über r_pFound zurück.
	bool Intersects(CHVector &a_vOrigin, CHVector &a_vRayDirection, float* r_fDistance); // Führt eine Ray/AABB Intersection nur für diesen Knoten durch


    // Sonstiges
    unsigned int GetID(void); // Gibt die eindeutige ID des Knotens zurück
    
    void SetName(const char* a_acName); // Setzt einen benutzerdefinierten Namen für diesen Knoten (z.B. "RootPlacement") -> Methode für Vektoria Editor
    const char* GetName(void); // Gibt den benutzerdefinierten Namen des Knotens zurück
    
    CHVector GetTranslation(void); // Gibt den translativen Anteil der globalen Matrix zurück

    bool IsPlacement(void); // Gibt true zurück, wenn es sich bei diesem Knoten um ein Placement handelt, ansonsten false
    bool IsTriangleList(void); // Gibt true zurück, wenn es sich bei diesem Knoten um eine TriangleList handelt, ansonsten false
    bool IsTriangleStrip(void); // Gibt true zurück, wenn es sich bei diesem Knoten um ein TriangleStrip handelt, ansonsten false
    bool IsGeo(void); //Gibt true zurück, wenn es sich bei diesem knoten um eine Geo handelt, ansonsten false
	bool IsSpotLight(void);

    
	// Tree Management
	CRoot*  m_proot;
	CNodes  m_parents;
	CNodes  m_children;
    int     m_eKind;
    int     m_eKindSub;
	
	void SetRoot(CRoot* a_proot);

	void AddParent(CNode* pnodeParent);
	void SubParent(CNode* pnodeParent);

	void AddChild(CNode* a_pnode);
	void SubChild(CNode* a_pnode);

    int GetCount(void); // Gibt die Anzahl an Kindern zurück

private:
    bool TypeOf(int a_iKind); // Gibt true zurück, wenn es sich bei diesem Knoten um einen Knoten vom Typ a_iKind handelt, ansonsten false

    unsigned int m_id;

    CGeoCube* m_pBoundingCube;

    char* m_acName;
};

}