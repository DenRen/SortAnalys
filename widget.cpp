#include <stdexcept>
#include "widget.h"

widget::widget (int location_x, int location_y) :
        location (location_x, location_y),
        size (0, 0)
{}

widget::widget (sf::Vector2i location) :
        widget (location.x, location.y)
{}

widget::widget (int location_x, int location_y, int height, int width) :
        location (location_x, location_y),
        size (height, width)
{}

widget::widget () :
        widget (0, 0, 0, 0)
{}

widget::widget (sf::Vector2i location, sf::Vector2i size) :
        location (location),
        size (size)
{}

void widget::setHeight (int height) {
    if (height <= 0)
        throw std::runtime_error ("height < 0");

    size.y = height;
}

void widget::setWidth (int width) {
    if (width <= 0)
        throw std::runtime_error ("width < 0");

    size.x = width;
}

void widget::move (int move_x, int move_y) {
     location += sf::Vector2i (move_x, move_y);
}

void widget::setSize (sf::Vector2u size) {
    this->size = size;
}

void widget::setLocate (sf::Vector2i locate) {
    location = locate;
}

void widget::move (sf::Vector2i move) {
    location += move;
}

image::image (const char *file) :
    texture (new sf::Texture),
    sprite (new sf::Sprite)
{
    SetTexture (file);
}

image::image () :
    texture (new sf::Texture),
    sprite (new sf::Sprite)
{}

image::~image () {
    delete sprite;
    delete texture;
}

void image::SetTexture (const char *file) {
    texture->loadFromFile (file);
    sprite->setTexture (*texture);
}

button::button (int locationX, int locationY) :
    widget (locationX, locationY),
    spriteOn (new sf::Sprite),
    spriteOff (new sf::Sprite)
{}

button::button () :
    button (0, 0)
{};

button::~button () {
    delete spriteOff;
    delete spriteOn;
}

void button::getTextures (sf::Texture *TurnOn, sf::Texture *TurnOff) {

}
