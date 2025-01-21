#include "CanvasImpl.h"


#include <stdexcept>
#include <iostream>

#include "Canvas.h"

CanvasImpl::CanvasImpl(Canvas* canvas)
{
    this->canvas = canvas;

    window.create(sf::VideoMode(sf::Vector2u(width, height)), "", sf::Style::Titlebar | sf::Style::Close);

    window.clear(sf::Color(255, 255, 255, 255));
}

CanvasImpl::~CanvasImpl()
{
}

void CanvasImpl::repaint()
{
    window.display();
}

int CanvasImpl::getWidth()
{
    return width;
}

int CanvasImpl::getHeight()
{
    return height;
}

sf::RenderTarget* CanvasImpl::getRenderer()
{
    return &window;
}

void CanvasImpl::processEvents()
{
    while (const std::optional event = window.pollEvent()){
        if (event->is<sf::Event::Closed>()) {
            exit(0); // IMPROVE This is a super dumb way to finish the game, but it works
        } else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
            int keyCode = convertKeyCharToKeyCode(key->code);
            // std::cout << "Key pressed: " << keyCode << std::endl;
            if (keyCode != 0) {
                canvas->publicKeyPressed(keyCode);
            }
        } else if (const auto* key = event->getIf<sf::Event::KeyReleased>()) {
            int keyCode = convertKeyCharToKeyCode(key->code);
            // std::cout << "Key released: " << keyCode << std::endl;
            if (keyCode != 0) {
                canvas->publicKeyReleased(keyCode);
            } else {
                if (key->code == sf::Keyboard::Key::Escape) {
                    // std::cout << "ESC released" << std::endl;
                    canvas->pressedEsc();
                }
            }
        }
    }
}

int CanvasImpl::convertKeyCharToKeyCode(sf::Keyboard::Key keyCode)
{
    switch (keyCode) {
    case sf::Keyboard::Key::Enter:
        return Canvas::Keys::FIRE;
    case sf::Keyboard::Key::Left:
        return Canvas::Keys::LEFT;
    case sf::Keyboard::Key::Right:
        return Canvas::Keys::RIGHT;
    case sf::Keyboard::Key::Up:
        return Canvas::Keys::UP;
    case sf::Keyboard::Key::Down:
        return Canvas::Keys::DOWN;
    default:
        std::cout << "unknown keyEvent: " << (int)keyCode << std::endl;
        return 0;
    }
}

void CanvasImpl::setWindowTitle(const std::string& title)
{
    window.setTitle(title);
}