#ifndef SRC_SCENE
#define SRC_SCENE

#include <vector>

#include "Shader.h"
#include "Doodle.h"

class Scene
{
public:
    Scene(Shader &shader);
    void AddDoodle(Doodle *doodle);
    void Update();
    void Draw();

private:
    Shader &_shader;
    std::vector<Doodle *> _doodles;
};

#endif /* SRC_SCENE */
