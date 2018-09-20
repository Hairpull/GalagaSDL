#ifndef Scoreboard_h
#define Scoreboard_h
#include "Texture.h"
#include <vector>


using namespace QuickSDL;


class Scoreboard : public GameEntity {
	
private:
	
	std::vector<Texture*> mScore;
	SDL_Color mColor;
	
public:
	
	Scoreboard();
	Scoreboard(SDL_Color color);
	~Scoreboard();
	
	void Score(int score);
	
	void Render();
	
	
private:
	
	void ClearBoard();
};

#endif /* Scoreboard_h */
