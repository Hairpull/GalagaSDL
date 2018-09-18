#ifndef InputManager_h
#define InputManager_h
#include "SDL2/SDL.h"


class InputManager {
	
private:
	
	static InputManager* sInstance;
	
	const Uint8* mKeyboardStates;
	
public:
	
	static InputManager* Instance();
	static void Release();
	
	bool KeyDown(SDL_Scancode scanCode);
	
	void Update();
	
public:
	InputManager();
	~InputManager();
	
	
	
};




#endif /* InputManager_h */
