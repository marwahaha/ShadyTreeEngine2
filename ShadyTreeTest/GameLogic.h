#pragma once
#include "ISystem.h"
#include "Level.h"

class GameObject;
class PhysicsSystem;

class GameLogic : public ISystem
{
public:
    GameLogic(void);
    ~GameLogic(void);

    virtual void Init();
    virtual void Load();
    virtual void Update(float deltaTime);
    virtual void Unload();
    virtual void Free();
    virtual void RecieveMessage(Message* msg);
    void CollideEvent(Message* msg);


    GameObject* playerObj;
    std::vector<GameObject*> enemies;
    Level level;

    void SetPhysics(PhysicsSystem* _ps);
    PhysicsSystem* ps;
    
    void SetWorldDimension(int height, int width);
    int Height;
    int Width;
};

