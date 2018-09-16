#include "AssetManager.h"

AssetManager* AssetManager::sInstance = NULL;

AssetManager* AssetManager::Instance() {
	if(sInstance == NULL)
		sInstance = new AssetManager();
	
	return sInstance;
}

void AssetManager::Release() {
	delete sInstance;
	sInstance = NULL;
	
}

AssetManager::AssetManager() {
	
}

AssetManager::~AssetManager() {
	
	for (auto tex : mTextures) {
		
		if(tex.second != NULL) {
			
			SDL_DestroyTexture(tex.second);
		}
	}
	mTextures.clear();
}

SDL_Texture* AssetManager::GetTexture(std::string filename) {
	
	std::string fullpath = SDL_GetBasePath();
	fullpath.append(filename);
	
	if(mTextures[fullpath] ==  nullptr)
		mTextures[fullpath] = Graphics::Instance()->LoadTexture(fullpath);
	
	return mTextures[fullpath];

}
