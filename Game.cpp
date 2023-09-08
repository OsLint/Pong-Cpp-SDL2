#include <iostream>

#include "Game.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;


Game::Game() : window(nullptr), renderer(nullptr), isRunning(false) {}

void Game::initialize() {
    window = SDL_CreateWindow("Pong in SDL2",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Window could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    } else {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) {
            std::cout << "Renderer could not be created!" << std::endl
                      << "SDL_Error: " << SDL_GetError() << std::endl;
        } else {
            isRunning = true;
            player1.innit(true);
            player2.innit(false);
        }
    }
}

void Game::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Game::handleEvents(SDL_Event &e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                player2.move(true);
                break;
            case SDLK_DOWN:
                player2.move(false);
                break;
            case SDLK_w:
                player1.move(true);
                break;
            case SDLK_s:
                player1.move(false);
                break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                player2.stopMoving();
                break;
            case SDLK_DOWN:
                player2.stopMoving();
                break;
            case SDLK_w:
                player1.stopMoving();
                break;
            case SDLK_s:
                player1.stopMoving();
                break;
        }
    }
}

void Game::update() {



    // Initialize renderer color white for the background
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    // Update game objects (e.g., player, ball, background)
    player1.update();
    player2.update();

    // Render game objects (e.g., players, ball, background)
    render();

    // Update screen
    SDL_RenderPresent(renderer);
}

void Game::render() {
    player1.render(renderer);
    player2.render(renderer);
}

