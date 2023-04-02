#include "Prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex):WorldPose(pos),Texture(tex)
{
    
}

void Prop::Render(Vector2 kimchanPos)
{

    Vector2 ScreenPose{Vector2Subtract(WorldPose, kimchanPos)};

    DrawTextureEx(Texture, ScreenPose, 0.f, scale, WHITE);
}

Rectangle Prop::getCollisionRec(Vector2 kimchanPos)
{
    Vector2 ScreenPos{Vector2Subtract(WorldPose, kimchanPos)};
    return Rectangle{ScreenPos.x, ScreenPos.y, Texture.width * scale, Texture.height * scale};
}