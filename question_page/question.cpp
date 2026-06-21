//
// Created by Brynlee Crispin on 6/15/26.
//

#include "question.h"
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>


using namespace std;
/*
void update_total_time(char* buffer, size_t size, double duration) {
    int time = int(duration) / 60;

    sprintf(buffer, "%02d", time);
}
*/
void run_question() {

    // Starting countdown unit
    Uint32 countdown = 30;

    bool is_paused = false;


    string question_background = "/Users/brynleemaya/PIVOT/PIVOT-boardgame/question_page/qpage_images/question_page.png"; // TODO: FIX THIS!

    // Create window
    SDL_Window* window = SDL_CreateWindow("Communityland",
        1366, 768, 0);

    // Initializing SDL Library essentials
    SDL_Init(SDL_INIT_VIDEO);

    // Create Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    // Make background image texture
    SDL_Texture* background_texture = IMG_LoadTexture(renderer, question_background.c_str());

    // Generate fonts
    TTF_Font* gagalin = TTF_OpenFont("/Users/brynleemaya/PIVOT/PIVOT-boardgame/fonts/Gagalin.otf", 12); // TODO: Fix this too!

    bool running = true;

    string text_sample = "Hi!";

    SDL_Event event;

    SDL_Surface* text_surface;
    SDL_Texture* texture;

    // Creating color
    SDL_Color white = {0, 0, 0, 0};

    while (running) {
        // Event so window is functional
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }


            // Create texture for timer text
            text_surface = TTF_RenderText_Solid(gagalin, text_sample.c_str(), 0, white);
            texture = SDL_CreateTextureFromSurface( renderer, text_surface);
            int width = text_surface->w;
            int height = text_surface->h;

            // Load?




            // Timer mechanics
            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                int x = event.button.x;
                int y = event.button.y;

                if (x > 1130 && x < 1160 && y > 490 && y < 520) {
                    is_paused = false;
                    countdown -= 1;
                }

                if (x > 1248 && x < 1280 && y > 485 && y < 520) {
                    is_paused = true;
                }


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
    SDL_DestroySurface(text_surface);
    SDL_DestroyTexture(background_texture);
    SDL_Quit();

}
