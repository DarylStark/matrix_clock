#include "ws2812b_matrix.h"

namespace dsl
{
    namespace arduino_components
    {

        WS2812B_Matrix::WS2812B_Matrix(const std::string &name, uint8_t gpio, uint16_t width, uint16_t height)
            : WS2812B(name, gpio, width * height), __width(width), __height(height)
        {
        }

        void WS2812B_Matrix::set_pixel(uint16_t x, uint16_t y, Color color, bool show /* = false */)
        {
            int32_t index = get_led_index(x, y);
            WS2812B::set_pixel(index, color, show);
        }

        int32_t WS2812B_Matrix::get_led_index(int32_t x, int32_t y)
        {
            if (x < 0 || x >= __width || y < 0 || y >= __height)
                return (__width * __height);

            uint16_t max_height = __height - 1;
            int lowest_in_column = (x * max_height) + x;
            int column_x_0 = x % 2 == 0 ? lowest_in_column + max_height : lowest_in_column;
            int minus = (x % 2 == 1 ? 1 : -1) * y;
            return column_x_0 + minus;
        }

        void WS2812B_Matrix::set_font(const std::string &name, dsl::models::MatrixFont &font)
        {
            __fonts[name] = font;
        }

        uint16_t WS2812B_Matrix::display_character(int32_t x, int32_t y, char character, std::string font, const Color &color)
        {
            dsl::models::MatrixFont &font_object = __fonts[font];

            if (character == ' ')
                return font_object.get_space_width();

            dsl::models::MatrixFontCharacter& character_face = font_object.get_character_face(character);
            for (const auto &pixel : character_face.get_pixels())
            {
                set_pixel(x + pixel.first, y + pixel.second, color);
            }
            return character_face.get_width();
        }
    };
};