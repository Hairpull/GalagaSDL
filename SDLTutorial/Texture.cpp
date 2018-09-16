#include "Texture.h"


Texture::Texture(std::string filename) {
	
	mGraphics = Graphics::Instance();
	
	mTex = AssetManager::Instance()->GetTexture(filename);
	
	
	SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

}


Texture::~Texture() {
	
	mTex = NULL;
	mGraphics = NULL;
}

void Texture::Render() {
	
	mGraphics->DrawTexture(mTex);
}
