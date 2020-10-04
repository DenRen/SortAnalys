#include <cmath>
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

    std::vector <std::pair <float, float>> data;
    const float size_data = 20;
    for (float x = 0; x < size_data; x += 0.1)
        data.push_back (std::make_pair (x, sin (x) * exp (x / 10 - 1)));

    Graphics->addGraph (sf::Vector2i (900, 400), sf::Vector2i (30, 8));

    Graphics->graphs[0]->data = data;

    Graphics->graphs[0]->SetMaxX (12);
    Graphics->graphs[0]->SetChanged ();

    int i = 0;
    for (float x = 0; x < size_data; x += 0.1, i++)
        data[i].second *= 10;

    Graphics->graphs[0]->data = data;

    app.Run ();

    return 0;
}