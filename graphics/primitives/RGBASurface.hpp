#pragma once

#include "graphics/primitives/ColorRGBA.hpp"

class SDL_Surface;

namespace graphics {

class RGBASurface {
	SDL_Surface * surface_;
	unsigned width_;
	unsigned height_;
public:
	RGBASurface(unsigned width, unsigned height);
    ~RGBASurface();
	void set_pixel(unsigned x, unsigned y, ColorRGBA color);
    ColorRGBA get_pixel(unsigned x, unsigned y) const;
    SDL_Surface * surface();
    unsigned width() const;
    unsigned height() const;
};

} // namespace graphics
