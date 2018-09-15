#ifndef Graphics_h
#define Graphics_h


#include "SDL2/SDL.h"
#include <stdio.h>

class Graphics {
	
	
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;
	
private:
	static Graphics* sInstance;
	static bool sInitialized;
	
	
	SDL_Window* mWindow;
	SDL_Surface* mBackBuffer;
	
public:
	
	static Graphics* Instance();
	static void Release();
	static bool Initialized();
	
	
	void Render();
	
private:
	
	Graphics();
	~Graphics();
	
	bool Init();
	
	
};

#endif /* Graphics_h */
