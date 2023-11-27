#include "Mapa.h"

Mapa::Mapa(){
    _texturacalles.loadFromFile("Calles.png");
    _spritecalles.setTexture(_texturacalles);
    _spritecalles.setPosition(10,10);

    texturayposicioncuadras();
    texturayposicioncasas();
}


Cuadras *Mapa::getcuadras(int numerodecuadra){

return &_cuadras[numerodecuadra];

}

Casas *Mapa::getcasa(int numerodecasa){

return &_casas[numerodecasa];

}



void Mapa::texturayposicioncuadras(){
    for(int x=0; x<14; x++)
    {
        _cuadras[x].cargartexturaensprite("SpriteManzana" + std::to_string(x+1) + ".png");
    }

    float _distMapa = 10;
    float _distCalle= 35;

    _cuadras[0].setposicionsprite(_distMapa + _distCalle , _distMapa + _distCalle);
    _cuadras[1].setposicionsprite(_distMapa + (2.f * _distCalle) +  _cuadras[0].getSprite().getGlobalBounds().width , _distMapa + _distCalle);
    _cuadras[2].setposicionsprite(_distMapa + (3.f * _distCalle) +  _cuadras[0].getSprite().getGlobalBounds().width +  _cuadras[1].getSprite().getGlobalBounds().width, _distMapa + _distCalle);
    _cuadras[3].setposicionsprite(_distMapa + _distCalle ,  _distMapa + (2.f * _distCalle) + _cuadras[0].getSprite().getGlobalBounds().height);
    _cuadras[4].setposicionsprite(_distMapa + (2.f * _distCalle) +  _cuadras[3].getSprite().getGlobalBounds().width ,  _distMapa + (2.f * _distCalle) + _cuadras[1].getSprite().getGlobalBounds().height);
    _cuadras[5].setposicionsprite(_distMapa + (3.f * _distCalle) +  _cuadras[3].getSprite().getGlobalBounds().width +  _cuadras[4].getSprite().getGlobalBounds().width, _distMapa + (2.f * _distCalle) + _cuadras[2].getSprite().getGlobalBounds().height);
    _cuadras[6].setposicionsprite(_distMapa + (4.f * _distCalle) +  _cuadras[3].getSprite().getGlobalBounds().width +  _cuadras[4].getSprite().getGlobalBounds().width +  _cuadras[5].getSprite().getGlobalBounds().width, _distMapa + (2.f * _distCalle) + _cuadras[2].getSprite().getGlobalBounds().height);
    _cuadras[7].setposicionsprite(_distMapa + (2.f * _distCalle) +  _cuadras[3].getSprite().getGlobalBounds().width ,  _distMapa + (3.f * _distCalle) + _cuadras[1].getSprite().getGlobalBounds().height + _cuadras[4].getSprite().getGlobalBounds().height);
    _cuadras[8].setposicionsprite(_distMapa + (3.f * _distCalle) +  _cuadras[3].getSprite().getGlobalBounds().width +  _cuadras[7].getSprite().getGlobalBounds().width,  _distMapa + (3.f * _distCalle) + _cuadras[1].getSprite().getGlobalBounds().height + _cuadras[4].getSprite().getGlobalBounds().height);
    _cuadras[9].setposicionsprite(_distMapa + _distCalle ,  _distMapa + (3.f * _distCalle) + _cuadras[0].getSprite().getGlobalBounds().height+ _cuadras[3].getSprite().getGlobalBounds().height);
    _cuadras[10].setposicionsprite(_distMapa + (2.f * _distCalle) +  _cuadras[9].getSprite().getGlobalBounds().width ,  _distMapa + (4.f * _distCalle) + _cuadras[1].getSprite().getGlobalBounds().height + _cuadras[4].getSprite().getGlobalBounds().height + _cuadras[7].getSprite().getGlobalBounds().height);
    _cuadras[11].setposicionsprite(_distMapa + (3.f * _distCalle) +  _cuadras[9].getSprite().getGlobalBounds().width  +  _cuadras[10].getSprite().getGlobalBounds().width,  _distMapa + (4.f * _distCalle) + _cuadras[1].getSprite().getGlobalBounds().height + _cuadras[4].getSprite().getGlobalBounds().height + _cuadras[7].getSprite().getGlobalBounds().height);
    _cuadras[12].setposicionsprite(_distMapa + (4.f * _distCalle) +  _cuadras[9].getSprite().getGlobalBounds().width  +  _cuadras[10].getSprite().getGlobalBounds().width +  _cuadras[11].getSprite().getGlobalBounds().width,  _distMapa + (4.f * _distCalle) + _cuadras[1].getSprite().getGlobalBounds().height + _cuadras[4].getSprite().getGlobalBounds().height + _cuadras[7].getSprite().getGlobalBounds().height);
    _cuadras[13].setposicionsprite(_distMapa + (5.f * _distCalle) +  _cuadras[9].getSprite().getGlobalBounds().width  +  _cuadras[10].getSprite().getGlobalBounds().width +  _cuadras[11].getSprite().getGlobalBounds().width +  _cuadras[12].getSprite().getGlobalBounds().width,  _distMapa + (4.f * _distCalle) + _cuadras[1].getSprite().getGlobalBounds().height + _cuadras[4].getSprite().getGlobalBounds().height + _cuadras[7].getSprite().getGlobalBounds().height);
}

void Mapa::texturayposicioncasas() {

    _casas[0].cargartexturaensprite("0_Textura_Casapipo.png");
    _casas[0].setSpriteOrigin(0, _casas[0].getBound().height);
    _casas[0].setposicionsprite(_cuadras[9].getxorigen(), _cuadras[9].getyorigen() +10);
    _casas[0].setSpriteRotation(90.f);


     _casas[1].cargartexturaensprite("1_Textura_kiosco.png");
    _casas[1].setSpriteOrigin(_casas[1].getBound().width, _casas[1].getBound().height);
    _casas[1].setposicionsprite(_cuadras[6].getxorigen() + _cuadras[6].getBound().width, _cuadras[6].getyorigen() + 15);
    _casas[1].setSpriteRotation(-90.f);

    _casas[2].cargartexturaensprite("2_Textura_casaariel.png");
    _casas[2].setSpriteOrigin(_casas[2].getBound().width, _casas[2].getBound().height);
    _casas[2].setposicionsprite(_cuadras[0].getxorigen() + _cuadras[0].getBound().width, _cuadras[0].getyorigen() + 10);
    _casas[2].setSpriteRotation(-90.f);

    _casas[3].cargartexturaensprite("3_Textura_Vecinofavor1.png");
    _casas[3].setSpriteOrigin(0, _casas[3].getBound().height);
    _casas[3].setposicionsprite(_cuadras[12].getxorigen() + 10, _cuadras[12].getyorigen() + _cuadras[12].getBound().height);

    _casas[4].cargartexturaensprite("4_Textura_bicicleteria.png");
    _casas[4].setSpriteOrigin(0, _casas[4].getBound().height);
    _casas[4].setposicionsprite(_cuadras[3].getxorigen(), _cuadras[3].getyorigen() +10);
    _casas[4].setSpriteRotation(90.f);


    _casas[5].cargartexturaensprite("5_Textura_Vecinofavor2.png");
    _casas[5].setSpriteOrigin(0, _casas[5].getBound().height);
    _casas[5].setposicionsprite(_cuadras[3].getxorigen() + 15, _cuadras[3].getyorigen() + _cuadras[3].getBound().height);

_casas[6].cargartexturaensprite("6_Textura_Casaexjugador.png");
    _casas[6].setSpriteOrigin(0, _casas[6].getBound().height);
    _casas[6].setposicionsprite(_cuadras[8].getxorigen() + 90, _cuadras[8].getyorigen() + _cuadras[8].getBound().height);



    _casas[7].cargartexturaensprite("7_Textura_lavadero.png");

    _casas[7].setSpriteOrigin(0, _casas[7].getBound().height);
    _casas[7].setposicionsprite(_cuadras[1].getxorigen() + 90, _cuadras[1].getyorigen());
    _casas[7].setSpriteRotation(-180.f);

    _casas[8].cargartexturaensprite("8-Textura_puestoDeDiarios.png");
    _casas[8].setSpriteOrigin(0, _casas[8].getBound().height);
    _casas[8].setposicionsprite(_cuadras[5].getxorigen() + 20, _cuadras[5].getyorigen() + _cuadras[5].getBound().height);

    _casas[9].cargartexturaensprite("9_Textura_casasAdosadas.png");
    _casas[9].setSpriteOrigin(0, _casas[9].getBound().height);
    _casas[9].setposicionsprite(_cuadras[5].getxorigen() + 120, _cuadras[5].getyorigen());
    _casas[9].setSpriteRotation(-180.f);

    _casas[10].cargartexturaensprite("10_Textura_iglesia.png");
    _casas[10].setSpriteOrigin(0, _casas[10].getBound().height);
    _casas[10].setposicionsprite(_cuadras[1].getxorigen() + 5, _cuadras[1].getyorigen() + _cuadras[1].getBound().height);

    _casas[11].cargartexturaensprite("11_Textura_escuela.png");
    _casas[11].setSpriteOrigin(0, _casas[11].getBound().height);
    _casas[11].setposicionsprite(_cuadras[7].getxorigen() + 15, _cuadras[7].getyorigen() + _cuadras[7].getBound().height);

    _casas[12].cargartexturaensprite("12_Textura_ferreteria.png");
    _casas[12].setSpriteOrigin(0, _casas[12].getBound().height);
    _casas[12].setposicionsprite(_cuadras[7].getxorigen() + 150, _cuadras[7].getyorigen());
    _casas[12].setSpriteRotation(-180.f);

    _casas[13].cargartexturaensprite("13_Textura_casaAmarillaYvioleta.png");
    _casas[13].setSpriteOrigin(0, _casas[13].getBound().height);
    _casas[13].setposicionsprite(_cuadras[8].getxorigen() + 15, _cuadras[8].getyorigen() + _cuadras[8].getBound().height);

        _casas[14].cargartexturaensprite("14_Textura_granero.png");
    _casas[14].setSpriteOrigin(0, _casas[14].getBound().height);
    _casas[14].setposicionsprite(_cuadras[2].getxorigen() + 130, _cuadras[2].getyorigen() + _cuadras[2].getBound().height);


    _casas[15].cargartexturaensprite("15_Textura_hospital.png");
    _casas[15].setSpriteOrigin(0, _casas[15].getBound().height);
    _casas[15].setposicionsprite(_cuadras[0].getxorigen() + 10, _cuadras[0].getyorigen() + _cuadras[0].getBound().height);



    _casas[16].cargartexturaensprite("16_Textura_heladeria.png");
    _casas[16].setSpriteOrigin(0, _casas[16].getBound().height);
    _casas[16].setposicionsprite(_cuadras[9].getxorigen() + 20, _cuadras[9].getyorigen() + _cuadras[9].getBound().height);

    _casas[17].cargartexturaensprite("17_Textura_casaTurquesa.png");
    _casas[17].setSpriteOrigin(0, _casas[17].getBound().height);
    _casas[17].setposicionsprite(_cuadras[10].getxorigen() + 10, _cuadras[10].getyorigen() + _cuadras[10].getBound().height);

    _casas[18].cargartexturaensprite("18_Textura_Jugueteria.png");
    _casas[18].setSpriteOrigin(_casas[18].getBound().width, _casas[18].getBound().height);
    _casas[18].setposicionsprite(_cuadras[11].getxorigen() + _cuadras[11].getBound().width, _cuadras[11].getyorigen() + 10);
    _casas[18].setSpriteRotation(-90.f);

    _casas[19].cargartexturaensprite("19_Textura_verduleria.png");
       _casas[19].setSpriteOrigin(0, _casas[19].getBound().height);
   _casas[19].setposicionsprite(_cuadras[5].getxorigen(), _cuadras[5].getyorigen() +5);
   _casas[19].setSpriteRotation(90.f);


    _casas[20].cargartexturaensprite("20_Textura_estacionDeServicio.png");
    _casas[20].setSpriteOrigin(0, _casas[20].getBound().height);
    _casas[20].setposicionsprite(_cuadras[13].getxorigen() + 10, _cuadras[13].getyorigen() + _cuadras[13].getBound().height);


}

sf:: Sprite Mapa::getspriteCalles(){ return _spritecalles; }

sf::FloatRect  Mapa::getBound() const{ return _spritecalles.getGlobalBounds();}

void Mapa::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_spritecalles, states);

    for(int x=0; x<14; x++){

        target.draw(_cuadras[x], states);
    }
for(int x=0; x<21; x++){

        target.draw(_casas[x], states);
    }

}

Mapa::~Mapa(){}
