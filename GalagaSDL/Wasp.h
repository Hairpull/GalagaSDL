#ifndef Wasp_h
#define Wasp_h
#include "Enemy.h"

class Wasp : public Enemy {
	
private:
	
	static std::vector<std::vector<Vector2>> sDivePaths;
	
	bool mDiver;
	
	
	
private:
	
	
	void PathComplete();
	void FlyInComplete();
	
	Vector2 LocalFormationPosition();
	
	void HandleDiveState();
	void HandleDeadState();
	
	void RenderDiveState();
	void RenderDeadState();
	
	
	
public:
	
	static void CreateDivePaths();
	
	
	Wasp(int index, int path, bool challengeStage, bool diver);
	~Wasp();
	
	
	
	
	
};





#endif /* Wasp_h */
