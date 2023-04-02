#include "Character.h"

Character::Character(int winwidth, int winhegth) : windowWidth(winwidth), windowHeight(winhegth)
{
    width = texture.width / maxFrames;
    height = texture.height;

    kimchanpos = {

        static_cast<float>(winwidth) / 2.0f - 4.0f * (0.5f * width),
        static_cast<float>(winhegth) / 2.0f - 4.0f * (0.5f * height)

    };
}

Vector2 Character::getscreenPos()
{
    return Vector2{

        static_cast<float>(windowWidth) / 2.0f - 4.0f * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - 4.0f * (0.5f * height)

    };
}

void Character::takeDamage(float Damage)
{
    health -= Damage;
    if (health <= 0.f)
    {
        setAlive(false);
    }
}

void Character::tick(float DeltaTime)
{

    if (!getAlive())
        return;

    if (IsKeyDown(KEY_A))
        Velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        Velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        Velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        Velocity.y += 1.0;
    BaseCharacter::tick(DeltaTime);
    Vector2 origin{};
    Vector2 offset{};
    float rotation;
    if (RighLeft > 0.f)
    {
        origin = {0.f, weapon.height * scale};
        offset = {50.f, 82.f};
        weaponCollisionRec = {getscreenPos().x + offset.x, getscreenPos().y + offset.y - weapon.height * scale, weapon.width * scale, weapon.height * scale};
        IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? rotation = 35.f : rotation = 0.f;
    }
    else
    {
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {70.f, 80.f};
        weaponCollisionRec = {getscreenPos().x + offset.x - weapon.width * scale, getscreenPos().y + offset.y - weapon.height * scale, weapon.width * scale, weapon.height * scale};
        IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? rotation = -35.f : rotation = 0.f;
    }
    // draw the sord
    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * RighLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getscreenPos().x + offset.x, getscreenPos().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);
}
