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

    // Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    // Make background image texture
    SDL_Texture* background_texture = IMG_LoadTexture(renderer, background.c_str());


    bool running = true;

    SDL_Event event;


    while (running) {

        // Rando event so window works
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        // Set backgroun image to black then clear
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Set intended image as background
        SDL_RenderTexture(renderer, background_texture, NULL, NULL);

        SDL_RenderPresent(renderer);

    }

    // Destory all
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}
