#include "SDL.h"

class Player {
private:
    SDL_Rect paddle{};
    SDL_Point velocity{};
    int isMoving;
public:
    Player();

    void innit(bool isPlayer1);

    void move(bool up);
    void stopMoving();

    void render(SDL_Renderer *renderer);

    void update();
};