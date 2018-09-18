//-----------------------------------------------------------------//
// AnimatedTexture.h                                               //
// Extends the Texture class' functionality to handle animations   //
// Uses the Texture class' spritesheet constructor                 //
//                                                                 //
// By: Ather Omar                                                  //
//-----------------------------------------------------------------//
#ifndef _ANIMATEDTEXTURE_H
#define _ANIMATEDTEXTURE_H
//--------------------------------------------------------------
#include "Timer.h"
#include "Texture.h"
//--------------------------------------------------------------
// QuickSDL
//--------------------------------------------------------------
namespace QuickSDL {
	//----------------------------------------------------------
	// AnimatedTexture : public Texture
	//----------------------------------------------------------
	class AnimatedTexture : public Texture {

	public:
		//---------------------------------------------------------
		//WRAP_MODE enum - wrap mode used by the animation
		//once / loop 
		//---------------------------------------------------------
		enum WRAP_MODE { once = 0, loop = 1 };
		//-----------------------------------------------------------------------------------
		//ANIM_DIR enum - The way the animation sprites are arranged in the spritesheet
		//horizontal / vertical
		//------------------------------------------------------------------------------------
		enum ANIM_DIR { horizontal = 0, vertical = 1 };

	private:

		//Used to get the deltatime to update the animation
		Timer* mTimer;

		//the first frame's starting pixel's X values on the spritesheet
		int mStartX;
		//the first frame's starting pixel's Y values on the spritesheet
		int mStartY;

		//Used to keep track of how long the current animation frame has been on screen
		float mAnimationTimer;
		//Used to determine the speed of the animation
		float mAnimationSpeed;
		//Stores how long each animation frame should be on screen
		float mTimePerFrame;

		//Stores the number of animation frames in the animation
		int mFrameCount;

		//Stores the wrap mode
		WRAP_MODE mWrapMode;
		//Stores the animation direction
		ANIM_DIR mAnimationDirection;

		//Is set to true only if the wrap mode is once and the last frame of the animation is reached
		bool mAnimationDone;

	public:
		//---------------------------------------------------------------------------------
		//Loads a texture from from file (relative to the exe path)
		//Supports spritesheets
		//x - Starting pixel's X on the spritesheet
		//y - Starting pixel's Y on the spritesheet
		//w - The width of the clipped sprite
		//h - The height of the clipped sprite
		//frameCount - The number of frames in the animation
		//animationSpeed - How long it takes to run the animation in seconds
		//animationDirection - How the animation sprites are arranges in the spritesheet
		//---------------------------------------------------------------------------------
		AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir);
		~AnimatedTexture();

		//---------------------------------------
		//Sets the wrap mode of the animation
		//---------------------------------------
		void WrapMode(WRAP_MODE mode);

		//---------------------------------------------------------------------------
		//Used to update the animation frames and loop the animation if needed
		//---------------------------------------------------------------------------
		void Update();
	};
}
#endif