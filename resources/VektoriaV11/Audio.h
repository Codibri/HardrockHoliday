#pragma once

#include "Node.h"
#include "windows.h" 
#include <mmsystem.h>
#include "dsound.h"
#include <stdio.h>


// #include "dmusici.h" // => mit Musik

//---------------------------------------------------
// CAudio: Klasse für 3D-Raumklang via DirectSound
//
// Autor: Prof. Dr. Tobias Breiner
// Letzte Änderung: 2011-08-07
//---------------------------------------------------


#define HAVETOSLACK 0
#define HAVETOLOOP 1 
#define HAVETOSTART 2 
#define HAVETOSTOP 3
#define ISLOOPING 4 
#define HASSTARTED 5

namespace Vektoria
{

class CAudio: public CNode
{
public:
	CAudio(void);
	~CAudio(void);

	bool Init(char *stringWavFile, HWND hwnd);  // Initialisiert einen Klang ohne 3D-Audio, dieser kann nicht in den Szenengraf eingebaut werden, die Funktion gibt true aus, falls die Initailisierung erfolgreich war, ansonsten false 
	bool Init3D(char *stringWavFile, HWND hwnd, float fRadius); // Initialisiert einen Klang mit 3D-Audio, die Funktion gibt true aus, falls die Initailisierung erfolgreich war, ansonsten false
	void Tick(CHMat & mAudio, float fTimeDelta,bool bTick); //Updated einen Klang mit 3D-Audio, muss bei jeden Frame aufgerufen werden, mAudio ist die globale Matrix der Klangquelle, fTimeDelta ist die verstrichene Zeit seit dem letzten Tick 
	void Fini(); // Finalisiert einen Klang, egal ob mit oder ohne 3D-Audio

	void Listen(CHMat & mListener, int iAudio); // Positioniert den Zuhörer beim 3D-Audio mittels der globalen Matrix mListener

	virtual void UpdateAABB();

	void Start();	// Startet einen Klang, spielt ihn einmal ab
	void Loop();	// Startet einen Klang, spielt ihn immer wieder ab
	void Stop();	// Beendet einen gestarten Klang 

	void SetVolume(float frVolume); // Modifiziert die Lautstärke (0.0F=aus 1.0F= volles Rohr) 
	void SetRadius(float fRadius); // Modifiziert den Wirkradius in Units eines 3D-Klanges 
	void SetDoppler(float fFactor); // fFactor=1.0: physikalisch richtiger Doppler-Effekt, fFactor=0.0: kein Doppler-Effekt; Default = 1.0F

	bool Is3D(); // Gibt true aus, wenn 3D-Audio, ansonsten false 

	bool m_bDoppler; // true, wenn Dopller-Effekt berechnet werden soll
	float m_fRadius;  // Eingestellter Wirkradius in Units eines 3D-Klanges, Default = 1.0F 
	float m_frVolume; // eingestellte Lautstärke (0.0F=aus 1.0F= volles Rohr), Default = 1.0F 
	bool m_bHaveToLoop;
	bool m_bHaveToStart;
	bool m_bHaveToStop;
	bool m_bHaveToSetVolume;
	void PauseCauseLoD(int iAudio); // Pausiert den Zuhörer beim 3D-Audio wegen LoD 
	void ContinueCauseLoD(int iAudio);  // Setzt den Zuhörer beim 3D-Audio nach LoD-Eintritt wieder fort 

	int * m_aeStatus; // 0 = not initialized, 1 = gestartet, 2 = looping, 3 = stopped, 4 = paused while started, 5 = paused  while looping
protected:
	bool m_bInitialized;
	bool m_bFirstCommit;
	IDirectSound8* m_lpDS;
	IDirectSoundBuffer* m_lpDSB;
	long m_lVolume;
	bool CreateSecondaryBuffer(int iAudio);
	int  m_iAllocStep;
	// Neu für 3D audio: 
	bool m_b3D;
	IDirectSound3DListener8* m_lpListener;
//	IDirectSoundBuffer8* m_lpDSBSecondary;
	IDirectSoundBuffer8** m_alpDSBSecondary;

	IDirectSound3DBuffer8** m_alpDS3DBSecondary;
	int m_iSecondary3DBufferAllocs;
	int m_iSecondary3DBufferInits;
	CHVector m_vListenerOld; 
	CHVector m_vAudioOld; 


	struct WaveHeaderType
	{
		char chunkId[4];
		unsigned long chunkSize;
		char format[4];
		char subChunkId[4];
		unsigned long subChunkSize;
		unsigned short audioFormat;
		unsigned short numChannels;
		unsigned long sampleRate;
		unsigned long bytesPerSecond;
		unsigned short blockAlign;
		unsigned short bitsPerSample;
		char dataChunkId[4];
		unsigned long dataSize;
	};



	bool LoadWave(char *stringWavFile);
	bool LoadWave3D(char *stringWavFile);
	float m_fTimeDelta;
	bool m_bTick;
	int m_iMatGlobals;

	FILE * m_file;
	WaveHeaderType m_waveFileHeader;
	DSBUFFERDESC m_bufferdescPrimary;
	WAVEFORMATEX m_waveformatPrimary;
	DSBUFFERDESC m_bufferdescSecondary;
	WAVEFORMATEX m_waveformatSecondary;
	int m_iSampleRate; 
	int m_iBitsPerSample;




};

}