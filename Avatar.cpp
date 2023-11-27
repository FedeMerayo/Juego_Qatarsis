#include "Avatar.h"
#include <string>

Avatar::Avatar()
{
    _texturaAvatar.loadFromFile("Avatar.png");
    _spriteAvatar.setTexture(_texturaAvatar);

    _spriteAvatar.setOrigin(0,_spriteAvatar.getGlobalBounds().height);
    _spriteAvatar.setPosition(10, 600 - 10); //deberia acceder al tamaño de la ventana y no tener los 600 de manera literal

    _fuente1.loadFromFile("geometric_415_black_bt.ttf");
    _textoNombre.setFont(_fuente1);
    _textoCronometro.setFont(_fuente1);

    _nombreJugador ="Jugador";
    _textoNombre.setCharacterSize(15);
    _textoNombre.setColor(sf::Color::Black);
    _textoNombre.setString(_nombreJugador);
    _textoNombre.setOrigin(_textoNombre.getGlobalBounds().width, _textoNombre.getGlobalBounds().height);
    _textoNombre.setPosition(_spriteAvatar.getPosition().x + 110.f, _spriteAvatar.getPosition().y -28.f);

    _textoCronometro.setString("18:00");
    _textoCronometro.setCharacterSize(15);
    _textoCronometro.setColor(sf::Color::Black);
    _textoCronometro.setOrigin(0, _textoCronometro.getGlobalBounds().height);
    _textoCronometro.setPosition(_spriteAvatar.getPosition().x + 55.f, _spriteAvatar.getPosition().y -14.f);
}

void Avatar::update()
{
{
    if(_tiempo2.asSeconds() < 10)
    {
        _textoCronometro.setString( "17:0"+ std::to_string((int)_tiempo2.asSeconds()));
    }
    else if(_tiempo2.asSeconds() < 60)
    {
        _textoCronometro.setString( "17:"+ std::to_string((int)_tiempo2.asSeconds()));
    }
    else if(_tiempo2.asSeconds() > 60 && _tiempo2.asSeconds() < 70)
    {
       _textoCronometro.setString( "18:0"+ std::to_string((int)_tiempo2.asSeconds()));
    }
    else if(_tiempo2.asSeconds() >= 70 && _tiempo2.asSeconds() < 120)
    {
        _textoCronometro.setString( "18:"+ std::to_string((int)_tiempo2.asSeconds()));
    }
    else if(_tiempo2.asSeconds() >=120 && _tiempo2.asSeconds() < 130)
    {
       _textoCronometro.setString( "19:0"+ std::to_string((int)_tiempo2.asSeconds()));
    }
    else if(_tiempo2.asSeconds() >=130 && _tiempo2.asSeconds() < 180)
    {
        _textoCronometro.setString( "19:"+ std::to_string((int)_tiempo2.asSeconds()));
    }
    else
    {
        _textoCronometro.setString( "20:00");
    }
}
}

void Avatar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_spriteAvatar, states);
    target.draw(_textoNombre, states);
    target.draw(_textoCronometro, states);
}

void Avatar::setNombreJugador(std::string nombre)
{
    _nombreJugador = nombre;
}

std::string Avatar::getNombreJugador()
{
    return _nombreJugador;
}

void Avatar::set_tiempo(sf::Time tiempo)
{
    _tiempo2 =tiempo;
}
