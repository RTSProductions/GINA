#include <raylib.h>
#include <rcamera.h>
#include <iostream>
#include <BulletDynamics/btBulletDynamicsCommon.h> 
#include "tools.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

#define TREE_COUNT 25
#define TREE_SPACING 4

float ys[51][51];

// Scene drawing
void DrawScene(void)
{
    int count = TREE_COUNT;
    int spacing = TREE_SPACING;

    // Grid of cube trees on a plane to make a "world"
    DrawPlane((Vector3){ 0, 0, 0 }, (Vector2){ 200, 200 }, BEIGE); // Simple world plane
        
    int xVal = 0;
    for (float x = -count*spacing; x <= count*spacing; x += spacing)
    {
        int zVal = 0;
        xVal++;
        for (float z = -count*spacing; z <= count*spacing; z += spacing)
        {
            zVal++;
            DrawCube((Vector3) {x, ys[xVal][zVal] + 0.5f, z}, 1, 1, 1, LIME);
            DrawCube((Vector3) {x, ys[xVal][zVal] * 0.5f, z}, 0.25f, ys[xVal][zVal], 0.25f, BROWN);
        }
    }
}


int main(void)
{
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    InitWindow(screenWidth, screenHeight, "GINA");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 1.0f, 10.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    int cameraMode = CAMERA_FIRST_PERSON;

    DisableCursor();                    // Limit cursor to relative movement inside the window


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    for (int x = 0; x < TREE_COUNT * 2 + 1; ++x)
    {
        for (int z = 0; z < TREE_COUNT * 2 + 1; ++z)
        {
            ys[x][z] = RandomFloat(0.7f, 2.0f);
        }
    }

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // TODO: Update your variables here
                UpdateCameraPro(&camera,
            (Vector3){
                (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*0.1f -      // Move forward-backward
                (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*0.1f,    
                (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*0.1f -   // Move right-left
                (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*0.1f,
                (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_E)) * 0.1f -
                (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_Q)) * 0.1f,                                                // Move up-down
            },
            (Vector3){
                GetMouseDelta().x*0.5f,                            // Rotation: yaw
                GetMouseDelta().y*0.5f,                            // Rotation: pitch
                0.0f                                                // Rotation: roll
            },
            0.0f);//GetMouseWheelMove()*2.0f);                              // Move to target (zoom)                // Update camera

        //Draw
        BeginDrawing();

            ClearBackground(SKYBLUE);

           BeginMode3D(camera);

           DrawScene();

            EndMode3D();

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}