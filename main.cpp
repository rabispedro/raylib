/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <string>
#include <iostream>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

		std::string fpsText;
		std::string frametimeText;



    InitWindow(screenWidth, screenHeight, "raylib first example");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
		const float ballVelocity = 250.5f;
		int ballRadius = 8;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
				ballPosition.x += ballVelocity * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * GetFrameTime();
				ballPosition.y += ballVelocity * (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * GetFrameTime();

				fpsText.append("FPS: ");
				fpsText.append(std::to_string(GetFPS()));

				frametimeText.append("Frametime: ");
				frametimeText.append(std::to_string(GetFrameTime()));

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

						ClearBackground(DARKGRAY);

						DrawTriangle({400.f, 0.f}, {0.f, 0.f}, {400.f, 300.f}, DARKBLUE);
						DrawTriangle({0.f, 0.f}, {0.f, 300.f}, {400.f, 300.f}, SKYBLUE);

						DrawTriangle({0.f, 300.f}, {0.f, 600.f}, {400.f, 300.f}, DARKBLUE);
						DrawTriangle({0.f, 600.f}, {400.f, 600.f}, {400.f, 300.f}, SKYBLUE);

						DrawTriangle({400.f, 600.f}, {800.f, 600.f}, {400.f, 300.f}, DARKBLUE);
						DrawTriangle({800.f, 600.f}, {800.f, 300.f}, {400.f, 300.f}, SKYBLUE);

						DrawTriangle({800.f, 300.f}, {800.f, 0.f}, {400.f, 300.f}, DARKBLUE);
						DrawTriangle({800.f, 0.f}, {400.f, 0.f}, {400.f, 300.f}, SKYBLUE);

            DrawCircleV(ballPosition, ballRadius, RED);

						DrawLine(0, 0, screenWidth, screenHeight, BEIGE);
						DrawLine(screenWidth, 0, 0, screenHeight, BEIGE);
						DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, BEIGE);
						DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, BEIGE);


            DrawText("move the ball with WASD keys", 10, 10, 20, RAYWHITE);
            DrawText("press ESC to exit", 10, 35, 20, RAYWHITE);
						DrawText(fpsText.c_str(), 10, 60, 20, RAYWHITE);
						DrawText(frametimeText.c_str(), 10, 80, 20, RAYWHITE);



        EndDrawing();
        //----------------------------------------------------------------------------------

				fpsText.clear();
				frametimeText.clear();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
