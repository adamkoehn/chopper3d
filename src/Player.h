#ifndef SRC_PLAYER
#define SRC_PLAYER

#include <iostream>

#include "Controller.h"
#include "Doodle.h"
#include "Queue.h"

class Player
{
public:
    Player() = default;
    void SetUp(Queue *queue, Doodle *doodle, Controller *controller, float flightSpeed, float gunFrequency);
    void Update(float deltaTime);

private:
    void updateMove(float deltaTime);
    void updateShooting(float deltaTime);

private:
    Queue *_queue;
    Doodle *_doodle;
    Controller *_controller;
    float _flightSpeed;
    float _gunFrequency;
    float _timeUntilNextShot;
};

#endif /* SRC_PLAYER */
