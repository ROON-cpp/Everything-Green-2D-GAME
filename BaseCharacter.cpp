#include "BaseCharacter.h"
#include "raymath.h"
void BaseCharacter::undoMovement()
{
    WorldPos = worldPoseLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{getscreenPos().x, getscreenPos().y, width * scale, height * scale};
}

void BaseCharacter::tick(float DeltaTime)
{
    worldPoseLastFrame = WorldPos;

    // update animation frame
    runningtime += DeltaTime;
    if (runningtime >= updatetime)
    {
        frame++;

        runningtime = 0;

        if (frame > maxFrames)
            frame = 0;
    }

    if (Vector2Length(Velocity) != 0.0)
    {

        WorldPos = Vector2Add(WorldPos, Vector2Scale(Vector2Normalize(Velocity), speed));

        Velocity.x < 0.f ? RighLeft = -1.f : RighLeft = +1;

        texture = Run;
    }

    // else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    // {
    //    texture = Attack;
    // }

    else
    {
        texture = Idl;
    }

    Velocity = {};
    Rectangle source{frame * width, 0.f, RighLeft * width, height};
    Rectangle dest{getscreenPos().x, getscreenPos().y, scale * width, scale * height};

    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}
