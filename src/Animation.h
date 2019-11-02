//
// Created by Jedrzej Lewandowski on 02/11/2019.
//

#ifndef INC_2DGAMEENGINE_ANIMATION_H
#define INC_2DGAMEENGINE_ANIMATION_H


class Animation {
public:
    unsigned int index;
    unsigned int numFrames;
    unsigned int animationSpeed;
    Animation();

    Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed);
};


#endif //INC_2DGAMEENGINE_ANIMATION_H
