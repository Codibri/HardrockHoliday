#pragma once
#include "Scenes.h"
#include "Hardwares.h"
#include "Geo.h"
#include "GeoQuad.h"
#include "GeoCube.h"
#include "GeoSkybox.h"
#include "GeoTube.h"
#include "GeoCone.h"
#include "GeoSweep.h"
#include "GeoSlice.h"
#include "GeoCylinder.h"
#include "GeoTetraeder.h"
#include "GeoEllipsoid.h"
#include "GeoIkosaeder.h"
#include "GeoWall.h"
#include "GeoWindow.h"
#include "GeoWing.h"
#include "GeoSphere.h"
#include "GeoDome.h"
#include "RenderApi.h"
#include "Materials.h"
#include "Device.h"
#include "FileX3D.h"
#include "File3DS.h" // TODO funktioniert nicht => Matthias fragen
#include "FileBlender.h"
#include "FileWavefront.h"
#include "Quaternion.h"
#include "Images.h"
#include "Wribel.h"
#include "Splash.h"

#include "DistributedGlobal.h"



//---------------------------------------------------
// CRoot: Klasse f�r die Wurzel des Szenegrafen-Baumes
//
// Autor: Prof. Dr. Tobias Breiner
// Letzte �nderung: 2011-08-07
//---------------------------------------------------

namespace Vektoria
{

class CRenderApi;

class CRoot
{
private:
	// singleton: (geht nicht wegen Disfactory und DisfacRoot)
// 	static CRoot* m_pRootInstance;
// 	CRoot();
// 	CRoot operator=(CRoot root);
// 	void Copy(CRoot root);
#ifdef NETWORKMASTER
	unsigned int m_idId;
	int m_icId;
#endif
public:
	#ifdef NETWORKMASTER
	unsigned int GetidId();
#endif
		
	CRoot();
	~CRoot();
	CRoot operator=(CRoot root);
	void Copy(CRoot root);
	
	void Init(CSplash * psplash); // Initialisiert die Wurzel, muss Splashscreen �bergeben bekommen, welches schon aufgerufen werden
//		void Init(); // Initialisiert die Wurzel
	void Tick(float & fTimeDelta); // Diese Methode muss jedes Frame aufgerufen werden
	void Fini(); // Finalisiert die Wurzel

	void AddScene(CScene * pscene);	// H�ngt eine Szene an die Wurzel an
	bool SubScene(CScene * pscene);	// H�ngt eine Szene von der Wurzel ab, gibt false aus, wenn die angegebene Szene nicht ein Kind der Wurzel ist oder �berhaupt nicht existiert, bei Erfolg wird true ausgegeben 

	void AddFrameHere(CFrame * pframe);  // H�ngt dem aktuellen Computer an die Wurzel an, und an diesen wiederum den angegebenen Frame

	void AddMaterial(CMaterial * pmaterial); //F�gt ein weiteres Material in die Materialliste der Wurzel hinzu
	bool SubMaterial(CMaterial * pmaterial); //L�scht ein Material aus der Materialliste der Wurzel, gibt true aus, wenn es funktioniert hat 
	bool SubAllMaterials();	// L�scht alle Materialien  aus der Materialliste der Wurzel (au�er dem Defaultmaterial), bei Erfolg wird true ausgegeben. Diese Methode ist sinnvoll vor dem Laden eines neuen Levels mit komplett neuen Texturen 

//	void AddImage(CImage * pimage); //F�gt ein weiteres Bilde in die Bilderliste der Wurzel hinzu
//	bool SubImage(CImage * pimage); //L�scht ein Bild aus der Bilderliste der Wurzel, gibt true aus, wenn es funktioniert hat 
//	bool SubAllImages();	// L�scht alle Bilder  aus der Bilderliste der Wurzel


	void OpenSesamy(char * ac);
	bool m_bSesamy;
	int m_iArchitecture;
	float m_fTime;

//	CImages m_images; // Bilderliste, damit jede Textur nur noch einmal geladen wird
	CMaterials m_materials;
	CScenes m_scenes;
	CHardwares m_hardwares;		// fremde Computer im LAN
	CHardware m_hardwareHere;	// dieser Computer

	CHMat m_m;
	CMaterial m_zmDefault; // Defaultmaterial "Wei�"
	bool m_bFirstTick; // true, wenn erster Tick, ansonsten false
private:
	CSplash * m_psplash;
};


}