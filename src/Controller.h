#ifndef SRC_CONTROLLER
#define SRC_CONTROLLER

#include <glm/glm.hpp>

class Controller
{
public:
    Controller();
    void SetAxis(glm::vec2 axis);
    glm::vec2 GetAxis();

private:
    glm::vec2 _axis;
};

#endif /* SRC_CONTROLLER */
