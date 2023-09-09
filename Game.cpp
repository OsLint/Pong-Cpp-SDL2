#include <iostream>

#include "Game.h"


Ball ball(Game::SCREEN_WIDTH,Game::SCREEN_HEIGHT);

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false) {

}

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
            ball.innit();
        }
    }
}

void Game::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(text);
    TTF_Quit();
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

    if(checkForPaddleCollision(player1.getPaddle()) ||
        checkForPaddleCollision(player2.getPaddle())) {
        int curXVelocity = ball.getVelocity().x;
        ball.setVelocity({-curXVelocity, ball.getVelocity().y});
    }else {
        checkForWallCollision();
    }
    ball.update();

    // Render game objects (e.g., players, ball, background)
    render();

    // Update screen
    SDL_RenderPresent(renderer);
}

void Game::render() {
    player1.render(renderer);
    player2.render(renderer);
    ball.render(renderer);
    //renderText();
}


bool Game::checkForPaddleCollision(SDL_Rect paddle) {
    if (ball.getBall().x + ball.getBall().w >= paddle.x &&
        ball.getBall().x <= paddle.x + paddle.w &&
        ball.getBall().y + ball.getBall().h >= paddle.y &&
        ball.getBall().y <= paddle.y + paddle.h) {
        return true;
    }
    return false;
}

void Game::checkForWallCollision() {
    // Check for collision with the top and bottom of the screen
    if (ball.getBall().y <= 0 || ball.getBall().y + ball.getBall().h >= SCREEN_HEIGHT) {
        int curYVelocity = ball.getVelocity().y;
        ball.setVelocity({ball.getVelocity().x, -curYVelocity});
    }

    // Check for collision with the left and right sides of the screen
    if (ball.getBall().x + ball.getBall().w <= 0) {
        // Ball passed the left side of the screen
        // Add points and reset ball position
        int score = Game::getPlayer2Score();
        Game::setPlayer2Score(score + 1); // Add points to player B (or your scoring mechanism)
        ball.innit();   // Reset the ball's position to the center
    } else if (ball.getBall().x >= SCREEN_WIDTH) {
        // Ball passed the right side of the screen
        // Add points and reset ball position
        int score = Game::getPlayer1Score();
        Game::setPlayer1Score(score + 1);
        //addPointsToPlayerA();  // Add points to player A (or your scoring mechanism)
        ball.innit();    // Reset the ball's position to the center
    }
}

void Game::renderText() {
    SDL_RenderCopy(renderer, text, NULL, &textRect);
    SDL_RenderPresent(renderer);
}
