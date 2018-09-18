//----------------------------------------------------//
// Timer.cpp                                          //
// Singleton                                          //
// Used to keep track of the time between each reset  //
// A reset is usually called after each frame         //
//                                                    //
// By: Ather Omar                                     //
//----------------------------------------------------//
#include "Timer.h"
//--------------------------------------------------------
// QuickSDL
//--------------------------------------------------------
namespace QuickSDL {
	//Initializing sInstance to NULL
	Timer* Timer::sInstance = NULL;

	Timer* Timer::Instance() {

		//Create a new instance of Timer if no instance was created before
		if(sInstance == NULL)
			sInstance = new Timer();

		return sInstance;
	}

	void Timer::Release() {

		delete sInstance;
		sInstance = NULL;
	}

	Timer::Timer() {

		//Using Reset to initialize all the values beside mTimeScale
		Reset();
		mTimeScale = 1.0f;
	}

	Timer::~Timer() {

	}

	void Timer::Reset() {

		mStartTicks = SDL_GetTicks();
		mElapsedTicks = 0;
		mDelataTime = 0.0f;
	}

	float Timer::DeltaTime() {

		return mDelataTime;
	}

	void Timer::TimeScale(float t) {

		mTimeScale = t;
	}

	float Timer::TimeScale() {

		return mTimeScale;
	}

	void Timer::Update() {

		mElapsedTicks = SDL_GetTicks() - mStartTicks;
		//Converting milliseconds to seconds
		mDelataTime = mElapsedTicks * 0.001f;
	}
}