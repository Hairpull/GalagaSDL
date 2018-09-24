#ifndef Formation_h
#define Formation_h
#include "GameEntity.h"
#include "Timer.h"

using namespace QuickSDL;


class Formation : public GameEntity {
		
private:
	
	Timer* mTimer;
	
	float mOffsetAmount;
	float mOffsetTimer;
	float mOffsetDelay;
	int mOffsetCounter;
	int mOffsetDirection;
	
	float mSpreadTimer;
	float mSpreadDelay;
	int mSpreadCounter;
	int mSpreadDirection;
	
	
	Vector2 mGridSize;
	
	bool mLocked;
	
	
public:
	
	
	Formation();
	~Formation();
	
	Vector2 GridSize();
	
	void Lock();
	
	void Update();
	
	
	
	
	
	
	
	
	
};




#endif /* Formation_h */
