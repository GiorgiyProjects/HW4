
#include "pretty.h"
#include "HardwareObjects.h"
#include "Controller.h"
#include "GUI.h"
#include "Model.h"
#include <iostream>



int main()
{
    GUI UI;
    Controller Con;
    HardwareObjects Ho;
    Model Mod;

    for (int i = 0; i < 100; i++)
    {
        Ho.CreateRandomEvent();
        auto x = UI.HardwareEventListen(Ho);
        Con.Manage(UI.HardwareEventListen(Ho), Mod, UI);
        Ho.BackToDefault();
    }

    std::cout << "Hello World!" << std::endl;
    return 0;
}


