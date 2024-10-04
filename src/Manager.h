#ifndef SRC_MANAGER
#define SRC_MANAGER

#include <map>
#include <string>
#include <vector>

#include "Model.h"
#include "Doodle.h"
#include "Shader.h"
#include "Bullet.h"

class Manager
{
public:
    Manager();
    ~Manager();
    void LoadLevel();
    void UpdateStaticAssets();
    void Update(float deltaTime);
    void Draw(Shader &shader);
    Doodle *CreateDynamicDoodle(
        std::string model,
        glm::vec3 position = glm::vec3(0.0f),
        glm::vec3 scale = glm::vec3(1.0f),
        glm::vec3 rotation = glm::vec3(0.0f));
    void RemoveDynamicDoodle(int index);
    void CreateBullet(glm::vec3 position);

private:
    void addModel(std::string name, std::string path);
    void addStaticDoodle(
        std::string model,
        glm::vec3 position = glm::vec3(0.0f),
        glm::vec3 scale = glm::vec3(1.0f),
        glm::vec3 rotation = glm::vec3(0.0f));

private:
    static const int MAX_MODEL_BUF_SIZE = 20;
    static const int MAX_STATIC_ASSET_SIZE = 20;
    static const int MAX_DYNAMIC_ASSET_SIZE = 200;
    int _modelBufCount;
    int _staticAssetCount;
    int _dynamicAssetCount;
    int _bulletCount;
    Bullet _bullet;
    std::map<std::string, Model *> _models;
    Model _modelBuf[MAX_MODEL_BUF_SIZE];
    Doodle _staticAssets[MAX_STATIC_ASSET_SIZE];
    Doodle _dynamicAssets[MAX_DYNAMIC_ASSET_SIZE];
};

#endif /* SRC_MANAGER */
