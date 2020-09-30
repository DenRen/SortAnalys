#ifndef SORTANALYS_MYFUNCS_H
#define SORTANALYS_MYFUNCS_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "widget.h"

sf::Sprite *getSprite (sf::Texture *texture, sf::Vector2u new_size);
void SetSprite (sf::Sprite &sprite, sf::Texture *texture, sf::Vector2u new_size);

void InitButtonMgr (ButtonMgr *Buttons, sf::Vector2u size_button, const int sizeFont);

sf::Texture *LoadTexture (const char *name_file, sf::Vector2u coord, sf::Vector2u size);

template <typename T, typename U>
sf::Vector2f getCenter (T location, U size) {
    return sf::Vector2f (location.x + size.x / 2, location.y + size.y / 2);
}

template <typename T, typename U, typename Z, typename X>
sf::Vector2f getCenter (T location, U size, Z height, X width) {
    return sf::Vector2f (location.x + (size.x - width) / 2, location.y + size.y / 2 - height);
}

#endif //SORTANALYS_MYFUNCS_H