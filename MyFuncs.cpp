#include "MyFuncs.h"

void SetSprite (sf::Sprite &sprite, sf::Texture *texture, sf::Vector2u new_size) {
    sf::Vector2u cur_size = texture->getSize ();
    sprite.setTexture (*texture);
    sprite.setScale ((float) new_size.x / cur_size.x, (float) new_size.y / cur_size.y);
}

sf::Sprite *getSprite (sf::Texture *texture, sf::Vector2u new_size) {
    sf::Vector2u cur_size = texture->getSize ();
    sf::Sprite *sprite = new sf::Sprite;
    sprite->setTexture (*texture);
    sprite->setScale ((float) new_size.x / cur_size.x, (float) new_size.y / cur_size.y);

    return sprite;
}

sf::Texture *LoadTexture (const char *name_file, sf::Vector2u coord, sf::Vector2u size) {
    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile (name_file, sf::IntRect (coord.x, coord.y, size.x, size.y));
    return texture;
}

void InitButtonMgr (ButtonMgr *Buttons, sf::Vector2u size_button, const int sizeFont) {
    const char FileTextureButtons[] = "../files/button-sprite.png";
    const sf::Vector2u size_image_button (297, 59);

    const char nameFont[] = "../files/fonts/Fulbo Argenta:Version 1.002.otf";
    sf::Font *font = new sf::Font;
    if (font->loadFromFile (nameFont) == false)
        throw std::runtime_error ("Failed open font");

    sf::Texture *TextureButtonOn  = LoadTexture (FileTextureButtons, {11, 8  }, size_image_button);
    sf::Texture *TextureButtonPtd = LoadTexture (FileTextureButtons, {11, 358}, size_image_button);
    sf::Texture *TextureButtonOff = LoadTexture (FileTextureButtons, {11, 77 }, size_image_button);

    Buttons->setSize (size_button);
    Buttons->setAnimation (TextureButtonOn, TextureButtonOff, TextureButtonPtd);
    Buttons->setFont (font, sizeFont, sf::Color::White, sf::Text::Style::Bold);
    if (Buttons->Verifier () == false)
        throw std::runtime_error ("Button construct incorrect");
}