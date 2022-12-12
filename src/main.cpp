#include <Arduino.h>
#include <arduino_components/ws2812b_matrix.h>

dsl::arduino_components::WS2812B_Matrix strip("matrix", 5, 32, 8);
dsl::models::MatrixFont font_subway_ticker;
dsl::models::MatrixFont font_daryl;

void setup()
{
    Serial.begin(115200);
    strip.setup();

    // Font: Daryl
    // Numbers
    font_daryl.set_character(
        '0',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}}));
    font_daryl.set_character(
        '1',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 0}}));
    font_daryl.set_character(
        '2',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 4}, {1, 0}, {1, 2}, {1, 4}, {2, 0}, {2, 2}, {2, 3}, {2, 4}}));
    font_daryl.set_character(
        '3',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 2}, {0, 4}, {1, 0}, {1, 2}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}}));
    font_daryl.set_character(
        '4',
        dsl::models::MatrixFontCharacter(
            {{0, 2}, {0, 3}, {0, 4}, {1, 2}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}}));
    font_daryl.set_character(
        '5',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 2}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 4}}));
    font_daryl.set_character(
        '6',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 2}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 4}}));
    font_daryl.set_character(
        '7',
        dsl::models::MatrixFontCharacter(
            {{0, 4}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}}));
    font_daryl.set_character(
        '8',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 2}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}}));
    font_daryl.set_character(
        '9',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 2}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}}));

    // Font: Subway Ticker
    // Characters
    font_subway_ticker.set_character(
        ':',
        dsl::models::MatrixFontCharacter(
            {{0, 2}, {0, 4}}));

    // Numbers
    font_subway_ticker.set_character(
        '0',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 6}, {2, 0}, {2, 6}, {3, 0}, {3, 6}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        '1',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 5}, {1, 0}, {1, 5}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 0}, {4, 0}}));
    font_subway_ticker.set_character(
        '2',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 5}, {1, 0}, {1, 1}, {1, 6}, {2, 0}, {2, 2}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 0}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        '3',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 5}, {1, 0}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 1}, {4, 2}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        '4',
        dsl::models::MatrixFontCharacter(
            {{0, 2}, {1, 2}, {1, 3}, {2, 2}, {2, 4}, {3, 2}, {3, 5}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        '5',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 3}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 1}, {4, 2}, {4, 6}}));
    font_subway_ticker.set_character(
        '6',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 3}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 1}, {4, 2}, {4, 5}}));
    font_subway_ticker.set_character(
        '7',
        dsl::models::MatrixFontCharacter(
            {{0, 6}, {1, 0}, {1, 1}, {1, 2}, {1, 6}, {2, 3}, {2, 6}, {3, 4}, {3, 6}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        '8',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 4}, {0, 5}, {1, 0}, {1, 3}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 1}, {4, 2}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        '9',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 4}, {0, 5}, {1, 0}, {1, 3}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));

    // Lower case letters
    font_subway_ticker.set_character(
        'a',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {1, 0}, {1, 3}, {1, 5}, {2, 0}, {2, 3}, {2, 5}, {3, 1}, {3, 2}, {3, 3}, {3, 4}}));
    font_subway_ticker.set_character(
        'b',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 4}, {2, 0}, {2, 4}, {3, 1}, {3, 2}, {3, 3}}));
    font_subway_ticker.set_character(
        'c',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 5}, {2, 0}, {2, 5}, {3, 1}, {3, 4}}));
    font_subway_ticker.set_character(
        'd',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 4}, {2, 0}, {2, 4}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}}));
    font_subway_ticker.set_character(
        'e',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 2}, {1, 5}, {2, 0}, {2, 2}, {2, 5}, {3, 2}, {3, 3}, {3, 4}}));
    font_subway_ticker.set_character(
        'f',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 3}, {1, 6}, {2, 6}}));
    font_subway_ticker.set_character(
        'g',
        dsl::models::MatrixFontCharacter(
            {{0, 3}, {0, 4}, {1, 0}, {1, 2}, {1, 5}, {2, 0}, {2, 2}, {2, 5}, {3, 1}, {3, 2}, {3, 3}, {3, 4}}));
    font_subway_ticker.set_character(
        'h',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 4}, {2, 4}, {3, 4}, {4, 0}, {4, 1}, {4, 2}, {4, 3}}));
    font_subway_ticker.set_character(
        'i',
        dsl::models::MatrixFontCharacter(
            {{0, 4}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 6}, {2, 0}}));
    font_subway_ticker.set_character(
        'j',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {1, 0}, {2, 0}, {2, 4}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 6}}));
    font_subway_ticker.set_character(
        'k',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 2}, {2, 1}, {2, 3}, {3, 0}, {3, 4}}));
    font_subway_ticker.set_character(
        'l',
        dsl::models::MatrixFontCharacter(
            {{0, 6}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 0}}));
    font_subway_ticker.set_character(
        'm',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 5}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}}));
    font_subway_ticker.set_character(
        'n',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 5}, {2, 5}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}}));
    font_subway_ticker.set_character(
        'o',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 5}, {2, 0}, {2, 5}, {3, 1}, {3, 2}, {3, 3}, {3, 4}}));
    font_subway_ticker.set_character(
        'p',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 5}, {2, 2}, {2, 5}, {3, 3}, {3, 4}}));
    font_subway_ticker.set_character(
        'q',
        dsl::models::MatrixFontCharacter(
            {{0, 3}, {0, 4}, {1, 2}, {1, 5}, {2, 2}, {2, 5}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}}));
    font_subway_ticker.set_character(
        'r',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 5}, {2, 5}}));
    font_subway_ticker.set_character(
        's',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 4}, {1, 0}, {1, 3}, {1, 5}, {2, 0}, {2, 2}, {2, 5}, {3, 1}, {3, 4}}));
    font_subway_ticker.set_character(
        't',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 4}, {2, 4}}));
    font_subway_ticker.set_character(
        'u',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {2, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}}));
    font_subway_ticker.set_character(
        'v',
        dsl::models::MatrixFontCharacter(
            {{0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 1}, {2, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}}));
    font_subway_ticker.set_character(
        'w',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {3, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'x',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 5}, {1, 1}, {1, 4}, {2, 2}, {2, 3}, {3, 1}, {3, 4}, {4, 0}, {4, 5}}));
    font_subway_ticker.set_character(
        'y',
        dsl::models::MatrixFontCharacter(
            {{0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 2}, {2, 0}, {2, 2}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}}));
    font_subway_ticker.set_character(
        'z',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 5}, {1, 0}, {1, 2}, {1, 5}, {2, 0}, {2, 3}, {2, 5}, {3, 0}, {3, 4}, {3, 5}}));

    // Upper case letters
    font_subway_ticker.set_character(
        'A',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 3}, {1, 6}, {2, 3}, {2, 6}, {3, 3}, {3, 6}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'B',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 3}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 1}, {4, 2}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'C',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 6}, {2, 0}, {2, 6}, {3, 0}, {3, 6}, {4, 1}, {4, 5}}));
    font_subway_ticker.set_character(
        'D',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 6}, {2, 0}, {2, 6}, {3, 0}, {3, 6}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'E',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 3}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 0}, {4, 6}}));
    font_subway_ticker.set_character(
        'F',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 3}, {1, 6}, {2, 3}, {2, 6}, {3, 3}, {3, 6}, {4, 6}}));
    font_subway_ticker.set_character(
        'G',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 5}}));
    font_subway_ticker.set_character(
        'H',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 3}, {2, 3}, {3, 3}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        'I',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {1, 0}, {1, 6}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 0}, {3, 6}, {4, 0}}));
    font_subway_ticker.set_character(
        'J',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {1, 0}, {1, 6}, {2, 0}, {2, 6}, {3, 0}, {3, 6}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'K',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 3}, {2, 2}, {2, 4}, {3, 1}, {3, 5}, {4, 0}, {4, 6}}));
    font_subway_ticker.set_character(
        'L',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {2, 0}, {3, 0}, {4, 0}}));
    font_subway_ticker.set_character(
        'M',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 6}, {2, 3}, {2, 4}, {2, 5}, {3, 6}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        'N',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 4}, {2, 3}, {3, 2}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        'O',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 6}, {2, 0}, {2, 6}, {3, 0}, {3, 6}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'P',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 3}, {1, 6}, {2, 3}, {2, 6}, {3, 3}, {3, 6}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'Q',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 0}, {1, 6}, {2, 0}, {2, 2}, {2, 6}, {3, 1}, {3, 6}, {4, 0}, {4, 2}, {4, 3}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'R',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 3}, {1, 6}, {2, 2}, {2, 3}, {2, 6}, {3, 1}, {3, 3}, {3, 6}, {4, 0}, {4, 4}, {4, 5}}));
    font_subway_ticker.set_character(
        'S',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 4}, {0, 5}, {1, 0}, {1, 3}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 3}, {3, 6}, {4, 1}, {4, 2}, {4, 5}}));
    font_subway_ticker.set_character(
        'T',
        dsl::models::MatrixFontCharacter(
            {{0, 6}, {1, 6}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 6}, {4, 6}}));
    font_subway_ticker.set_character(
        'U',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {2, 0}, {3, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        'V',
        dsl::models::MatrixFontCharacter(
            {{0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 1}, {2, 0}, {3, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        'W',
        dsl::models::MatrixFontCharacter(
            {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {3, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        'X',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 6}, {1, 1}, {1, 5}, {2, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5}, {4, 0}, {4, 6}}));
    font_subway_ticker.set_character(
        'Y',
        dsl::models::MatrixFontCharacter(
            {{0, 4}, {0, 5}, {0, 6}, {1, 3}, {2, 0}, {2, 1}, {2, 2}, {3, 3}, {4, 4}, {4, 5}, {4, 6}}));
    font_subway_ticker.set_character(
        'Z',
        dsl::models::MatrixFontCharacter(
            {{0, 0}, {0, 1}, {0, 6}, {1, 0}, {1, 2}, {1, 6}, {2, 0}, {2, 3}, {2, 6}, {3, 0}, {3, 4}, {3, 6}, {4, 0}, {4, 5}, {4, 6}}));

    strip.clear();
    strip.set_font("subway_ticker", font_subway_ticker);
    strip.set_font("daryl", font_daryl);

    strip.set_brightness(10);
}

void loop()
{
    strip.clear();
    strip.display_string(0, 0, "ABCDE", "subway_ticker", {0, 255, 0});
    strip.show();
    delay(1000);

    strip.clear();
    strip.display_string(0, 0, "FGHIJ", "subway_ticker", {0, 255, 0});
    strip.show();
    delay(1000);

    strip.clear();
    strip.display_string(0, 0, "KLMNO", "subway_ticker", {0, 255, 0});
    strip.show();
    delay(1000);

    strip.clear();
    strip.display_string(0, 0, "PQRST", "subway_ticker", {0, 255, 0});
    strip.show();
    delay(1000);

    strip.clear();
    strip.display_string(0, 0, "UVWXY", "subway_ticker", {0, 255, 0});
    strip.show();
    delay(1000);

    strip.clear();
    strip.display_string(0, 0, "Z", "subway_ticker", {0, 255, 0});
    strip.show();
    delay(1000);
}