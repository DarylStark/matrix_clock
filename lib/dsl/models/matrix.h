#include <list>
#include <utility>
#include <unordered_map>

namespace dsl
{
    namespace models
    {
        typedef std::list<std::pair<uint16_t, uint16_t>> PixelList;

        class MatrixFontCharacter
        {
        private:
            PixelList __pixels;
            uint16_t __width;

        public:
            MatrixFontCharacter() = default;
            MatrixFontCharacter(PixelList pixels);
            const PixelList &get_pixels() const;
            uint16_t get_width();
        };

        class MatrixFont
        {
        private:
            std::unordered_map<char, MatrixFontCharacter> __characters;
            uint16_t __space_width;

        public:
            MatrixFont(uint16_t space_width = 1);
            void set_character(const char &character, const MatrixFontCharacter &face);
            MatrixFontCharacter &get_character_face(const char character);
            uint16_t get_space_width() const;
        };
    };
};