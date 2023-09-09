#include "SDL.h"

class Player {
private:
    SDL_Rect paddle{};
    SDL_Point velocity{};
    int isMoving;
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
public:
    Player(int screenWidth, int screenHeight);

    SDL_Rect getPaddle() const{ return paddle; }

    void innit(bool isPlayer1);

    void move(bool up);
    void stopMoving();

    void render(SDL_Renderer *renderer);

    void update();
};