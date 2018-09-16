#ifndef Texture_h
#define Texture_h
#include "GameEntity.h"
#include "Graphics.h"



class Texture : public GameEntity {
	
private:
	
	SDL_Texture* mTex;
	
	Graphics* mGraphics;
	
public:
	
	Texture(std::string path);
	~Texture();
	
	virtual void Render();
	
};



#endif /* Texture_h */
