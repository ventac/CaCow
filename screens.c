
#include "stdbool.h"
#include "defs.h"
#include "liste_chainee.h"

//The image we will load and show on the screen


// Afficher le menu initiel
void ShowMainMenu(SDL_Renderer * m_renderer){
 
    SDL_Event events;

    while (gameStatus.isOpen && gameStatus.inMenu)
    { 
        SDL_RenderClear(m_renderer);
        SetBackground(m_renderer,"/IMG/MainMenu_1.bmp");
        SDL_RenderPresent(m_renderer);
        SDL_Delay(1000);


        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                gameStatus.isOpen = false;
                break;
            case SDL_KEYDOWN:
                switch (events.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gameStatus.isOpen = false;
                    break;
                case SDLK_RETURN:  // Si clique dans le button de start
                    gameStatus.inMenu = false;
                    gameStatus.inGame = false;                    
                }
            }
        }   
        SDL_RenderClear(m_renderer);
        SetBackground(m_renderer,"/IMG/MainMenu_2.bmp");
        SDL_RenderPresent(m_renderer);
        SDL_Delay(1000);
        
    }
}

// TODO: Faire avec des enum
char* GetPickACowPhoto(int choix, int playerNo){
    char* cheminImage = "";

    switch (choix)
    {
    case 0:
        if (playerNo == 1){  // Modifier l'image de chaque player individuallement
            cheminImage = "/IMG/Players/cow_Player_Selection_BrownBull_P1.bmp";
            // Animation ici
        }else{
            cheminImage = "/IMG/Players/cow_Player_Selection_BrownBull_P2.bmp";
        }        
        break;
    case 1:
        if (playerNo == 1){  // Modifier l'image de chaque player individuallement
            cheminImage = "/IMG/Players/cow_Player_Selection_Black_P1.bmp";
        }else{
            cheminImage = "/IMG/Players/cow_Player_Selection_Black_P2.bmp";
        }    
        break;
    case 2:
        /* code */
        break;    
    default:
        if (playerNo == 1){  // Modifier l'image de chaque player individuallement
            cheminImage = "/IMG/Players/cow_Player_Selection_BrownBull_P1.bmp";
        }else{
            cheminImage = "/IMG/Players/cow_Player_Selection_BrownBull_P2.bmp";
        }        
        break;
    }

    return cheminImage;

}

void PickACow(SDL_Renderer * m_renderer){
 // Afficher le menu initiel
    SDL_Event events;
    gameStatus.inGame = false;
    int playerActifP1 = 0;
    int playerActifP2 = 0;
    bool choixPerso = true;

    while (gameStatus.isOpen && gameStatus.pickingTheCow)
    { 
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
                case SDL_QUIT:
                    gameStatus.isOpen = false;
                    break;
                case SDL_KEYDOWN:
                    switch (events.key.keysym.sym)
                    {
                        case SDLK_UP:                 
                            // Passer de la sélection de personnage à la selecion de vache
                            choixPerso = !choixPerso; 
                            break;
                        case SDLK_DOWN:
                            choixPerso = !choixPerso;
                            break;
                        case SDLK_LEFT:
                            // Personnage précedent
                            if (playerActifP2 <= 0){
                                playerActifP2 = 0;
                            }else{
                                playerActifP2--;
                            }
                            break;
                        case SDLK_RIGHT:
                            // Prochain personnage
                            if (playerActifP2 >= TOTAL_PERSOS_DISPO){  // Éviter le maximum dans la liste
                                playerActifP2 = TOTAL_PERSOS_DISPO;
                            }else{
                                playerActifP2++;
                            }
                            break;
                        case SDLK_w:
                            choixPerso = !choixPerso;
                            break;
                        case SDLK_s:
                            choixPerso = !choixPerso;
                            break;
                        case SDLK_a:
                            // Personnage précedent
                            if (playerActifP1 <= 0){
                                playerActifP1 = 0;
                            }else{
                                playerActifP1--;
                            }
                            break;
                        case SDLK_d:
                            // Prochain personnage
                            if (playerActifP1 >= TOTAL_PERSOS_DISPO){  // Éviter le maximum dans la liste
                                playerActifP1 = TOTAL_PERSOS_DISPO;
                            }else{
                                playerActifP1++;
                            }
                            break;
                        case SDLK_ESCAPE:
                            gameStatus.isOpen = false;
                            break;
                        case SDLK_RETURN:  // Si clique dans le button de start
                            gameStatus.inMenu = false;
                            gameStatus.gameOver = false;
                            gameStatus.inGame = true;     
                            gameStatus.pickingTheCow=false;                     
                }
            }   
        }





        //EXECUÇÃO DO MENU AQUI
        // Afficher imgage menu      
        SDL_RenderClear(m_renderer);
        SetBackground(m_renderer,"/IMG/ChooseChar.bmp");
        //SetBackground(m_renderer,"/IMG/Players/cow_Player_B_BrownBull.bmp");
        SetBackground(m_renderer,GetPickACowPhoto(playerActifP1,1));
        SetBackground(m_renderer,GetPickACowPhoto(playerActifP2,2));

        SDL_RenderPresent(m_renderer);
    }
}


void GameOver(SDL_Renderer * m_renderer){
 // Afficher le menu initiel
    SDL_Event events;
    gameStatus.inGame = false;

    while (gameStatus.isOpen && gameStatus.gameOver)
    { 
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                gameStatus.isOpen = false;
                break;
            case SDL_KEYDOWN:
                switch (events.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gameStatus.isOpen = false;
                    break;
                case SDLK_RETURN:  // Si clique dans le button de start
                    gameStatus.inMenu = false;
                    gameStatus.gameOver = false;
                }
            }
        }   

        //EXECUÇÃO DO MENU AQUI
        // Afficher imgage menu
        //SDL_SetRenderDrawColor(m_renderer, 255, 25, 25, 255);
        SDL_RenderClear(m_renderer);
        SetBackground(m_renderer,"/IMG/gameOver.bmp");
        SDL_RenderPresent(m_renderer);
    }
}


void GetReady(SDL_Renderer * m_renderer){
 // Afficher le menu initiel
    SDL_Event events;

    while (gameStatus.isOpen && gameStatus.inMenu)
    { 
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                gameStatus.isOpen = false;
                break;
            case SDL_KEYDOWN:
                switch (events.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gameStatus.isOpen = false;
                    break;
                case SDLK_RETURN:  // Si clique dans le button de start
                    gameStatus.inMenu = false;
                    gameStatus.inGame = true;
                }
            }
        }   

        //EXECUÇÃO DO MENU AQUI
        // Afficher imgage menu
        //SDL_SetRenderDrawColor(m_renderer, 255, 25, 25, 255);
        SetBackground(m_renderer,"/IMG/grama.bmp");
        //SDL_RenderClear(m_renderer);
        SDL_RenderPresent(m_renderer);

        

    }
}
