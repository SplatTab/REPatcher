#include <raybehavior.h>
#include <raylib.h>

class ClassName : public IRayBehaviour {
    public:

        void Init() override {
            // Load any resources and initilize you're gameobject here
        }

        void Draw() override
        {
            DrawText("This rectangle was loaded dynamically", (GetScreenWidth() - GetScreenWidth() / 2) - MeasureText("This rectangle was loaded dynamically", 10), (GetScreenHeight() - GetScreenHeight() / 2) - 150, 20, BLACK);
            DrawRectangle(GetScreenWidth() - GetScreenWidth() / 2 - 50, GetScreenHeight() - GetScreenHeight() / 2 - 50, 100, 100, RED); // Try changing the color.
        }
};

// The only necessary boiler plate code!
extern "C" __declspec(dllexport)IRayBehaviour* GetBehaviour(){ return new ClassName();}
extern "C" __declspec(dllexport)void KillBehaviour( IRayBehaviour* p ){ delete p;}