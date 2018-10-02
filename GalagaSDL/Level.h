#ifndef Level_h
#define Level_h
#include "InputManager.h"
#include "PlaySideBar.h"
#include "BackgroundStars.h"
#include "Player.h"
#include "Butterfly.h"
#include "Wasp.h"
#include "Boss.h"

class Level : public GameEntity {
	
public:
	
	
	
	enum LEVEL_STATES { running, finished, gameover };
	
private:
	Timer* mTimer;
	PlaySideBar* mSideBar;
	BackgroundStars* mStars;
	
	int mStage;
	bool mStageStarted;
	
	float mLabelTimer;
	
	Texture* mStageLabel;
	Scoreboard* mStageNumber;
	float mStageLabelOnScreen;
	float mStageLabelOffScreen;
	
	Texture* mReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;
	
	
	Player* mPlayer;
	bool mPlayerHit;
	float mPlayerRespawnDelay;
	float mPlayerRespawnTimer;
	float mPlayerRespawnLabelOnScreen;
	
	Texture* mGameOverLabel;
	bool mGameOver;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;
	
	LEVEL_STATES mCurrentState;
	
	Formation* mFormation;
	
	
	const int MAX_BUTTERFLIES = 16;
	int mButterflyCount;
	
	const int MAX_WASPS = 20;
	int mWaspCount;

	const int MAX_BOSSES = 4;
	int mBossCount;
	
	std::vector<Enemy*> mEnemies;
	
private:
	
	void StartStage();
	void HandleStartLabels();
	void HandleCollisions();
	void HandlePlayerDeath();
	
	
	void HandleEnemySpawning();
	void HandleEnemyFormation();
	void HandleEnemyDiving();
	
	
public:
	
	Level(int stage, PlaySideBar* sideBar, Player* player);
	~Level();
	
	LEVEL_STATES State();
	
	void Update();
	
	void Render();
};

#endif /* Level_h */
