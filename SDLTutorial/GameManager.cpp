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
	
	mInputMgr = InputManager::Instance();
	
	mTimer = Timer::Instance();
	
	
	mTex = new AnimatedTexture("SpriteSheet.png", 204, 45, 40, 38, 4, 0.5f, AnimatedTexture::horizontal);
	mTex->WrapMode(AnimatedTexture::once);
	mTex->Pos(Vector2(100, 200));
}

GameManager::~GameManager() {
	
	Graphics::Release();
	mGraphics = NULL;
	
	AssetManager::Release();
	mAssetMgr = NULL;
	
	InputManager::Release();
	mInputMgr = NULL;
	
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
			
			mInputMgr->Update();
			
			mTex ->Update();
			
			mGraphics->ClearBackBuffer();
			
			mTex->Render();
			
			mGraphics->Render();
			
			mTimer->Reset();
			
		}
		
		
	}
}
