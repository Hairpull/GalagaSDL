#ifndef GameManager_h
#define GameManager_h

#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"



class GameManager {
	
private:
	
	
	static GameManager* sInstance;
	
	const int FRAME_RATE = 60;
	
	bool mQuit;
	Graphics* mGraphics;
	AssetManager* mAssetMgr;
	InputManager* mInputMgr;
	AudioManager* mAudioMgr;
	
	
	Timer* mTimer;
	
	
	SDL_Event mEvents;
	
	Texture* mTex;
	Texture* mTex2;

	
	
	
public:
	
	static GameManager* Instance();
	static void Release();
	
	void Run();
	
private:
	
	GameManager();
	~GameManager();
	
};


#endif /* GameManager_h */
