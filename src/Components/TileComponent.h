//
// Created by Jedrzej Lewandowski on 04/11/2019.
//

#ifndef INC_2DGAMEENGINE_TILECOMPONENT_H
#define INC_2DGAMEENGINE_TILECOMPONENT_H

#include <SDL.h>
#include "../Game.h"
#include "../EntityManager.h"
#include "../AssetManager.h"
#include "../../lib/glm/glm.hpp"

class TileComponent: public Component {
public:
    SDL_Texture *texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    glm::vec2 position;

    TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureId) {
        texture = Game::assetManager->GetTexture(assetTextureId);

        sourceRectangle.x = sourceRectX;
        sourceRectangle.y = sourceRectY;
        sourceRectangle.h = tileScale;
        sourceRectangle.w = tileScale;

        destinationRectangle.x = x;
        destinationRectangle.y = y;
        destinationRectangle.w = tileScale * tileSize;
        destinationRectangle.h = tileScale * tileSize;

        position.x = x;
        position.y = y;
    }

    virtual ~TileComponent() {
        SDL_DestroyTexture(texture);
    }

    void Update(float deltaTime) override {

    }

    void Render() override {
        TextureManager::Draw(texture, sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
    }
};


#endif //INC_2DGAMEENGINE_TILECOMPONENT_H