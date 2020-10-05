#include <cmath>
#include <random>
#include "WinApp.h"
#include "GraphicsSettings.h"
#include "MySorts.h"

sf::RenderWindow *Window = nullptr;

template <typename T>
void FillRandVal32 (T data[], int size, std::mt19937 *mt) {
    while (--size >= 0)
        data[size] = (*mt) ();
}

template <typename T>
bool CheckSortArray (T data[], int size) {
    if (size <= 1)
        return true;

    while (--size >= 1)
        if (data[size] < data[size - 1])
            return false;

    return true;
}

typedef struct rint res_type;

int main () {

    const int size = 1024 * 1024;

    res_type *data = (res_type *) calloc (size, sizeof (int));

    std::random_device rd;
    std::mt19937 mersenne (rd ());
    FillRandVal32 (data, size, &mersenne);

    QSort (data, size);

    if (CheckSortArray (data, size) == false) {
        printf ("Failed sort array");
        return EXIT_FAILURE;
    } else {
        printf ("Nice sort");
        return EXIT_SUCCESS;
    }

    /*
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
        data.push_back (std::make_pair (x, 2 + sin (0.04 * x * x) - x * 0.01));

    Graphics->addGraph (sf::Vector2i (900, 400), sf::Vector2i (30, 8));

    Graphics->graphs[0]->data = data;

    Graphics->graphs[0]->SetMaxX (12);
    Graphics->graphs[0]->SetChanged ();

    Graphics->graphs[0]->data = data;

    app.Run ();

    return 0;*/
}

/*
void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
*/