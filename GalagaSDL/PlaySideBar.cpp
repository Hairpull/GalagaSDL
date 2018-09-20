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
	
	
	mShips = new GameEntity();
	mShips->Parent(this);
	mShips->Pos(Vector2(-40.0f,400.0f));
	
	
	for(int i = 0; i < MAX_SHIP_TEXTURES; i++) {
		mShipTextures[i] = new Texture("playership.png");
		mShipTextures[i]->Parent(mShips);
		mShipTextures[i]->Pos(Vector2(62.0f * (i % 3), 70.0f * (i / 3)));
	}
	
	mTotalShipsLabel = new Scoreboard();
	mTotalShipsLabel->Parent(mShips);
	mTotalShipsLabel->Pos(Vector2(140.0f, 80.0f));
	
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
	
	delete mShips;
	mShips = NULL;
	
	for(int i = 0; i < MAX_SHIP_TEXTURES; i++) {
		delete mShipTextures[i];
		mShipTextures[i] = NULL;
	}
	
	delete mTotalShipsLabel;
	mTotalShipsLabel = NULL;
}

void PlaySideBar::SetHighScore(int score) {
	
	mHighScoreboard->Score(score);
}

void PlaySideBar::SetPlayerScore(int score) {
	
	mPlayerOneScore->Score(score);
}

void PlaySideBar::SetShips(int ships) {
	
	mTotalShips = ships;
	
	if(ships > MAX_SHIP_TEXTURES)
		mTotalShipsLabel->Score(ships);
}

void PlaySideBar::Update() {
	
	
	mBlinkTimer += mTimer->DeltaTime();
	if (mBlinkTimer >= mBlinkInterval) {
		
	
		mPlayerOneLabelVisible = !mPlayerOneLabelVisible;
		mBlinkTimer = 0.0f;
	}
}

void PlaySideBar::Render() {
	
	mBackground->Render();
	
	mHighLabel->Render();
	mScoreLabel->Render();
	mHighScoreboard->Render();
	
	if(mPlayerOneLabelVisible)
		mPlayerOneLabel->Render();
	
	mPlayerOneScore->Render();
	
	for (int i = 0; i < MAX_SHIP_TEXTURES && i < mTotalShips; i++)
		mShipTextures[i]->Render();

	if(mTotalShips > MAX_SHIP_TEXTURES)
		mTotalShipsLabel->Render();
}
