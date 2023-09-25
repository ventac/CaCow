#include <stdio.h>
#include <stdlib.h>
#include "liste_chainee.h"
//#include <SDL2_image/SDL_image.h>


Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Définition des valeurs de démarrage
    element->caca.position.x = 0;
    element->caca.position.y = 0;
    qttCarees = 0;
    
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}


void insertion(Liste *liste, int x, int y)
{
    // Création du nouvel Élément
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Définition des valeurs standard
    nouveau->caca.position.x = x;
    nouveau->caca.position.y = y;
    nouveau->caca.r = 130 + (rand() % (220-130));  // Coleur en aléatoire. Tons de marron
    qttCarees++;
    
    // Insertion de l'ÈlÈment au dÈbut de la liste
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
    //printf("NULL\n");
}


// Essai de detecter le prochain mouvement pour toucher le trai de l'autre player

bool AtePoo(Player* player,Liste *liste){
    if (liste == NULL)    
        exit(EXIT_FAILURE);

    Element *actuel = liste->premier;

    // Détecter le prochain mouvement
    int next_X = 0;
    int next_Y = 0;

    switch (player->direction)
    {
    case UP:
        next_Y = SPEED;  // Trocar por CACA_WIDTH se for mto        
        break;
    case DOWN:
        next_Y = - SPEED;
        break;
    case LEFT:
        next_X = - SPEED;
        break;
    case RIGHT:
        next_X = SPEED;
        break;       
    default:
        NULL;
        break;
    }
    
    while (actuel != NULL)
    {
        if 
        (
                ((player->position.x + next_X >= actuel->caca.position.x) 
                && (player->position.x + next_X <= actuel->caca.position.x + CACA_WIDTH))
            && 
                ((player->position.y + next_Y >= actuel->caca.position.y) 
                && (player->position.y + next_Y <= actuel->caca.position.y + CACA_HEIGHT))
            && 
                ((player->position.x != player->initPos.x)
                && (player->position.y != player->initPos.y)))  // et la position est differente de l'initialle
        {
            return true;  // La vache a mangée le truc
        }
        actuel = actuel->suivant;
    }
    return false;  // La vache n'a pas mangé le truc
}


// Backup AtePoo


/*
bool AtePoo(Player* player,Liste *liste){
    if (liste == NULL)    
        exit(EXIT_FAILURE);

    Element *actuel = liste->premier;
    
    while (actuel != NULL)
    {
        if 
        (((
            ((player->position.x >= actuel->caca.position.x) 
            && (player->position.x <= (actuel->caca.position.x + CACA_WIDTH)))       
        )
        && 
            ((player->position.y >= actuel->caca.position.y) 
            && player->position.y <= (actuel->caca.position.y + CACA_HEIGHT)))
        && 
            ((player->position.x != player->initPos.x)
            && (player->position.y != player->initPos.y  // et la position est differente de l'initialle
        ))) 
        
         {
            return true;
         }
        actuel = actuel->suivant;
    }
    return false;
}


*/






//Loads media
bool loadMedia(char * src);

//The image we will load and show on the screen
SDL_Surface* gTextura = NULL;
SDL_Texture* txtTextura = NULL;

bool loadMedia(char * src)
{
	//Loading success flag
	bool success = true;

	//Load splash image
	//gTextura = SDL_LoadBMP( "hello_world.bmp" );
    gTextura = SDL_LoadBMP(src);
	if( gTextura == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void SetBackground(SDL_Renderer * m_renderer, char* src){
    if(!loadMedia(src)){
        printf( "Failed to load media!\n" );
    }
    else{
        // SDL_RenderClear(m_renderer);
        txtTextura = SDL_CreateTextureFromSurface(m_renderer, gTextura);
        SDL_RenderCopy(m_renderer, txtTextura, NULL, NULL);
        // SDL_RenderPresent(m_renderer);
        // SDL_DestroyTexture(txtTextura);
    }
}


/*
// Version avec image
void FaireCaca(SDL_Renderer * m_renderer, Player* caca, SDL_Window * m_window){

    SDL_Rect rectangle;
    int rw = PLAYER_WIDTH;  // Width rectangle
    int rh = PLAYER_HEIGHT;  // Height rectangle
    int dist = 0; // Distance entre les rectangles


    if(!loadMedia("hello_world.bmp"))
    {
        printf( "Failed to load media!\n" );
    }
    else
    {
        //SDL_CreateSur
        //rectangle = {caca->position.x,caca->position.y,PLAYER_WIDTH,PLAYER_HEIGHT};
        rectangle.x = caca->position.x; rectangle.y = caca->position.y; rectangle.w = PLAYER_WIDTH; rectangle.h = PLAYER_HEIGHT;
        SDL_Texture* image_surface = SDL_CreateTextureFromSurface(m_renderer, gTextura);
        SDL_RenderCopy(m_renderer, image_surface, NULL, &rectangle);
	}
}*/

void Clouds(SDL_Renderer * m_renderer, SDL_Window * m_window, Position cloudPos){

    SDL_Rect rectangle;

    if(!loadMedia("/IMG/clouds.bmp"))
    {
        printf( "Failed to load media!\n" );
    }
    else
    {        
        rectangle.x = cloudPos.x; rectangle.y = 30; 
        rectangle.w = SCREEN_WIDTH; rectangle.h = SCREEN_HEIGHT;
        SDL_Texture* image_surface = SDL_CreateTextureFromSurface(m_renderer, gTextura);
        SDL_RenderCopy(m_renderer, image_surface, NULL, &rectangle);

        // Retour des nouages si a la fin
        // if (cloudPos.x > SCREEN_WIDTH){
        //     cloudPos.x = 0;
        // }
	}
}

void FaireCaca(SDL_Renderer * m_renderer, Player* caca, SDL_Window * m_window){
    SDL_Rect rectangle;

    // Ombre
    SDL_SetRenderDrawColor(m_renderer,caca->r,110,59,255);
    rectangle.x = caca->position.x; rectangle.y = caca->position.y; rectangle.w = CACA_WIDTH; rectangle.h = CACA_HEIGHT;
    SDL_RenderFillRect(m_renderer,&rectangle);

}