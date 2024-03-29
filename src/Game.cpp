#include "./Game.h"
#include "./AssetManager.h"
#include "./Components/KeyboardControlComponent.h"
#include "./Components/SpriteComponent.h"
#include "./Components/TileComponent.h"
#include "./Components/TransformComponent.h"
#include "./Constants.h"
#include "./Entity.h"
#include "./EntityManager.h"
#include "./FontManager.h"
#include "Components/ColliderComponent.h"
#include "Components/ProjectileEmitterComponent.h"
#include "Components/TextLabelComponent.h"
#include "Map.h"
#include <iostream>

EntityManager manager;
AssetManager *Game::assetManager = new AssetManager(&manager);
SDL_Renderer *Game::renderer;
SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
Map *map;

Game::Game() { this->isRunning = false; }

Game::~Game() {}

bool Game::IsRunning() const { return this->isRunning; }

void Game::Initialize(int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }
  if (TTF_Init() != 0) {
    std::cerr << "Error initializing TTF." << std::endl;
    return;
  }
  window =
      SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       width, height, SDL_WINDOW_BORDERLESS);
  if (!window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }

  LoadLevel(0);

  isRunning = true;
}

Entity &player(manager.AddEntity("chopper", PLAYER_LAYER));

void Game::LoadLevel(int levelNumber) {
  sol::state lua;
  lua.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);

  std::string levelName = "Level" + std::to_string(levelNumber);
  lua.script_file("./assets/scripts/" + levelName + ".lua");

  sol::table levelData = lua[levelName];
  sol::table levelAssets = levelData["assets"];

  /*********************************************/
  /* LOADS ASSETS FROM LUA CONFIG FILE         */
  /*********************************************/
  unsigned int assetIndex = 0;

  while (true) {
    sol::optional<sol::table> existsAssetIndexNode = levelAssets[assetIndex];

    if (existsAssetIndexNode == sol::nullopt) {
      break;
    } else {
      sol::table asset = levelAssets[assetIndex];
      std::string assetType = asset["type"];

      if (assetType == "texture") {
        std::string assetId = asset["id"];
        std::string assetFile = asset["file"];
        assetManager->AddTexture(assetId, assetFile.c_str());
      }
    }
    assetIndex++;
  }

  /*********************************************/
  /* LOADS MAP FROM LUA CONFIG FILE            */
  /*********************************************/
  sol::table levelMap = levelData["map"];
  std::string mapTextureId = levelMap["textureAssetId"];
  std::string mapFile = levelMap["file"];

  map = new Map(
      mapTextureId,
      static_cast<int>(levelMap["scale"]),
      static_cast<int>(levelMap["tileSize"])
  );

  map->LoadMap(
      mapFile,
      static_cast<int>(levelMap["mapSizeX"]),
      static_cast<int>(levelMap["mapSizeY"])
  );
}

void Game::ProcessInput() {
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT: {
    isRunning = false;
    break;
  }
  case SDL_KEYDOWN: {
    if (event.key.keysym.sym == SDLK_ESCAPE) {
      isRunning = false;
    }
  }
  default: {
    break;
  }
  }
}

void Game::Update() {
  // Wait until 16ms has ellapsed since the last frame
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME))
    ;

  // Delta time is the difference in ticks from last frame converted to secomds
  float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

  // Clamp deltaTime to a maximum value
  deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

  // Sets the new ticks for the current frame to be used in the next pass
  ticksLastFrame = SDL_GetTicks();

  manager.Update(deltaTime);

  HandleCameraMovement();
  CheckCollisions();
}

void Game::Render() {
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);

  if (manager.HasNoEntities()) {
    return;
  }

  manager.Render();

  SDL_RenderPresent(renderer);
}

void Game::Destroy() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::HandleCameraMovement() {
  auto *mainPlayerTransform = player.GetComponent<TransformComponent>();
  camera.x = mainPlayerTransform->position.x - (WINDOW_WIDTH / 2);
  camera.y = mainPlayerTransform->position.y - (WINDOW_HEIGHT / 2);

  camera.x = camera.x < 0 ? 0 : camera.x;
  camera.y = camera.y < 0 ? 0 : camera.y;
  camera.x = camera.x > camera.w ? camera.w : camera.x;
  camera.y = camera.y > camera.h ? camera.h : camera.y;
}
void Game::CheckCollisions() {
  CollisionType collisionType = manager.CheckCollisions();
  if (collisionType == PLAYER_ENEMY_COLLISION) {
    ProcessGameOver();
  }
  if (collisionType == PLAYER_PROJECTILE_COLLISION) {
    ProcessGameOver();
  }
  if (collisionType == PLAYER_LEVEL_COMPLETE_COLLISION) {
    ProcessNextLevel(1);
  }
}

void Game::ProcessGameOver() {
  std::cout << "Game Over" << std::endl;
  isRunning = false;
}

void Game::ProcessNextLevel(int levelNumber) {
  std::cout << "Next Level" << std::to_string(levelNumber) << std::endl;
  isRunning = false;
}