#include "Enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{

    WorldPos = pos;
    texture = idle_texture;
    Run = run_texture;
    Idl = idle_texture;
    width = texture.width / 6;
    height = texture.height;
    speed = 3.0f;
}

void Enemy::tick(float DeltaTime)
{
    if (!getAlive())
        return;
    // get ToTarget
    Velocity = Vector2Subtract(target->getscreenPos(), getscreenPos());

    if (Vector2Length(Velocity) < radius)
        Velocity = {};

    BaseCharacter::tick(DeltaTime);

    if (CheckCollisionRecs(target->getCollisionRec(), getCollisionRec()))
    {
        target->takeDamage(damageperSec * DeltaTime);
    }
}

Vector2 Enemy::getscreenPos()
{
    return Vector2(Vector2Subtract(WorldPos, target->GetWorldPos()));
}
