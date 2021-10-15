//How to translate a Simple Triangle
//Use WSAD to translate
//Hooman Salamat
#include <iostream>

#include "Game.h"

int main(int argc, char** argv)
{
    try
    {
        Game app;
        app.initApp();
        app.getRoot()->startRendering();
        app.closeApp();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error occurred during execution: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

//! [fullsource]
