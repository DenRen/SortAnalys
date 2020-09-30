#ifndef SORTANALYS_WINAPP_H
#define SORTANALYS_WINAPP_H

#include "widget.h"

class WinApp {
    int height, width;
    sf::Color ColorBG;

public:

    sf::RenderWindow window;
    ButtonMgr Buttons;

    WinApp (int height, int width, const char *title);
    void Run ();

    void SetColorBackground (sf::Color color);
};

#endif //SORTANALYS_WINAPP_H
