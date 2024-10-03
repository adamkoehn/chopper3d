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
#include "Manager.h"

class Scene
{
public:
    Scene();
    void Draw(Shader &shader);
    void Load();
    bool DidRequestStop();
    void ProcessInput();
    void Update(float deltaTime);

private:
    int _selected;
    int _activePlayers;
    Player _players[4];
    Queue _queue;
    Input _input;
    Controller _keyboard;
    Manager _manager;
};

#endif /* SRC_SCENE */
