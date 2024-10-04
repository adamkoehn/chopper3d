#ifndef SRC_DYNAMIC
#define SRC_DYNAMIC

#include <glm/glm.hpp>

class Dynamic
{
public:
    Dynamic() {}
    ~Dynamic() {}
    virtual bool IsActive(glm::vec3 &position) = 0;
    virtual glm::vec3 Update(float deltaTime, glm::vec3 &position) = 0;
};

#endif /* SRC_DYNAMIC */
