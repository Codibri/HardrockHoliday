////////////////////////////////////////////////////
/// @file Timer.h
///  A plattform independent class for high resolution timer operations.
/// @author Benedikt Walser
/// @author Kim Werner
/// Überarbeitet und erweitert durch Tobias Breiner
/// ** Copyright (c) Humanics GbR **
////////////////////////////////////////////////////

#pragma once

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
  #include <windows.h>
#endif
#ifdef LINUX
  #include <sys/time.h>
#endif
#ifdef WIN64
#include <windows.h>
#endif

#define I_FR_TICKS 30 // Anzahl der letzten Ticks, die für die Frame-Rate-Berechnung herangezogen werden, je höher der Wert, desto genauer die Berechnung, aber desto weniger oft wird der Wert aktualisiert 
#define I_FR_LONG_TERM_FAKTOR 100 // Anzahl des Faktors, der für die Langzeit Frame-Rate-Berechnung herangezogen wird, wird intern mit I_FR_TICKS multipliziert 

namespace Vektoria
{

class CTimer
{
  public:
    CTimer(); // Initialisiert den Timer 

    void Init();    // Initialisiert den Timer neu, falls der Aufruf des Konstruktors zu lange her ist
	void Tick(float & fTime, float & fTimeDelta);	// Sollte jeden Tick aufgerufen werden, berechnet fTime (Zeit in Sekunden, die seit Init bzw. Konstruktor-Aufruf vergangen ist) und fTimeDelta (Zeit, seit dem letzten Tick vergangen ist)
	void Fini();	// Finalisiert den Timer, wird zurzeit nicht verwendet
	
	void SwitchFrameRateCalculationOn();	// Schaltet die Berechnung der Bildwiederholrate ein, FR-Berechnung kostet ein wenig Performanz, daher per Default aus
	void SwitchFrameRateCalculationOff();	// Schaltet die Berechnung der Bildwiederholrate aus, FR-Berechnung kostet ein wenig Performanz, daher per Default aus
	
	float GetFrameRateAverage();			// Gibt den arithmetischen Kurzzeitdurchschnitt über die letzten Ticks (I_FR_TICKS) der FrameRate aus 
	float GetFrameRateAverageLong();		// Gibt den arithmetischen Langzeitdurchschnitt über die letzten Ticks (I_FR_TICKS*I_FR_LONG_TERM_FAKTOR)der FrameRate aus 
	float GetFrameRateMin();				// Gibt den schlechtesten Wert über die letzten Ticks (I_FR_TICKS) der FrameRate aus 
	float GetFrameRateMax();				// Gibt den besten Wert über die letzten Ticks (I_FR_TICKS) der FrameRate aus 

    void Start();   // Startet den Timer.
	void Stop();	// Stopt den Timer.
    double GetElapsedTime();  // Get elapsed time in seconds.
    double GetElapsedTimeInMilliSeconds(); // Get elapsed time in milliseconds.
    double GetElapsedTimeInMicroSeconds(); // Get elapsed time in microseconds.

	double m_dStartTime;
    double m_dStopTime;
    bool m_bStopped;
   
#ifdef WIN32
    LARGE_INTEGER m_Frequency;
    LARGE_INTEGER m_StartCount;
    LARGE_INTEGER m_StopCount;
	LARGE_INTEGER m_CountFirst;
	LARGE_INTEGER m_Count;
	LARGE_INTEGER m_CountOld;
	float m_fPCFrequency;
#else
    timeval m_StartCount;
    timeval m_StopCount;
    timeval m_Count;
    timeval m_CountOld;
#endif


	float m_fTime;					// Zeit in Sekunden, die seit dem letzten Init bzw. Konstuktoraufruf vergangen ist
	float m_fTimeDelta;				// Zeit in Sekunden, die seit dem letzten Tick vergangen ist

	bool m_bCalcFrameRate; 
	float m_fFrameRate;				// FrameRate seit dem letzten Tick
	float m_fFrameRateAverage;		// der arithmetische Kurzzeitdurchschnitt über die letzten Ticks der FrameRate 
	float m_fFrameRateAverageLong;	// der arithmetische Kurzzeitdurchschnitt über die letzten Ticks der FrameRate  
	float m_fFrameRateMin;			// der schlechteste FR-Wert über die letzten Ticks der FrameRate  
	float m_fFrameRateMax;			// der beste FR_Wert über die letzten Ticks der FrameRate
private:
	void CalcFrameRate(); // Berechnet die Bildwiederholrate (vier Werte: der arithmetische Kurzzeitdurchschnitt, der arithmetische Langzeitdurchschnitt, die schlechteste und der beste Wert)

	float m_fFRMax;
	float m_fFRMin; // unmöglich hohe Frame Rate Zahl
	float m_afFRAvg[I_FR_TICKS];
	float m_afFRAvgLong[I_FR_LONG_TERM_FAKTOR];
	float m_fFRAvg;
	float m_fFRAvgLong;
	int m_iFR;
	int m_iFRLong;


};

}