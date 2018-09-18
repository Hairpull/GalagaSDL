//---------------------------------------------------------------------//
// Graphics.h                                                          //
// Singleton                                                           //
// Handles the initialization of the graphics related SDL libraries    //
// and their release                                                   //
// Also handles texture and text loading                               //
//                                                                     //
// By: Ather Omar                                                      //
//---------------------------------------------------------------------//
#ifndef _GRAPHICS_H
#define _GRAPHICS_H
//-------------------------------------------------------------------
#include <string>
#include <stdio.h>
//-------------------------------------------------------------------
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
//-------------------------------------------------------------------
// QuickSDL
//-------------------------------------------------------------------
namespace QuickSDL {
	//---------------------------------------------------------------
	// Graphics
	//---------------------------------------------------------------
	class Graphics {

	public:

		//The Width of the game's window
		const int SCREEN_WIDTH = 800;
		//The Height of the game's window
		const int SCREEN_HEIGHT = 600;
		//The title of the game's window
		const char* WINDOW_TITLE = "QuickSDL";

	private:
		//Needed to make GameManager a singleton class
		static Graphics* sInstance;
		//Is set to true if all the graphics libraries initialized correctly
		static bool sInitialized;

		//The window created using SDL
		SDL_Window* mWindow;

		//The renderer used to render all textures
		SDL_Renderer* mRenderer;

	public:
		//--------------------------------------------
		//Returns a pointer to the class instance  
		//--------------------------------------------
		static Graphics* Instance();
		//--------------------------------------------------------
		//Releases the class instance and sets it back to NULL 
		//Sets Initialized to false
		//--------------------------------------------------------
		static void Release();
		//--------------------------------------------------------
		//Is true if the SDL libraries initialized correctly
		//--------------------------------------------------------
		static bool Initialized();

		//----------------------------------------------------------------------------------
		//Loads a texture from file using the given path
		//Note: Should only be used by the AssetManager to cache the textures for reuse
		//----------------------------------------------------------------------------------
		SDL_Texture* LoadTexture(std::string path);
		//----------------------------------------------------------------------------------
		//renders a texture from using the given font and text
		//Note: Should only be used by the AssetManager to cache the textures for reuse
		//----------------------------------------------------------------------------------
		SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

		//--------------------------------------------------------
		//Clears all rendered textures from the back buffer
		//usually used at the begining of the frame's render
		//--------------------------------------------------------
		void ClearBackBuffer();

		//------------------------------------------------
		//Draws the given texture to the back buffer
		//------------------------------------------------
		void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);

		//----------------------------------------------------
		//Refreshes the back buffer
		//Usually called at then end of the frame's render
		//----------------------------------------------------
		void Render();

	private:

		//------------------------------------------------------------------------------------------
		//Contructor is private so that Instance() must be used to get an instance when needed  
		//------------------------------------------------------------------------------------------
		Graphics();
		//--------------------------------------------------------------------------------------
		//Destructor is private so that the instance can only be destroyed using Release()  
		//--------------------------------------------------------------------------------------
		~Graphics();

		//------------------------------------------------------------------
		//Used to initialize all the SDL graphic libraries
		//Returns true if all libraries initialized correctly
		//Returns false otherwise to be handled by the GameManager
		//------------------------------------------------------------------
		bool Init();
	};
}
#endif
