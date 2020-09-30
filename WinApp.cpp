#include <SFML/Graphics/Color.hpp>
#include <SFML/Window.hpp>
#include "WinApp.h"

WinApp::WinApp (int height, int width, const char *title) :
    ColorBG (sf::Color (0, 0, 0)),
    height (height), width (width),
    window (sf::VideoMode (width, height), title)
{
    Window = &(this->window);
}

void WinApp::Run () {
    while (window.isOpen ()) {
        sf::Event event = sf::Event ();
        while (window.pollEvent (event)) {
            if (event.type == sf::Event::Closed)
                window.close ();

            Buttons.action (event);
        }

        Buttons.action ();

        window.clear ();

        Buttons.draw ();

        window.display ();
    }
}

void WinApp::SetColorBackground (sf::Color color) {
    ColorBG = color;
}


