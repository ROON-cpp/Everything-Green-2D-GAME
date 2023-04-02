#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"

class Prop
{
private:
    Texture2D Texture;

    Vector2 WorldPose{0.0, 0.0};

    float scale{4};

public:
    Prop(Vector2 pos, Texture2D tex);

    void Render(Vector2 kimchanPos);

    Rectangle getCollisionRec(Vector2 kimchanPos);
};
