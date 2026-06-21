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

    Uint32 countdown = 30;
    char time_text[15];
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
    SDL_Texture* qbackground_texture = IMG_LoadTexture(renderer, question_background.c_str());

    // Generate fonts
    TTF_Font* gagalin = TTF_OpenFont("/Users/brynleemaya/PIVOT/PIVOT-boardgame/fonts/Gagalin.otf", 12);

    bool running = true;

    SDL_Event event;
    SDL_Color white = {0, 0, 0, 0};

    while (running) {
        // Event so window is functional
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }


            SDL_Texture* total_texture = SDL_CreateTextureFromSurface(renderer, countdown);
            SDL_Rect total_rect = {530, 420, countdown->w, countdown->h};
            SDL_RenderCopy(renderer, total_texture, NULL, &total_rect);


            sprintf(time_text, "%02d", countdown);

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
        SDL_RenderTexture(renderer, qbackground_texture, NULL, NULL);

        SDL_Surface* text_surface = TTF_RenderText_Blended(gagalin, time_text, white);
        SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

        SDL_RenderPresent(renderer);

        SDL_Rect text_rect = {185, 420, text_surface->w, text_surface->h};

        SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);

    }

    // Destroy all
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}
