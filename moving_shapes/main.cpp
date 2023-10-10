#include "raylib.h"
int main() {
    InitWindow(900, 600, "Move Shapes");

    Font customFont = LoadFont("resources/font.ttf");

    const Color tutututrutututu[] = {RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, PINK};

    Vector2 ballPos = {(float) GetScreenWidth()/2, (float) GetScreenHeight()/2 - 30};
    bool isPos = true;

    Texture2D mario = LoadTexture("resources/image.png");
    float marioScale = 0.9f;

    int frame = 0;
    int curentTuTuRu = 0;

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        if (isPos) {
            ballPos.x += 1;
        } else {
            ballPos.x -= 1;
        }

        if ( ballPos.x >= GetScreenWidth() - mario.width * marioScale + 70) {
            isPos = false;
        } else if (ballPos.x <= 25) {
            isPos = true;
        }

        if (frame % 5 == 0) {
            if(!IsKeyDown(KEY_A)) {
                curentTuTuRu++;
            }
        }

        if (curentTuTuRu == (sizeof(tutututrutututu)/sizeof(Color))) {
            curentTuTuRu = 0;
        }

        Vector2 marioPos = {ballPos.x - 15, ballPos.y - 40};

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextEx(customFont, TextFormat("Drawing Stuffs %i %i %i", curentTuTuRu, frame, frame % 5), {10, 10}, 25, 1, BLACK);
        DrawCircleV(ballPos, 25, tutututrutututu[curentTuTuRu]);
        DrawTextureEx(mario, marioPos, 0.0f, marioScale, WHITE);
        EndDrawing();

        frame++;
    };

//REMEBER TO UNLOAD
    UnloadTexture(mario);
    UnloadFont(customFont);
}

