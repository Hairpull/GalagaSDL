//-----------------------------------------------------------------//
// Texture.cpp                                                     //
// Singleton                                                       //
// The base class for all textures to be rendered on screen        //
// Can load full textures, or clipped textures from a spritesheet  //
// or convert a string into a texture to be rendered               //
//                                                                 //
// By: Ather Omar                                                  //
//-----------------------------------------------------------------//
#include "Texture.h"
//--------------------------------------------------------------
// QuickSDL
//--------------------------------------------------------------
namespace QuickSDL {

	Texture::Texture(std::string filename) {

		mGraphics = Graphics::Instance();

		//Loads the texture from the AssetManager to avoid loading textures more than once
		mTex = AssetManager::Instance()->GetTexture(filename);

		//Gets the Width and Height of the texture
		SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

		//Clipped is false since the image is not loaded from a spritesheet
		mClipped = false;

		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;
	}

	Texture::Texture(std::string filename, int x, int y, int w, int h) {

		mGraphics = Graphics::Instance();

		//Loads the texture from the AssetManager to avoid loading textures more than once
		mTex = AssetManager::Instance()->GetTexture(filename);

		//Clipped is true since the image could be loaded from a spritesheet
		mClipped = true;

		mWidth = w;
		mHeight = h;

		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;

		//Setting the clipped rectangle to only get the needed texture from the spritesheet
		mClipRect.x = x;
		mClipRect.y = y;
		mClipRect.w = mWidth;
		mClipRect.h = mHeight;
	}

	Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color color) {

		mGraphics = Graphics::Instance();

		//Loads the texture from the AssetManager to avoid loading textures more than once
		mTex = AssetManager::Instance()->GetText(text, fontPath, size, color);

		//Clipped is false since the image is not loaded from a spritesheet
		mClipped = false;

		//Gets the Width and Height of the texture
		SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;
	}

	Texture::~Texture() {

		mTex = NULL;
		mGraphics = NULL;
	}

	void Texture::Render() {

		Vector2 pos = Pos(world);
		Vector2 scale = Scale(world);

		//Centers the texture on the texture's world position so that its position is not the top left corner
		mRenderRect.x = (int)(pos.x - mWidth*scale.x*0.5f);
		mRenderRect.y = (int)(pos.y - mHeight*scale.y*0.5f);

		//Scales the width and height according to the scale of the GameEntity
		mRenderRect.w = (int)(mWidth * scale.x);
		mRenderRect.h = (int)(mHeight * scale.y);

		mGraphics->DrawTexture(mTex, (mClipped) ? &mClipRect : NULL, &mRenderRect, Rotation(world));
	}
}