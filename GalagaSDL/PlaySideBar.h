#ifndef PlaySideBar_h
#define PlaySideBar_h
#include "Timer.h"
#include "ScoreBoard.h"
#include "AudioManager.h"



class PlaySideBar : public GameEntity {
	
private:
	Timer* mTimer;
	AudioManager* mAudio;
	
	
	Texture* mBackground;
	
	Texture* mHighLabel;
	Texture* mScoreLabel;
	Scoreboard* mHighScoreboard;
	
	Texture* mPlayerOneLabel;
	float mBlinkTimer;
	float mBlinkInterval;
	bool mPlayerOneLabelVisible;
	Scoreboard* mPlayerOneScore;
	
	
	
public:
	
	PlaySideBar();
	~PlaySideBar();
	
	void SetHighScore(int score );
	void SetPlayerScore(int score);
	
	void Update();
	void Render();
	
	
	
};





#endif /* PlaySideBar_h */
