#include <iterator>
#include "models/matrix.h"
#include "arduino_components/ws2812b.h"

namespace dsl
{
    namespace arduino_components
    {
        class WS2812B_Matrix : public WS2812B
        {
        private:
            uint16_t __width;
            uint16_t __height;
            std::map<std::string, dsl::models::MatrixFont> __fonts;

        public:
            WS2812B_Matrix(const std::string &name, uint8_t gpio, uint16_t width, uint16_t height);
            int32_t get_led_index(int32_t x, int32_t y);
            void set_pixel(uint16_t x, uint16_t y, Color color, bool show = false);
            void set_font(const std::string &name, dsl::models::MatrixFont &font);
            void display_pixel_list(dsl::models::PixelList pixel_list, const Color &color);
            uint16_t display_character(int32_t x, int32_t y, char character, std::string font, const Color &color);
            uint16_t display_string(const int32_t x, const int32_t y, const std::string &string, const std::string &font, const Color &color);
            void draw_horizontal_line(const int32_t x, const int32_t y, const int32_t length, const Color &color);
            void draw_vertical_line(const int32_t x, const int32_t y, const int32_t height, const Color &color);
            void draw_rectangle(const int32_t x, const int32_t y, const uint16_t width, const uint16_t height, const Color &border, const Color& fillcolor);
        };
    };
};