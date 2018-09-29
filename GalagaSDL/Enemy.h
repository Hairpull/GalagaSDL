#ifndef Enemy_h
#define Enemy_h
#include "Animatedtexture.h"
#include "BezierPath.h"
#include "Formation.h"

class Enemy : public GameEntity {
	
public:
	
	enum STATES { flyIn, formation, dive, dead };

	
	
protected:
	
	static std::vector<std::vector<Vector2>> sPaths;
	static Formation* sFormation;
	
	
	Timer* mTimer;
	
	Texture* mTextures[2];
	
	STATES mCurrentState;
	
	int mCurrentPath;
	
	int mCurrentWaypoint;
	
		// Ather has his EPSILON set to 5.0f, but my enemies jitter like crazy with a setting below 15.0f. Not sure why, but this is a difference between our source files. I think it has something to do with his enemy image size. I can't find  spot where he mentions the size explicitly.
	const float EPSILON = 15.0f;
	
	float mSpeed;
	
	int mIndex;
	
	Vector2 mTargetPosition;
	
	bool mChallengeStage;
	
protected:

	
	virtual void PathComplete();
	
	virtual Vector2 FlyInTargetPosition();
	virtual void FlyInComplete();
	
	virtual Vector2 FormationPosition() = 0;
	
	virtual void HandleFlyInState();
	virtual void HandleFormationState();
	virtual void HandleDiveState() = 0;
	virtual void HandleDeadState() = 0;
	
	void HandleStates();

	
	
public:
	
	static void SetFormation(Formation* f);
	
	static void CreatePaths();
	
	Enemy(int index, int path, bool challengeStage);
	virtual ~Enemy();
	
	STATES CurrentState();
	
	void Update();
	
	void Render();
	
	
	
};




#endif /* Enemy_h */
