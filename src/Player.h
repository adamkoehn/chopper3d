#ifndef SRC_PLAYER
#define SRC_PLAYER

#include <iostream>

#include "Controller.h"
#include "Doodle.h"
#include "Queue.h"
#include "commands/Shoot.h"

class Player
{
public:
    Player(Queue &queue, Doodle &doodle, float flightSpeed, float gunFrequency);
    void AttachController(Controller *controller);
    void Update(float deltaTime);

private:
    void updateMove(float deltaTime);
    void updateShooting(float deltaTime);

private:
    Queue &_queue;
    Doodle &_doodle;
    float _flightSpeed;
    float _gunFrequency;
    float _timeUntilNextShot;
    Controller *_controller;
};

#endif /* SRC_PLAYER */
