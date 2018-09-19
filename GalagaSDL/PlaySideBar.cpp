#include "PlaySideBar.h"


PlaySideBar::PlaySideBar() {
	

	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	
	mBackground = new Texture("black.png");
	mBackground->Parent(this);
	mBackground->Pos(Vector2(45.0f, 380.0f));
	mBackground->Scale(Vector2(3.0f, 10.0f));

	mHighLabel = new Texture("HIGH", "emulogic.ttf", 32, { 150, 0, 0 });
	mHighLabel->Parent(this);
	mHighLabel->Pos(Vector2( -25.0f, 0.0f));
	
	mScoreLabel = new Texture("SCORE", "emulogic.ttf", 32, { 150, 0, 0 });
	mScoreLabel->Parent(this);
	mScoreLabel->Pos(Vector2( 25.0f, 32.0f));
	
	mHighScoreboard = new Scoreboard();
	mHighScoreboard->Parent(this);
	mHighScoreboard->Pos(Vector2( 90.0f, 64.0f));
	
	mPlayerOneLabel = new Texture("1UP", "emulogic.ttf", 32, { 150, 0, 0});
	mPlayerOneLabel->Parent(this);
	mPlayerOneLabel->Pos(Vector2(-45.0f, 160.0f));
	
	mBlinkTimer = 0.0f;
	mBlinkInterval = 0.5f;
	mPlayerOneLabelVisible = true;
	
	mPlayerOneScore = new Scoreboard;
	mPlayerOneScore->Parent(this);
	mPlayerOneScore->Pos(Vector2(90.0f, 192.0f));
}

PlaySideBar::~PlaySideBar() {
	
	mTimer = NULL;
	mAudio = NULL;
	
	delete mBackground;
	mBackground = NULL;
	
	delete mHighLabel;
	mHighLabel = NULL;
	delete mScoreLabel;
	mScoreLabel = NULL;
	delete mHighScoreboard;
	mHighScoreboard = NULL;
	delete mPlayerOneLabel;
	mPlayerOneLabel = NULL;
	delete mPlayerOneScore;
	mPlayerOneScore = NULL;
}

void PlaySideBar::SetHighScore(int score) {
	
	mHighScoreboard->Score(score);
}

void PlaySideBar::SetPlayerScore(int score) {
	
	mPlayerOneScore->Score(score);
}

void PlaySideBar::Update() {
	
	
	mBlinkTimer += mTimer->DeltaTime();
	if (mBlinkTimer >= mBlinkInterval)
		mPlayerOneLabelVisible = !mPlayerOneLabelVisible;
}

void PlaySideBar::Render() {
	
	mBackground->Render();
	
	mHighLabel->Render();
	mScoreLabel->Render();
	mHighScoreboard->Render();
	
	if(mPlayerOneLabelVisible)
		mPlayerOneLabel->Render();
	
	mPlayerOneScore->Render();
}
