#include "root.h"
#include "Util.h"
#include "Engine\EngineModule.h"

using namespace Vektoria;

#pragma once
enum Sound
{
	BackgroundMusic,
	StoneRolling,
	StoneFalling,
	StoneBreaking
};


//Singleton funktioniert noch nicht, wird von Engine gemacht

class SoundManager : public EngineModule 
{
public:
	SoundManager();
	~SoundManager();
	void play(Sound SoundName, bool looped = false);
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
};


