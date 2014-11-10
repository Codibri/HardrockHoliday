 #pragma once
#include "Vertexs.h"
#include "Material.h"
#include "Node.h"
#include "RenderApi.h"
#include "HVector.h"

//------------------------
// CGeo: Klasse für Geometrien
//
// Autor: Prof. Dr. Tobias Breiner, Florian Schnell

namespace Vektoria
{

class CLight;
class CGeoCube;
class CGeos;

enum EMagnetKind
{
	eMagnetKind_Center,
	eMagnetKind_SurfaceNormal,
	eMagnetKind_X,
	eMagnetKind_Y,
	eMagnetKind_Z
};

class CGeo : public CNode
{
	friend class CGeos;
	friend class CTriangleList;
	friend class CTriangleStrip;
private:
	void Tick(CHMat & m, float & fTimeDelta); // wird automatisch von dem übergeordneten Placement aufgerufen
public:
	CGeo();
	~CGeo();

	void Init(); // Initialisiert eine leere Geometrie
	void Fini();

	void AddVertex(CVertex *vertex); // Fügt der Geometrie ein Vertex hinzu
	bool SubVertex(CVertex *vertex); // Hängt betreffendes Vertex ab, gibt true aus, wenn es funktioniert hat 

	virtual void Draw(float fDistanceToCameraSquare, CHMat & mGlobal);
	virtual void UpdateAABB();

	void SwitchOn(); // Schaltet Geometrie an
	void SwitchOff(); // Schaltet Geometrie aus

	void MapPlanarX(); // Planares UV-Mapping entlang der X-Achse
	void MapPlanarY();  // Planares UV-Mapping entlang der Y-Achse
	void MapPlanarZ(); // Planares UV-Mapping entlang der Z-Achse
	void MapCubic(); // Vereinfachtes kubisches UV-Mapping
	void MapCylindricalY(); // Zylindrisches UV-Mapping um die Y-Achse
	void MapBicylindricalY(); // Bizylindrisches UV-Mapping um die Y-Achse


	void TwistX(float faStrength); // Twisting um die X-Achse
	void TwistY(float faStrength); // Twisting um die Y-Achse
	void TwistZ(float faStrength); // Twisting um die Z-Achse

	void BendX(float fRadius, float faSection); // Bending um die X-Achse
	void BendY(float fRadius, float faSection); // Bending um die Y-Achse
	void BendZ(float fRadius, float faSection); // Bending um die Z-Achse

	void TaperX(float fStrength, bool bInfluenceX=false, bool bInfluenceY=true, bool bInfluenceZ = true); // Tapering in Richtung der X-Achse
	void TaperY(float fStrength, bool bInfluenceX=true, bool bInfluenceY=false, bool bInfluenceZ = true); // Tapering in Richtung der Y-Achse
	void TaperZ(float fStrength, bool bInfluenceX=true, bool bInfluenceY=true, bool bInfluenceZ = false); // Tapering in Richtung der Z-Achse

	void WaveX(float fAmplitude, float fWavelength, float faPhase = 0.0F, bool bInfluenceX=true, bool bInfluenceY=false, bool bInfluenceZ = true); // Wellenform in Richtung der X-Achse
	void WaveY(float fAmplitude, float fWavelength, float faPhase = 0.0F, bool bInfluenceX=true, bool bInfluenceY=false, bool bInfluenceZ = true); // Wellenform in Richtung der Y-Achse
	void WaveZ(float fAmplitude, float fWavelength, float faPhase = 0.0F, bool bInfluenceX=true, bool bInfluenceY=false, bool bInfluenceZ = true); // Wellenform in Richtung der Z-Achse

	void RippleY(float fAmplitude, int iHarmonics, float faPhase = 0.0F, bool bInfluenceX=true, bool bInfluenceY=false, bool bInfluenceZ = true); // Wellenriffeln um die Y-Achse
	void RippleYHard(float fAmplitude, int iHarmonics, float faPhase = 0.0F, bool bInfluenceX=true, bool bInfluenceY=false, bool bInfluenceZ = true); // Wellenriffeln um die Y-Achse

	void Transform(CHMat & m); // Transformiert alle Punkte der Geometrie mit der Transformationsmatrix m
	void Unite(CGeo * pzg, CHMat & m, bool bKill = false); // Vereinigt die Vorliegende Geometrie und die Geometrie pzg zu einer Einzigen, wenn bKill gleich true ist, wird pzg danach gelöscht, ansonsten kannn man mit ihr ganz normal weiterarbeiten.
	bool IsTriangleList(); // Gibt true aus, wenn es sich bei der vorliegenden Geometrie um ein TriangleList handelt, ansonsten fal
	bool IsTriangleStrip(); // Gibt true aus , wenn es sich  bei der vorliegenden Geometrie um ein TriangleStrip handelt, ansonsten false

	void Magnet(CHVector v, float fRadius, float frStrength, bool bAttract, EMagnetKind eKind = eMagnetKind_Center); // Neuartige Modellierungsmethode (Magnet, der die Vertices im Radius fRadius anzieht bzw. abstößt)
	void ReduceRedundancy(bool bSmooth = true); // Reduziert redundante Vertices (Achtung!!! Braucht sehr lange, nur in Notfällen benutzen)

	void SetMaterial(CMaterial * pmaterial); // Setzt Material auf Geometiemesh, kann auch während der Laufzeit geschehen


	void FlipTangents();
	void FlipBitangents();

	CVertexs m_vertices;
	CMaterial * m_pmaterial;
	int m_idMaterial;

	CLight* m_aplightAffect[4];
	unsigned int m_iLightsAffectCount;

	RHND m_ahandle[4];


	bool HasTransparent(); // Gibt true aus, wenn irgenein transparentes Objekt an die Geometrie angehangen wurde
	bool m_bTransparent; // true, wenn Material der Geometrie irgendwo durchsichtige Anteile enthält
	bool m_bSwitch;  // boolsches Flag, um Anzeige der Geometrie aus(false) bzw. an(true) zu schalten

	void AddGeo(CGeo * pgeo); // Hängt eine Geometrie an eine andere Geometrie an
	bool SubGeo(CGeo * pgeo); // Hängt die Geometrie wieder von der aktuellen Geometrie ab, gibt true aus, wenns geklappt hat
	CGeos * m_pgeos;
#ifdef NETWORKMASTER
	unsigned int GetidId();

	unsigned int m_idId;
	int m_icId;
#endif

};

}