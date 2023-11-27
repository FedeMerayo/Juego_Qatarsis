#include "Cuadras.h"

Cuadras::Cuadras(){}

void Cuadras::cargartexturaensprite(std::string nombredelarchivo){

    _texturacuadras.loadFromFile(nombredelarchivo);
    _spritecuadras.setTexture(_texturacuadras);
}



void Cuadras:: setposicionsprite(float x, float y){

    _spritecuadras.setPosition(x,y);
}

sf::FloatRect  Cuadras::getBound() const{   return _spritecuadras.getGlobalBounds();}

void Cuadras::draw(sf::RenderTarget& target, sf::RenderStates states) const{  target.draw(_spritecuadras, states);}

sf::Sprite  Cuadras::getSprite() const { return _spritecuadras;}

float Cuadras::getxorigen() { return _spritecuadras.getPosition().x;}

float Cuadras::getyorigen(){ return _spritecuadras.getPosition().y;}
