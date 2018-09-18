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
	
	mAudioMgr = AudioManager::Instance();
	
	mTimer = Timer::Instance();
	
	
	mTex = new Texture("Hello World!", "Arial.ttf", 72, {255, 0, 0});
	mTex->Pos(Vector2(400, 200));
	
	mTex2 = new Texture("Goodbye World!", "Arial.ttf", 72, {0, 255, 0});
	mTex2->Pos(Vector2(400, 400));
}

GameManager::~GameManager() {
	
	AudioManager::Release();
	mAudioMgr = NULL;
	
	AssetManager::Release();
	mAssetMgr = NULL;
	
	Graphics::Release();
	mGraphics = NULL;
	
	InputManager::Release();
	mInputMgr = NULL;
	
	Timer::Release();
	mTimer = NULL;
	
	delete mTex;
	mTex = NULL;
	
	delete mTex2;
	mTex2 = NULL;
	

	

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
			
			if(mInputMgr->KeyDown(SDL_SCANCODE_1)) {
				
				mAudioMgr->PlaySFX("beat.wav");
			}
						
			mGraphics->ClearBackBuffer();
			
			mTex->Render();
			mTex2->Render();

			
			mGraphics->Render();
			
			mTimer->Reset();
			
		}
		
		
	}
}
