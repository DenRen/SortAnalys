#ifndef SORTANALYS_WIDGET_H
#define SORTANALYS_WIDGET_H

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

    void InitText (sf::Font &font, int size, sf::Color color);
    void InitText (sf::Font &font, int size, sf::Color color, sf::Text::Style style);

    void SetInCenter (sf::Vector2i location, sf::Vector2u size);
};

// Coordinate central!
class button : public widget, public MyText {
    sf::Sprite *spriteOn;
    sf::Sprite *spritePtd;
    sf::Sprite *spriteOff;
    unsigned state : 2;
public:

    int id = -1;

    button ();
    button (int locationX, int locationY);
    button (sf::Vector2i location, sf::Vector2u size);
    button (button &&) = default;

    void SetAnimation (sf::Texture *TurnOn, sf::Texture *TurnOff, sf::Texture *Pointed);
    void SetInCenter ();

    void draw ();
    void action ();
    void action (sf::Event event);
    //button (sf::Texture texture);
    ~button ();
};

class ButtonMgr {       // Fabric
public:
    sf::Vector2u size;
    sf::Texture *TurnOn;
    sf::Texture *TurnOff;
    sf::Texture *Pointed;

    sf::Font *font;
    unsigned sizeFont;
    sf::Color color;
    int style = -1;

    std::vector <button *> buttons;


    ButtonMgr () = default;
    ~ButtonMgr ();

    void setSize (sf::Vector2u size);
    void setAnimation (sf::Texture *TurnOn, sf::Texture *TurnOff, sf::Texture *Pointed);
    void setFont (sf::Font *font, unsigned sizeFont, sf::Color color);
    void setFont (sf::Font *font, unsigned sizeFont, sf::Color color, sf::Text::Style style);

    bool Verifier ();

    void draw ();
    void action ();
    void action (sf::Event event);

    void addButton (sf::Vector2i CenterCoord, std::string title);
};

#endif //SORTANALYS_WIDGET_H
