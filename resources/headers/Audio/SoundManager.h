#include "root.h"
#include "Util.h"

using namespace Vektoria;

#pragma once
enum Sound
{
	BackgroundMusic,
	StoneRolling,
	StoneFalling,
	StoneBreaking
};


//Singleton funktioniert noch nicht, wird noch gefixt

class SoundManager 
{
public:
	static SoundManager* getInstance();
	static void Init(HWND hwnd);
	static void Fini();
	SoundManager(HWND hwnd);
	~SoundManager();
    void play(Sound SoundName, bool looped=false);
    void stop(Sound SoundName);
	void setVolume(Sound SoundName, float volume);
private:
    CAudio* getSound(Sound SoundName);
	//Je Sound (Enum) ein CAudio Object
	//Fuer neue Sounds hier eine Private Variable anlegen und
	//die Methode getSound(...), den Konstruktor und den Destruktor anpassen
    CAudio mBackgroundMusic;
    CAudio mStoneRolling;
	CAudio mStoneFalling;
	CAudio mStoneBreaking;
	//static SoundManager* instance;
};


