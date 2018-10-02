#include "Formation.h"


Formation::Formation () {
	
	mTimer = Timer::Instance();
	
	mOffsetAmount = 10.0f;
	mOffsetDelay = 0.4f;
	mOffsetTimer = 0.0f;
	mOffsetCounter = 4;
	mOffsetDirection = 1;
	
	mSpreadTimer = 0.0f;
	mSpreadDelay = 0.6f;
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

int Formation::GetTick() {
	
	 if(!mLocked || mOffsetCounter != 4)
		 return mOffsetCounter;
	else
		return mSpreadCounter;
	
}


void Formation::Lock() {
	
	mLocked = true;
}

bool Formation::Locked() {
	
	return mLocked && mOffsetCounter == 4;
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
		
		}  else {
			
			mSpreadTimer += mTimer->DeltaTime();
			if(mSpreadTimer >= mSpreadDelay) {
				
				mSpreadCounter += mSpreadDirection;
				
				mGridSize.x += (mSpreadDirection * ((mSpreadCounter % 2 == 0) ? 1 : 2));
				
				if(mSpreadCounter == 4 || mSpreadCounter == 0) {
					
					mSpreadDirection *= -1;
				}
				
				mSpreadTimer = 0.0f;
			}
			
		}
	}

