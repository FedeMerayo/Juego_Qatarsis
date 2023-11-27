#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Paneldecontrol.h"
#include "Protagonista.h"
#include "Mapa.h"
#include "Personajes.h"
#include "Cuadras.h"
#include "Casas.h"
#include "Objeto.h"
#include "Figurita.h"
#include "Repetida.h"
#include "Avatar.h"
#include "Archivo.h"
#include "Ranking.h"
#include <SFML/Graphics.hpp>
#include  <iostream>
#include <ctime>
#include <math.h>


using namespace std;

class Gameplay : public sf::Drawable
{
private:

    // Sprites y fuentes
    sf::Sprite _spritefondo;
    sf::Texture _texturafondo;
    sf::Sprite _spriteRio;
    sf::Texture _texturaRio;
    sf::Font _fuente1;
    sf::Sprite _spriteCuadroExterno;
    sf::Texture _texturaCuadroExterno;
    sf:: Sprite _spriteCuadroNombre;
    sf::Texture _texturaCuadroNombre;
    char  _nombreJugador[10];
    sf::Text  _textoEscribirNombre;
    std:: string _stringTextoEscribirNombre;
    sf::Text  _textoNombre;
    std:: string _stringTextoNombre;
    sf::Font _fuente2;
    sf::Event _evento2;



    // Clases/Variables
    Mapa _mapa;
    Avatar _avatar;
    Paneldecontrol _paneldecontrol;



    // Accesores
    int numerodedialogomama, numdialogoPipo,numerodialogoariel,numerodialogovecino1,numerodialogobici,numerodialogovecino2,numerodialogoexjugador;
    int Objetivos=0;
    bool _pausa;
    bool _estaActivo;
    bool _comienzaJuego;
    bool _apretoescape;


    // Reloj
    sf::Clock _reloj1;
    sf::Time _tiempo1;
    sf::Time _tiempoGanador;

    //Personajes/Objetos

    Protagonista _pipo;
    Personajes _personajes[12];
    Figurita _figuritas[6];
    Repetida _repetidas[3];
    Objeto _objetos[3];

    // Alias
    Protagonista *Pipo=&_pipo;
    Objeto *Pelota=_objetos;
    Objeto *Camiseta=&_objetos[1];
    Objeto *Autografo=&_objetos[2];
    Figurita *Figuritamessi=_figuritas;
    Figurita *Figuritaalvarez=&_figuritas[1];
    Figurita *Figuritadepaul=&_figuritas[2];
    Figurita *Figuritadimaria=&_figuritas[3];
    Figurita *Figuritadibu=&_figuritas[4];
    Figurita *Figuritalautaro=&_figuritas[5];
    Repetida *Repetidacristiano=_repetidas;
    Repetida *Repetidasuarez=&_repetidas[1];
    Repetida *Repetidaneymar=&_repetidas[2];
    Personajes *Mamadepipo=_personajes;
    Personajes *Kioskera=&_personajes[1];
    Personajes *Amigoariel=&_personajes[2];
    Personajes *Vecinofavor1=&_personajes[3];
    Personajes *Bicicletero=&_personajes[4];
    Personajes *Vecinofavor2=&_personajes[5];
    Personajes *Vecinoexjugador=&_personajes[6];
    Personajes *Lavadero=&_personajes[7];
    Personajes *Personajesinfigus1=&_personajes[8];
    Personajes *Personajesinfigus2=&_personajes[9];
    Personajes *Personajesinfigus3=&_personajes[10];
    Personajes *Pipohablando=&_personajes[11];



public:

    Gameplay();

    /// Funciones
    // bool Pausar(){_pausa=true;}
    // bool Continuar(){_pausa=false;}
    // bool getpausa(){return _pausa;}

    // inicializadores
    void inicializarobjetos();
    void repartirobjetos();
    void inicializarfiguritas();
    void inicializarpersonajes();

    // Update
    void update();
    void resetarescape();
    void Chequearimpresiones();
    void Desarrollo();
    void colisionesdemapa();
    void limitesdelmapa();
    bool getapretoescape();
    void setapretoescape();
    void grabarRanking();

    // Sprites y Draw
    sf::FloatRect getBound() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // Accesores
    void set_estaActivo(bool op){_estaActivo = op;}
    bool get_estaActivo(){return _estaActivo;}

    virtual ~Gameplay();
};
#endif // GAMEPLAY_H
