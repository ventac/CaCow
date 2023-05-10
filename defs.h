// Définition des constantes
#pragma once
#include <SDL2/SDL.h>
#define SCREEN_WIDTH   840
#define SCREEN_HEIGHT  600
#define PLAYER_WIDTH   10
#define PLAYER_HEIGHT  10
#define SPEED 12  // Distance entre pas
#define DELAY 100
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define N_FRAMES_PER_MOVEMENT 10
#define X_INIT_P1 0
#define Y_INIT_P1 0



/*
struct Coleurs{
    SDL_Color bleu = {0, 0, 255, 255};
    Branco: 0xFF, 0xFF, 0xFF, 0xFF
    SDL_Color orange = {255, 127, 40, 255};
}
*/

typedef struct Position Position;
typedef struct Player Player;
typedef struct GameStatus Gamestatus;

struct Position{
    int x;
    int y;
};

struct Player{
    Position initPos;
    Position position;
    int direction;
    int r,g,b;
};

struct GameStatus{
    bool isOpen;  // Au moins une fenetre est ouverte
    bool inMenu;
    bool inGame;  // En train de jouer
    int score;
};

// "Globale" pour les donnés principales du jeu
Gamestatus gameStatus;
