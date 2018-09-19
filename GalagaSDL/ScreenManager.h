#ifndef ScreenManager_h
#define ScreenManager_h
#include "StartScreen.h"

class ScreenManager {
	
	
private:
	
	enum SCREENS { start, play };
	
	static ScreenManager* sInstance;
	
	InputManager* mInput;
	
	BackgroundStars* mBackgroundStars;
	StartScreen* mStartScreen;
	
	SCREENS mCurrentScreen;
	
	
	
public:
	
	
	static ScreenManager* Instance();
	static void Release();
	
	void Update();
	void Render();
	
	
private:
	
	ScreenManager();
	~ScreenManager();
	
	
	
};


#endif /* ScreenManager_h */
