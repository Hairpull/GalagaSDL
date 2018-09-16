#ifndef GameManager_h
#define GameManager_h


#include "Graphics.h"
#include "Timer.h"
#include "GameEntity.h"



class GameManager {
	
private:
	
	
	static GameManager* sInstance;
	
	const int FRAME_RATE = 60;
	
	bool mQuit;
	Graphics* mGraphics;
	
	
	Timer* mTimer;
	
	
	SDL_Event mEvents;
	
	
	
	GameEntity* mParent;
	GameEntity* mChild;
	
public:
	
	static GameManager* Instance();
	static void Release();
	
	void Run();
	
private:
	
	GameManager();
	~GameManager();
	
};


#endif /* GameManager_h */
