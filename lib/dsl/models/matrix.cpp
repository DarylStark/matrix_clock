#include "matrix.h"

namespace dsl
{
    namespace models
    {
        MatrixFontCharacter::MatrixFontCharacter(PixelList pixels)
            : __pixels(pixels)
        {
        }

        const PixelList &MatrixFontCharacter::get_pixels() const
        {
            return __pixels;
        }

        uint16_t MatrixFontCharacter::get_width()
        {
            if (__width > 0)
                return __width;

            for (const auto &pixel : __pixels)
            {
                if (pixel.first > __width)
                    __width = pixel.first;
            }
            __width += 1;
            return __width;
        }

        MatrixFont::MatrixFont(uint16_t space_width /* = 1 */)
            : __space_width(space_width)
        {
        }

        void MatrixFont::set_character(const char &character, const MatrixFontCharacter &face)
        {
            __characters[character] = face;
        }

        MatrixFontCharacter &MatrixFont::get_character_face(const char character)
        {
            return __characters.at(character);
        }

        uint16_t MatrixFont::get_space_width() const
        {
            return __space_width;
        }
    };
};