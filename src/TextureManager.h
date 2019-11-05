//
// Created by Jedrzej Lewandowski on 30/10/2019.
//

#ifndef INC_2DGAMEENGINE_TEXTUREMANAGER_H
#define INC_2DGAMEENGINE_TEXTUREMANAGER_H

#include "./Game.h"

class TextureManager {
public:
  static SDL_Texture *LoadTexture(const char *fileName);

  static void Draw(SDL_Texture *texture, SDL_Rect sourceRectangle,
                   SDL_Rect destinationRectangle, SDL_RendererFlip flip);
};

#endif // INC_2DGAMEENGINE_TEXTUREMANAGER_H
