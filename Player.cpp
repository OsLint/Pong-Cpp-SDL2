#include "Player.h"

const int PLAYER_MOVEMENT_SPEED = 4;

Player::Player(int screenWidth, int screenHeight) : isMoving(false),SCREEN_WIDTH(screenWidth), SCREEN_HEIGHT(screenHeight){
    velocity.x = 0;
    velocity.y = 0;
}

void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &paddle);
}

void Player::innit(bool isPlayer1) {
    if (!isPlayer1)
        //Set the X axis of the paddle to the left of the screen
        paddle.x = SCREEN_WIDTH - 20;
    else
        //Set the X axis of the paddle to the right of the screen;
        paddle.x = 0;

    //Set the Y axis of the paddle to the middle of the screen
    paddle.y = (SCREEN_HEIGHT / 2) - 50;
    paddle.w = 20;
    paddle.h = 100;
}

void Player::update(){
    if(isMoving){
        // Update the player's position based on velocity and deltaTime
        paddle.y += velocity.y;

        // Add boundary checks to ensure the paddle stays within the screen
        if (paddle.y < 0) {
            paddle.y = 0;
        } else if (paddle.y + paddle.h > SCREEN_HEIGHT) {
            paddle.y = SCREEN_HEIGHT - paddle.h;
        }
    }
}

void Player::move(bool up) {
    isMoving = true;
    //change the velocity of the paddle
    velocity.y = up ? -PLAYER_MOVEMENT_SPEED : PLAYER_MOVEMENT_SPEED;

}

void Player::stopMoving() {
    this->isMoving = false;
    velocity.x = 0; // Stop vertical movement
}


