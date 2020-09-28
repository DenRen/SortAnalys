#ifndef SORTANALYS_MYFUNCS_H
#define SORTANALYS_MYFUNCS_H


sf::Sprite *getSprite (sf::Texture *texture, sf::Vector2u new_size);
void SetSprite (sf::Sprite &sprite, sf::Texture *texture, sf::Vector2u new_size);

sf::Texture *LoadTexture (const char *name_file, sf::Vector2u coord, sf::Vector2u size);

#endif //SORTANALYS_MYFUNCS_H