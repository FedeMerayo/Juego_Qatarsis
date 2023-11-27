#ifndef PERSONAJES_H
#define PERSONAJES_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Figurita.h"
#include "Objeto.h"
#include "Repetida.h"
#include "RLUTIL.h"

class Personajes : public sf::Drawable
{


protected:

    //	Sprites
    sf::Sprite _spritepersonajecuadrotexto;
    sf::Texture _texturapersonajecuadrotexto;
    std::string *_vectordedialogos;

    sf::Text  _textoCuadroTexto;
    std:: string  _textoCuadro;
     sf::Font _fuente1;
    int _codigodepersonaje;
    int _cantidaddedialogos;
    bool _objetos[3];
    bool _figuritas[6];
    bool _repetidas[3];
    bool _hablando;
    bool _dibujar;
    int _dialogoactual;
public:

    Personajes();
   std::string getdialogo(int numerodedialogo);
   // Funciones
    int getcodigodepersonaje();
    int getcantidaddedialogos(){return _cantidaddedialogos;};
    bool gethablando();
    void setcodigodepersonaje(int codigo);
    void inicializarpunteros();
    void update();
    void setcantidaddedialogos(int _cantidaddedialogos);
    void setdialogo(int numerodedialogo, std::string dialogo);
    // Acciones
    void Hablar(int numerodedialogo);
    void sethablando(bool hablando);
    void addFigurita(Figurita *jugador);
    void addRepetida(Repetida *repetida);
    void addobjeto(Objeto *objeto);
    bool hablando();
//void findialogo();
    void darfigurita(Figurita *figurita, Personajes *personaje);
    void darfiguritaapipo(Figurita *figurita, Personajes *personaje);
    void darobjeto(Objeto *objeto, Personajes *personaje);
    void darobjetoapipo(Objeto *objeto, Personajes *personaje);

    void solucionarobjeto(Objeto *objeto);

    //	Sprites y draw
    void setsprite(std::string nombredearchivo);
    sf::FloatRect getBound() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual ~Personajes();
};


#endif // PERSONAJES_H
