#include "raylib.h"
#include "Character.h"
#include "BaseCharacter.h"
class Enemy : public BaseCharacter
{

private:
    Character *target;
    float damageperSec{10.f};
    float radius{25.f};

public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void tick(float DeltaTime) override;
    void setTarget(Character *character) { target = character; }
    virtual Vector2 getscreenPos() override;
};
