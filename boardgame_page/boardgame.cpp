//
// Created by Brynlee Crispin on 6/15/26.
//

#include "boardgame.h"
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "boardgame.h"
/*
using namespace std;

void run_question() {

    string boardgame_background = "../boardgame_page/qpage_images/main_page.png"; // TODO: FIX THIS!

    // Create window
    SDL_Window* window = SDL_CreateWindow("Communityland",
        1366, 768, 0);

    // Initializing SDL Library essentials
    SDL_Init(SDL_INIT_VIDEO);
    // SDL_SetTextInputArea(window, rect);
    SDL_StartTextInput(window);

    // Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    // Make background image texture
    SDL_Texture* background_texture = IMG_LoadTexture(renderer, boardgame_background.c_str());


    bool running = true;

    SDL_Event main_event;


    while (running) {

        // Rando event so window works
        while (SDL_PollEvent(&main_event)) {
            if (main_event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Set background image to black then clear
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Set intended image as background
        SDL_RenderTexture(renderer, background_texture, NULL, NULL);

        SDL_RenderPresent(renderer);

    }

    // Destroy all
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}
*/