#include "WinApp.h"
#include "GraphicsSettings.h"

sf::RenderWindow *Window = nullptr;

int main () {

    const int height = 720, width = 1200;
    const int FPS_Limit = 30;

    const sf::Color ColorBackground = sf::Color (0, 0, 0);

    const sf::Vector2u size_button (297, 59);
    const int sizeFontButton = 24;

    const sf::Vector2u size_graphic (300, 400);
    const int sizeFontGraphic = 24;

    WinApp app (height, width, "SortAnalys");

    app.window.setFramerateLimit (FPS_Limit);
    app.SetColorBackground (ColorBackground);

    std::vector <std::string> nameSort = {"First", "Second"};
    const int QuntButton = nameSort.size ();

    ButtonMgr *Buttons = &app.Buttons;
    InitButtonMgr (Buttons, size_button, sizeFontButton);

    Buttons->addButton (sf::Vector2i (1 * width / 4, 2 * height / 10), "Hello");
    Buttons->addButton (sf::Vector2i (2 * width / 4, 2 * height / 10), "Hello");
    Buttons->addButton (sf::Vector2i (3 * width / 4, 2 * height / 10), "Hello");

    GraphicMgr *Graphics = &app.Graphics;
    InitGraphicMgr (Graphics, size_graphic, sizeFontGraphic);

    Graphics->addGraph (sf::Vector2i (400, 400), sf::Vector2i (200, 50));
    Graphics->addGraph (sf::Vector2i (900, 400), sf::Vector2i (100, 50));

    app.Run ();

    return 0;
}