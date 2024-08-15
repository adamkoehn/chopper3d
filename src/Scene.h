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
    void Calculate();
    void Draw();
    void Select();
    void Up();
    void Down();
    void Left();
    void Right();
    void Back();
    void Forward();
    void ScaleUp();
    void ScaleDown();
    void MoveDoodle(glm::vec3 move);
    void ScaleDoodle(glm::vec3 scale);

private:
    Shader &_shader;
    int _selected;
    std::vector<Doodle *> _doodles;
};

#endif /* SRC_SCENE */
