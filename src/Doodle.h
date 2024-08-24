#ifndef SRC_DOODLE
#define SRC_DOODLE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include "Model.h"
#include "Shader.h"

class Doodle
{
public:
    Doodle(Model &model, glm::vec3 position, glm::vec3 scale = glm::vec3(1.0f), glm::vec3 rotation = glm::vec3(0.0f));
    glm::vec3 GetPosition();
    glm::vec3 GetScale();
    void SetPosition(glm::vec3 position);
    void SetScale(glm::vec3 scale);
    void SetRotation(glm::vec3 rotation);
    void Draw(Shader &shader);
    void Calculate();

private:
    Model &_model;
    glm::vec3 _position;
    glm::vec3 _scale;
    glm::vec3 _rotation;
    glm::mat4 _mat;
    glm::mat3 _norm;
};

#endif /* SRC_DOODLE */
