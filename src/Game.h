#ifndef GAME_H
#define GAME_H

#include "./Component.h"
#include "../lib/lua/sol.hpp"
#include "./Entity.h"
#include "./EntityManager.h"
#include <SDL.h>

class AssetManager;

class Game {
private:
  bool isRunning;
  SDL_Window *window;


public:
  Game();

  ~Game();

  int ticksLastFrame = 0;

  bool IsRunning() const;

  static SDL_Renderer *renderer;
  static AssetManager *assetManager;
  static SDL_Event event;
  static SDL_Rect camera;

  void LoadLevel(int levelNumber);

  void Initialize(int width, int height);

  void ProcessInput();

  void Update();

  void Render();

  void Destroy();

  void HandleCameraMovement();

  void CheckCollisions();
  void ProcessGameOver();
  void ProcessNextLevel(int levelNumber);
};

#endif
