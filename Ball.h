#include "SDL.h"

class Ball {
public:
    Ball(int screenWidth, int screenHeight);

    void innit();

    void render(SDL_Renderer *renderer);

    void update();

    SDL_Rect getBall() const { return ball; }
    SDL_Point getVelocity() const { return velocity; }


    void setVelocity(SDL_Point vel) { velocity = vel; }

private:
    SDL_Rect ball;
    SDL_Point velocity;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;

};


