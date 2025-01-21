#pragma once

#include <string>
#include <SFML/Graphics/Texture.hpp>

class Image {
private:
    sf::Texture surface;

public:
    Image(const std::string& embeddedPath);
    Image(int width, int height);
    ~Image();

    int getWidth() const;
    int getHeight() const;
    const sf::Texture* getSurface() const;
};
