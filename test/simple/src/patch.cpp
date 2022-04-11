// A basic test patch for testloader.cpp
// Everything in here can be modified besides the 2 lines of boilerplate code.

#include <raybehavior.h> // Interface for behaviours
#include <iostream>

// And that's it! You can now write whatever in this patch and it will be loaded at runtime.
class TestBehaviour : public IRayBehaviour {
    public:

        // Standard interface functions you can of course modify the interface to you're liking.
        // Try changing something and recompiling and see if test loader changes
        void Init() override
        {
            std::cout << "Init" << std::endl;
        }

        void Update() override
        {
            std::cout << "Update" << std::endl;
        }

        void Draw() override
        {
            std::cout << "Draw" << std::endl;
        }

        void Close() override
        {
            std::cout << "Close" << std::endl;
        }
};

// The only necessary boiler plate code!
extern "C" __declspec(dllexport)IRayBehaviour* GetBehaviour(){ return new TestBehaviour();}
extern "C" __declspec(dllexport)void KillBehaviour( IRayBehaviour* p ){ delete p;}