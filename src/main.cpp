#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "gameEngine/GameEngine.h"

int main()
{
   GameEngine engine;
   engine.run();
   return 0;
}



//cmake .. -G "MinGW Makefiles" 
//cmake --build . --config Release

