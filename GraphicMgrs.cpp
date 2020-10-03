#include "GraphicMgrs.h"

void ButtonMgr::addButton (sf::Vector2i CenterCoord, std::string title) {

    button *Button = new button (sf::Vector2i (CenterCoord.x - size.x / 2, CenterCoord.y - size.y / 2), size);

    SetTemplParam (Button);
    Button->text.setString (title);
    Button->SetInCenter ();

    buttons.push_back (Button);
}

void ButtonMgr::SetTemplParam (button *Button) {
    Button->SetAnimation (TurnOn, TurnOff, Pointed);
    if (style == -1)
        Button->InitText (*font, sizeFont, color);
    else
        Button->InitText (*font, sizeFont, color, static_cast <sf::Text::Style > (style));
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
    int iter = buttons.size ();
    while (--iter >= 0)
        buttons[iter]->draw ();
}

void ButtonMgr::action () {
    int iter = buttons.size ();
    while (--iter >= 0)
        buttons[iter]->action ();
}

void ButtonMgr::action (sf::Event event) {
    int iter = buttons.size ();
    while (--iter >= 0)
        buttons[iter]->action (event);
}

ButtonMgr::~ButtonMgr () {
    size_t iter = buttons.size ();
    while (--iter >= 0)
        delete buttons[iter];

    delete Pointed;
    delete TurnOn;
    delete TurnOff;

    delete font;
}

GraphicMgr::~GraphicMgr () {
    size_t iter = graphs.size ();
    while (--iter >= 0)
        delete graphs[iter];
}

bool GraphicMgr::Verifier () {
    return (size.x    >  0 && size.y    >  0) &&
           (RelLenX.x >= 0 && RelLenX.y >= 0) &&
           (RelLenY.x >= 0 && RelLenY.y >= 0) &&
           (thickAxes >= 0 && thickDiv  >= 0) &&
           (lenDiv    >= 0 && lenArrow  >= 0) &&
           (RelPosIntAxes.x >= 0 && RelPosIntAxes.y >= 0);
}


void GraphicMgr::setFont (sf::Font *font, unsigned sizeFont, sf::Color color) {
    if (font == nullptr)
        throw std::runtime_error ("font == nullptr");

    this->font = font;
    this->sizeFont = sizeFont;
    this->color = color;
}

void GraphicMgr::setFont (sf::Font *font, unsigned sizeFont, sf::Color color, sf::Text::Style style) {
    setFont (font, sizeFont, color);
    this->style = style;
}

void GraphicMgr::draw () {
    int iter = graphs.size ();
    while (--iter >= 0)
        graphs[iter]->draw ();
}

void GraphicMgr::action () {
    int iter = graphs.size ();
    while (--iter >= 0)
        graphs[iter]->action ();
}

void GraphicMgr::action (sf::Event event) {
    int iter = graphs.size ();
    while (--iter >= 0)
        graphs[iter]->action (event);
}

void GraphicMgr::addGraph (sf::Vector2i CenterCoord, sf::Vector2i MaxVal) {
    Graphic *graph = new Graphic (sf::Vector2i {CenterCoord.x - (int) size.x / 2,
                                                CenterCoord.y - (int) size.y / 2}, size);
    SetTemplParam (graph);
    graph->valDiv = SetValDiv (MaxVal);
    graph->SetChanged ();

    graphs.push_back (graph);
}

void GraphicMgr::SetTemplParam (Graphic *graph) {
    graph->size = size;
    graph->RelPosIntAxes = RelPosIntAxes;
    graph->RelLenX = RelLenX;
    graph->RelLenY = RelLenY;
    graph->NumDivX = NumDivX;
    graph->NumDivY = NumDivY;
    graph->thickAxes = thickAxes;
    graph->thickDiv = thickDiv;

    graph->lenDiv = lenDiv;
    graph->sizeDiv = sizeDiv;
    graph->DistBetweenDivVal = DistBetweenDivVal;

    graph->lenArrow = lenArrow;
    graph->angleArrow = angleArrow;

    if (style == -1)
        graph->InitText (*font, sizeFont, color);
    else
        graph->InitText (*font, sizeFont, color, static_cast <sf::Text::Style > (style));

    graph->radiusPoint = radiusPoint;
    graph->colorPoint = colorPoint;
}

sf::Vector2i GraphicMgr::SetValDiv (sf::Vector2i MaxVal) {
    return sf::Vector2i (MaxVal.x / (NumDivX.x + NumDivX.y + 1),
                         MaxVal.y / (NumDivY.x + NumDivY.y + 1));
}
