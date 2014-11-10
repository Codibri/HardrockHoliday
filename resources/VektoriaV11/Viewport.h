#pragma once
#include "Backgrounds.h"
#include "Overlays.h"
#include "Writings.h"
#include "WritingChar.h"
#include "Camera.h"
#include "Color.h"
#include <windows.h>

#include "DistributedGlobal.h"


//--------------------------------------------------------------------------------------------
// CVieport: Klasse f�r einen Bildschirmausschnitt zum Rendern
//
// Autor: Prof. Dr. Tobias Breiner
// Letzte �nderung: 2012-04-19
//--------------------------------------------------------------------------------------------

#define	S_STYLE_NORMAL 0x0
#define	S_STYLE_COLOR 0x01
#define	S_STYLE_HALFTRANSPARENT 0x02
#define	S_STYLE_POPART 0x04
#define	S_STYLE_OUTLINING 0x08
#define	S_STYLE_FOG 0x10
#define	S_STYLE_MONOCHROME 0x10
#define	S_STYLE_OWN 0x20

namespace Vektoria
{

	class CRoot;
	class CFrame;

	class CViewport
	{

		friend class CViewports;
	private:
		void Tick(float & fTimeDelta);

	public:
		CViewport();
		~CViewport();
		CViewport operator=(CViewport & viewport);
		void Copy(CViewport & viewport);


		void InitFull(CCamera * pcamera); // Initialisiert Viewport, so dass er das gaze Frame ausf�llt
		void Init(CCamera * pcamera, float frx, float fry, float frWidth, float frHeight); // Initialisiert Viewport mit relativen Ma�en zum Frame
		void Init(CCamera * pcamera, CFloatRect floatrect); // Initialisiert Viewport mit relativen Ma�en zum Frame
		void Fini();

		void ReSize(float frx, float fry, float frWidth, float frHeight); // Ver�ndert relative Gr��e des Viewports zum Frame
		void ReSize(); // Ver�ndert Gr��e des Viewports bei ver�nderung der Gr��e des Frames
		void CalcSize(); // Berechnet absolute Ausma�e des Viewports

		void SetBackfaceCullingOn(); // Schaltet Backfaceculling an (Default: an) 
		void SetBackfaceCullingOff(); // Schaltet Backfaceculling aus(Default: an) 
		void SetAntialiasingOn(); // Schaltet Antialiasing an (funktioniert nur, wenn Grafikkarte dies unterst�tzt, Default: an) 
		void SetAntialiasingOff(); // Schaltet Antialiasing aus (Default: an) 
		void SetWireframeOff(); // Schaltet Drahtgittermodellmodus an (Default: aus) 
		void SetWireframeOn(); // Schaltet Drahtgittermodellmodus aus (Default: aus) 

		void SetShadowRenderingOn(); // Schaltet Schatten f�r den Viewport an (Default: an) 
		void SetShadowRenderingOff(); // Schaltet Schatten f�r den Viewport aus (Default: an) 
		void SetPointLightRenderingOn(); // Schaltet Punktlichter f�r den Viewport an (Default: an) 
		void SetPointLightRenderingOff(); // Schaltet Punktlichter f�r den Viewport aus (Default: an) 
		void SetParallelLightRenderingOn(); // Schaltet Parallellichter f�r den Viewport an (Default: an) 
		void SetParallelLightRenderingOff(); // Schaltet Parallellichter f�r den Viewport aus (Default: an) 
		void SetSpotLightRenderingOn(); // Schaltet Schweinwerferlichter f�r den Viewport an (Default: an) 
		void SetSpotLightRenderingOff(); // Schaltet Scheinwerferlichter f�r den Viewport aus (Default: an) 

		void SetFogOn(); // Schaltet Nebel an
		void SetFogOff(); // Schaltet Nebel aus
		void SetFogStrength(float fFogStrength); // Gibt Nebelst�rke an, Default = 0.01 
		float m_fFogStrengthInv;

		void SetStyle(int eStyle); // Schaltet bestimmten Rendering-Stil an, die Stile sind kombinierbar 
		void SetStyleOutlineTheshold(float frStyleOutlineThreshold); // Gibt den fraktionalen Grenzwert f�r das Outlining an, default = 0.5
		void SetColorOutline(CColor & colorOutline); // Setzt die Konturfarbe, zur Parametrisierung eines Renderingstiles



		void StyleOwn(); // Schaltet denjenigen Teil, den man selbst im Shader ver�ndern kann, an
		void StylePopArt(); // Schaltet auf Pop-Style-Anmutung
		void StyleCartoon(); // Schaltet auf Cartoon-Anmutung
		void StyleOutlining(); // Schaltet Konturierung an
		void StyleMonochrome(CColor c); // Schaltet Monochrome-Anmutung an, c gibt die F�rbung an
		void StyleSepia(); // Schaltet Sepia-Anmutung an
		void StylePurpleHaze(); // Schaltet auf PurpleHaze-Anmutung
		void StyleBlueDream(); // Schaltet BlueDream-Anmutung an
		void StyleBlackWhite(); // Schaltet Schwarzwei�-Anmutung an
		void StyleContrast(float fr); // Erh�ht Kontrast (Werte>0) bzw. vermindert Kontrast (Werte<0)
		void StyleContrast(CColor c); // Erh�ht Kontrast (Werte>0) bzw. vermindert Kontrast (Werte<0) jeweils getrennt nach RGB-Werten 
		void StyleBrightness(float fr); // Erh�ht Helligkeit (Werte>1), vermindert Helligkeit (Werte 0..1), invertiert Farbe (Wert<0) 
		void StyleBrightness(CColor c); // Erh�ht Helligkeit (Werte>1), vermindert helligkeit (Werte 0..1), invertiert Farbe (Wert<0) jeweils getrennt nach RGB-Werten 
		void StyleRotateHue(float faHue); // Rotiert Farbwert um den Winkel fa im Bogenma�
		void StyleInverse(); // Invertiert alle Farben
		void StyleOff(); // Schaltet alle Stile aus

		void AddOverlay(COverlay * poverlay); // H�ngt ein 2D-Sprite an den Viewport an
		bool SubOverlay(COverlay * poverlay); // H�ngt ein vorhandenes 2D-Sprite vom Viewport ab, gibt true aus, wenn's geklappt hat

		void AddBackground(CBackground * pbackground); // H�ngt einen 2D-Hintergrund an den Viewport an
		bool SubBackground(CBackground * pbackground); // H�ngt ein vorhandenes 2D-Background vom Viewport ab, gibt true aus, wenn's geklappt hat

		void AddWriting(CWriting * pwriting); // H�ngt ein Writing-Textfeld an den Viewport an
		bool SubWriting(CWriting * pwriting); // H�ngt ein vorhandenes Writing-Textfeld vom Viewport ab, gibt true aus, wenn's geklappt hat

		void AddWritingChar(CWritingChar * pwritingchar); // H�ngt ein Writing-Buchstabenfeld an den Viewport an
		bool SubWritingChar(CWritingChar * pwritingchar); // H�ngt ein vorhandenes Writing-Buchstabenfeld vom Viewport ab, gibt true aus, wenn's geklappt hat



		void FrameToViewportCoord(float & frx, float & fry); // �bersetzt die Koordinaten des Frames in Koordinaten des Viewports

		COverlays m_overlays;
		CBackgrounds m_backgrounds;
		CWritings m_writings;

		bool m_bSwitch;

		void SwitchOn(); // Schaltet Viewport mitsamt seiner Unterhierarchie an
		void SwitchOff(); // Schaltet Viewport mitsamt seiner Unterhierarchie aus


		int m_ix;
		int m_iy;
		int m_iWidth;
		int m_iHeight;

		float m_frx;
		float m_fry;
		float m_frWidth;
		float m_frHeight;

		bool m_bBackfaceCulling;
		bool m_bAntialiasing;
		bool m_bWireframe;
		bool m_bParallelLightRendering;
		bool m_bSpotLightRendering;
		bool m_bPointLightRendering;
		bool m_bShadowRendering;

		float m_fAspectRatio;
		CCamera * m_pcamera;
		CFrame * m_pframe;
		bool m_bInit;
		int m_i;
		int m_eStyle;

		CHMat m_mColorModification;

		CColor m_colorOutline;
		void SetFrame(CFrame * pframe);
		void SetRoot(CRoot * proot);
		CRoot * m_proot;
#ifdef NETWORKMASTER
		unsigned int GetidId();
	private:

		unsigned int m_idId;
		int m_icId;
#endif


	};

}