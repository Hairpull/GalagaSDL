
#include "GameManager.h"

int main(int argc, char* argv[]) {

	GameManager* game = GameManager::Instance();
	
	game->Run();
	
	GameManager::Release();
	game = NULL;
	
		// testing 1 2 3
	
    return 0;
}
