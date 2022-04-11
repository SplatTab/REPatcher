#include <repatcher.h>
#include <iostream>

int main() {
    REPatcher::SetTempLibaryPath("temp\\libs"); // The temp libary path is where dlls will be stored and deleted.

    REPatcher::AddSourceFile("src\\patch.cpp", "-I. -I../../src", ""); // Adds a source file to be dynamically loaded at runtime.

    // The source file was compiled and it's behaviour was pushed back to m_rayBehaviours so you can now use it.
    REPatcher::m_rayBehaviours[0].RayObj->Init();

    while (true)
    {
        REPatcher::m_rayBehaviours[0].RayObj->Update();
        REPatcher::m_rayBehaviours[0].RayObj->Draw();
        REPatcher::Update(); // Checks for file changes and recompiles.
    }

    REPatcher::m_rayBehaviours[0].RayObj->Close();

    REPatcher::UnloadAll(); // Unload all ray behaviours and frees libaries.
    return 0;
}