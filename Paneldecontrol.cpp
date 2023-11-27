#include "Paneldecontrol.h"

Paneldecontrol::Paneldecontrol()
{
    _texturapanellateral.loadFromFile("panellateral.png");
    _spritepanellateral.setTexture(_texturapanellateral);
    _spritepanellateral.setPosition(575,10);
    _texturacuadrotextoinferior.loadFromFile("Cuadrotextoinferior.png");
    _spritecuadrotextoinferior.setTexture(_texturacuadrotextoinferior);
    _spritecuadrotextoinferior.setPosition(150,480);
        _fuente1.loadFromFile("geometric_415_black_bt.ttf");
     _texturavictoria.loadFromFile("textura_victoria.png");
    _spritevictoria.setTexture(_texturavictoria);
    _spritevictoria.setPosition(10,10);
    _texturaderrota.loadFromFile("textura_derrota.png");
    _spritederrota.setTexture(_texturaderrota);
    _spritederrota.setPosition(10,10);
    _textoCuadroTexto.setFont(_fuente1);
    _textoCuadroTexto.setCharacterSize(20);
    _textoCuadroTexto.setColor(sf::Color::Black);
    _textoCuadroTexto.setScale(1,1);
    _textoCuadroTexto.setPosition(210,525);
    _textoCuadroTexto.setOrigin(_textoCuadroTexto.getGlobalBounds().width/2,_textoCuadroTexto.getGlobalBounds().height/2);
    //_spritecasitas.setOrigin(_spritecasitas.getGlobalBounds().width/2,_spritecasitas.getGlobalBounds().height/2);
    cargarstrings();
    Cargarcasitas();




}


void Paneldecontrol::Cargarcasitas(){


    _texturacasitas[0].loadFromFile("1_Textura_kiosco.png");
   _texturacasitas[1].loadFromFile("2_Textura_casaariel.png");
   _texturacasitas[2].loadFromFile("3_Textura_Vecinofavor1.png");
   _texturacasitas[3].loadFromFile("4_Textura_bicicleteria - copia.png");
   _texturacasitas[4].loadFromFile("5_Textura_Vecinofavor2.png");
   _texturacasitas[5].loadFromFile("6_Textura_Casaexjugador.png");
    _texturacasitas[6].loadFromFile("7_Textura_lavadero - copia.png");
    _texturacasitas[7].loadFromFile("0_Textura_Casapipo.png");


}
void Paneldecontrol::cargarstrings(){

_objetivos[0]="Dirigete al Kiosko   ";
_objetivos[1]="Dirigete a lo de Ariel  ";
_objetivos[2]="Dirigete a lo del tio de Ariel";
_objetivos[3]="Dirigete a la bicicleteria";
_objetivos[4]="Dirigete a lo del librero";
_objetivos[5]="Dirigete a lo del rifle";
_objetivos[6]="Dirigete al lavadero";
_objetivos[7]="Dirigete a tu casa";






}

void Paneldecontrol::imprimirobjetivos(int numerodeobjetivo){


activarobjetivos();
_textoCuadroTexto.setString(_objetivos[numerodeobjetivo]);
_spritecasitas.setTexture(_texturacasitas[numerodeobjetivo]);
_spritecasitas.setPosition(_textoCuadroTexto.getPosition().x+_textoCuadroTexto.getGlobalBounds().width,_textoCuadroTexto.getPosition().y-20);



}



void Paneldecontrol::cargarobjetos(Figurita *Vectorfiguritas, const int cantidadfigus, Objeto *Vectorobjetos, const int cantidadobjetos, Repetida *vectorrepetidas, const int cantidadrepetidas){

for(int i=0;i<6;i++){    _figuritas[i]=&Vectorfiguritas[i];}

for(int i=0;i<3;i++){    _objetos[i]=&Vectorobjetos[i];}

for(int i=0;i<3;i++){    _repetidas[i]=&vectorrepetidas[i];}

}

void Paneldecontrol::update(){


}


Paneldecontrol::~Paneldecontrol()
{
    //dtor
}
sf::FloatRect  Paneldecontrol::getBound() const
{
    return _spritepanellateral.getGlobalBounds();
}

void Paneldecontrol::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
 target.draw(_spritecuadrotextoinferior, states);
    target.draw(_spritepanellateral, states);
    for(int i=0;i<3;i++){
    if(_objetos[i]->getenpantalla()){
        target.draw(*_objetos[i],states);
    }
   }

    if(gano==true){

        target.draw(_spritevictoria);
    }
    if(perdio==true){

        target.draw(_spritevictoria);
    }

    if(objetivosactivos){

        target.draw(_spritecasitas);
        target.draw(_textoCuadroTexto);

    }

   for(int i=0;i<6;i++){
    if(_figuritas[i]->getestado()){
        target.draw(*_figuritas[i],states);
    }
   }

   for(int i=0;i<3;i++){
    if(_repetidas[i]->getestado()){
        target.draw(*_repetidas[i],states);
    }
   }



}



















