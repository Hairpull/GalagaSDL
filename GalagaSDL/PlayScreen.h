#ifndef PlayScreen_h
#define PlayScreen_h
#include "InputManager.h"
#include "BackgroundStars.h"
#include "PlaySideBar.h"
#include "Level.h"

class PlayScreen : public GameEntity {
	
private:
	
	
	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;
	
	BackgroundStars* mStars;
	
	PlaySideBar* mSideBar;
	
	Texture* mStartLabel;
	
	float mLevelStartTimer;
	float mLevelStartDelay;
	
	bool mGameStarted;
	
	Level* mLevel;	
	bool mLevelStarted;
	int mCurrentStage;
	
private:
	
	void StartNextLevel();
	
public:
	
	PlayScreen();
	~PlayScreen();
	
	void StartNewGame();
	
	void Update();
	
	void Render();
	
	
};





#endif /* PlayScreen_h */
