#include "Butterfly.h"

Butterfly::Butterfly(int index, int path, bool challengeStage)
: Enemy(index, path, challengeStage)

{

	
	mTextures[0] = new Texture("butterfly1.png");
	mTextures[0]->Parent(this);
	mTextures[0]->Pos(VEC2_ZERO);
	
	mTextures[1] = new Texture("butterfly2.png");
	mTextures[1]->Parent(this);
	mTextures[1]->Pos(VEC2_ZERO);
	
	mType = butterfly;

}


Butterfly::~Butterfly() {
	
	
	
}


Vector2 Butterfly::LocalFormationPosition() {
	
	Vector2 retVal;
	
	retVal.x = (sFormation->GridSize().x + sFormation->GridSize().x * 2 * (mIndex / 4)) * pow(-1, mIndex % 2 +1);
	retVal.y = sFormation->GridSize().y * ((mIndex % 4) / 2 );
	
	return retVal;
}

void Butterfly::HandleDiveState() {
	
	
}

void Butterfly::HandleDeadState() {
	
	
}

void Butterfly::RenderDiveState() {
	
	
}

void Butterfly::RenderDeadState() {
	
	
}
