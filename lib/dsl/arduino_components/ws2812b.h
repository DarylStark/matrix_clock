#ifndef __WS2812B_H__
#define __WS2812B_H__

#include <Adafruit_NeoPixel.h>
#include "arduino_components/component.h"
#include "entity_manager/entity.h"

namespace dsl
{
    namespace arduino_components
    {
        // Class for colors
        class Color
        {
        public:
            uint8_t red;
            uint8_t green;
            uint8_t blue;
            float brightness = 1.f;

            operator uint32_t() const;
        };

        class WS2812B : public Component
        {
        private:
            uint8_t __gpio;
            uint16_t __length;
            Adafruit_NeoPixel __component;

        public:
            WS2812B(const std::string &name, uint8_t gpio, uint16_t length);
            ~WS2812B();
            void setup() override;
            void loop() override;

            // LED strip methods
            void fill(const Color color, bool show = false);
            void clear(bool show = false);
            void show();
            void set_pixel(uint16_t led, Color color, bool show = false);
            void set_brightness(uint8_t level);
        };
    }
};

#endif // __WS2812B_H__