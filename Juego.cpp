#include "Juego.h"

Juego::Juego(){


    inicializarventana();
    Gameloop();
    //inicializar archivo?
}

// inicializaciones

void Juego::inicializarArchivo()
{
    Archivo _arch;
    char nom[10]="vacio";

    if(_arch.leer(0)!=1)
    {
        for(int x=0; x<3; x++)
        {
            _arch.setNombre(nom);
            _arch.setMin(0);
            _arch.setSeg(0);
            _arch.grabar();
        }
    }
}


void Juego::inicializarventana(){

    _window = new sf::RenderWindow(sf::VideoMode(900, 600), "Qatarsis!");
    _window->setFramerateLimit(15);

}

// GAMELOOP

void Juego::Gameloop(){
    while (ventanaabierta())
    {


        update();

        draw();
    }
}


// Updates

void Juego::update()
{
           _ranking.update();
    pollevents();
    chequearescape(_gameplay.getapretoescape());
  //  std::cout<<_tiempo.asSeconds() << std::endl;

    if(_menu.get_eligioSalir()==true)
    {
        exit(1);
    }
    else if(_menu.get_eligioJuego()==true || _gameplay.get_estaActivo()==true)
    {
        if(_menu.get_eligioJuego()==true)
        {
            _window->setFramerateLimit(40);
            _menu.set_eligioJuego(false);
            _menu.set_estaActivo(false);
            _gameplay.set_estaActivo(true);
        }
        _gameplay.update();
    }
    else if(_menu.get_eligioRanking()==true || _ranking.get_estaActivo()==true)
    {
        if(_menu.get_eligioRanking()==true)
        {
            _window->setFramerateLimit(15);
            _menu.set_eligioRanking(false);
            _menu.set_estaActivo(false);
            _ranking.set_estaActivo(true);
        }

    }
    else if(_menu.get_estaActivo()==true || (_gameplay.get_estaActivo()==false && _ranking.get_estaActivo()==false))
    {
        _window->setFramerateLimit(15);
        if(_gameplay.get_estaActivo()==false && _ranking.get_estaActivo()==false)
        {
            _menu.set_estaActivo(true);
        }
        _menu.update();
    }
}

void Juego::chequearescape(bool saliodegameplay){

   if (saliodegameplay==true){

    _gameplay.set_estaActivo(false);
    _menu.set_estaActivo(true);
    _gameplay.resetarescape();
   }

   }


// Accesores

const bool Juego::ventanaabierta()const {
    return this->_window->isOpen();
}


// Funciones

void Juego:: pollevents(){
    while (_window->pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            _window->close();
    }
}

//Draw

void Juego::draw()
{
    _window->clear(); /// borrar frame anterior

    if(_menu.get_estaActivo()==true)
    {
        _window->draw(_menu);
    }
    else if(_gameplay.get_estaActivo()==true)
    {
        _window->draw(_gameplay);
    }
    else if(_ranking.get_estaActivo()==true)
    {
        _window->draw(_ranking);
    }
    else if(_menu.get_eligioSalir()==true)
    {
        _window->close();
    }
    _window->display(); /// display el frame
}

Juego::~Juego(){

delete _window;
}
