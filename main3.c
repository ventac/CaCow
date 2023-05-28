#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "defs.h"
//CTRL Shift K

int main(int argc, char* argv[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Cow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set the background color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear the renderer with the background color
    SDL_RenderClear(renderer);

    // Set the drawing color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Draw the body of the cow
    SDL_Rect bodyRect = { 100, 100, 200, 150 };
    SDL_RenderFillRect(renderer, &bodyRect);

    // Draw the head of the cow
    SDL_Rect headRect = { 250, 50, 100, 100 };
    SDL_RenderFillRect(renderer, &headRect);

    // Draw the eyes of the cow
    SDL_Rect leftEyeRect = { 275, 75, 20, 20 };
    SDL_RenderFillRect(renderer, &leftEyeRect);

    SDL_Rect rightEyeRect = { 305, 75, 20, 20 };
    SDL_RenderFillRect(renderer, &rightEyeRect);

    // Draw the mouth of the cow
    SDL_Rect mouthRect = { 265, 105, 70, 20 };
    SDL_RenderFillRect(renderer, &mouthRect);

    // Draw the legs of the cow
    SDL_Rect frontLeftLegRect = { 90, 250, 40, 100 };
    SDL_RenderFillRect(renderer, &frontLeftLegRect);

    SDL_Rect frontRightLegRect = { 270, 250, 40, 100 };
    SDL_RenderFillRect(renderer, &frontRightLegRect);

    SDL_Rect backLeftLegRect = { 90, 350, 40, 100 };
    SDL_RenderFillRect(renderer, &backLeftLegRect);

    SDL_Rect backRightLegRect = { 270, 350, 40, 100 };
    SDL_RenderFillRect(renderer, &backRightLegRect);

    // Render the drawing
    SDL_RenderPresent(renderer);

    // Wait for the user to close the window
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}