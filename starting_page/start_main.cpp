//
// Created by Brynlee Crispin on 5/31/26.
//


#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>


using namespace std;

void run_starting_page() {

    // Declare background image
    string background = "/Users/brynleemaya/PIVOT/PIVOT-boardgame/starting_page/page_images/welcome.png";


    // Initializing SDL Library essentials
    SDL_Init(SDL_INIT_VIDEO);

    // Create window
    SDL_Window* window = SDL_CreateWindow("Communityland",
        1366, 768, 0);


    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);


    SDL_Texture* background_texture = IMG_LoadTexture(renderer, background.c_str());
    bool running = true;

    SDL_Event event;
    while (running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderTexture(renderer, background_texture, NULL, NULL);

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}
