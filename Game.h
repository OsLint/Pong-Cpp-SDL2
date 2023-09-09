#include <SDL_ttf.h>
#include "Player.h"
#include "Ball.h"

class Game {
public:
    Game();

    ~Game() = default;

    int initialize();

    void cleanup();

    void handleEvents(SDL_Event &e);

    void update();



    void render();

    void renderText();

    int getPlayer1Score() const { return player1score; }
    int getPlayer2Score() const { return player2score; }

    void setPlayer1Score(int score) { player1score = score;
    std::cout << "Player 1 score: " << player1score << std::endl;}
    void setPlayer2Score(int score) { player2score = score;
    std::cout << "Player 2 score: " << player2score << std::endl;}

    bool isRunning;

    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 640;

    bool checkForPaddleCollision(SDL_Rect paddle);

    void checkForWallCollision();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Player player1 = Player(SCREEN_WIDTH, SCREEN_HEIGHT);
    Player player2 = Player(SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture *textTexture;
    TTF_Font *font;
    SDL_Surface *textSurface;
    SDL_Rect textRect;


    int player1score;
    int player2score;

};