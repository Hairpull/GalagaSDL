#ifndef AssetManager_h
#define AssetManager_h
#include "Graphics.h"
#include <map>


class AssetManager {

private:
	
	static AssetManager* sInstance;
	
	std::map<std::string, SDL_Texture*> mTextures;
	std::map<std::string, SDL_Texture*> mText;
	std::map<std::string, TTF_Font*> mFonts;
	
	
public:
	
	
	static AssetManager* Instance();
	static void Release();
	
	SDL_Texture* GetTexture(std::string filename);
	SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);
	
	
private:
	
	AssetManager();
	~AssetManager();
	
	TTF_Font* GetFont(std::string filename, int size);
	
};



#endif /* AssetManager_h */
