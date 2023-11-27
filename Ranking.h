#ifndef RANKING_H
#define RANKING_H
#include<iostream>
#include <SFML/Graphics.hpp>

class Ranking : public sf::Drawable
{
private:
    int pos;
    bool _estaActivo;
    int _cantRankingMostrar;
    sf::Sprite _spriteFondoRanking;
    sf::Texture _texturaFondoRanking;

    sf::Sprite _spriteFiguraCentral;
    sf::Texture _texturaFiguraCentral;

    sf::Sprite * _spriteCuadroRanking;
    sf::Texture _texturaCuadroRanking;
    sf::Text * _textoCuadroTexto;
    std:: string * _textoCuadro;
    sf::Text  _textoInferior;
    std:: string _stringTextoInferior;

    sf::Clock _reloj;
    sf::Time _tiempo;

    sf::Font _fuente1;

    sf::Event _evento1;

public:
    Ranking();
    void set_estaActivo(bool op) {_estaActivo = op;}
    bool get_estaActivo(){return _estaActivo;}
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void procesarTeclado();
    std::string toString();
    ~Ranking();

};

#endif // RANKING_H
