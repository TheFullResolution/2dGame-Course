//
// Created by Jedrzej Lewandowski on 07/11/2019.
//

#ifndef INC_2DGAMEENGINE_TEXTLABELCOMPONENT_H
#define INC_2DGAMEENGINE_TEXTLABELCOMPONENT_H

#include "../AssetManager.h"
#include "../Component.h"
#include "../FontManager.h"
#include "../Game.h"
#include <SDL_rect.h>
#include <SDL_ttf.h>
#include <string>
class TextLabelComponent : public Component {
private:
  SDL_Rect position;
  std::string text;
  std::string fontFamily;
  SDL_Color color;
  SDL_Texture *texture;

public:
  TextLabelComponent(int x, int y, const std::string text,
                     const std::string fontFamily, const SDL_Color &color)
      : text(text), fontFamily(fontFamily), color(color) {
    this->position.x = x;
    this->position.y = y;
    this->text = text;
    this->fontFamily = fontFamily;
    this->color = color;
    SetLabelText(text, fontFamily);
  }

  void SetLabelText(std::string text, const std::string fontFamily) {
    SDL_Surface *surface = TTF_RenderText_Blended(
        Game::assetManager->GetFont(fontFamily), text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
  };

  void Render() override { FontManager::Draw(texture, position); }
};

#endif // INC_2DGAMEENGINE_TEXTLABELCOMPONENT_H
