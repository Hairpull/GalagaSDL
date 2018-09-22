#include "Level.h"

Level::Level(int stage, PlaySideBar* sidebar, Player* player) {
	
	mTimer = Timer::Instance();
	mSideBar = sidebar;
	mSideBar->SetLevel(stage);
	mStars = BackgroundStars::Instance();
	
	mStage = stage;
	
	mStageStarted = false;
	
	mLabelTimer = 0.0f;
	
	mStageLabel = new Texture("STAGE", "emulogic.ttf", 32, { 75, 75, 200 });
	mStageLabel->Parent(this);
	mStageLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.35f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mStageNumber = new Scoreboard({ 75, 75, 200 });
	mStageNumber->Score(mStage);
	mStageNumber->Parent(this);
	mStageNumber->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	
	mStageLabelOnScreen = 0.0f;
	mStageLabelOffScreen = 1.5f;
	
	mReadyLabel = new Texture("READY", "emulogic.ttf", 32, { 150, 0, 0 });
	mReadyLabel->Parent(this);
	mReadyLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.4f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mReadyLabelOnScreen = mStageLabelOffScreen;
	mReadyLabelOffScreen = mReadyLabelOnScreen + 3.0f;
	
	mPlayer = player;
	mPlayerHit = false;
	mPlayerRespawnDelay = 3.0f;
	mPlayerRespawnTimer = 0.0f;
	mPlayerRespawnLabelOnScreen = 2.0f;
	
	mGameOverLabel = new Texture("GAME OVER", "emulogic.ttf", 32, {150, 0, 0 });
	mGameOverLabel->Parent(this);
	mGameOverLabel->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f));
	
	mGameOver = false;
	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0f;
	mGameOverLabelOnScreen = 1.0f;
	
	mCurrentState = running;
	
	mEnemy = new Enemy(0);
}


Level::~Level() {
	
	mTimer = NULL;
	mSideBar = NULL;
	mStars = NULL;
	
	delete mStageLabel;
	mStageLabel = NULL;
	delete mStageNumber;
	mStageNumber = NULL;
	
	delete mReadyLabel;
	mReadyLabel = NULL;
	
	mPlayer = NULL;
	
	delete mGameOverLabel;
	mGameOverLabel = NULL;
	
	delete mEnemy;
	mEnemy = NULL;
	
}


void Level::StartStage() {

	mStageStarted = true;
}

void Level::HandleStartLabels() {
	
	
	mLabelTimer += mTimer->DeltaTime();
	if(mLabelTimer >= mStageLabelOffScreen) {
		
		mStars->Scroll(true);
		
		if(mStage > 1) {
			
			StartStage();
		} else {
			if(mLabelTimer >= mReadyLabelOffScreen) {
				
				StartStage();
				mPlayer->Active(true);
				mPlayer->Visible(true);
			}
		}
	}

	
	
}


void Level::HandleCollisions() {
	
	if(!mPlayerHit) {
		
		if(InputManager::Instance()->KeyPressed(SDL_SCANCODE_X)) {
			
			mPlayer->WasHit();
			mSideBar->SetShips(mPlayer->Lives());
			
			mPlayerHit = true;
			mPlayerRespawnTimer = 0.0f;
			mPlayer->Active(false);
			mStars->Scroll(false);
		}
	}
}

void Level::HandlePlayerDeath() {
	
	if(!mPlayer->IsAnimating()) {
		
		if(mPlayer->Lives() > 0) {
			
			if(mPlayerRespawnTimer == 0.0f)
				mPlayer->Visible(false);
			
			mPlayerRespawnTimer += mTimer->DeltaTime();
			if(mPlayerRespawnTimer >= mPlayerRespawnDelay) {
				
				mPlayer->Active(true);
				mPlayer->Visible(true);
				mPlayerHit = false;
				mStars->Scroll(true);
			}
			
		} else {
			
			if(mGameOverTimer == 0.0f)
				mPlayer->Visible(false);
			
			mGameOverTimer += mTimer->DeltaTime();
			if(mGameOverTimer >= mGameOverDelay) {
				
				mCurrentState = gameover;
			}
		}
	}
}

Level::LEVEL_STATES Level::State() {
	
	return mCurrentState;
}

void Level::Update() {
	
	if(!mStageStarted) {
		
		HandleStartLabels();
		
	} else {
		
		mEnemy->Update();
		
		HandleCollisions();
		
		if(mPlayerHit) {
			HandlePlayerDeath();
		} else {
			
			if(InputManager::Instance()->KeyPressed(SDL_SCANCODE_N)) {
				
				mCurrentState = finished;
			}
		}
	}
}

void Level::Render() {
	
	
	if(!mStageStarted) {
		
		if(mLabelTimer > mStageLabelOnScreen && mLabelTimer < mStageLabelOffScreen) {
			
			mStageLabel->Render();
			mStageNumber->Render();
			
		} else if(mLabelTimer > mReadyLabelOnScreen && mLabelTimer < mReadyLabelOffScreen) {
			
			mReadyLabel->Render();
			
		}
	} else {
		
		mEnemy->Render();
		
		if(mPlayerHit) {
			
			if(mPlayerRespawnTimer >= mPlayerRespawnLabelOnScreen)
				mReadyLabel->Render();
			
			if(mGameOverTimer >= mGameOverLabelOnScreen)
				mGameOverLabel->Render();
		}
		
	}
}
