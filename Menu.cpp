#include "Menu.h"

Menu::Menu()
{
    _estaActivo = true;
    _eligioRanking = false;
    _eligioJuego = false;
    _eligioSalir = false;

    //cargo textura y sprite fondo MENU
    _texturaFondoMenu.loadFromFile("fondoMenu.png");
    _spriteFondoMenu.setTexture(_texturaFondoMenu);

    //cargo textura y sprite dibujo Central
    _texturaFiguraCentral.loadFromFile("figuraCentralMenu.png");
    _spriteFiguraCentral.setTexture(_texturaFiguraCentral);
    //posiciono el dibujo central
    _spriteFiguraCentral.setOrigin(_spriteFiguraCentral.getGlobalBounds().width / 2, _spriteFiguraCentral.getGlobalBounds().height);
    _spriteFiguraCentral.setPosition(_spriteFondoMenu.getGlobalBounds().width / 2, _spriteFondoMenu.getGlobalBounds().height);

    _cantOpcionesMenu = 3;
    _spriteCuadroTexto = new sf::Sprite[_cantOpcionesMenu];
    _textoCuadroTexto = new sf:: Text [_cantOpcionesMenu]; //el que se imprime
    _textoCuadro = new std:: string [_cantOpcionesMenu]; //se lo asigno a textoCuadroTexto

    //cargo textura de cuadros de texto
    _texturaCuadroTexto.loadFromFile("cuadroTextoMenu.png");

    //cargo fuente y leyendas de cuadros de texto, desde abajo hacia arriba, por si quiero agregar mas
    _fuente1.loadFromFile("geometric_415_black_bt.ttf");
    _textoCuadro[2] = "JUGAR";
    _textoCuadro[1] = "RANKING";
    _textoCuadro[0] = "SALIR";

    _opMenu = _cantOpcionesMenu-1;

    //cargo sprite de los cuadros de texto, seteo los cuadros de texto y los posiciono segun el primer cuadro posicionado de abajo hacia arriba
    for(int x=0; x<_cantOpcionesMenu; x++)
    {
        _spriteCuadroTexto[x].setTexture(_texturaCuadroTexto);
        _textoCuadroTexto[x].setFont(_fuente1);
        _textoCuadroTexto[x].setString(_textoCuadro[x]);

        _spriteCuadroTexto[x].setOrigin(_spriteCuadroTexto[x].getLocalBounds().width / 2, _spriteCuadroTexto[x].getLocalBounds().height/ 2);

        if(x==0)
        {
            _spriteCuadroTexto[x].setPosition(_spriteFondoMenu.getGlobalBounds().width/2, _spriteFondoMenu.getGlobalBounds().height - 30);
            _textoCuadroTexto[x].setCharacterSize(20);
            _textoCuadroTexto[x].setColor(sf::Color::Red);
        }
        else if(x == _cantOpcionesMenu-1)
        {
            _spriteCuadroTexto[x].setPosition(_spriteCuadroTexto[x-1].getPosition().x, (_spriteCuadroTexto[x-1].getPosition().y - (_spriteCuadroTexto[x-1].getGlobalBounds().height /2) - 20));
            _textoCuadroTexto[x].setCharacterSize(20);
            _textoCuadroTexto[x].setColor(sf::Color::White);
            _spriteCuadroTexto[x].setColor(sf::Color::Black);
        }
        else
        {
            _spriteCuadroTexto[x].setPosition(_spriteCuadroTexto[x-1].getPosition().x, (_spriteCuadroTexto[x-1].getPosition().y - (_spriteCuadroTexto[x-1].getGlobalBounds().height /2) - 20));
            _textoCuadroTexto[x].setCharacterSize(20);
            _textoCuadroTexto[x].setColor(sf::Color::Red);
        }

        _textoCuadroTexto[x].setOrigin(_textoCuadroTexto[x].getGlobalBounds().width /2, 0);
        //centro el texto en el cuadro de texto
        _textoCuadroTexto[x].setPosition(_spriteCuadroTexto[x].getPosition().x, _spriteCuadroTexto[x].getPosition().y - _spriteCuadroTexto[x].getGlobalBounds().height /2);
    }
}

void Menu::update()
{

    procesarTecladoFlecha();
    actualizarMenu();
    procesarTecladoEleccion();
}

void Menu::procesarTecladoFlecha()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {


        if(_opMenu!=0)
        {
         _opMenu--;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {


        if(_opMenu!=2)
        {
        _opMenu++;
        }
    }
}

void Menu::actualizarMenu()
{
    for(int x=0; x<_cantOpcionesMenu; x++)
    {
        if(x ==_opMenu) // es la opcion que se pone en negro
        {
            _textoCuadroTexto[x].setColor(sf::Color::White);
            _spriteCuadroTexto[x].setColor(sf::Color::Black);
        }
        else
        {
            _textoCuadroTexto[x].setColor(sf::Color::Red);
            _spriteCuadroTexto[x].setColor(sf::Color::White);
        }
    }
}

void Menu::procesarTecladoEleccion()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch(_opMenu)
        {
        case 0:
            std::cout<<"eligio salir" << std::endl;
            _eligioSalir = true;
            break;
        case 1:
            std::cout<<"eligio ranking" << std::endl;
            _eligioRanking = true;
            break;
        case 2:
            std::cout<<"eligio juego" << std::endl;
            _eligioJuego = true;
            break;
        }
    }
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_spriteFondoMenu, states);
    target.draw(_spriteFiguraCentral, states);

    for(int x=0; x< _cantOpcionesMenu; x++)
    {
        target.draw(_spriteCuadroTexto[x], states);
        target.draw(_textoCuadroTexto[x], states);
    }
}

Menu::~Menu()
{
    delete[] _spriteCuadroTexto;
    delete[] _textoCuadroTexto;
    delete[] _textoCuadro;
}
