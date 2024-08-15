#include "Camera.h"

Camera::Camera(float fov, float aspect)
{
    _position = glm::vec3(0.0f, 0.0f, 20.0f);
    _front = glm::vec3(0.0f, 0.0f, -1.0f);
    _up = glm::vec3(0.0f, 1.0f, 0.0f);
    _projection = glm::perspective(fov, aspect, 0.1f, 1000.0f);
    _view = glm::lookAt(_position, _position + _front, _up);
}

glm::mat4 Camera::GetView()
{
    return _view;
}

glm::mat4 Camera::GetProjection()
{
    return _projection;
}
