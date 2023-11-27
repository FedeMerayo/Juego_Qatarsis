#include "Figurita.h"

Figurita::Figurita(){}

/// Funciones

void Figurita::Pegar(){pegada=true;}

bool Figurita::getestado(){return pegada;}

void Figurita::setcodigodefigurita(int codigo)  {_codigodefigurita=codigo;  }

int Figurita::getcodigodefigurita()     {return _codigodefigurita;}

/// Sprites y draw

void Figurita::setsprite(std::string nombredearchivo){

    _texturafigurita.loadFromFile(nombredearchivo);
    _spritefigurita.setTexture(_texturafigurita);
}

sf::Sprite Figurita::getSprite()    {return _spritefigurita;   }

sf::FloatRect Figurita::getBound() const    {return _spritefigurita.getGlobalBounds();  }

void Figurita::setposicionsprite(float x, float y)  {_spritefigurita.setPosition(x,y);  }

void Figurita::draw(sf::RenderTarget& target, sf::RenderStates states) const    {target.draw(_spritefigurita);  }


Figurita::~Figurita(){}
