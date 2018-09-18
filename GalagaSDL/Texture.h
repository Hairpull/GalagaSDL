//-----------------------------------------------------------------//
// Texture.h                                                       //
// The base class for all textures to be rendered on screen        //
// Can load full textures, or clipped textures from a spritesheet  //
// or convert a string into a texture to be rendered               //
//                                                                 //
// By: Ather Omar                                                  //
//-----------------------------------------------------------------//
#ifndef _TEXTURE_H
#define _TEXTURE_H
//---------------------------------------------------------------
#include "GameEntity.h"
#include "AssetManager.h"
//---------------------------------------------------------------
// QuickSDL
//---------------------------------------------------------------
namespace QuickSDL {
	//-----------------------------------------------------------
	// Texture : public GameEntity
	//-----------------------------------------------------------
	class Texture : public GameEntity {

	protected:

		//The SDL_Texture to be rendered
		SDL_Texture* mTex;

		//Used to render the texture
		Graphics* mGraphics;

		//Width of the texture
		int mWidth;
		//Height of the texture
		int mHeight;

		//True if the texture is loaded from a spritesheet
		bool mClipped;

		//Is used to render the texture on the screen
		SDL_Rect mRenderRect;
		//Is used to clip the texture from a spritesheet
		SDL_Rect mClipRect;

	public:
		//--------------------------------------------------------------
		//Loads a whole texture from a file (relative to the exe path)
		//Note: For spritesheets use the other contructor
		//--------------------------------------------------------------
		Texture(std::string filename);
		//-------------------------------------------------------------
		//Loads a texture from from file (relative to the exe path)
		//Supports spritesheets
		//x - Starting pixel's X on the spritesheet
		//y - Starting pixel's Y on the spritesheet
		//w - The width of the clipped sprite
		//h - The height of the clipped sprite
		//-------------------------------------------------------------
		Texture(std::string filename, int x, int y, int w, int h);
		//------------------------------------------------------------
		//Converts the given text into a texture to be rendered
		//Note: fontpath is relative to the exe path
		//size - The size of the text to be rendered
		//color - The color of the text to be rendered
		//------------------------------------------------------------
		Texture(std::string text, std::string fontpath, int size, SDL_Color color);
		~Texture();

		//----------------------------------------------
		//Called to render the texture to the screen
		//----------------------------------------------
		virtual void Render();
	};
}
#endif
