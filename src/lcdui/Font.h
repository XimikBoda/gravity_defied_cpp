#pragma once

#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <cmrc/cmrc.hpp>

class Font {
public:
    enum FontSize {
        SIZE_SMALL = 8,
        SIZE_MEDIUM = 0,
        SIZE_LARGE = 16
    };

    enum FontStyle {
        STYLE_PLAIN = sf::Text::Style::Regular,
        STYLE_BOLD = sf::Text::Style::Bold,
        STYLE_ITALIC = sf::Text::Style::Italic
    };

    enum FontFace {
        FACE_SYSTEM = 0
    };

    Font(FontStyle style, FontSize pointSize);
    ~Font();

    int getBaselinePosition() const;
    int getHeight() const;
    sf::Text getTtfFont() const;
    int charWidth(char c);
    int stringWidth(const std::string& s);
    int substringWidth(const std::string& string, int offset, int len);

private:
    static inline sf::Font font;
    FontStyle style;
    FontSize pointSize;
    int height;

    static int getRealFontSize(FontSize size);
};