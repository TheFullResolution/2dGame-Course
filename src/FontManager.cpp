//
// Created by Jedrzej Lewandowski on 07/11/2019.
//

#include "FontManager.h"
#include "Game.h"

TTF_Font *FontManager::LoadFont(const char *fileName, int fontSize) {
  return TTF_OpenFont(fileName, fontSize);
}
void FontManager::Draw(SDL_Texture *texture, SDL_Rect position) {
  SDL_RenderCopy(Game::renderer, texture, nullptr, &position);
}
