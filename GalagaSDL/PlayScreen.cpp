#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();
	
	mStars = BackgroundStars::Instance();
	
	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.85f, Graphics::Instance()->SCREEN_HEIGHT * 0.05f));
	
	mStartLabel = new Texture("START", "emulogic.ttf", 32, { 150, 0, 0 });
	mStartLabel->Parent(this);
	mStartLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.4f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	

	mLevel = NULL;
	mLevelStartDelay = 1.0f;
	mLevelStarted = false;
	
	mPlayer = NULL;
	
}

PlayScreen::~PlayScreen() {
	
	mTimer = NULL;
	mInput = NULL;
	
	mStars = NULL;
	
	delete mSideBar;
	mSideBar = NULL;
	
	delete mStartLabel;
	mStartLabel = NULL;
	
	delete mLevel;
	mLevel = NULL;
	
	delete mPlayer;
	mPlayer = NULL;
}

void PlayScreen::StartNextLevel() {
	
	mCurrentStage++;
	mLevelStartTimer = 0.0f;
	mLevelStarted = true;
	delete mLevel;
	mLevel = new Level(mCurrentStage, mSideBar, mPlayer);
}


void PlayScreen::StartNewGame() {
	
	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.4f, Graphics::Instance()->SCREEN_HEIGHT * 0.9f));
	mPlayer->Active(false);

	
	mStars->Scroll(false);
	
	mSideBar->SetHighScore(30000);
	mSideBar->SetShips(mPlayer->Lives());
	mSideBar->SetPlayerScore(mPlayer->Score());
	mSideBar->SetLevel(0);
	
	
	mGameStarted = false;
	mLevelStarted = false;
	mLevelStartTimer = 0.0f;
	mCurrentStage = 0;
	
	mAudio->PlayMusic("gamestart.wav", 0);
}

bool PlayScreen::GameOver() {
	
	if(!mLevelStarted)
		return false;

	return (mLevel->State() == Level::gameover);
}


void PlayScreen::Update() {
	
	if(mGameStarted) {
		
		if(!mLevelStarted) {
			
			mLevelStartTimer += mTimer->DeltaTime();
			if(mLevelStartTimer >= mLevelStartDelay)
				StartNextLevel();
			
		}
		
		
	} else {
		if(!Mix_PlayingMusic()) {
			
			mGameStarted = true;
		}
	}
	
	if(mGameStarted ) {
		
		if(mCurrentStage > 0)
			mSideBar->Update();
		
		if(mLevelStarted) {
			
			mLevel->Update();
			
			if(mLevel->State() == Level::finished) {
				
				mLevelStarted = false;
			}
		}
		mPlayer->Update();
		}
}

void PlayScreen::Render() {
	
	mSideBar->Render();
	
	if(!mGameStarted)
		mStartLabel->Render();
	
	if(mGameStarted) {
		
		if(mLevelStarted)
			mLevel->Render();
		
		mPlayer->Render();
	}
}
