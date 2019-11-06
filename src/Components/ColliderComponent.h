//
// Created by Jedrzej Lewandowski on 06/11/2019.
//

#ifndef INC_2DGAMEENGINE_COLLIDERCOMPONENT_H
#define INC_2DGAMEENGINE_COLLIDERCOMPONENT_H

#include "../EntityManager.h"
#include "../Game.h"
#include "TransformComponent.h"
#include <SDL_rect.h>

class ColliderComponent : public Component {
public:
  std::string colliderTag;
  SDL_Rect collider;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;
  TransformComponent *transform;

  ColliderComponent(std::string colliderTag, int x, int y, int width,
                    int height) {
    this->colliderTag = colliderTag;
    this->collider = {x, y, width, height};
  }

  void Initialize() override {
    if (owner->HasComponent<TransformComponent>()) {
      transform = owner->GetComponent<TransformComponent>();
      sourceRectangle = {0, 0, transform->width, transform->height};
      destinationRectangle = {collider.x, collider.y, collider.w, collider.h};
    }
  }

  void Update(float deltatime) override {
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);

    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;

    destinationRectangle.x = collider.x - Game::camera.x;
    destinationRectangle.y = collider.y - Game::camera.y;
  }
};

#endif // INC_2DGAMEENGINE_COLLIDERCOMPONENT_H
