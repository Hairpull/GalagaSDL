#ifndef Timer_h
#define Timer_h
#include "SDL2/SDL.h"



class Timer {
	
private:
	
	static Timer* sInstance;
	
	unsigned int mStartTicks;
	unsigned int mElapsedTicks;
	float mDeltaTime;
	float mTimeScale;
	
	
	
	
public:
	
	static Timer* Instance();
	static void Release();
	
	void Reset();
	float DeltaTime();
	
	void TimeScale(float t);
	float TimeScale();
	
	void Update();
	
private:
	
	Timer();
	~Timer();
	
	
};



#endif /* Timer_h */
