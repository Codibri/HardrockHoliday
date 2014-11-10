#pragma once
#include "Node.h"
#include "HMat.h"

#include "DistributedGlobal.h"


//------------------------------------------------------------------
// CCamera: Klasse für eine Kamera
//
// Autor: Prof. Dr. Tobias Breiner & Florian Schnell 
// Letzte Änderung: 2013-06-06
//-------------------------------------------------------------------

namespace Vektoria
{

class CPlacement;

class CCamera : public CNode
{
	friend class CCameras;
private:
	void Tick(CHMat & m, float & fTimeDelta); // Wird automatisch jedes Frame aufgerufen

public:
	CCamera();
	~CCamera();
	CCamera operator=(CCamera camera); // Zuweisungsoperator
	void Copy(CCamera camera); // Kopiert eine Kamera

	void Init(float faFov=2.0F, float fNearClipping=0.1F, float fFarClipping=1000.0F);  // Initalisiert eine Kamera
	void Fini(); // Finalisiert die Kamera

	virtual void UpdateAABB();

	void CalcMat(); // Rechnet die homogene Projektionsmatrix der Kamera aus, wird automatisch aufgerufen, wenn notwendig

	void SetFov(float faMat); // Setzt den Kameraöffnungswinkel
	void SetNearClipping(float fNearClipping); // Setzt den Kameraabstand der vorderen Schnittebene des Sichtpyramidenstumpfes
	void SetFarClipping(float fFarClipping); // Setzt den Kameraabstand der hinteren Schnittebene des Sichtpyramidenstumpfes
	void SetOrthoOn(); // Schaltet Kamera in Othogonalprojektionsmodus
	void SetOrthoOff(); // Schaltet Kamera wieder in normalen fovealen Projektionsmodus (default)


	float GetFov(); // Gibt den Kameraöffnungswinkel aus
	float GetNearClipping(); // Gibt den Kameraabstand der vorderen Schnittebene des Sichtpyramidenstumpfes aus
	float GetFarClipping(); // Gibt den Kameraabstand der hinteren Schnittebene des Sichtpyramidenstumpfes aus

	CHMat m_matProjection;  // Projektionsmatrix der Kamera
	float m_faFov;			// Kameraöffnungswinkel
	float m_fNearClipping;  // Abstand zwischen der Kamera und der vorderen Schnittebene des Sichtpyramidenstumpfes
	float m_fFarClipping;   // Abstand zwischen der Kamera und der hinteren Schnittebene des Sichtpyramidenstumpfes
	float m_fViewportAspectRatio; // Verzerrungsverhältnis zwischen Breite und Höhe
	bool m_bOrtho;

#ifdef NETWORKMASTER
	unsigned int GetidId();
private:
	unsigned int m_idId;
	int m_icId;
#endif
};

}
