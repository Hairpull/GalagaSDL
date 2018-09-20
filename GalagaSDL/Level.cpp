#include "Level.h"

Level::Level(int stage, PlaySideBar* sidebar) {
	
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
	
}


void Level::StartStage() {

	mStageStarted = true;
}

void Level::Update() {
	
	if(!mStageStarted) {
		
		mLabelTimer += mTimer->DeltaTime();
		if(mLabelTimer >= mStageLabelOffScreen) {
			
			mStars->Scroll(true);
			
			if(mStage > 1) {
				
				StartStage();
			} else {
				if(mLabelTimer >= mReadyLabelOffScreen)
					StartStage();
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
	}
}
