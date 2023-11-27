#include "Objeto.h"

Objeto::Objeto(){}

//	Funciones

void Objeto::setcodigoobjeto(int codigo)    {_codigodeobjeto=codigo;}

int Objeto::getcodigoobjeto()   {return _codigodeobjeto;}

void Objeto::solucionado()  {_solucionado=true;}

void Objeto::imprimir()  {_enpantalla=true;}


///	Sprites y draw

sf::FloatRect Objeto::getBound() const  {

if(_solucionado==true){
    return _spriteobjeto[1].getGlobalBounds();

    }
    else{
    return _spriteobjeto[0].getGlobalBounds();
    }
}

void Objeto::draw(sf::RenderTarget& target, sf::RenderStates states) const  {

if(_solucionado==true){
target.draw(_spriteobjeto[1]);

    }
    else{
target.draw(_spriteobjeto[0]);
    }


}

void Objeto::setposicionsprite(int numerodesprite,float x, float y){

_spriteobjeto[numerodesprite].setPosition(x,y);


}


void Objeto::setsprite(int numerodesprite, std::string nombredearchivo){
    _texturaobjeto[numerodesprite].loadFromFile(nombredearchivo);
    _spriteobjeto[numerodesprite].setTexture(_texturaobjeto[numerodesprite]);

}

Objeto::~Objeto(){}
