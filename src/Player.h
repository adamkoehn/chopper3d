#ifndef SRC_PLAYER
#define SRC_PLAYER

#include <iostream>

#include "Controller.h"
#include "Doodle.h"

class Player
{
public:
    Player(Doodle &doodle, float speed);
    void AttachController(Controller *controller);
    void Update();

private:
    Doodle &_doodle;
    float _speed;
    Controller *_controller;
};

#endif /* SRC_PLAYER */
