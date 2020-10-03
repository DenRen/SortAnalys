#ifndef SORTANALYS_GRAPHICMGRS_H
#define SORTANALYS_GRAPHICMGRS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "widget.h"

class ButtonMgr {       // Fabric
    sf::Vector2u size;
    sf::Texture *TurnOn;
    sf::Texture *TurnOff;
    sf::Texture *Pointed;

    sf::Font *font;
    unsigned sizeFont;
    sf::Color color;
    int style = -1;
public:
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
    void SetTemplParam (button *Button);
};

class GraphicMgr {


public:
    sf::Font *font;
    unsigned sizeFont;
    sf::Color color;
    int style = -1;

    sf::Vector2u size;

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

    int lenArrow;       // Hypotenuse
    float angleArrow;

    int radiusPoint;
    sf::Color colorPoint;

    std::vector <Graphic *> graphs;

    GraphicMgr () = default;
    ~GraphicMgr ();

    void setFont (sf::Font *font, unsigned sizeFont, sf::Color color);
    void setFont (sf::Font *font, unsigned sizeFont, sf::Color color, sf::Text::Style style);

    bool Verifier ();

    void draw ();
    void action ();
    void action (sf::Event event);

    void addGraph (sf::Vector2i CenterCoord, sf::Vector2i MaxVal);

    void SetTemplParam (Graphic *graph);
    sf::Vector2i SetValDiv (sf::Vector2i MaxVal);
};

#endif //SORTANALYS_GRAPHICMGRS_H
