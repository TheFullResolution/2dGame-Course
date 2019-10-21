#include <iostream>
#include "./Constants.h"
#include "./Game.h"

int main(int argc, char *args[]) {
  Game *game = new Game();

  game->initialize(WINDOW_WIDTH, WINDOW_HEIGHT);
   
  std::cout << "Game is running" << std::endl;

  while (game->IsRunning())
  {
    game -> ProcessInput();
    game -> Update();
    game -> Render();
  }
  
  game -> Destroy();


  return 0;
}  