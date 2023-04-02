#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Enemy.h"
#include "Prop.h"
#include <string>
int main()
{
    const int WindowWidth = 600;
    const int WindowHight = 600;
    // initilaize the window
    InitWindow(WindowWidth, WindowHight, "WeeboDark");

    Texture2D Map = LoadTexture("textures/WeeboDark.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};
    Character KimChan(WindowWidth, WindowHight);

    //Prop Rock{Vector2{600.f, 500.f}, LoadTexture("textures/Rock.png")};

    Prop Props[2]{Prop{Vector2{700.f, 666.f}, LoadTexture("textures/Log.png")}, Prop{Vector2{900.f, 555.f}, LoadTexture("textures/Rock.png")}};

    Enemy Goblin(Vector2{800.f, 300.f}, LoadTexture("textures/goblin_idle_spritesheet.png"), LoadTexture("textures/goblin_run_spritesheet.png"));

    Enemy slime{

        Vector2{500.f, 700.f}, LoadTexture("textures/slime_idle_spritesheet.png"), LoadTexture("textures/slime_run_spritesheet.png")

    };
    Enemy slime2{

        Vector2{111.f, 500.f}, LoadTexture("textures/slime_idle_spritesheet.png"), LoadTexture("textures/slime_run_spritesheet.png")

    };

    Enemy *enemeis[]{
        &Goblin, &slime, &slime2};
    for (auto enemy : enemeis)
    {
        enemy->setTarget(&KimChan);
    }

    Goblin.setTarget(&KimChan);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(KimChan.GetWorldPos(), -1.f);

        DrawTextureEx(Map, mapPos, 0.0, 4.0, WHITE);

        for (auto prop : Props)
        {
            prop.Render(KimChan.GetWorldPos());
        }

       // Rock.Render(KimChan.GetWorldPos());

        KimChan.tick(GetFrameTime());

        if (KimChan.GetWorldPos().x < 0.f || KimChan.GetWorldPos().y < 0.f || KimChan.GetWorldPos().x + WindowWidth > Map.width * mapScale || KimChan.GetWorldPos().y + WindowHight > Map.height * mapScale)
        {
            KimChan.undoMovement();
        }

        for (auto Prop : Props)
        {
            if (CheckCollisionRecs(Prop.getCollisionRec(KimChan.GetWorldPos()), KimChan.getCollisionRec()))
            {
                KimChan.undoMovement();
            }
        }

        if (!KimChan.getAlive())
        {
            DrawText("GameOver", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }

        else
        {
            std::string kimchanHealth = " Health ";
            kimchanHealth.append(std::to_string(KimChan.gethealth()), 0, 5);
            DrawText(kimchanHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        for (auto enemy : enemeis)
        {
            enemy->tick(GetFrameTime());
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (auto enemy : enemeis)
            {
                if (CheckCollisionRecs(enemy->getCollisionRec(), KimChan.getWeaponCollisionRec()))
                {
                    enemy->setAlive(false);
                }
            }
        }
        EndDrawing();
    }
    CloseWindow();
}
