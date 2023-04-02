#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"
#include "raymath.h"

class BaseCharacter
{

private:
    bool alive{true};

protected:
    Texture2D texture = LoadTexture("textures/Man_idle.png");
    Texture2D Idl = LoadTexture("textures/Man_idle.png");
    Texture2D Run = LoadTexture("textures/Man_walk.png");
   // Texture2D Attack = LoadTexture("textures/Man_attack.png");
    Vector2 kimchanpos{};
    Vector2 WorldPos{};
    Vector2 worldPoseLastFrame;
    int frame{};
    float RighLeft{1.f};
    float runningtime{};
    float maxFrames{4};
    float updatetime{1.f / 12.f};
    float speed{5.f};
    float width{};
    float height{};
    float scale{2.5f};
    Vector2 Velocity;

public:
    Vector2 GetWorldPos() { return WorldPos; }
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float DeltaTime);
    virtual Vector2 getscreenPos() = 0;
    bool getAlive() { return alive; }
    void setAlive(bool IsAlive) { alive = IsAlive; }
};

#endif