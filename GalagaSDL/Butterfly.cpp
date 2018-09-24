#include "Butterfly.h"

Butterfly::Butterfly(int index, int path, bool challengeStage)
: Enemy(index, path, challengeStage)

{
	if(!challengeStage) {
		
		mTargetPosition = FormationPosition();
	}
	
	mTexture = new Texture("butterfly.png");
	mTexture->Parent(this);
	mTexture->Pos(VEC2_ZERO);
	
}


Butterfly::~Butterfly() {
	
	
	
}


Vector2 Butterfly::FormationPosition() {
	
	Vector2 retVal;
	
	retVal.x = (sFormation->GridSize().x + sFormation->GridSize().x * 2 * (mIndex / 4)) * pow(-1, mIndex % 2 +1);
	retVal.y = sFormation->GridSize().y * ((mIndex % 4) / 2 );
	
	return retVal;
}

void Butterfly::HandleDiveState() {
	
	
}

void Butterfly::HandleDeadState() {
	
	
}
