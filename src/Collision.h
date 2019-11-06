//
// Created by Jedrzej Lewandowski on 06/11/2019.
//

#ifndef INC_2DGAMEENGINE_COLLISION_H
#define INC_2DGAMEENGINE_COLLISION_H

#include <SDL_rect.h>
class Collision {
public:
  static bool CheckRectangleCollision(const SDL_Rect &rectangleA,
                                      const SDL_Rect &rectangleB);
};

#endif // INC_2DGAMEENGINE_COLLISION_H
