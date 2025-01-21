#pragma once

#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Canvas;

class CanvasImpl {
private:
    Canvas* canvas;

    sf::RenderWindow window;

    const int width = 640;
    const int height = 480;

    static int convertKeyCharToKeyCode(sf::Keyboard::Key keyCode);

public:
    CanvasImpl(Canvas* canvas);
    ~CanvasImpl();

    void repaint();
    int getWidth();
    int getHeight();

    sf::RenderTarget* getRenderer();
    void processEvents();
    void setWindowTitle(const std::string& title);
};