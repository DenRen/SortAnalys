#include <stdexcept>
#include <iostream>
#include "widget.h"
#include "MyFuncs.h"

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

void widget::setLocation (sf::Vector2i locate) {
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

void widget::SetCenter (sf::Vector2i location) {
    this->location = sf::Vector2i (location.x + size.x / 2, location.y + size.y / 2);
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
    spriteOn  (new sf::Sprite),
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

    Window->draw (text);
}

void button::action (sf::Event event) {

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition (*Window);

            if (Intersect (mousePosition)) {
                state = BUTTON_STATE::TURN_ON;
            }
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition (*Window);

            if (Intersect (mousePosition))
                state = BUTTON_STATE::POINTED;
            else
                state = BUTTON_STATE::TURN_OFF;
        }
    }
}

void button::action () {
    if (state != BUTTON_STATE::TURN_ON) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition (*Window);
        if (Intersect (mousePosition))
            state = BUTTON_STATE::POINTED;
        else
            state = BUTTON_STATE::TURN_OFF;
    }
}

void button::SetInCenter () {
    MyText::SetInCenter (location, size);
}

void MyText::InitText (sf::Font &font, int size, sf::Color color) {
    text.setFont (font);
    text.setCharacterSize (size);
    text.setFillColor (color);
}

void MyText::InitText (sf::Font &font, int size, sf::Color color, sf::Text::Style style) {
    InitText (font, size, color);
    text.setStyle (style);
}

void MyText::SetInCenter (sf::Vector2i location, sf::Vector2u size) {
    sf::FloatRect bounds = text.getLocalBounds ();
    text.setPosition (getCenter (location, size, bounds.height, bounds.width));
}

void ButtonMgr::addButton (sf::Vector2i CenterCoord, std::string title) {

    button *Button = new button (sf::Vector2i (CenterCoord.x - size.x / 2, CenterCoord.y - size.y / 2), size);
    Button->SetAnimation (TurnOn, TurnOff, Pointed);
    if (style == -1)
        Button->InitText (*font, sizeFont, color);
    else
        Button->InitText (*font, sizeFont, color, static_cast <sf::Text::Style > (style));

    Button->text.setString (title);
    Button->SetInCenter ();

    buttons.push_back (Button);
}

void ButtonMgr::setFont (sf::Font *font, unsigned sizeFont, sf::Color color) {
    if (font == nullptr)
        throw std::runtime_error ("font == nullptr");

    this->font = font;
    this->sizeFont = sizeFont;
    this->color = color;
}

void ButtonMgr::setFont (sf::Font *font, unsigned sizeFont, sf::Color color, sf::Text::Style style) {
    setFont (font, sizeFont, color);
    this->style = style;
}

void ButtonMgr::setAnimation (sf::Texture *TurnOn, sf::Texture *TurnOff, sf::Texture *Pointed) {
    this->TurnOn = TurnOn;
    this->TurnOff = TurnOff;
    this->Pointed = Pointed;
}

void ButtonMgr::setSize (sf::Vector2u size) {
    this->size = size;
}

bool ButtonMgr::Verifier () {
    return (size.x > 0 && size.y > 0) &&
           (TurnOn != nullptr && TurnOff != nullptr && Pointed != nullptr) &&
           (font != nullptr && sizeFont > 0);
}

void ButtonMgr::draw () {
    const int size = buttons.size ();
    for (int i = 0; i < size; i++)
        buttons[i]->draw ();
}

void ButtonMgr::action () {
    const int size = buttons.size ();
    for (int i = 0; i < size; i++)
        buttons[i]->action ();
}

void ButtonMgr::action (sf::Event event) {
    const int size = buttons.size ();
    for (int i = 0; i < size; i++)
        buttons[i]->action (event);
}

ButtonMgr::~ButtonMgr () {
    int iter = buttons.size ();
    while (--iter >= 0)
        delete buttons[iter];

    delete Pointed;
    delete TurnOn;
    delete TurnOff;

    delete font;
}

