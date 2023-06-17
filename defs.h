// Définition des constantes
#pragma once
#include <SDL2/SDL.h>
#define SCREEN_WIDTH   840
#define SCREEN_HEIGHT  600
#define PLAYER_WIDTH   40  // (avant = 20)
#define PLAYER_HEIGHT  40  // (avant = 20)
#define CACA_WIDTH 10
#define CACA_HEIGHT 10
#define SPEED 12  // Distance entre pas (avant = 12)
#define DELAY 100
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define N_FRAMES_PER_MOVEMENT 12
#define X_INIT_P1 0
#define Y_INIT_P1 0
#define TOTAL_PERSOS_DISPO 2


// Déclaration des players ici pour pas rénvoyer tout le temps comme paramètre
//Player player1, player2;

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
    char* personnage;
    int cowNo;  // Le numéro de la vache
    int direction;
    int r,g,b;
};

struct GameStatus{
    bool isOpen;  // Au moins une fenetre est ouverte
    bool inMenu;
    bool inGame;  // En train de jouer
    bool gameOver;
    bool pickingTheCow;
    int score;
};

// "Globale" pour les donnés principales du jeu
Gamestatus gameStatus;
