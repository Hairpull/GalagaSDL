//--------------------------------------------------------------//
// AudioManager.cpp                                             //
// Singleton                                                    //
// Plays WAV files                                              //
// Can play one BGM at a time, and many sound effects at once   //
//                                                              //
// By: Ather Omar                                               //
//--------------------------------------------------------------//
#include "AudioManager.h"
//----------------------------------------------------------
// QuickSDL
//----------------------------------------------------------
namespace QuickSDL {

	//Initializing to NULL
	AudioManager* AudioManager::sInstance = NULL;

	AudioManager* AudioManager::Instance() {

		//Create a new instance if no instance was created before
		if(sInstance == NULL)
			sInstance = new AudioManager();

		return sInstance;
	}

	void AudioManager::Release() {

		delete sInstance;
		sInstance = NULL;
	}

	AudioManager::AudioManager() {

		mAssetMgr = AssetManager::Instance();

		//Initialize the SDL_mixer using 44.1 khz and 2 channels (change if needed) and handle initialization errors
		if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {

			printf("Mixer Initialization Error: %s\n", Mix_GetError());
		}
	}

	AudioManager::~AudioManager() {

		mAssetMgr = NULL;

		//Close the SDL_mixer
		Mix_Quit();
	}

	void AudioManager::PlayMusic(std::string filename, int loops) {

		//Play the Mix_Music* loaded in the AssetManager so that the file is not reloaded every time
		Mix_PlayMusic(mAssetMgr->GetMusic(filename), loops);
	}

	void AudioManager::PauseMusic() {

		if(Mix_PlayingMusic() != 0)
			Mix_PauseMusic();
	}

	void AudioManager::ResumeMusic() {

		if(Mix_PausedMusic() != 0)
			Mix_ResumeMusic();
	}

	void AudioManager::PlaySFX(std::string filename, int loops, int channel) {

		//Play the Mix_Chunk* loaded in the AssetManager so that the file is not reloaded every time
		Mix_PlayChannel(channel, mAssetMgr->GetSFX(filename), loops);
	}
}
