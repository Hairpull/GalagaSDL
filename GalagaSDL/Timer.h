//----------------------------------------------------//
// Timer.h                                            //
// Singleton                                          //
// Used to keep track of the time between each reset  //
// A reset is usually called after each frame         //
//                                                    //
// By: Ather Omar                                     //
//----------------------------------------------------//
#ifndef _TIMER_H
#define _TIMER_H
//---------------------------------------------------------------------
#include <SDL2/SDL.h>
//---------------------------------------------------------------------
// QuickSDL
//---------------------------------------------------------------------
namespace QuickSDL {
	//-----------------------------------------------------------------
	// Timer
	//-----------------------------------------------------------------
	class Timer {

	private:
		//Needed to make Timer a singleton class
		static Timer* sInstance;

		//Contains the time of the last reset
		unsigned int mStartTicks;
		//Stores the number of milliseconds since the last reset
		unsigned int mElapsedTicks;
		//Stores the time elapsed since the last reset in seconds
		float mDelataTime;
		//Can be used to speed up or slowdown all entities that transform using it
		float mTimeScale;

	public:
		//-----------------------------------------
		//Returns a pointer to the class instance  
		//-----------------------------------------
		static Timer* Instance();
		//-----------------------------------------------------
		//Releases the class instance and sets it back to NULL 
		//-----------------------------------------------------
		static void Release();

		//------------------------------------------------------------------------
		//Resets the time elapsed back to 0, is usually called after each frame
		//so that mDeltaTime is the time elapsed since last frame
		//------------------------------------------------------------------------
		void Reset();

		//-------------------------------------------------------
		//Time elapsed in seconds since the last Reset
		//-------------------------------------------------------
		float DeltaTime();

		//---------------------------------------------------------------
		//Sets the TimeScale default value: 1.0f
		//---------------------------------------------------------------
		void TimeScale(float t = 1.0f);
		//---------------------------------------------------------------
		//Can be used to speed up or slowdown all transformations
		//by multiplying it by the change in position or rotation
		//---------------------------------------------------------------
		float TimeScale();

		//--------------------------------------------------------------------
		//Should be called in the EarlyUpdate, updates the time elapsed,
		//as well as the DeltaTime since the last Reset
		//--------------------------------------------------------------------
		void Update();

	private:

		//------------------------------------------------------------------------------------------
		//Contructor is private so that Instance() must be used to get an instance when needed  
		//------------------------------------------------------------------------------------------
		Timer();
		//--------------------------------------------------------------------------------------
		//Destructor is private so that the instance can only be destroyed using Release()  
		//--------------------------------------------------------------------------------------
		~Timer();
	};
}
#endif
