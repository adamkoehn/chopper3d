#ifndef SRC_SCENE
#define SRC_SCENE

#include <vector>

#include "Shader.h"
#include "Doodle.h"
#include "Model.h"
#include "Input.h"
#include "Controller.h"
#include "Player.h"
#include "Queue.h"

class Scene
{
public:
    Scene();
    void Calculate();
    void Draw(Shader &shader);
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
    void Load();
    bool DidRequestStop();
    void ProcessInput();
    void Update(float deltaTime);

private:
    int _selected;
    Queue _queue;
    std::vector<Doodle> _doodles;
    std::vector<Model> _models;
    std::vector<Player> _players;
    Input _input;
    Controller _keyboard;
};

#endif /* SRC_SCENE */
