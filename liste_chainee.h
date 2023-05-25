#ifndef H_LISTE_CHAINEE
#define H_LISTE_CHAINEE
#include "defs.h"

typedef struct Element Element;
struct Element
{
    Player caca;    
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int x, int y);
void suppression(Liste *liste);
void afficherListe(SDL_Renderer * m_renderer, Liste *liste, SDL_Window* m_window);
void FaireCaca(SDL_Renderer * m_renderer, Player* player, SDL_Window* m_window);
void SetBackground(SDL_Renderer * m_renderer, char* src);




int qttCarees;

#endif
