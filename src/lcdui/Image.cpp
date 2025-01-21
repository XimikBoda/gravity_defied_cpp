#include "Image.h"

#include <stdexcept>
#include <string>

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(assets);

Image::Image(int width, int height)
{
    throw std::runtime_error("Non implemented");
}

Image::Image(const std::string& embeddedPath)
{
    cmrc::embedded_filesystem embeddedFs = cmrc::assets::get_filesystem();
    cmrc::file fileData = embeddedFs.open(embeddedPath);

    surface.loadFromMemory(fileData.begin(), fileData.size());
}

Image::~Image()
{
}

int Image::getWidth() const
{
    return surface.getSize().x;
}

int Image::getHeight() const
{
    return surface.getSize().y;
}

const sf::Texture* Image::getSurface() const
{
    return &surface;
}
