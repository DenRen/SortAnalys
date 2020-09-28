#include <cassert>
#include "MyWindow.h"

sf::RenderWindow *Window = nullptr;

int main () {

    const int height = 1200, width = 720;
    const int FPS_Limit = 30 * 3;

    const char nameTextureButtons[] = "../files/button-sprite.png";

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

    sf::Texture *TextureButtonOn  = LoadTexture (nameTextureButtons, {11, 8  }, size_image_button);
    sf::Texture *TextureButtonPtd = LoadTexture (nameTextureButtons, {11, 358}, size_image_button);
    sf::Texture *TextureButtonOff = LoadTexture (nameTextureButtons, {11, 77 }, size_image_button);

    /*
    button TemplateButton (sf::Vector2i (0, 0), size_button);
    TemplateButton.SetAnimation (TextureButtonOn, TextureButtonOff, TextureButtonPtd);
    TemplateButton.InitText (font, 24, sf::Color::White, sf::Text::Style::Bold);


    TemplateButton.text.setString ("Hello");
    TemplateButton.SetInCenter ();
*/
    ButtonMgr Buttons;
    Buttons.setSize (size_button);
    Buttons.setAnimation (TextureButtonOn, TextureButtonOff, TextureButtonPtd);
    Buttons.setFont (&font, 24, sf::Color::White, sf::Text::Style::Bold);
    assert (Buttons.Verifier ());
    Buttons.addButton (sf::Vector2i (100, 200), "Hello");

    //app.Run ();
    while (app.window.isOpen ()) {
        sf::Event event;
        while (app.window.pollEvent (event)) {
            if (event.type == sf::Event::Closed)
                app.window.close ();

            Buttons.action (event);
            //TemplateButton.action (event);
        }

        Buttons.action ();
        //TemplateButton.action ();

        app.window.clear ();

        Buttons.draw ();
        //TemplateButton.draw ();

        app.window.display ();
    }

    return 0;
}