#include <SFML/Graphics/Color.hpp>
#include <SFML/Window.hpp>

#include "WinApp.h"
#include "MySorts.h"

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
            Graphics.action (event);
        }

        Buttons.action ();
        Graphics.action ();


        window.clear (ColorBG);

        Buttons.draw ();
        Graphics.draw ();

        window.display ();

        CheckButtons ();
    }
}

void WinApp::SetColorBackground (sf::Color color) {
    ColorBG = color;
}

void WinApp::CheckButtons () {
    static int num_button_on = -1;

    std::vector <button *>& buttons = Buttons.buttons;
    const int size = buttons.size ();
    for (int i = 0; i < size; i++)
        if (buttons[i]->getState () == BUTTON_STATE::TURN_ON && num_button_on != i) {
            num_button_on = i;

            auto data = GetSwapComp (max_size_arr, 20, sorts[i]);

            Graphics.graphs[0]->data = data.first;
            Graphics.graphs[0]->SetMaxY (MaxSecond (data.first));
            Graphics.graphs[0]->SetMaxX (max_size_arr);
            Graphics.graphs[0]->SetChanged ();

            Graphics.graphs[1]->data = data.second;
            Graphics.graphs[1]->SetMaxY (MaxSecond (data.second));
            Graphics.graphs[1]->SetMaxX (max_size_arr);
            Graphics.graphs[1]->SetChanged ();

            printf ("Hey! %d\n", i);
            break;
        }
}


