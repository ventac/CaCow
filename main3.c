#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "defs.h"
//CTRL Shift K

    // Bouttons
    /// Enum sert à faciliter pour pas avoir le besoin de faire un "int KEY_PRESS_SURFACE_DEFAULT = 0" à chaque fois
    enum btn{
        SURFACE_MENU,
        SURFACE_PLAGE,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };
    
    // Fenetre
    SDL_Window* fenetre = NULL;  // The window we'll be rendering to
    SDL_Surface* screenSurface = NULL;  // La surface dans l'intérieur de la fenetre
    // Image
    SDL_Surface* image = NULL;
    // Image comme texture

    // Renderer
    SDL_Renderer* gRenderer = NULL;

    //The images that correspond to a keypress
    SDL_Surface* ListeSurfaces[KEY_PRESS_SURFACE_TOTAL];
    SDL_Surface* surfaceActive = NULL;  // Image affichée dans le moment

/// @brief Fonction pour l'initialisation du programme (pour moins écrire dans main)
/// @return
bool init(){

    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {

        //Create window
        fenetre = SDL_CreateWindow( "C-Tron", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( fenetre == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(fenetre);

            //Fill the surface white
            //SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xAA, 0xFF, 0xFF));
            
            //Update the surface
            //SDL_UpdateWindowSurface(fenetre);
            success = true;
        }
    }
    return success;

}

bool ChargerImage(char* cheminImage){
//bool ChargerImage(){
    bool success = true;

    //image = SDL_LoadBMP("IMG/quadra.bmp");
    image = SDL_LoadBMP(cheminImage);
    //image = SDL_LoadBMP(chemin);
    if (image == NULL){
        printf("Pas pu charger l'image %s! Erreur SDL : %s\n", "IMG/quadra.bmp", SDL_GetError());
        success = false;
    }
    return success;
    ///Users/guilhermeventapane/Downloads/preview.bmp
}

SDL_Surface* chargerSurface(char* chemin)
{
    // Image optimisée
    SDL_Surface* surfaceOptimisee = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(chemin);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", chemin, SDL_GetError() );
    }else{   // Adapter l'image à la taille de l'écran

        // Prends la "loadedSurface", la remplace la transforme et la mets dans surfaceOptimisee
        surfaceOptimisee = SDL_ConvertSurface(loadedSurface, screenSurface->format,0);
        if (surfaceOptimisee == NULL){
            printf("Erreur dans la reglage de la taille de l'image %s. Erreur SDL :  %s\n", chemin,SDL_GetError());
        }

        // Effacer l'anciene surface de la memoire et de l'affichage
        SDL_FreeSurface(loadedSurface);
    }

    return surfaceOptimisee;
}



bool loadMedia()
{
    //Loading success flag
    bool success = true;

    // Menu
    ListeSurfaces[ SURFACE_MENU ] = chargerSurface( "IMG/quadra.bmp" );
    if( ListeSurfaces[ SURFACE_MENU ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    // Plage
    ListeSurfaces[ SURFACE_PLAGE ] = chargerSurface( "IMG/praia.bmp" );
    if( ListeSurfaces[ SURFACE_PLAGE ] == NULL )
    {
        printf( "Failed to load up image!\n" );
        success = false;
    }

    //Load down surface
    ListeSurfaces[ KEY_PRESS_SURFACE_DOWN ] = chargerSurface( "04_key_presses/down.bmp" );
    if( ListeSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
    {
        printf( "Failed to load down image!\n" );
        success = false;
    }

    //Load left surface
    ListeSurfaces[ KEY_PRESS_SURFACE_LEFT ] = chargerSurface( "04_key_presses/left.bmp" );
    if( ListeSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface
    ListeSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = chargerSurface( "04_key_presses/right.bmp" );
    if( ListeSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}

void fermerProgramme()
{
    //Deallocate surfaces
    for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
    {
        SDL_FreeSurface(ListeSurfaces[i]);
        ListeSurfaces[i] = NULL;
    }


    //Deallocate surface
    //SDL_FreeSurface(screenSurface);
    //screenSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( fenetre );
    fenetre = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}



int main( int argc, char* args[] )
{

    if (init()==false){
        printf("Erreur dans l'initialisation");
    }else{

        if (!loadMedia()){
            printf("Pas réussi à charger la media");
        }else{
            bool sortir = false;
            SDL_Event e;  // Gestion évenément

			//Set default current surface
			surfaceActive = ListeSurfaces[SURFACE_MENU];
            // Pendent que l`utilisateur ne sort pas du jeu "Main Loop"
            while(!sortir){
            // Tourner jusqu'à que l'événement arrive
                while(SDL_PollEvent(&e)!=0){
                    // Si l'utilisateur souhaite sortir du programme
                    if(e.type == SDL_QUIT)
                    {
                        sortir = true;
                    }else if(e.type == SDL_KEYDOWN){
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                            break;

                            case SDLK_DOWN:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                            break;

                            case SDLK_LEFT:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                            break;

                            case SDLK_RIGHT:
                            //surfaceActive = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                            break;

                            default:
                                surfaceActive = ListeSurfaces[SURFACE_PLAGE];
                            break;
                        }                   
                    }
                }
            // Appliquer l'image, mais pas encore l'afficher
            //SDL_BlitSurface(surfaceActive, NULL, screenSurface, NULL);

            // Appliquer l'image avec des dimensions modifiées
            SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled(surfaceActive, NULL, screenSurface, &stretchRect );

            // Mise à jour de la fenetre
            SDL_UpdateWindowSurface(fenetre);

            // Hack to get window to stay up
            //SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

            } 
        }
    }

    // Mise à jour de la fenetre
    //SDL_UpdateWindowSurface(fenetre);


    //Quit SDL subsystems
    fermerProgramme();

    return 0;
}
