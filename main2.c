#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "defs.h"
#include "listes.c"





/// @brief Dessine un tableau, c'etait juste un test pour apprendre à utiliser SDL
/// @param m_renderer 
void drawGrid(SDL_Renderer * m_renderer){
    // Définir la taille des carrés :
    SDL_Rect rectangle;
    int rw = 10;  // Width rectangle
    int rh = 10;  // Height rectangle
    int dist = 1; // Distance entre les rectangles (1 pour éffacer l'espace entre blocks)

    for (int ligne = 0; ligne < SCREEN_WIDTH;ligne++){
        for (int col = 0; col < SCREEN_HEIGHT;col++){
            SDL_SetRenderDrawColor(m_renderer,240,240,240,255);
            rectangle.x = ligne; rectangle.y = col; rectangle.w = 10; rectangle.h = 10;
            SDL_RenderFillRect(m_renderer,&rectangle);
            col+=rw - dist; // -1 pour éffacer l'espace entre blocks
        }
        ligne+=rh - dist;
    }
}

void DrawPlayer(SDL_Renderer * m_renderer, Player* player){
    SDL_Rect rectangle;
    int rw = PLAYER_WIDTH;  // Width rectangle
    int rh = PLAYER_HEIGHT;  // Height rectangle
    int dist = 0; // Distance entre les rectangles

    SDL_SetRenderDrawColor(m_renderer,player->r,player->g,player->b,255);
    rectangle.x = player->position.x; rectangle.y = player->position.y; rectangle.w = PLAYER_WIDTH; rectangle.h = PLAYER_HEIGHT;
    SDL_RenderFillRect(m_renderer,&rectangle);
}



void MovePlayer(Player* player){

    switch (player->direction)
    {
    case UP:
        player->position.y-=SPEED;
        break;
    case DOWN:
        player->position.y+=SPEED;
        break;
    case RIGHT:
        player->position.x+=SPEED;
        break;
    case LEFT:
        player->position.x-=SPEED;
        break;    
    default:
        NULL;
        break;
    }

    // Éviter de sortir de la fenetre
    if (player->position.x < 0){
        player->position.x = 0;
    }else if(player->position.y < 0){
        player->position.y = 0;
    }else if(player->position.x + PLAYER_WIDTH > SCREEN_WIDTH){
        player->position.x = SCREEN_WIDTH - SPEED;  // 10 est la taille carré
    }else if(player->position.y + PLAYER_HEIGHT > SCREEN_HEIGHT){
        player->position.y = SCREEN_HEIGHT - SPEED;
    }
}

int main( int argc, char * argv[] ) {
    SDL_Window * m_window = NULL; 
    SDL_Renderer * m_renderer = NULL;
    SDL_Event events;
    SDL_Rect rectangle;
    SDL_Point point;
    
    // PLAYER 1
        Player player1;
        Position derniereP1;
        Liste * CacaP1 = initialisation();

        // Position
        player1.initPos.x = X_INIT_P1;
        player1.initPos.y = Y_INIT_P1;
        player1.position = player1.initPos;
        derniereP1.x = 0;
        derniereP1.y = 0;

    // PLAYER 2
    Player player2;
    Position derniereP2;
    Liste * CacaP2 = initialisation();
    player2.position.x = SCREEN_WIDTH - SPEED;
    player2.position.y = SCREEN_HEIGHT - SPEED;
    player2.initPos = player2.position;
    player2.r=255;
    player2.g=255;
    player2.b=255;
    derniereP2.x = player2.position.x;
    derniereP2.y = player2.position.y;

    // Config Fenetres
    bool isOpen = true;
    bool inGame = false;
    bool inMenu = true;


    // DEMARRAGE DE SDL
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) == -1)    
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        isOpen = false;
        exit(EXIT_FAILURE);         
    }
    else{
        // Céation de la fenetre et du renderer
        //SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN,&m_window, &m_renderer);
        
        m_window = SDL_CreateWindow("C-Tron",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN);
        m_renderer = SDL_CreateRenderer(m_window, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
       
        SDL_SetWindowTitle(m_window, "CaCOW");
        //SDL_SetWindowIcon

        
        // Afficher le menu initiel
        while (isOpen && inMenu)
        { 
            while (SDL_PollEvent(&events))
            {
                switch (events.type)
                {
                case SDL_QUIT:
                    isOpen = false;
                    break;
                case SDL_KEYDOWN:
                    switch (events.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        isOpen = false;
                        break;
                    case SDLK_RETURN:  // Si clique dans le button de start
                        inMenu = false;
                        inGame = true;
                    }
                }
            }   

            //EXECUÇÃO DO MENU AQUI
            // Afficher imgage menu
            SDL_SetRenderDrawColor(m_renderer, 25, 25, 25, 255);
            SDL_RenderClear(m_renderer);
            SDL_RenderPresent(m_renderer);

        }

        
        // Affichage du jeux
        while (isOpen && inGame)
        {        
            while (SDL_PollEvent(&events))
            {
                // ENTREES
                switch(events.type){
                    case SDL_QUIT:
                        isOpen = false;
                    break;                    
                    case SDL_KEYDOWN:  // Detection des clés clavier
                        switch(events.key.keysym.sym)
                        {
                            case SDLK_UP:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                                player2.direction = UP;
                            break;

                            case SDLK_DOWN:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                                player2.direction = DOWN;
                            break;

                            case SDLK_LEFT:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                                player2.direction = LEFT;
                            break;

                            case SDLK_RIGHT:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                                player2.direction = RIGHT;
                            break;

                            case SDLK_w:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                                player1.direction = UP;
                            break;

                            case SDLK_s:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                                player1.direction = DOWN;
                            break;

                            case SDLK_a:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                                player1.direction = LEFT;
                            break;

                            case SDLK_d:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                                player1.direction = RIGHT;
                            break;

                            case SDLK_ESCAPE:
                                isOpen = false;
                            break;
                        }      
                }

            }
                // Enregistrer la dernière position avant, pour tester après
                derniereP1.x = player1.position.x;
                derniereP1.y = player1.position.y;
                MovePlayer(&player1);

                derniereP2.x = player2.position.x;
                derniereP2.y = player2.position.y;
                MovePlayer(&player2);

                // Insérer que si la position a changé
                if (derniereP2.x != player2.position.x || 
                    derniereP2.y != player2.position.y)
                    // Et si la difference est supérieure à width/length de l'objet
                {                       
                    if (rand() % 4 + 1 == 1){ // Pas toujours faire caca
                        insertion(CacaP2,player2.position.x,player2.position.y);
                    }                  
                }

                // Insérer que si la position a changé
                if (derniereP1.x != player1.position.x || 
                    derniereP1.y != player1.position.y)
                    // Et si la difference est supérieure à width/length de l'objet
                {
                    if (rand() % 4 + 1 == 1){ // Pas toujours faire caca
                    insertion(CacaP1,player1.position.x,player1.position.y);
                    }
                }

                // Colision avec la caca
                // Se jogador p1 comeu cocô p1
                // "Voce comeu seu proprio cocô"
                if (
                    //AtePoo(&player1,CacaP1) ||
                    AtePoo(&player1,CacaP2) ||
                    AtePoo(&player2,CacaP1) 
                    //|| AtePoo(&player2,CacaP2)
                    )
                {
                    isOpen = false;
                }


                // Effacer objet de la liste si supérieur que la taille souhaité

                // NETTOYAGE ÉCRAN (sem isso a tela cria um artefato feio)
                SDL_SetRenderDrawColor(m_renderer, 0x46, 0xA5, 0x3B, 0xFF);
                SDL_RenderClear(m_renderer);

                // TRAITEMENT                

                // Grid
                //drawGrid(m_renderer);           
                afficherListe(m_renderer,CacaP2,m_window);                         
                afficherListe(m_renderer,CacaP1,m_window);
                DrawPlayer(m_renderer, &player2); 
                DrawPlayer(m_renderer, &player1);           
                
                SDL_Delay(DELAY);
                
                // AFFICHAGE                
                SDL_RenderPresent(m_renderer); // mise à jour de la fenêtre PRESENTER
        
        }
    }

    // Libération des objets
    if (isOpen == false){
       SDL_DestroyWindow(m_window);
       SDL_DestroyRenderer(m_renderer);
       SDL_Quit();
    }

    return EXIT_SUCCESS;
}