#ifndef CASAS_H
#define CASAS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"
using namespace std;

class Casas : public sf::Drawable , public Colisionable
{
        private:
        sf::Sprite _spritecasas;
        sf::Texture _texturacasas;

    public:
Casas();
        virtual ~Casas();
        sf::FloatRect getBound() const;
        void cargartexturaensprite(string nombredelarchivo);
        void setposicionsprite(float x, float y);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::Sprite getSprite() { return _spritecasas;}
        sf::Texture getTexture() { return _texturacasas;}
        float getxorigen();
        float getyorigen();
        void setSpriteRotation(float op);
        void setSpriteOrigin(float x , float y);
};

#endif // CASAS_H
