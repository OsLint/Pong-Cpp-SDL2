#include <iostream>


#include "SDL.h"
#include "Game.h"

const int TARGET_FPS = 60;
const int DELAY_TIME = 1000 / TARGET_FPS;

int main() {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init() failed: " << TTF_GetError() << std::endl;
        // Handle initialization failure
        return 1;
    }

    Game game;
    int initGaame = game.initialize();
    if(initGaame != 0){
        std::cout << "Game could not be initialized!" << std::endl;
        return 1;
    }

    SDL_Event e; // Create an SDL event to handle events

    while(game.isRunning){
        Uint32 frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                game.isRunning = false; // Exit the loop if the window is closed
            }
            game.handleEvents(e); // Handle player input
        }

        game.update();
        game.render();

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME) {
            SDL_Delay(DELAY_TIME - frameTime);
        }
    }

    game.cleanup();

    SDL_Quit();

}



