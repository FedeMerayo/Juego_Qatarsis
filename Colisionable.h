#ifndef COLISIONABLE_H
#define COLISIONABLE_H
#include <SFML/Graphics.hpp>

class Colisionable
{
public:
    virtual sf::FloatRect getBound() const =0;
    bool iscolision (Colisionable &obj) const;

};

#endif // COLISIONABLE_H
