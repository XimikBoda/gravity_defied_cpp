#include "Font.h"

#include <stdexcept>

CMRC_DECLARE(assets);

Font::Font(FontStyle style, FontSize pointSize)
{
    if (!font.hasGlyph('0')) {
        cmrc::embedded_filesystem internalFs = cmrc::assets::get_filesystem();
        cmrc::file fileData = internalFs.open("FontSansSerif.ttf");
        font.openFromMemory(fileData.begin(), fileData.size());
    }

    this->style = style;
    this->pointSize = pointSize;
    this->height = getRealFontSize(pointSize);
}

Font::~Font()
{
}

int Font::getBaselinePosition() const
{
    return height;
}

int Font::getHeight() const
{
    return height;
}

sf::Text Font::getTtfFont() const
{
    int realSize = getRealFontSize(pointSize);
    sf::Text text(font, "", realSize);
    text.setStyle(style);
    return text;
}

int Font::charWidth(char c)
{
    return stringWidth(std::string(1, c));
}

int Font::stringWidth(const std::string& s)
{
    int width, height;
    sf::Text text = getTtfFont(); 
    text.setString(s);
    return text.getLocalBounds().size.x;
}

int Font::substringWidth(const std::string& string, int offset, int len)
{
    return stringWidth(string.substr(offset, len));
}

int Font::getRealFontSize(FontSize size)
{
    switch (size) {
    case SIZE_LARGE:
        return 32;
    case SIZE_MEDIUM:
        return 16;
    case SIZE_SMALL:
        return 12;
    default:
        throw std::runtime_error("unknown font size: " + std::to_string(size));
    }
}
