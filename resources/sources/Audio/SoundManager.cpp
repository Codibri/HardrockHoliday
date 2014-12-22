#include "Audio\SoundManager.h"
#include "Utility\DebugLog.h"
#include "Engine\Engine.h"

SoundManager::SoundManager()
{
	HWND hwnd = Engine::getInstance()->globalResources.hWnd;
	mBackgroundMusic.Init("GameResources\\Sounds\\test.wav", hwnd);
	mStoneRolling.Init("GameResources\\Sounds\\test.wav", hwnd);
	mStoneFalling.Init("GameResources\\Sounds\\test.wav", hwnd);
	mStoneBreaking.Init("GameResources\\Sounds\\test.wav", hwnd);
}

SoundManager::~SoundManager()
{
	mBackgroundMusic.Fini();
	mStoneRolling.Fini();
	mStoneFalling.Fini();
	mStoneBreaking.Fini();
}

//lokaler Soundtest
/*void SoundManager::update(float deltaTime, float time) {
	count++;
	if (count % 500 == 0) {
		std::cout << "Hallo Sound!" << std::endl;
		play(BackgroundMusic, false);
	}	
}*/

void SoundManager::play(Sound SoundName, bool looped)
{
	CAudio* CurrentAudio = getSound(SoundName);
	if (looped)
		CurrentAudio->Loop();
	else
		CurrentAudio->Start();
}

void SoundManager::stop(Sound SoundName)
{
	CAudio* CurrentAudio = getSound(SoundName);
	CurrentAudio->Stop();
}

void SoundManager::setVolume(Sound SoundName, float volume)
{
	CAudio* CurrentAudio = getSound(SoundName);
	//falsche Werte abfangen
	if (volume < 0) volume = 0;
	if (volume > 1) volume = 1;
	CurrentAudio->Stop();
}

CAudio* SoundManager::getSound(Sound SoundName)
{
	//transform Enum to SoundPointer
	switch (SoundName)
	{
	case BackgroundMusic:
	{
		return &mBackgroundMusic;
		break;
	}
	case StoneRolling:
	{
		return &mStoneRolling;
		break;
	}
	case StoneFalling:
	{
		return &mStoneFalling;
		break;
	}
	case StoneBreaking:
	{
		return &mStoneBreaking;
		break;
	}
	};
	//ab hier nur noch Fehlerbehandlung und return 0 fuer Compiler
	return 0;
}
