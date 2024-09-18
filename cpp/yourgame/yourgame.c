/*******************************************************************************************
 *
 *   raylib [core] example - 2D Camera system
 *
 *   Example originally created with raylib 1.5, last time updated with
 *raylib 3.0
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an
 *OSI-certified, BSD-like license that allows static linking with closed source
 *software
 *
 *   Copyright (c) 2016-2024 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"
#include <stdio.h>
#include <string.h>

#define MAX_BUILDINGS 100

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 400;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Calculator");
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  char number[16] = {'7', '8', '9', 'x', '4', '5', '6', '-',
                     '1', '2', '3', '+', '^', '0', '.', '='};
  char exp[16] = {'\0'};
  int a[4][4] = {0};
  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);

    Vector2 myPos = GetMousePosition();

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int x = j * 100;
        int y = i * 100 + 200;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
            CheckCollisionPointRec(myPos, (Rectangle){x, y, 90, 90})) {
          a[i][j] = 1;
          char temp[10];
          snprintf(temp, 2, &number[i * 4 + j]);
          strcat(exp, temp);
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) &&
            CheckCollisionPointRec(myPos, (Rectangle){x, y, 90, 90})) {
          a[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (a[i][j] == 1) {
          DrawRectangle(j * 100, i * 100 + 200, 90, 90, DARKGRAY);
        } else {
          DrawRectangle(j * 100, i * 100 + 200, 90, 90, LIGHTGRAY);
        }
        char temp[10];
        snprintf(temp, 2, &number[i * 4 + j]);
        DrawText(temp, j * 100 + 35, i * 100 + 200 + 30, 40, BLACK);
      }
    }

    DrawText(exp, 0, 100, 40, BLACK);

    // DrawRectangle(100, 100, 90, 90, LIGHTGRAY);
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
