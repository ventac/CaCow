
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
                    gameStatus.inGame = true;
                }
            }
        }   
        SDL_RenderClear(m_renderer);
        SetBackground(m_renderer,"/IMG/MainMenu_2.bmp");
        SDL_RenderPresent(m_renderer);
        SDL_Delay(1000);
        
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
