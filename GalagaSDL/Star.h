#ifndef Star_h
#define Star_h
#include "Timer.h"
#include "Texture.h"

using namespace QuickSDL;


class Star : public Texture {
	
private:
	
	
	static bool sScroll;
	
	Timer* mTimer;
	
	
	bool mVisible;
	float mFlickerTimer;
	float mFlickerSpeed;
	
	Vector2 StarPos;

	
	float mScrollSpeed;
	
public:
	static void Scroll(bool b);
	
	Star(int layer);
	~Star();
	
	void Update();
	void Render();
	
	
private:
	void ScrollStar();
	
	
};





#endif /* Star_h */
