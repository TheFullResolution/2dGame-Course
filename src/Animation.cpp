//
// Created by Jedrzej Lewandowski on 02/11/2019.
//

#include "Animation.h"

Animation::Animation() {

}

Animation::Animation(unsigned int index, unsigned int numFrames, unsigned int animationSpeed) {
    this->index = index;
    this->numFrames = numFrames;
    this->animationSpeed = animationSpeed;
}

