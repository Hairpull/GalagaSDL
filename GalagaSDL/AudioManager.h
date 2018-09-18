//--------------------------------------------------------------//
// AudioManager.h                                               //
// Singleton                                                    //
// Plays WAV files                                              //
// Can play one BGM at a time, and many sound effects at once   //
//                                                              //
// By: Ather Omar                                               //
//--------------------------------------------------------------//
#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H
//-----------------------------------------------------------
#include "AssetManager.h"
//-----------------------------------------------------------
// QuickSDL
//-----------------------------------------------------------
namespace QuickSDL {
	//-------------------------------------------------------
	// AudioManager
	//-------------------------------------------------------
	class AudioManager {

	private:
		//Needed to make AudioManager a singleton class
		static AudioManager* sInstance;

		//Used to load audio files
		AssetManager* mAssetMgr;

	public:
		//-----------------------------------------
		//Returns a pointer to the class instance  
		//-----------------------------------------
		static AudioManager* Instance();
		//-----------------------------------------------------
		//Releases the class instance and sets it back to NULL 
		//-----------------------------------------------------
		static void Release();

		//----------------------------------------------------------------------------------------------
		//Sets the BGM to play using the provided file, loops = -1 is infinite looping (default: -1)
		//-----------------------------------------------------------------------------------------------
		void PlayMusic(std::string filename, int loops = -1);
		//-------------------------------------------------------
		//Pauses the currently playing BGM if there is any
		//-------------------------------------------------------
		void PauseMusic();
		//-------------------------
		//Resumes paused BGM
		//-------------------------
		void ResumeMusic();

		//--------------------------------------------------
		//Plays a sound effect from the file provided
		//plays if for the given loops (default: 0)
		//on the given channel (default: 0)
		//--------------------------------------------------
		void PlaySFX(std::string filename, int loops = 0, int channel = 0);

	private:
		//------------------------------------------------------------------------------------------
		//Contructor is private so that Instance() must be used to get an instance when needed  
		//------------------------------------------------------------------------------------------
		AudioManager();
		//-------------------------------------------------------------------------------------
		//Destructor is private so that the instance can only be destroyed using Release()  
		//-------------------------------------------------------------------------------------
		~AudioManager();
	};
}
#endif
