#include <SDL2/SDL.h>

#include <iostream>

#include "graphics/primitives/RGBASurface.hpp"

typedef uint32_t color_t;

int main() {
	SDL_Window * win = nullptr;
	win = SDL_CreateWindow("Serenity", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_SHOWN);
	if (win == nullptr){
	   std::cout << SDL_GetError() << std::endl;
	   return 1;
	}

    graphics::RGBASurface surface(100, 100);

    const graphics::ColorRGBA from(0, 255, 0, 255);
    const graphics::ColorRGBA to(100, 0, 0, 255);
    const unsigned rad = 40;
    struct {unsigned x; unsigned y;} center = {50, 50};
    for (unsigned x = 0; x < surface.width(); ++x) {
        for (unsigned y = 0; y < surface.height(); ++y) {

            static_cast<unsigned>(from.red);
        }
    }
    surface.set_pixel(40, 5, graphics::ColorRGBA(0, 0, 255, 255));

    SDL_Surface * screen = SDL_GetWindowSurface(win);

    // SDL_Rect r = {0, 0, 20, 20};
    SDL_BlitSurface(surface.surface(), NULL, screen, NULL);

    SDL_UpdateWindowSurface(win);

    SDL_Delay(2000);

    // SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    SDL_Quit();

	return 0;
}
