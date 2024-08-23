#include "Controller.h"

Controller::Controller()
    : _axis(glm::vec2(0.0f, 0.0f)), _shooting(false)
{
}

void Controller::SetAxis(glm::vec2 axis)
{
    _axis = axis;
}

glm::vec2 Controller::GetAxis()
{
    return _axis;
}

void Controller::StartShooting()
{
    _shooting = true;
}

void Controller::StopShooting()
{
    _shooting = false;
}
