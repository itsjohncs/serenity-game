#include "ColorRGBA.hpp"

namespace graphics {

ColorRGBA::ColorRGBA(uint32_t value) : red(value >> 24),
		green(value >> 16 & 0xFF), blue(value >> 8 & 0xFF),
		alpha(value & 0xFF) {
	// Do nothing
}

ColorRGBA::ColorRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
		red(red), green(green), blue(blue), alpha(alpha) {
	// Do nothing
}

uint32_t ColorRGBA::value() const {
	return red << 24 | green << 16 | blue << 8 | alpha;
}

} // namespace graphics
