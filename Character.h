#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter

{

private:
    int windowWidth;
    int windowHeight;
    Texture2D weapon{LoadTexture("textures/steel-weapons.png")};
    Rectangle weaponCollisionRec{};
    float health{100.f};

public:
    Character(int winwidth, int winheigt);
    virtual void tick(float DeltaTime) override;
    virtual Vector2 getscreenPos() override;
    Rectangle getWeaponCollisionRec() { return weaponCollisionRec; }
    float gethealth() const { return health; }
    void takeDamage(float Damage);
};

#endif