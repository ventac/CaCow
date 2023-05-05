#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"


Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    //element->nombre = 0;
    element->caca.position.x = 0;
    element->caca.position.y = 0;
    qttCarees = 0;
    
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}


void insertion(Liste *liste, int x, int y)
{
    /* CrÈation du nouvel ÈlÈment */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    //nouveau->caca = newCaca;
    nouveau->caca.position.x = x;
    nouveau->caca.position.y = y;
    qttCarees++;

    
    /* Insertion de l'ÈlÈment au dÈbut de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(SDL_Renderer * m_renderer,Liste *liste,SDL_Window * m_window)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        FaireCaca(m_renderer,&actuel->caca,m_window);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

bool AtePoo(Player* player,Liste *liste){
    if (liste == NULL)    
        exit(EXIT_FAILURE);

    Element *actuel = liste->premier;
    
    while (actuel != NULL)
    {
        if (((player->position.x == actuel->caca.position.x)
         && (player->position.y == actuel->caca.position.y))
         && 
         ((player->position.x != player->initPos.x)
         && (player->position.y != player->initPos.y)))  // et la position est differente de l'initialle
        
         {
            return true;
         }
        actuel = actuel->suivant;
    }
    return false;
}

 //The image we will load and show on the screen
    SDL_Surface* gHelloWorld = NULL;

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP( "hello_world.bmp" );
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}


/// PAREI AQUI
void FaireCaca(SDL_Renderer * m_renderer, Player* caca, SDL_Window * m_window){

    SDL_Rect rectangle;
    int rw = PLAYER_WIDTH;  // Width rectangle
    int rh = PLAYER_HEIGHT;  // Height rectangle
    int dist = 0; // Distance entre les rectangles


    if( !loadMedia() )
    {
        printf( "Failed to load media!\n" );
    }
    else
    {
        //Apply the image
        //SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );


            // SDL_Rect srcrect = { 0, 0, 100, 100 };
            // SDL_Rect dstrect = { caca->position.x, caca->position.y, PLAYER_WIDTH, PLAYER_HEIGHT };

            // //Apply the image
            // SDL_BlitSurface( gHelloWorld, &srcrect, m_renderer, &dstrect );
            
            //Update the surface
            //SDL_UpdateWindowSurface( m_renderer );

	}



    // Dessiner la caca
    SDL_SetRenderDrawColor(m_renderer,165,110,59,255);
    rectangle.x = caca->position.x; rectangle.y = caca->position.y; rectangle.w = PLAYER_WIDTH; rectangle.h = PLAYER_HEIGHT;
    SDL_RenderFillRect(m_renderer,&rectangle);
}



// void FaireCaca(SDL_Renderer * m_renderer, Player* caca){
//     SDL_Rect rectangle;
//     int rw = PLAYER_WIDTH;  // Width rectangle
//     int rh = PLAYER_HEIGHT;  // Height rectangle
//     int dist = 0; // Distance entre les rectangles

//     // Dessiner la caca
//     SDL_SetRenderDrawColor(m_renderer,165,110,59,255);
//     rectangle.x = caca->position.x; rectangle.y = caca->position.y; rectangle.w = PLAYER_WIDTH; rectangle.h = PLAYER_HEIGHT;
//     SDL_RenderFillRect(m_renderer,&rectangle);
// }