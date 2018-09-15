#include "Graphics.h"

Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;


Graphics* Graphics::Instance() {
	if(sInstance == NULL)
		sInstance = new Graphics();
	

	return sInstance;
}


void Graphics::Release(){
	delete sInstance;
	sInstance = NULL;
	
	sInitialized = false;

}


bool Graphics::Initialized() {
	return sInitialized;
}

Graphics::Graphics() {
	
	mBackBuffer = NULL;
	
	sInitialized = Init();
	
}

Graphics::~Graphics(){
	
	
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	
	SDL_Quit();
	
}




bool Graphics::Init(){
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Initialization error: %s\n", SDL_GetError());
		return false;
	}
	
	
	mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(mWindow == NULL) {
		printf("Window creation error: %s\n", SDL_GetError());
		return false;
	}
	
	mBackBuffer = SDL_GetWindowSurface(mWindow);
	
	return true;
}

void Graphics::Render() {
	
	SDL_UpdateWindowSurface(mWindow);
}


