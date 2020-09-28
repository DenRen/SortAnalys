#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "MyFuncs.h"

sf::Sprite *getSprite (sf::Texture *texture, sf::Vector2u new_size) {
    sf::Vector2u cur_size = texture->getSize ();
    sf::Sprite *sprite = new sf::Sprite;
    sprite->setTexture (*texture);
    sprite->setScale ((float) new_size.x / cur_size.x, (float) new_size.y / cur_size.y);

    return sprite;
}