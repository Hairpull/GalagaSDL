#include "Animatedtexture.h"

AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir)
: Texture(filename, x, y, w, h)
{
	mTimer = Timer::Instance();
	
	mStartX = x;
	mStartY = y;
	
	mFrameCount = frameCount;
	mAnimationSpeed = animationSpeed;
	mTimePerframe = mAnimationSpeed / frameCount;
	mAnimationTimer = 0.0f;
	
	mAnimationDirection = animationDir;
	
	mAnimationDone = false;
	
	mWrapMode = loop;
}

AnimatedTexture::~AnimatedTexture () {
	
}

void AnimatedTexture::WrapMode(WRAP_MODE mode) {
	
	mWrapMode = mode;
	
}

void AnimatedTexture::Update() {
	
	if(!mAnimationDone) {
		
		mAnimationTimer += mTimer->DeltaTime();
		
		if(mAnimationTimer >= mAnimationSpeed) {
			
			if (mWrapMode == loop) {
				mAnimationTimer -= mAnimationSpeed;
				
			} else {
				
				mAnimationDone = true;
				mAnimationTimer = mAnimationSpeed - mTimePerframe;
			}
		}
		
		if (mAnimationDirection == horizontal) {
			
			mClipRect.x = mStartX + (int)(mAnimationTimer / mTimePerframe) * mWidth;
		} else {
			
			mClipRect.y = mStartY + (int)(mAnimationTimer / mTimePerframe) * mHeight;
		}
	}
}
