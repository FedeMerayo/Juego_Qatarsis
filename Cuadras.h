#ifndef CUADRAS_H
#define CUADRAS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"


class Cuadras : public sf::Drawable, public Colisionable
{
private:
    sf::Sprite _spritecuadras;
    sf::Texture _texturacuadras;

public:

    Cuadras();

    /// Funciones
    float getxorigen();
    float getyorigen();


    /// Draw y sprites
    sf::FloatRect getBound() const;
    sf::Sprite getSprite() const;
    void cargartexturaensprite(std::string nombredelarchivo);
    void setposicionsprite(float x, float y);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // CUADRAS_H
