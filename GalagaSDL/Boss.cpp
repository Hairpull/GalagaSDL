#include "Boss.h"

Boss::Boss(int index, int path, bool ChallengeStage)
	: Enemy(index, path, ChallengeStage)
{
	if(!ChallengeStage)
		mTargetPosition = FormationPosition();
	
	mTextures[0] = new Texture("boss1.png");
	mTextures[0]->Parent(this);
	mTextures[0]->Pos(VEC2_ZERO);
	
	mTextures[1] = new Texture("boss2.png");
	mTextures[1]->Parent(this);
	mTextures[1]->Pos(VEC2_ZERO);
	
}

Boss::~Boss() {
	
	
	
}

Vector2 Boss::FormationPosition() {
	
	Vector2 retVal;
	
	retVal.x = (sFormation->GridSize().x + sFormation->GridSize().x * 2 * (mIndex / 2)) * pow(-1, mIndex % 2 +1);
	retVal.y = -sFormation->GridSize().y;
	
	return retVal;
	
}


void Boss::HandleDiveState() {
	
	
}

void Boss::HandleDeadState() {
	
	
	
}
