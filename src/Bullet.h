#ifndef SRC_BULLET
#define SRC_BULLET

#include <glm/glm.hpp>

#include "Doodle.h"
#include "Dynamic.h"

class Bullet : public Dynamic
{
public:
    Bullet();
    glm::vec3 Update(float deltaTime, glm::vec3 &position) override;
    bool IsActive(glm::vec3 &position) override;

private:
    float _speed;
    glm::vec3 _velocity;
};

#endif /* SRC_BULLET */
