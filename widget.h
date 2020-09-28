#ifndef SORTANALYS_WIDGET_H
#define SORTANALYS_WIDGET_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "point.h"

class widget {
    sf::Vector2i location;
    sf::Vector2u size;

public:
    widget ();
    widget (sf::Vector2i location);
    widget (sf::Vector2i location, sf::Vector2i size);
    widget (int location_x, int location_y);
    widget (int location_x, int location_y, int height, int width);

    void setLocate (sf::Vector2i locate);
    void move (sf::Vector2i move);
    void move (int move_x, int move_y);

    void setHeight (int height);
    void setWidth (int width);
    void setSize (sf::Vector2u size);

    virtual void action () = 0;
    virtual void draw () = 0;
};

class image {
public:
    sf::Texture *texture;
    sf::Sprite *sprite;

    image ();
    image (const char *file);

    void SetTexture (const char *file);

    ~image ();
};

// Coordinate central!
class button : public widget {
    sf::Sprite *spriteOn;
    sf::Sprite *spriteOff;
public:
    button ();
    button (int locationX, int locationY);


    void getTextures (sf::Texture *TurnOn, sf::Texture *TurnOff);

    //button (sf::Texture texture);
    ~button ();
};

#endif //SORTANALYS_WIDGET_H
