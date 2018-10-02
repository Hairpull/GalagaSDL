#ifndef Boss_h
#define Boss_h


#include "Enemy.h"

class Boss : public Enemy {

	
	
private:
	
	
	Vector2 LocalFormationPosition();
	
	void HandleDiveState();
	void HandleDeadState();
	
	void RenderDiveState();
	void RenderDeadState();
	
	
public:
	
	Boss(int index, int path, bool challengeStage);
	
	~Boss();
	
	
	
	
	
};

#endif /* Boss_h */
