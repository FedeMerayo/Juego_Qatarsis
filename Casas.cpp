#include "Casas.h"


void Casas::cargartexturaensprite(string nombredelarchivo)
{
    _texturacasas.loadFromFile(nombredelarchivo);
    _spritecasas.setTexture(_texturacasas);
}


void Casas::setposicionsprite(float x, float y)
{
    _spritecasas.setPosition(x,y);
}

sf::FloatRect  Casas::getBound() const
{
    return _spritecasas.getGlobalBounds();
}


void Casas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_spritecasas, states);
}

float Casas::getxorigen()
{
    return _spritecasas.getPosition().x;
}

float Casas::getyorigen()
{
    return _spritecasas.getPosition().y;
}

void Casas::setSpriteRotation(float op)
{
    _spritecasas.rotate(op);
}

void Casas::setSpriteOrigin(float x , float y)
{
    _spritecasas.setOrigin(x , y);
}

Casas::Casas()
{
    //ctor
}

Casas::~Casas()
{
    //dtor
}
