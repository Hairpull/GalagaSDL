#ifndef GameManager_h
#define GameManager_h


#include "Graphics.h"



class GameManager {
	
private:
	
	
	static GameManager* sInstance;
	
	bool mQuit;
	Graphics* mGraphics;
	
	SDL_Event mEvents;
	
public:
	
	static GameManager* Instance();
	static void Release();
	
	void Run();
	
private:
	
	GameManager();
	~GameManager();
	
};


#endif /* GameManager_h */
