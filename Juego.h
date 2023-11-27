#ifndef JUEGO_H
#define JUEGO_H
#include "Menu.h"
#include "Ranking.h"
#include "Gameplay.h"
#include "Archivo.h"
#include<iostream>

class Juego
{

private:

    //Ventana
    sf::RenderWindow *_window;

    // Eventos
    sf::Event _event;

    //Clases/variables
    Gameplay _gameplay;
    Menu _menu;
    Ranking _ranking;
    Archivo _archivoRanking;

    void inicializarventana();
    void inicializarArchivo();

    //Rel
    sf::Clock _reloj;
    sf::Time _tiempo;

public:
    Juego();

    //ACCESORES
    const bool ventanaabierta() const;
    sf::RenderWindow *getwindow(){return _window;}
    void chequearescape(bool saliodegameplay);

    ///FUNCIONES
    void Gameloop();
    void update ();
    void draw ();
    void pollevents();

    ~Juego();
};

#endif // JUEGO_H
