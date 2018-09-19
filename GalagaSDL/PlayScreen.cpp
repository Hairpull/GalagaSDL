#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	
	mStars = BackgroundStars::Instance();
	
	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.85f, Graphics::Instance()->SCREEN_HEIGHT*0.05f));
	mSideBar->SetHighScore(30000);
	mSideBar->SetPlayerScore(50000);
	
}

PlayScreen::~PlayScreen() {
	
	mTimer = NULL;
	mInput = NULL;
	
	mStars = NULL;
	
	delete mSideBar;
	mSideBar = NULL;
	
}

void PlayScreen::Update() {
	
	mSideBar->Update();
	
}

void PlayScreen::Render() {
	
	mSideBar->Render();
}
