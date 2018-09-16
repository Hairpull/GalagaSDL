#include "Texture.h"


Texture::Texture(std::string path) {
	
	mGraphics = Graphics::Instance();
	
	mTex = mGraphics->LoadTexture(path);
	

}


Texture::~Texture() {
	
	SDL_DestroyTexture(mTex);
	mTex = NULL;
	mGraphics = NULL;
}

void Texture::Render() {
	
	mGraphics->DrawTexture(mTex);
}
