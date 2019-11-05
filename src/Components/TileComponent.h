//
// Created by Jedrzej Lewandowski on 04/11/2019.
//

#ifndef INC_2DGAMEENGINE_TILECOMPONENT_H
#define INC_2DGAMEENGINE_TILECOMPONENT_H

#include "../../lib/glm/glm.hpp"
#include "../AssetManager.h"
#include "../EntityManager.h"
#include "../Game.h"
#include <SDL.h>

class TileComponent : public Component {
public:
  SDL_Texture *texture;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;
  glm::vec2 position;

  TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize,
                int tileScale, std::string assetTextureId) {
    texture = Game::assetManager->GetTexture(assetTextureId);

    sourceRectangle.x = sourceRectX;
    sourceRectangle.y = sourceRectY;
    sourceRectangle.h = tileSize;
    sourceRectangle.w = tileSize;

    destinationRectangle.x = x;
    destinationRectangle.y = y;
    destinationRectangle.w = tileScale * tileSize;
    destinationRectangle.h = tileScale * tileSize;

    position.x = x;
    position.y = y;
  }

  virtual ~TileComponent() { SDL_DestroyTexture(texture); }

  void Update(float deltaTime) override {
    destinationRectangle.x = position.x - Game::camera.x;
    destinationRectangle.y = position.y - Game::camera.y;
  }

  void Render() override {
    TextureManager::Draw(texture, sourceRectangle, destinationRectangle,
                         SDL_FLIP_NONE);
  }
};

#endif // INC_2DGAMEENGINE_TILECOMPONENT_H
