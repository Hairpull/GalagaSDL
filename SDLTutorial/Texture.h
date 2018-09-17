#ifndef Texture_h
#define Texture_h
#include "GameEntity.h"
#include "AssetManager.h"



class Texture : public GameEntity {
	
private:
	
	SDL_Texture* mTex;
	
	Graphics* mGraphics;
	
	int mWidth;
	int mHeight;
	
	bool mClipped;
	SDL_Rect mRenderRect;
	SDL_Rect mClipRect;
	
	
public:
	
	Texture(std::string filename);
	Texture(std::string filename, int x, int y, int w, int h);
	~Texture();
	
	virtual void Render();
	
};



#endif /* Texture_h */
