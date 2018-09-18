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
	
	for(auto text : mText) {
		
		if(text.second != NULL) {
			
			SDL_DestroyTexture(text.second);
		}
	}
	
	mText.clear();
	
	for(auto font : mFonts) {
		
		if(font.second != NULL)	{
			
			TTF_CloseFont(font.second);
		}
	}
	
	mFonts.clear();
}

SDL_Texture* AssetManager::GetTexture(std::string filename) {
	
	std::string fullpath = SDL_GetBasePath();
	fullpath.append(filename);
	
	if(mTextures[fullpath] ==  nullptr)
		mTextures[fullpath] = Graphics::Instance()->LoadTexture(fullpath);
   	
	return mTextures[fullpath];
}

TTF_Font* AssetManager::GetFont(std::string filename, int size) {
	
	std::string fullPath = SDL_GetBasePath();
	fullPath.append(filename);
	std::string key = fullPath + (char)size;
	
	if(mFonts[key] == nullptr) {
		
		mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
		if(mFonts[key] == nullptr)
			printf("font loading error: Font -%s Error-%s", filename.c_str(), TTF_GetError());
	}
	
	return mFonts[key];
	
}


SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size, SDL_Color color) {
		
		TTF_Font* font = GetFont(filename, size);
		
		std::string key = text + filename + (char)size + (char)color.r + (char)color.b + (char)color.g;
		
		if(mText[key] == nullptr)
			mText[key] = Graphics::Instance()->CreateTextTexture(font, text, color);
		
		return mText[key];
	
	}

Mix_Music* AssetManager::GetMusic(std::string filename) {
	
	std::string fullPath = SDL_GetBasePath();
	fullPath.append(filename);
	
	if(mMusic[fullPath] == nullptr) {
		
		mMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
		if(mMusic[fullPath] == NULL)
		printf("Music loading error: File-%s Error-%s", filename.c_str(), Mix_GetError());
	}
	
	return mMusic[fullPath];
}


Mix_Chunk* AssetManager::GetSFX(std::string filename) {
	

	std::string fullPath = SDL_GetBasePath();
	fullPath.append(filename);
	
	if(mSFX[fullPath] == nullptr) {
		
		mSFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
		if(mSFX[fullPath] == NULL)
			printf("SFX loading error: File-%s Error-%s", filename.c_str(), Mix_GetError());
	}
	
	return mSFX[fullPath];

	
}



;
