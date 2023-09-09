#include "Ball.h"

#include <cstdlib>
#include <iostream>

const int SIZE = 10;
const int SPEED = 5;


Ball::Ball(int screenWidth, int screenHeight) : SCREEN_WIDTH(screenWidth),
SCREEN_HEIGHT(screenHeight) {}

void Ball::innit() {
    //Set the Y and X axis of the ball to the middle of the screen
    ball.h = SIZE;
    ball.w = SIZE;
    ball.y = (SCREEN_HEIGHT / 2) - SIZE;
    ball.x = (SCREEN_WIDTH / 2) - SIZE;

    //randomize the velocity of the ball
    int lb = 0, ub = 5;
    srand(time(0));
    int rand = (std::rand() & (ub - lb)) + lb;

    switch (rand) {
        case 0:
            velocity.y = SPEED;
            velocity.x = SPEED;
            break;
        case 1:
            velocity.y = -SPEED;
            velocity.x = -SPEED;
            break;
        case 2:
            velocity.y = SPEED;
            velocity.x = -SPEED;
            break;
        case 3:
            velocity.y = -SPEED;
            velocity.x = SPEED;
            break;
        case 4:
            velocity.y = SPEED/2;
            velocity.x = SPEED;
            break;
        case 5:
            velocity.y = SPEED/2;
            velocity.x = -SPEED;

        default:
            break;
    }

}

void Ball::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &ball);
}

void Ball::update() {
    ball.y += velocity.y;
    ball.x += velocity.x;
}

