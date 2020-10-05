#include "GraphicsSettings.h"

void InitButtonMgr (ButtonMgr *Buttons, sf::Vector2u size_button, const int sizeFont) {
    const char FileTextureButtons[] = "../files/button-sprite.png";
    const sf::Vector2u size_image_button (297, 59);

    const char nameFont[] = "../files/fonts/Fulbo Argenta:Version 1.002.otf";
    sf::Font *font = new sf::Font;
    if (font->loadFromFile (nameFont) == false)
        throw std::runtime_error ("Failed open font");

    sf::Texture *TextureButtonOn  = LoadTexture (FileTextureButtons, {11, 8  }, size_image_button);
    sf::Texture *TextureButtonPtd = LoadTexture (FileTextureButtons, {11, 427}, size_image_button);
    sf::Texture *TextureButtonOff = LoadTexture (FileTextureButtons, {11, 77 }, size_image_button);

    Buttons->setSize (size_button);
    Buttons->setAnimation (TextureButtonOn, TextureButtonOff, TextureButtonPtd);
    Buttons->setFont (font, sizeFont, sf::Color::White, sf::Text::Style::Bold);

    if (Buttons->Verifier () == false)
        throw std::runtime_error ("Incorrect value in InitButtonMgr");
}

void InitGraphicMgr (GraphicMgr *Graphics, sf::Vector2u size_graphic, const int sizeFont) {
    const char nameFont[] = "../files/fonts/Fulbo Argenta:Version 1.002.otf";
    sf::Font *font = new sf::Font;
    if (font->loadFromFile (nameFont) == false)
        throw std::runtime_error ("Failed open font");

    Graphics->size = size_graphic;
    Graphics->RelPosIntAxes = {0.0, 0.0};
    Graphics->RelLenX = {1, 1};
    Graphics->RelLenY = {1, 1};
    Graphics->NumDivX = {3, 0};
    Graphics->NumDivY = {4, 0};
    Graphics->thickAxes = 2;
    Graphics->thickDiv = 1;

    Graphics->lenDiv = 6;
    Graphics->sizeDiv = {3, 3};
    Graphics->DistBetweenDivVal = {6, 6};

    Graphics->lenArrow = 10;
    Graphics->angleArrow = 20;

    Graphics->setFont (font, sizeFont, sf::Color::White, sf::Text::Style::Bold);

    Graphics->radiusPoint = 3;
    Graphics->colorPoint = sf::Color::Green;

    Graphics->titleX = std::string ("Size");
    Graphics->locateNameArrows = sf::Vector2i (LOCATE_NAME_ARROW::UP, LOCATE_NAME_ARROW::RIGHT);

    if (Graphics->Verifier () == false)
        throw std::runtime_error ("Incorrect value in InitGraphicMgr");
}