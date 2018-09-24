#include "Formation.h"


Formation::Formation () {
	
	mTimer = Timer::Instance();
	
	mOffsetAmount = 10.0f;
	mOffsetDelay = 0.4f;
	mOffsetTimer = 0.0f;
	mOffsetCounter = 4;
	mOffsetDirection = 1;
	
	mSpreadTimer = 0.0f;
	mSpreadDelay = 1.0f;
	mSpreadCounter = 0;
	mSpreadDirection = 1;
	
	mLocked = false;
	
	mGridSize = Vector2(32.0f, 64.0f);
	
	
	
}

Formation::~Formation() {
	
	
	mTimer = NULL;
}


Vector2 Formation::GridSize() {
	return mGridSize;
}

void Formation::Lock() {
	
	mLocked = true;
}


void Formation::Update() {
	
	
	
	if(!mLocked || mOffsetCounter != 4) {
		
		mOffsetTimer += mTimer->DeltaTime();
		if(mOffsetTimer >= mOffsetDelay) {
			
			mOffsetCounter++;
			Translate(VEC2_RIGHT * mOffsetDirection * mOffsetAmount, world);
			
			if(mOffsetCounter == 8) {
				
				mOffsetCounter = 0;
				mOffsetDirection *= -1;
				
			}
			
			mOffsetTimer = 0.0f;
			
		}
	}
}
