#ifndef Wasp_h
#define Wasp_h
#include "Enemy.h"

class Wasp : public Enemy {
	
private:
	bool mDiver;
	
	
	
private:
	
	Vector2 FlyInTargetPosition();
	
	
	void PathComplete();
	void FlyInComplete();
	
	Vector2 FormationPosition();
	
	void HandleDiveState();
	void HandleDeadState();
	
	
public:
	
	Wasp(int index, int path, bool challengeStage, bool diver);
	~Wasp();
	
	
	
	
	
};





#endif /* Wasp_h */
