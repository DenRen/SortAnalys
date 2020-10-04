#include <stdexcept>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
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
    text.setOrigin (bounds.width / 2, bounds.height);
    text.setPosition (sf::Vector2f (location.x + size.x / 2, location.y + size.y / 2));
}

void MyText::SetOriginInCenter () {
    sf::Rect <float> size = text.getLocalBounds ();
    text.setOrigin (size.width / 2, size.height);
}

void MyText::SetOriginInUp () {
    sf::Rect <float> size = text.getLocalBounds ();
    text.setOrigin (size.width / 2, size.height / 2);
}

void MyText::SetOriginInRight () {
    sf::Rect <float> size = text.getLocalBounds ();
    text.setOrigin (size.width, size.height);
}

void MyText::SetOriginInLeft () {
    sf::Rect <float> size = text.getLocalBounds ();
    text.setOrigin (0, size.height);
}

void MyText::SetOriginInTopRight () {
    sf::Rect <float> size = text.getLocalBounds ();
    text.setOrigin (size.width, 0);
}

bool Graphic::Verifier () {
    return (widget::size.x > 0 && thickAxes > 0) &&
           (widget::size.y > 0 && thickDiv  > 0);
}

void Graphic::draw () {
    if (changed)
        update ();

    Window->draw (AxesX);
    Window->draw (AxesY);

    DivX.setPosition (coordCenter.x, coordCenter.y);
    int delta_X = LenAxesX.y / (NumDivX.x + 1);
    for (int i = 0; i < NumDivX.x; i++) {
        DivX.move (delta_X, 0);
        Window->draw (DivX);

        text.setString (std::to_string (valDiv.x * (i + 1)));
        MyText::SetOriginInUp ();
        text.setPosition (coordCenter.x + (i + 1) * delta_X, coordCenter.y + lenDiv / 2 + DistBetweenDivVal.x);
        Window->draw (text);
    }

    DivX.setPosition (coordCenter.x, coordCenter.y);
    delta_X = LenAxesX.x / (NumDivX.y + 1);
    for (int i = 0; i < NumDivX.y; i++) {
        DivX.move (-delta_X, 0);
        Window->draw (DivX);

        text.setString (std::to_string (-valDiv.x * (i + 1)));
        MyText::SetOriginInUp ();
        text.setPosition (coordCenter.x - (i + 1) * delta_X, coordCenter.y + lenDiv / 2 + DistBetweenDivVal.x);
        Window->draw (text);
    }

    DivY.setPosition (coordCenter.x, coordCenter.y);
    int delta_Y = LenAxesY.x / (NumDivY.x + 1);
    for (int i = 0; i < NumDivY.x; i++) {
        DivY.move (0, -delta_Y);
        Window->draw (DivY);

        text.setString (std::to_string (valDiv.y * (i + 1)));
        MyText::SetOriginInRight ();
        text.setPosition (coordCenter.x - lenDiv / 2 - DistBetweenDivVal.y, coordCenter.y - delta_Y * (i + 1));
        Window->draw (text);
    }

    DivY.setPosition (coordCenter.x, coordCenter.y);
    delta_Y = LenAxesY.y / (NumDivY.y + 1);
    for (int i = 0; i < NumDivY.y; i++) {
        DivY.move (0, delta_Y);
        Window->draw (DivY);

        text.setString (std::to_string (-valDiv.y * (i + 1)));
        MyText::SetOriginInRight ();
        text.setPosition (coordCenter.x - lenDiv / 2 - DistBetweenDivVal.y, coordCenter.y - delta_Y * (i + 1));
        Window->draw (text);
    }

    text.setString ("0");
    MyText::SetOriginInTopRight ();
    text.setPosition (coordCenter.x - lenDiv / 2, coordCenter.y + lenDiv / 2);
    Window->draw (text);

    // Draw arrow of axes
    for (int i = 0; i < 2; i++) {
        Window->draw (ArrowX[i]);
        Window->draw (ArrowY[i]);
    }

    // Draw only I part graphic
    const int size_data = data.size ();
    const int maxValX = GetMinMaxValX ().y;
    const int maxValY = GetMinMaxValY ().y;

    sf::Vector2f coef = sf::Vector2f ((float) LenAxesX.y / maxValX, (float) LenAxesY.x / maxValY);

    for (int i = 0; i < size_data; i++) {
        float x = data[i].first, y = data[i].second;
        if (x <= maxValX && y <= maxValY) {
            point.setPosition (coordCenter.x + x * coef.x, coordCenter.y - y * coef.y);
            Window->draw (point);
        }
    }
}

void Graphic::action () {

}

void Graphic::action (sf::Event event) {

}

void Graphic::update () {
    coordCenter = sf::Vector2i (location.x + size.x * RelPosIntAxes.x,
                                location.y + size.y * (1 - RelPosIntAxes.y));

    LenAxesX = sf::Vector2i ((coordCenter.x - location.x) * RelLenX.x,
                             (location.x + size.x - coordCenter.x) * RelLenX.y);

    LenAxesY = sf::Vector2i ((coordCenter.y - location.y) * RelLenY.x,
                             (location.y + size.y - coordCenter.y) * RelLenY.y);

    AxesX.setSize (sf::Vector2f (LenAxesX.x + LenAxesX.y, thickAxes));
    AxesX.setOrigin (0, thickAxes / 2);
    AxesX.setPosition (coordCenter.x - LenAxesX.x, coordCenter.y);

    AxesY.setSize (sf::Vector2f (thickAxes, LenAxesY.x + LenAxesY.y));
    AxesY.setOrigin (thickAxes / 2, 0);
    AxesY.setPosition (coordCenter.x, coordCenter.y - LenAxesY.x);

    DivX.setSize (sf::Vector2f (thickDiv, lenDiv));
    DivX.setOrigin (sf::Vector2f (thickDiv / 2, lenDiv / 2));

    DivY.setSize (sf::Vector2f (lenDiv, thickDiv));
    DivY.setOrigin (sf::Vector2f (lenDiv / 2, thickDiv / 2));

    for (int i = 0; i < 2; i++) {
        ArrowX[i].setSize (sf::Vector2f (lenArrow, thickAxes));
        ArrowX[i].setOrigin (sf::Vector2f (lenArrow, thickAxes / 2));
        ArrowX[i].setPosition (sf::Vector2f (coordCenter.x + LenAxesX.y, coordCenter.y));
        ArrowX[i].setRotation ((1 - 2 * i) * angleArrow);
    }
    for (int i = 0; i < 2; i++) {
        ArrowY[i].setSize (sf::Vector2f (thickAxes, lenArrow));
        ArrowY[i].setOrigin (sf::Vector2f (thickAxes / 2, 0));
        ArrowY[i].setPosition (sf::Vector2f (coordCenter.x, coordCenter.y - LenAxesY.x));
        ArrowY[i].setRotation ((1 - 2 * i) * angleArrow);
    }

    point.setRadius (radiusPoint);
    point.setFillColor (colorPoint);
    point.setOrigin (radiusPoint / 2, radiusPoint / 2);

    changed = false;
}

Graphic::Graphic (sf::Vector2i location, sf::Vector2u size) :
    widget (location, size)
{}

void Graphic::SetChanged () {
    changed = true;
}

sf::Vector2i Graphic::GetMinMaxValX () {
    int left_min_val = 0;
    if (LenAxesX.x != 0)
        left_min_val = valDiv.x * (NumDivX.y + 1);

    int right_max_val = 0;
    if (LenAxesX.y != 0)
        right_max_val = valDiv.x * (NumDivX.x + 1);

    return sf::Vector2i (left_min_val, right_max_val);
}

sf::Vector2i Graphic::GetMinMaxValY () {
    int down_min_val = 0;
    if (LenAxesY.y != 0)
        down_min_val = valDiv.y * (NumDivY.y + 1);

    int up_max_val = 0;
    if (LenAxesY.x != 0)
        up_max_val = valDiv.y * (NumDivY.x + 1);

    return sf::Vector2i (down_min_val, up_max_val);
}

sf::Vector2i Graphic::GetValDiv (sf::Vector2i MaxVal) {
    return sf::Vector2i (MaxVal.x / (NumDivX.x + NumDivX.y + 1),
                         MaxVal.y / (NumDivY.x + NumDivY.y + 1));
}

void Graphic::SetMaxX (int MaxValX) {
    valDiv.x = GetValDiv (sf::Vector2i (MaxValX, 0)).x;
}

void Graphic::SetMaxY (int MaxValY) {
    valDiv.y = GetValDiv (sf::Vector2i (0, MaxValY)).y;
}
