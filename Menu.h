#ifndef MENU_H
#define MENU_H
#include"iostream"
#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable
{
      private:
        //int _opciones=1;
     bool _estaActivo;
    bool _eligioRanking;
    bool _eligioJuego;
    bool _eligioSalir;
    int _cantOpcionesMenu;
    sf::Sprite _spriteFondoMenu;
    sf::Texture _texturaFondoMenu;

    sf::Sprite _spriteFiguraCentral;
    sf::Texture _texturaFiguraCentral;

    sf::Sprite * _spriteCuadroTexto;
    sf::Texture _texturaCuadroTexto;
    sf::Text * _textoCuadroTexto;
    std:: string * _textoCuadro;

    int _opMenu;

    sf::Font _fuente1;

    sf::Event _evento1;

    sf::Vector2i pos_mouse;

    public:
        Menu();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void procesarTecladoFlecha();
    void actualizarMenu();
    void procesarTecladoEleccion();

    void set_estaActivo(bool op){_estaActivo = op;}
    bool get_estaActivo(){return _estaActivo;}
    void set_eligioJuego(bool op){_eligioJuego = op;}
    bool get_eligioJuego(){return _eligioJuego;}
    void set_eligioRanking(bool op){_eligioRanking = op;}
    bool get_eligioRanking(){return _eligioRanking;}
    void set_eligioSalir(bool op){_eligioSalir = op;}
    bool get_eligioSalir(){return _eligioSalir;}


        //bool gameplayactivo();
        virtual ~Menu();




};

#endif // MENU_H
