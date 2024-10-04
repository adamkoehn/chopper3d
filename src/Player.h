#ifndef SRC_PLAYER
#define SRC_PLAYER

#include <glm/glm.hpp>
#include <iostream>

#include "Controller.h"
#include "Queue.h"
#include "Dynamic.h"

class Player : public Dynamic
{
public:
    Player() = default;
    void SetUp(Queue *queue, Controller *controller, float flightSpeed, float gunFrequency);
    glm::vec3 Update(float deltaTime, glm::vec3 &position) override;
    bool IsActive(glm::vec3 &position) override;

private:
    glm::vec3 updateMove(float deltaTime, glm::vec3 &position);
    void updateShooting(float deltaTime, glm::vec3 &position);

private:
    Queue *_queue;
    Controller *_controller;
    float _flightSpeed;
    float _gunFrequency;
    float _timeUntilNextShot;
};

#endif /* SRC_PLAYER */
