// Game.h
#pragma once

#include "Player.h"

class Game {
public:
    Game();

    ~Game() = default;

    void initialize();

    void cleanup();

    void handleEvents(SDL_Event &e);

    void update();

    void render();

    //[[nodiscard]] int getScore() const { return score; }

    bool isRunning;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;


    Player player1;
    Player player2;

   // int score;

};