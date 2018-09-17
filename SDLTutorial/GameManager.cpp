#include "GameManager.h"

GameManager* GameManager::sInstance = NULL;

GameManager* GameManager::Instance() {
	
	if(sInstance == NULL)
		sInstance = new GameManager();
	
	return sInstance;
}

void GameManager::Release() {
	
	delete sInstance;
	sInstance = NULL;
}

GameManager::GameManager() {
	
	mQuit = false;
	
	mGraphics = Graphics::Instance();
	
	if(!Graphics::Initialized())
	   mQuit = true;
	
	mAssetMgr = AssetManager::Instance();
	
	mTimer = Timer::Instance();
	
	
	mTex = new Texture("SpriteSheet.png", 182, 54, 20, 20);
	mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
}

GameManager::~GameManager() {
	
	Graphics::Release();
	mGraphics = NULL;
	
	AssetManager::Release();
	mAssetMgr = NULL;
	
	Timer::Release();
	mTimer = NULL;
	
	delete mTex;
	mTex = NULL;
	

	

}

void GameManager::Run() {
	
	while(!mQuit) {
		
		mTimer->Update();
		
		while(SDL_PollEvent(&mEvents) != 0) {
			
			if(mEvents.type == SDL_QUIT) {
				
				mQuit = true;
			}
			
		}
		if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {

			
			mGraphics->ClearBackBuffer();
			
			mTex->Render();

			mGraphics->Render();
			
			mTimer->Reset();

		}
		

	}
}
