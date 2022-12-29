#include "arduino_components/ws2812b.h"

namespace dsl
{
    namespace arduino_components
    {
        // Public methods for Color
        Color::operator uint32_t() const
        {
            uint32_t rv = red * brightness;
            rv = rv << 8;
            rv += green * brightness;
            rv = rv << 8;
            rv += blue * brightness;
            return rv;
        }

        // Public methods for LiquidCrystal
        WS2812B::WS2812B(const std::string &name, uint8_t gpio, uint16_t length, bool autoshow /* = false */)
            : Component(name), __gpio(gpio), __length(length), __autoshow(autoshow)
        {
        }

        WS2812B::~WS2812B()
        {
        }

        void WS2812B::setup()
        {
            // Configure the strip
            __component.setPin(__gpio);
            __component.begin();
            __component.updateLength(__length);
        }

        void WS2812B::loop()
        {
        }

        void WS2812B::fill(const Color color)
        {
            __component.fill(color);
            if (__autoshow)
                this->show();
        }

        void WS2812B::clear()
        {
            __component.clear();
            if (__autoshow)
                this->show();
        }

        void WS2812B::show()
        {
            __component.show();
        }

        void WS2812B::set_pixel(uint16_t led, Color color)
        {
            if (led >= __length)
                return;
            uint32_t color_code = static_cast<uint32_t>(color);
            __component.setPixelColor(led, color_code);
            if (__autoshow)
                this->show();
        }

        void WS2812B::set_brightness(uint8_t level)
        {
            __component.setBrightness(level);
        }
    };
};