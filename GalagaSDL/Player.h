#ifndef Player_h
#define Player_h
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"




using namespace QuickSDL;

class Player : public GameEntity {
	
private:
	
	
	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;
	
	bool mVisible;
	bool mAnimating;
	
	int mScore;
	int mLives;
	
	Texture* mShip;
	
	AnimatedTexture* mDeathAnimation;
	
	float mMoveSpeed;
	Vector2 mMoveBounds;
	
private:
	
	void HandleMovement();
	
public:
	
	Player();
	
	~Player();
	
	void Visible(bool visible);
	bool IsAnimating();
	
	int Score();
	int Lives();
	
	
	void AddScore(int change);
	
	void WasHit();
	
	void Update();
	void Render();
	
	
};






#endif /* Player_h */
