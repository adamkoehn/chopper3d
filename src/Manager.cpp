#include "Manager.h"

Manager::Manager()
    : _modelBufCount(0),
      _staticAssetCount(0),
      _dynamicAssetCount(0)
{
}

Manager::~Manager()
{
}

void Manager::LoadLevel()
{
    addModel("cloud", "models/cloud/cloud.glb");
    addModel("sun", "models/sun/sun.glb");
    addModel("mountain", "models/mountain/mountain.glb");
    addModel("chopper", "models/chopper/chopper.glb");
    addModel("tank", "models/tank/tank.glb");
    addModel("ground", "models/ground/ground.glb");
    addModel("bullet", "models/bullet/bullet.glb");

    addStaticDoodle("cloud", glm::vec3(6.0f, 16.5f, -59.5f), glm::vec3(1.0f), glm::vec3(0.0f, 45.0f, 0.0f));
    addStaticDoodle("cloud", glm::vec3(-23.5f, 22.0f, -52.5f), glm::vec3(1.2f));
    addStaticDoodle("sun", glm::vec3(45.5f, 33.5f, -74.5f), glm::vec3(3.0f));
    addStaticDoodle("mountain", glm::vec3(-12.5f, -4.5f, -12.0f), glm::vec3(1.1f), glm::vec3(0.0f, 90.0f, 0.0f));
    addStaticDoodle("mountain", glm::vec3(-2.5f, -6.0f, -14.0f), glm::vec3(1.1f));
    addStaticDoodle("mountain", glm::vec3(9.0f, -5.0f, -13.0f), glm::vec3(1.4f));
    addStaticDoodle("ground", glm::vec3(0.0f, -8.5f, -28.5f));
}

void Manager::addModel(std::string name, std::string path)
{
    int location = _modelBufCount++;
    _modelBuf[location] = Model(path);
    _models[name] = &_modelBuf[location];
}

void Manager::addStaticDoodle(std::string model, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
{
    int location = _staticAssetCount++;
    _staticAssets[location] = Doodle(_models[model], position, scale, rotation);
}

unsigned int Manager::CreateDynamicDoodle(std::string model, glm::vec3 position, glm::vec3 scale, glm::vec3 rotation)
{
    _dynamicAssets[_dynamicAssetCount] = Doodle(_models[model], position, scale, rotation);
    return _dynamicAssetCount++;
}

Doodle &Manager::GetDynamicDoodle(unsigned int at)
{
    return _dynamicAssets[at];
}

void Manager::DeleteDynamicDoodle(unsigned int at)
{
    _dynamicAssets[at] = _dynamicAssets[_dynamicAssetCount - 1];
    _dynamicAssetCount--;
}

void Manager::UpdateStaticAssets()
{
    for (int i = 0; i < _staticAssetCount; i++)
    {
        _staticAssets[i].Calculate();
    }
}

void Manager::Update()
{
    for (int i = 0; i < _dynamicAssetCount; i++)
    {
        _dynamicAssets[i].Calculate();
    }
}

void Manager::Draw(Shader &shader)
{
    for (int i = 0; i < _staticAssetCount; i++)
    {
        _staticAssets[i].Draw(shader);
    }
    for (int i = 0; i < _dynamicAssetCount; i++)
    {
        _dynamicAssets[i].Draw(shader);
    }
}
