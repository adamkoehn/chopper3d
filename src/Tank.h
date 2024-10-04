#ifndef SRC_TANK
#define SRC_TANK

#include "Dynamic.h"

class Tank : public Dynamic
{
public:
    Tank();
    bool IsActive(glm::vec3 &position) override;
    glm::vec3 Update(float deltaTime, glm::vec3 &position) override;

private:
    float _speed;
};

#endif /* SRC_TANK */
