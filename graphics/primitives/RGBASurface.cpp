#include "RGBASurface.hpp"

#include <SDL2/SDL.h>

#include "common/SDLException.hpp"

namespace graphics {

RGBASurface::RGBASurface(unsigned width, unsigned height) {
    surface_ = SDL_CreateRGBSurface(0, width, height, 32, ColorRGBA::RED_MASK,
        ColorRGBA::GREEN_MASK, ColorRGBA::BLUE_MASK, ColorRGBA::ALPHA_MASK);
    if (surface_ == NULL) {
        throw common::SDLException();
    }
    if (SDL_MUSTLOCK(surface_) == SDL_TRUE) {
        // This error should never occur
        throw common::SDLException("RGBASurface is requiring a lock");
    }
}

RGBASurface::~RGBASurface() {
    SDL_FreeSurface(surface_);
    surface_ = NULL;
}

void RGBASurface::set_pixel(unsigned x, unsigned y, ColorRGBA color) {
    uint8_t * start_of_row = reinterpret_cast<uint8_t *>(surface_->pixels) +
        surface_->pitch * y;
    uint32_t * target  = reinterpret_cast<uint32_t *>(start_of_row) + x;
    *target = color.value();
}

ColorRGBA RGBASurface::get_pixel(unsigned x, unsigned y) const {
    auto start_of_row = reinterpret_cast<uint8_t const *>(surface_->pixels) +
        surface_->pitch * y;
    auto target = reinterpret_cast<uint32_t const *>(start_of_row) + x;
    return *target;
}

SDL_Surface * RGBASurface::surface() {
    return surface_;
}

} // namespace graphics
