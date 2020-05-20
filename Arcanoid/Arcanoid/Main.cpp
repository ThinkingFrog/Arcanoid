#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "GameLoop.h"

int main(void){
    srand((unsigned)time(0));

    GameLoop GameLoop;
    GameLoop.Start();
    
    _CrtDumpMemoryLeaks();
    return 0;
}