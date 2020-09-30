#include "WinApp.h"
#include "MyFuncs.h"

sf::RenderWindow *Window = nullptr;

int main () {

    const int height = 720, width = 1200;
    const int FPS_Limit = 30;

    const sf::Color ColorBackground = sf::Color (255, 255, 255);

    const sf::Vector2u size_button (297, 59);
    const int sizeFont = 24;

    WinApp app (height, width, "SortAnalys");

    app.window.setFramerateLimit (FPS_Limit);
    app.SetColorBackground (ColorBackground);

    std::vector <std::string> nameSort = {"First", "Second"};
    const int QuntButton = nameSort.size ();

    ButtonMgr *Buttons = &app.Buttons;

    InitButtonMgr (Buttons, size_button, sizeFont);
    Buttons->addButton (sf::Vector2i (1 * width / 4, height / 2), "Hello");
    Buttons->addButton (sf::Vector2i (2 * width / 4, height / 2), "Hello");
    Buttons->addButton (sf::Vector2i (3 * width / 4, height / 2), "Hello");

    app.Run ();

    return 0;
}