#include <raylib.h>
#include <repatcher.h>

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 650;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_TOPMOST);
    InitWindow(screenWidth, screenHeight, "RPatcher example - Dyanmic loading of raylib game objects");

    SetTargetFPS(60);

    REPatcher::SetTempLibaryPath("temp\\libs"); // The temp libary path is where dlls will be stored and deleted.

    #ifdef _WIN32
    REPatcher::AddSourceFile("src\\rectangle.cpp", "-I. -I../../src -Iinclude", "-Llib -L. -lraylib -lopengl32 -lgdi32 -lwinmm -lws2_32"); // Adds a source file to be dynamically loaded at runtime.
    REPatcher::AddSourceFile("src\\circle.cpp", "-I. -I../../src -Iinclude", "-Llib -L. -lraylib -lopengl32 -lgdi32 -lwinmm -lws2_32");
    #elif __linux__
    REPatcher::AddSourceFile("src\\rectangle.cpp", "-I. -I../../src -Iinclude", "-Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11"); // Adds a source file to be dynamically loaded at runtime.
    REPatcher::AddSourceFile("src\\circle.cpp", "-I. -I../../src -Iinclude", "-Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11");
    #endif

    // The source file was compiled and it's behaviour was pushed back to m_rayBehaviours so you can now use it.
    for (auto& gameObject : REPatcher::m_rayBehaviours) gameObject.RayObj->Init();

    while (!WindowShouldClose())
    {
    for (auto& gameObject : REPatcher::m_rayBehaviours) gameObject.RayObj->Update();

        BeginDrawing();

            ClearBackground(RAYWHITE);

        for (auto& gameObject : REPatcher::m_rayBehaviours) gameObject.RayObj->Draw();

        EndDrawing();

        REPatcher::Update(); // Checks for file changes and recompiles.
    }

    REPatcher::UnloadAll(); // Unload all ray behaviours and frees libaries.
    CloseWindow();

    return 0;
}