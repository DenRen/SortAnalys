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