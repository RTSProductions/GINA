#include <raylib.h>
#include <rcamera.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

// Scene drawing
void DrawScene(void)
{
    int count = 5;
    float spacing = 4;

    // Grid of cube trees on a plane to make a "world"
    DrawPlane((Vector3){ 0, 0, 0 }, (Vector2){ 50, 50 }, BEIGE); // Simple world plane

    for (float x = -count*spacing; x <= count*spacing; x += spacing)
    {
        for (float z = -count*spacing; z <= count*spacing; z += spacing)
        {
            DrawCube((Vector3) { x, 1.5f, z }, 1, 1, 1, LIME);
            DrawCube((Vector3) { x, 0.5f, z }, 0.25f, 1, 0.25f, BROWN);
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

            // Draw info boxes
            // DrawRectangle(5, 5, 330, 100, Fade(SKYBLUE, 0.5f));
            // DrawRectangleLines(5, 5, 330, 100, BLUE);

            // DrawText("Camera controls:", 15, 15, 10, BLACK);
            // DrawText("- Move keys: W, A, S, D, Space, Left-Ctrl", 15, 30, 10, BLACK);
            // DrawText("- Look around: arrow keys or mouse", 15, 45, 10, BLACK);
            // DrawText("- Camera mode keys: 1, 2, 3, 4", 15, 60, 10, BLACK);
            // DrawText("- Zoom keys: num-plus, num-minus or mouse scroll", 15, 75, 10, BLACK);
            // DrawText("- Camera projection key: P", 15, 90, 10, BLACK);

            // DrawRectangle(600, 5, 195, 100, Fade(SKYBLUE, 0.5f));
            // DrawRectangleLines(600, 5, 195, 100, BLUE);

            // DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)", camera.position.x, camera.position.y, camera.position.z), 610, 60, 10, BLACK);
            // DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)", camera.target.x, camera.target.y, camera.target.z), 610, 75, 10, BLACK);
            // DrawText(TextFormat("- Up: (%06.3f, %06.3f, %06.3f)", camera.up.x, camera.up.y, camera.up.z), 610, 90, 10, BLACK);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}