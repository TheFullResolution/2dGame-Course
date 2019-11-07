//
// Created by Jedrzej Lewandowski on 07/11/2019.
//

#ifndef INC_2DGAMEENGINE_FONTMANAGER_H
#define INC_2DGAMEENGINE_FONTMANAGER_H

#include <SDL_ttf.h>
class FontManager {
public:
  static TTF_Font* LoadFont(const char* fileName, int fontSize);
  static void Draw(SDL_Texture* texture, SDL_Rect position);

};

#endif // INC_2DGAMEENGINE_FONTMANAGER_H
