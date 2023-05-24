#include "SDL.h"
#include <windows.h>
#include <iostream>

int main(int argc, char** argv)
{
	unsigned int lasttime = 0, currenttime = 0;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* mWindow;
	int ball_x = 450;
	int wall_x = 10;
	int wall_y = 50;
	mWindow = SDL_CreateWindow(
		"Game Programming in C++",
		0,
		30,
		500,
		500,
		0
	);
	SDL_Renderer* mRenderer;
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
while (1) {
		if (SDL_GetTicks() > currenttime + 16) {
			SDL_Event e;
			if (SDL_PollEvent(&e)) {
				if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP ) {
					if(wall_y >= 0 + 10)wall_y -= 10;
				} else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN) {
					if(wall_y <= 500 - 50 - 10)wall_y += 10;
				}
			}
			SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
			SDL_RenderClear(mRenderer);
			SDL_SetRenderDrawColor(mRenderer, 255, 0, 0, 255);
			SDL_Rect wall{
				wall_x,
				wall_y,
				10,
				50
			};
			SDL_RenderFillRect(mRenderer, &wall);
			SDL_SetRenderDrawColor(mRenderer, 0, 255, 0, 255);
			SDL_Rect ball{
				ball_x,
				250,
				10,
				10
			};
			SDL_RenderFillRect(mRenderer, &ball);
			SDL_RenderPresent(mRenderer);
			std::cout << currenttime << "\n";
			std::cout << "wall_y : " << wall_y << "\n";
			currenttime = SDL_GetTicks() / 100 * 100;
			ball_x -= 5;
		}
		if (currenttime > 30000) break;
	}

	
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
	return 0;
}