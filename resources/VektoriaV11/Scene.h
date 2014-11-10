#pragma once
#include "Placements.h"
#include "RenderApi.h"
#include "ParallelLights.h"
#include "Cameras.h"

#include "DistributedGlobal.h"


//---------------------------------------------------
// CScene: Klasse für ein Szenenobjekt 
//
// Autor: Prof. Dr. Tobias Breiner
// Letzte Änderung: 2011-08-07
//---------------------------------------------------

namespace Vektoria
{

	class CScene
	{
		friend class CScenes;
	private:
		void Tick(float & fTimeDelta); // wird automatisch jedes Frame von Root aus aufgerufen

	public:
		CScene();
		~CScene();
		CScene operator=(CScene scene);
		void Copy(CScene scene);

		void Init(); // Initialisiert ein Szenenobjekt (Aufruf nicht unbedingt notwendig, da schon im Konstruktor aufgerufen)
		void Fini();  // Finaliisiert ein Szenenobjekt

		void AddParallelLight(CParallelLight * pparallelLight);	// Hängt ein direktionales Licht an die Szene an.
		void AddPlacement(CPlacement * pplacement); // Hängt ein Placement an eine Szene an.

		bool SubPlacement(CPlacement * pplacement); // Hängt ein Placement von einer Szene ab, gibt true aus, wenn es geklappt hat.
		bool SubParallelLight(CParallelLight * pparallelLight);	// Hängt ein direktionales Licht von der Szene ab, gibt true aus, wenn es geklappt hat.

		CHMat m_mGlobal;

		void SearchForCameras();
		bool HasCamera(CCamera * pcamera);
		void Draw(CCamera * pcamera);


		CPlacements m_placements;
		CParallelLights m_parallelLights;

		void SetRoot(CRoot * proot);
		CRoot * m_proot;

		bool m_bSwitch;

		void SwitchOn(); // Schaltet Szene mitsamt seiner Unterhierarchie an
		void SwitchOff(); // Schaltet Szene mitsamt seiner Unterhierarchie aus


#ifdef NETWORKMASTER
		unsigned int GetidId();
#endif
	private:
		bool m_bTick;
		bool m_bFirstTick;
		CCameras m_cameras; // hier müssen alle Cameras verzeichnet sein, welche irgendwo die Szene betrachten
#ifdef NETWORKMASTER
		unsigned int m_idId;
		int m_icId;
#endif
	};

}