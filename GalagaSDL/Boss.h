#ifndef Boss_h
#define Boss_h


#include "Enemy.h"

class Boss : public Enemy {

	
	
private:
	
	
	Vector2 FormationPosition();
	
	void HandleDiveState();
	void HandleDeadState();
	
	
	
	
public:
	
	Boss(int index, int path, bool challengeStage);
	
	~Boss();
	
	
	
	
	
};

#endif /* Boss_h */
