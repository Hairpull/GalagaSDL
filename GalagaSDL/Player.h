#ifndef Player_h
#define Player_h
#include "AnimatedTexture.h"
#include "InputManager.h"

using namespace QuickSDL;

class Player : public GameEntity {
	
private:
	
	
	Timer* mTimer;
	InputManager* mInput;
	
	bool mVisible;
	bool mAnimating;
	
	int mScore;
	int mLives;
	
	Texture* mShip;
	
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
	
	void Update();
	void Render();
	
	
};






#endif /* Player_h */
