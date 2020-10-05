#ifndef SORTANALYS_WINAPP_H
#define SORTANALYS_WINAPP_H

#include "widget.h"
#include "GraphicMgrs.h"

class WinApp {
    int height, width;
    sf::Color ColorBG;

public:

    sf::RenderWindow window;

    ButtonMgr Buttons;
    GraphicMgr Graphics;

    int max_size_arr;
    int num_sorts;
    void (**sorts) (struct rint[], int);

    WinApp (int height, int width, const char *title);
    void Run ();

    void CheckButtons ();
    void SetColorBackground (sf::Color color);
};

#endif //SORTANALYS_WINAPP_H
