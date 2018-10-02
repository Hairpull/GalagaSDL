#ifndef Enemy_h
#define Enemy_h
#include "Animatedtexture.h"
#include "BezierPath.h"
#include "Formation.h"

class Enemy : public GameEntity {
	
public:
	
	enum STATES { flyIn, formation, dive, dead };
	enum TYPES { butterfly, wasp, boss };
	
	
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
	
	TYPES mType;
	
	int mIndex;
	
	bool mChallengeStage;
	
	Vector2 mDiveStartPosition;
	
protected:

	
	virtual void PathComplete();
	
	virtual void FlyInComplete();
	
	
	void JoinFormation();
	virtual Vector2 WorldFormationPosition();
	virtual Vector2 LocalFormationPosition() = 0;
	
	virtual void HandleFlyInState();
	virtual void HandleFormationState();
	virtual void HandleDiveState() = 0;
	virtual void HandleDeadState() = 0;
	
	void HandleStates();

	
	virtual void RenderFlyInState();
	virtual void RenderFormationState();
	virtual void RenderDiveState() = 0;
	virtual void RenderDeadState() = 0;
	
	void RenderStates();
	
	
public:
	
	static void SetFormation(Formation* f);
	
	static void CreatePaths();
	
	Enemy(int index, int path, bool challengeStage);
	virtual ~Enemy();
	
	STATES CurrentState();
	
	TYPES Type();
	
	void Dive();
	
	void Update();
	
	void Render();
	
	
	
};




#endif /* Enemy_h */
