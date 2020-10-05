#ifndef SORTANALYS_WIDGET_H
#define SORTANALYS_WIDGET_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "MyWindow.h"

class widget {
public:
    sf::Vector2i location;
    sf::Vector2u size;

    widget ();
    widget (sf::Vector2i location);
    widget (sf::Vector2i location, sf::Vector2u size);
    widget (int location_x, int location_y);
    widget (int location_x, int location_y, int height, int width);

    void setLocation (sf::Vector2i locate);
    void move (sf::Vector2i move);
    void move (int move_x, int move_y);

    void setHeight (int height);
    void setWidth (int width);
    void setSize (sf::Vector2u size);

    const sf::Vector2u getSize () const;

    void SetCenter (sf::Vector2i location);

    bool VerifySize ();
    bool Intersect (sf::Vector2i Point);

    virtual void action (sf::Event event) = 0;
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

enum BUTTON_STATE {
    TURN_OFF,
    POINTED,
    TURN_ON
};

struct MyText {
    sf::Text text;

    MyText () = default;

    void InitText (sf::Font &font, int size, sf::Color color);
    void InitText (sf::Font &font, int size, sf::Color color, sf::Text::Style style);

    void SetInCenter (sf::Vector2i location, sf::Vector2u size);

    void SetOriginInCenter ();
    void SetOriginInUp ();;
    void SetOriginInDown ();
    void SetOriginInRight ();
    void SetOriginInLeft ();
    void SetOriginInTopRight ();
};

// Coordinate central!
class button : public widget, public MyText {
    sf::Sprite *spriteOn;
    sf::Sprite *spritePtd;
    sf::Sprite *spriteOff;
    unsigned state : 2;
public:

    button ();
    button (int locationX, int locationY);
    button (sf::Vector2i location, sf::Vector2u size);
    button (button &&) = default;

    void SetAnimation (sf::Texture *TurnOn, sf::Texture *TurnOff, sf::Texture *Pointed);
    void SetInCenter ();

    void draw ();
    void action ();
    void action (sf::Event event);
    int getState () const;
    //button (sf::Texture texture);
    ~button ();
};

enum LOCATE_NAME_ARROW {
    UP,
    LEFT,
    DOWN,
    RIGHT
};

class Graphic : public widget, public MyText {

    sf::RectangleShape AxesX;
    sf::RectangleShape AxesY;

    sf::RectangleShape DivX;
    sf::RectangleShape DivY;

    sf::RectangleShape ArrowX[2];
    sf::RectangleShape ArrowY[2];

    sf::CircleShape point;

    bool changed = true;

    sf::Vector2i coordCenter;
    sf::Vector2i LenAxesX;
    sf::Vector2i LenAxesY;

public:
    sf::Vector2f RelPosIntAxes;     // Relative position of intersecting axes

    sf::Vector2f RelLenX;
    sf::Vector2f RelLenY;

    sf::Vector2u NumDivX;
    sf::Vector2u NumDivY;

    int thickAxes;                  // Thickness of axes
    int thickDiv;                   // Thickness of division
    int lenDiv;

    sf::Vector2u sizeDiv;
    sf::Vector2i DistBetweenDivVal;

    sf::Vector2i valDiv;

    int radiusPoint;
    sf::Color colorPoint;

    int lenArrow;       // Hypotenuse
    float angleArrow;

    std::vector <std::pair <float, float>> data;

    std::string titleX, titleY;
    sf::Vector2i locateNameArrows;

    void SetChanged ();

    Graphic () = default;
    Graphic (sf::Vector2i location, sf::Vector2u size);

    void action ();
    void action (sf::Event event);
    void draw ();

    bool Verifier ();
    void update ();

    sf::Vector2i GetMinMaxValX ();
    sf::Vector2i GetMinMaxValY ();
    sf::Vector2i GetValDiv (sf::Vector2i MaxVal);

    void SetMaxX (int MaxValX);
    void SetMaxY (int MaxValY);

    void setTitleX (std::string title);
    void setTitleY (std::string title);
};
#endif //SORTANALYS_WIDGET_H