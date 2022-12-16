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

        void WS2812B_Matrix::display_pixel_list(dsl::models::PixelList pixel_list, const Color &color)
        {
            for (const auto &pixel : pixel_list)
            {
                set_pixel(pixel.first, pixel.second, color);
            }
        }

        uint16_t WS2812B_Matrix::display_character(int32_t x, int32_t y, char character, std::string font, const Color &color)
        {
            dsl::models::MatrixFont &font_object = __fonts[font];

            if (character == ' ')
                return font_object.get_space_width();

            // Copy the pixellist for the character to a PixelList object
            dsl::models::MatrixFontCharacter &character_face = font_object.get_character_face(character);
            dsl::models::PixelList pixels;
            std::copy(
                std::begin(character_face.get_pixels()),
                std::end(character_face.get_pixels()),
                std::back_insert_iterator(pixels));

            // Add the position
            for (auto &pixel : pixels)
            {
                pixel.first += x;
                pixel.second += y;
            }

            display_pixel_list(pixels, color);
            return character_face.get_width();
        }

        uint16_t WS2812B_Matrix::display_string(const int32_t x, const int32_t y, const std::string &string, const std::string &font, const Color &color)
        {
            // TODO:
            // - Get spacing from font
            // - Make a PixelList and sent that to display_pixel_list
            int16_t pos = x;
            int16_t total = 0;
            for (const auto &character : string)
            {
                total += display_character(pos + total, y, character, font, color) + 1;
            }
            return total;
        }

        void WS2812B_Matrix::draw_horizontal_line(const int32_t x, const int32_t y, const int32_t length, const Color &color)
        {
            for (int32_t i = x; i < x + length; i++)
            {
                if (i >= 0)
                    set_pixel(i, y, color);
            }
        }

        void WS2812B_Matrix::draw_vertical_line(const int32_t x, const int32_t y, const int32_t height, const Color &color)
        {
            for (int32_t i = y; i < y + height; i++)
            {
                if (i >= 0)
                    set_pixel(x, i, color);
            }
        }

        void WS2812B_Matrix::draw_rectangle(const int32_t x, const int32_t y, const uint16_t width, const uint16_t height, const Color &border, const Color &fillcolor)
        {
            // Draw the border
            draw_horizontal_line(x, y, width, border);
            draw_horizontal_line(x, (y + height) - 1, width, border);
            draw_vertical_line(x, y + 1, height - 2, border);
            draw_vertical_line((x + width) - 1, y + 1, height - 2, border);

            // Fill the border (if set)
            uint32_t fc = fillcolor;
            if (fc > 0)
            {
                for (int16_t filly = y + 1; filly <= (y + height) - 2; ++filly)
                    draw_horizontal_line(x + 1, filly, width - 2, fillcolor);
            }
        }

    };
};