//
// Created by Brynlee Crispin on 5/31/26.
//

/*
#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "start_main.h"

using namespace std;



// Runs the game's intro screen
void run_starting_page() {

    // Declare background image
    string background = "/Users/brynleemaya/PIVOT/PIVOT-boardgame/starting_page/qpage_images/welcome.png"; //fix

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
    SDL_Texture* background_texture = IMG_LoadTexture(renderer, background.c_str());

    SDL_Surface* password_surface = TTF_RenderText_Blended(font, text_buffer, 0, (SDL_Color){255, 255, 255, 255});
    SDL_Texture* password_texture = SDL_CreateTextureFromSurface(renderer, password_surface);



    bool running = true;

    SDL_Event event;

    int cursor_index = 0;


    while (running) {

        // Rando event so window works
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }

           while SDL_PollEvent(@sdlEvent)
               do {

               } while (true);

        }

        // Set background image to black then clear
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Set intended image as background
        SDL_RenderTexture(renderer, background_texture, NULL, NULL);

        SDL_RenderPresent(renderer);

        // Rendering password entry box
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &textbox_rect);
        SDL_RenderTexture(renderer, password_texture, NULL, &textbox_rect);
    }

    // Destroy all
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(password_texture);
    SDL_DestroySurface(password_surface);
    SDL_Quit();

}

*/