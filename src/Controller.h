#ifndef SRC_CONTROLLER
#define SRC_CONTROLLER

#include <glm/glm.hpp>
#include <iostream>

class Controller
{
public:
    Controller();
    void SetAxis(glm::vec2 axis);
    glm::vec2 GetAxis();
    void StartShooting();
    void StopShooting();
    bool IsShooting();

private:
    glm::vec2 _axis;
    bool _shooting;
};

#endif /* SRC_CONTROLLER */
