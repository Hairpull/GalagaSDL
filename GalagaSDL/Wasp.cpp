#include "Wasp.h"


Wasp::Wasp(int index, int path, bool challengeStage, bool diver)
	: Enemy(index, path, challengeStage)
{
	if(!challengeStage) {
		
		mTargetPosition = FormationPosition();
		
	}
	
	mDiver = diver;
	
	mTextures[0] = new Texture("wasp1.png");
	mTextures[0]->Parent(this);
	mTextures[0]->Pos(VEC2_ZERO);

	mTextures[1] = new Texture("wasp2.png");
	mTextures[1]->Parent(this);
	mTextures[1]->Pos(VEC2_ZERO);
	
}

Wasp::~Wasp() {
	
	
}


Vector2 Wasp::FlyInTargetPosition() {
	
	
	
	if(mDiver)
		return mTargetPosition;
	else
		return Enemy::FlyInTargetPosition();
	
}

void Wasp::PathComplete() {
	
	if(mDiver) {
		mTargetPosition = VEC2_ZERO;
		
	} else Enemy::PathComplete();
	
}

void Wasp::FlyInComplete() {
	
	if(mDiver)
		mCurrentState = dead;
	else
		Enemy::FlyInComplete();
	
}


Vector2 Wasp::FormationPosition() {
	
	Vector2 retVal;
	
	retVal.x = (sFormation->GridSize().x + sFormation->GridSize().x * 2 * (mIndex / 4)) * pow(-1, mIndex % 2 +1);
	retVal.y = sFormation->GridSize().y * 2 + sFormation->GridSize().y * ((mIndex % 4) / 2 );
	
	return retVal;
	
}

void Wasp::HandleDiveState() {
	
	
	
}


void Wasp::HandleDeadState() {
	
	
	
}
