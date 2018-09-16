#ifndef AssetManager_h
#define AssetManager_h
#include "Graphics.h"
#include <map>


class AssetManager {

private:
	
	static AssetManager* sInstance;
	
	std::map<std::string, SDL_Texture*> mTextures;
	
	
public:
	
	
	static AssetManager* Instance();
	static void Release();
	
	SDL_Texture* GetTexture(std::string filename);
	
	
private:
	
	AssetManager();
	~AssetManager();
	
};



#endif /* AssetManager_h */
