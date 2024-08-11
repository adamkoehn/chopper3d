#ifndef SRC_CAMERA
#define SRC_CAMERA

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(float fov, float aspect);
    glm::mat4 GetView();
    glm::mat4 GetProjection();

private:
    glm::vec3 _position;
    glm::vec3 _front;
    glm::vec3 _up;
    glm::mat4 _view;
    glm::mat4 _projection;
};

#endif /* SRC_CAMERA */
