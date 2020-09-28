#include "MyWindow.h"

int main () {

    const int height = 1200, width = 720;
    const int FPS_Limit = 30;

    const char Buttons[] = "../files/GUI-Buttons.jpg";

    WinApp app (height, width, "SortAnalys");

    app.window.setFramerateLimit (FPS_Limit);

    app.SetColorBackground (sf::Color (255, 255, 255));

    std::vector <std::string> nameSort = {"First", "Second"};
    const int QuntButton = nameSort.size ();

    sf::Vector2u size_button (60, 25);
    sf::Vector2u size_image_button (110, 40);

    sf::Texture *TextureButtonOn = new sf::Texture;
    TextureButtonOn->loadFromFile (Buttons, sf::IntRect (27, 55, size_image_button.x, size_image_button.y));
    sf::Sprite *SpriteButtonOn = getSprite (TextureButtonOn, size_button);
    app.window.draw (*SpriteButtonOn);

    sf::Texture *TextureButtonOff = new sf::Texture;
    TextureButtonOff->loadFromFile (Buttons, sf::IntRect (152, 55, size_image_button.x, size_image_button.y));
    sf::Sprite *SpriteButtonOff = getSprite (TextureButtonOff, size_button);
    SpriteButtonOff->move (50, 50);

    app.window.draw (*SpriteButtonOff);
    app.window.display ();

    while (true);
    //app.Run ();

    return 0;
}