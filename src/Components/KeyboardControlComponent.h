//
// Created by Jedrzej Lewandowski on 02/11/2019.
//

#ifndef INC_2DGAMEENGINE_KEYBOARDCONTROLCOMPONENT_H
#define INC_2DGAMEENGINE_KEYBOARDCONTROLCOMPONENT_H

#include "../Components/SpriteComponent.h"
#include "../Components/TransformComponent.h"
#include "../EntityManager.h"
#include "../Game.h"

class KeyboardControlComponent : public Component {
public:
  std::string upKey;
  std::string downKey;
  std::string rightKey;
  std::string leftKey;
  std::string shootKey;

  TransformComponent *transform;
  SpriteComponent *sprite;

  KeyboardControlComponent() {}

  KeyboardControlComponent(std::string upKey, std::string downKey,
                           std::string rightKey, std::string leftKey,
                           std::string shootKey) {
    this->upKey = GetSDLKeyStringCode(upKey);
    this->downKey = GetSDLKeyStringCode(downKey);
    this->rightKey = GetSDLKeyStringCode(rightKey);
    this->leftKey = GetSDLKeyStringCode(leftKey);
    this->shootKey = GetSDLKeyStringCode(shootKey);
  }

  std::string GetSDLKeyStringCode(std::string key) {
    if (key == "up")
      return "1073741906";
    if (key == "right")
      return "1073741905";
    if (key == "left")
      return "1073741904";
    if (key == "down")
      return "1073741903";
    if (key == "space")
      return "32";
    return std::to_string(static_cast<int>(key[0]));
  }

  void Initialize() override {
    transform = owner->GetComponent<TransformComponent>();
    sprite = owner->GetComponent<SpriteComponent>();
  }

  void Update(float deltaTime) override {
    if (Game::event.type == SDL_KEYDOWN) {
      std::string keyCode = std::to_string(Game::event.key.keysym.sym);

      if (keyCode == upKey) {
        transform->velocity.y = -10;
        transform->velocity.x = 0;
        sprite->Play("UpAnimation");
      }

      if (keyCode == rightKey) {
        transform->velocity.y = 0;
        transform->velocity.x = 10;
        sprite->Play("RightAnimation");
      }

      if (keyCode == downKey) {
        transform->velocity.y = 10;
        transform->velocity.x = 0;
        sprite->Play("DownAnimation");
      }

      if (keyCode == leftKey) {
        transform->velocity.y = 0;
        transform->velocity.x = -10;
        sprite->Play("LeftAnimation");
      }

      if (keyCode == shootKey) {
      }
    }
    if (Game::event.type == SDL_KEYUP) {
      std::string keyCode = std::to_string(Game::event.key.keysym.sym);
      if (keyCode.compare(upKey) == 0) {
        transform->velocity.y = 0;
      }

      if (keyCode.compare(rightKey) == 0) {
        transform->velocity.x = 0;
      }

      if (keyCode.compare(downKey) == 0) {
        transform->velocity.y = 0;
      }

      if (keyCode.compare(leftKey) == 0) {
        transform->velocity.x = 0;
      }
    }
  }
};

#endif // INC_2DGAMEENGINE_KEYBOARDCONTROLCOMPONENT_H
