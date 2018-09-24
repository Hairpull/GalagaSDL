#ifndef Butterfly_h
#define Butterfly_h
#include "Enemy.h"

class Butterfly : public Enemy {
	
	
private:
	

	Vector2 FormationPosition();
	
	void HandleDiveState();
	void HandleDeadState();
	
	
	

public:
	
	Butterfly(int index, int path, bool challengeStage);
	
	~Butterfly();
	
	
};



#endif /* Butterfly_h */
