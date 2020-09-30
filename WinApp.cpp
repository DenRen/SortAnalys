#include "MyWindow.h"

WinApp::WinApp (int height, int width, const char *title) :
    ColorBG (sf::Color (0, 0, 0)),
    height (height), width (width),
    window (sf::VideoMode (width, height), title)
{
    Window = &(this->window);
}

void WinApp::Run () {
    while (window.isOpen ()) {
        sf::Event event;
        while (window.pollEvent (event))
            if (event.type == sf::Event::Closed)
                window.close ();

        window.clear (ColorBG);

        window.display ();
    }
}

void WinApp::SetColorBackground (sf::Color color) {
    ColorBG = color;
}


