#include "TheLife/LifeData.h"
#include "TheLife/TheLifePart.h"

#include <iostream>
#include <unistd.h>
#include <SDL.h>

using namespace std;

void PrintBoard(SDL_Renderer* &renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for(int x = 0;x<BoardSize_X;x++) {
        for(int y = 0;y<BoardSize_Y;y++) {
            if(LifeBoard[x][y])SDL_RenderDrawPoint(renderer, y,x);
        }
    }
    SDL_RenderPresent(renderer);
}

int main (int argc, char* argv[])
{
    SetBoard();
    NewBoard();

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("The Game Of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetScale(renderer,5,5);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        SDL_Delay(100);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN) {
                running = false;
                break;
            }
        }
        NextBoard();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        PrintBoard(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
