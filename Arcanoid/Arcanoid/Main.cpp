#include <SFML/Graphics.hpp>
#include "GameLoop.h"

int main(void){
    srand((unsigned)time(0));

    GameLoop GameLoop;
    GameLoop.Start();
    
    return 0;
}