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

widget::widget (sf::Vector2i location, sf::Vector2u size) :
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

bool widget::VerifySize () {
    return size.x > 0 && size.y > 0;
}

const sf::Vector2u widget::getSize () const {
    return size;
}

bool widget::Intersect (sf::Vector2i point) {
    return (location.x + size.x >= point.x && location.x <= point.x) &&
           (location.y + size.y >= point.y && location.y <= point.y);
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

button::button (sf::Vector2i location, sf::Vector2u size) :
    widget (location, size),
    spriteOn (new sf::Sprite),
    spritePtd (new sf::Sprite),
    spriteOff (new sf::Sprite),
    state (BUTTON_STATE::TURN_OFF)
{
        spriteOn->setPosition  (location.x, location.y);
        spritePtd->setPosition (location.x, location.y);
        spriteOff->setPosition (location.x, location.y);
}

button::button (int locationX, int locationY) :
    button (sf::Vector2i (locationX, locationY), sf::Vector2u (0, 0))
{}

button::button () :
    button (0, 0)
{};

button::~button () {
    delete spriteOff;
    delete spriteOn;
}

void button::SetAnimation (sf::Texture *TurnOn, sf::Texture *TurnOff, sf::Texture *Pointed) {
    if (VerifySize () == false)
        throw std::runtime_error ("size < 0");

    SetSprite (*spriteOn,  TurnOn,  getSize ());
    SetSprite (*spriteOff, TurnOff, getSize ());
    SetSprite (*spritePtd, Pointed, getSize ());
}


void button::draw () {
    switch (state) {
        case BUTTON_STATE::TURN_ON:
            Window->draw (*spriteOn);
            break;
        case BUTTON_STATE::POINTED:
            Window->draw (*spritePtd);
            break;
        case BUTTON_STATE::TURN_OFF:
            Window->draw (*spriteOff);
            break;
    }
}

void button::action (sf::Event event) {
    // Empty
}

void button::action () {
    sf::Vector2i mousePosition = sf::Mouse::getPosition (*Window);
    if (Intersect (mousePosition))
        if (sf::Mouse::isButtonPressed (sf::Mouse::Left))
            state = BUTTON_STATE::TURN_ON;
        else
            state = BUTTON_STATE::POINTED;
    else
        state = BUTTON_STATE::TURN_OFF;
}
