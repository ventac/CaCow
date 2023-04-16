/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <stdio.h>

int initMixer() {
	Mix_Init(MIX_INIT_MP3);
	SDL_Init(SDL_INIT_AUDIO);
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_Mixer couldnt init. Err: %s\n", Mix_GetError());
		return -1;
	}
	//setVolume(80);
	return 0;
}


int main(int argc, char* argv[]) {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL2 failed to initialize: %s\n", SDL_GetError());
        return -1;
    }

    initMixer();


/*
    // Load the mp3 file
    Mix_Music* music = Mix_LoadMUS("Music/cow.mp3");
    if (!music) {
        printf("Failed to load mp3 file: %s\n", Mix_GetError());
        return -1;
    }

    // Play the music
    Mix_PlayMusic(music, 0);

    // Wait for the music to finish playing
    while (Mix_PlayingMusic()) {
        SDL_Delay(100);
    }

    // Free the music and quit SDL_mixer and SDL2
    Mix_FreeMusic(music);
    Mix_CloseAudio();

    */
    SDL_Quit();
    
    return 0;
}