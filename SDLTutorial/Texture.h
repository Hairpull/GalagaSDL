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
	
public:
	
	Texture(std::string filename);
	~Texture();
	
	virtual void Render();
	
};



#endif /* Texture_h */
