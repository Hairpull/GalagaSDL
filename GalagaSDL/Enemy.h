#ifndef Enemy_h
#define Enemy_h
#include "Animatedtexture.h"
#include "BezierPath.h"

class Enemy : public GameEntity {
	
	
	
	
private:
	
	static std::vector<std::vector<Vector2>> sPaths;
	
	enum STATES { flyIn, formation, dive, dead };
	
	Timer* mTimer;
	
	Texture* mTexture;
	
	STATES mCurrentState;
	
	int mCurrentPath;
	
	int mCurrentWaypoint;
	
		// Ather has his EPSILON set to 5.0f, but my enemies jitter like crazy with a setting below 15.0f. Not sure why, but this is a difference between our source files.
	const float EPSILON = 15.0f;
	
	float mSpeed;
	
public:
	
	static void CreatePaths();
	
	Enemy(int path);
	virtual ~Enemy();
	
	virtual void HandleFlyInState();
	virtual void HandleFormationState();
	virtual void HandleDiveState();
	virtual void HandleDeadState();
	
	void HandleStates();
	
	void Update();
	
	void Render();
	
	
	
};




#endif /* Enemy_h */
