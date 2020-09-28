#include "MyWindow.h"

sf::RenderWindow *Window = nullptr;

int main () {

    const int height = 1200, width = 720;
    const int FPS_Limit = 30 * 3;

    const char Buttons[] = "../files/button-sprite.png";

    WinApp app (height, width, "SortAnalys");

    app.window.setFramerateLimit (FPS_Limit);

    app.SetColorBackground (sf::Color (255, 255, 255));

    std::vector <std::string> nameSort = {"First", "Second"};
    const int QuntButton = nameSort.size ();

    sf::Vector2u size_button (297, 59);
    sf::Vector2u size_image_button (297, 59);

    const char nameFont[] = "../files/fonts/Fulbo Argenta:Version 1.002.otf";
    sf::Font font;
    if (font.loadFromFile (nameFont) == false)
        throw std::runtime_error ("Failed open font");

    sf::Texture *TextureButtonOn  = LoadTexture (Buttons, {11, 8}, size_image_button);
    sf::Texture *TextureButtonPtd = LoadTexture (Buttons, {11, 358}, size_image_button);
    sf::Texture *TextureButtonOff = LoadTexture (Buttons, {11, 77},  size_image_button);

    button Sort1 (sf::Vector2i(400, 300), size_button);
    Sort1.SetAnimation (TextureButtonOn, TextureButtonOff, TextureButtonPtd);
    Sort1.InitText (font, 24, sf::Color::White, sf::Text::Style::Bold);
    Sort1.text.setString ("Hello");
    Sort1.SetInCenter ();

    //app.Button = &Sort1;

    //app.Run ();
    while (app.window.isOpen ()) {
        sf::Event event;
        while (app.window.pollEvent (event)) {
            if (event.type == sf::Event::Closed)
                app.window.close ();

            Sort1.action (event);
        }

        Sort1.action ();

        app.window.clear ();

        Sort1.draw ();

        app.window.display ();
    }

    return 0;
}