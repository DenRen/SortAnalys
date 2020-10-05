#include <cmath>
#include <random>
#include "WinApp.h"
#include "GraphicsSettings.h"
#include "MySorts.h"

sf::RenderWindow *Window = nullptr;

int main () {

    const int num_sorts = SORTS::size;
    void (*sorts[num_sorts]) (struct rint[], int) = {SelectSort,    BubbleSort,   InsertSort,   QSort};
    std::string name_sort[num_sorts]              = {"SelectSort", "BubbleSort", "InsertSort", "QSort"};
    const int FuncSort = SORTS::BUBBLE;

    const int max_size_arr = 4 * 1024;

    const int height = 720, width = 1200;
    const int FPS_Limit = 30;

    const sf::Color ColorBackground = sf::Color (0, 0, 0);

    const sf::Vector2u size_button (200, 59);
    const int sizeFontButton = 24;

    const sf::Vector2u size_graphic (300, 400);
    const int sizeFontGraphic = 24;

    WinApp app (height, width, "SortAnalys");

    app.num_sorts = num_sorts;
    app.sorts = sorts;
    app.max_size_arr = max_size_arr;

    app.window.setFramerateLimit (FPS_Limit);
    app.SetColorBackground (ColorBackground);

    ButtonMgr *Buttons = &app.Buttons;
    InitButtonMgr (Buttons, size_button, sizeFontButton);

    const int distBetwButtons = width / (num_sorts + 1);
    const float relHeightButtons = 0.2;
    const int locateButtonY = relHeightButtons * height;
    for (int i = 0; i < num_sorts; i++) {
        Buttons->addButton (sf::Vector2i ((i + 1) * distBetwButtons, locateButtonY), name_sort[i]);
    }

    GraphicMgr *Graphics = &app.Graphics;
    InitGraphicMgr (Graphics, size_graphic, sizeFontGraphic);

    for (int i = 0; i < 2; i++)
        Graphics->addGraph (sf::Vector2i ((i + 1) * width / 3, 400), sf::Vector2i (30, 8));

    Graphics->graphs[0]->setTitleY ("Swap");
    Graphics->graphs[1]->setTitleY ("Comp");

    Graphics->graphs[0]->SetChanged ();
    Graphics->graphs[1]->SetChanged ();

    app.Run ();

    return 0;
}