#include "Ranking.h"
#include"Archivo.h"

Ranking::Ranking(){
    _estaActivo = false;
    pos =0;

    //cargo textura y sprite fondo RANKING
    _texturaFondoRanking.loadFromFile("fondoMenu.png");
    _spriteFondoRanking.setTexture(_texturaFondoRanking);

    //cargo textura y sprite dibujo Ranking
    _texturaFiguraCentral.loadFromFile("figuraCentralRanking.png");
    _spriteFiguraCentral.setTexture(_texturaFiguraCentral);
    //posiciono el dibujo central
    _spriteFiguraCentral.setOrigin(_spriteFiguraCentral.getGlobalBounds().width / 2, _spriteFiguraCentral.getGlobalBounds().height);
    _spriteFiguraCentral.setPosition(_spriteFondoRanking.getGlobalBounds().width / 2, 200);

    _cantRankingMostrar = 3;

    _spriteCuadroRanking = new sf::Sprite[_cantRankingMostrar];
    _textoCuadroTexto = new sf:: Text [_cantRankingMostrar];
    _textoCuadro = new std:: string [_cantRankingMostrar];

    //cargo textura de cuadros de texto
    _texturaCuadroRanking.loadFromFile("CuadroTextoRanking.png");

    //cargo fuente y leyendas de cuadros de texto, desde abajo hacia arriba, por si quiero agregar mas
    _fuente1.loadFromFile("geometric_415_black_bt.ttf");
    //MODIFICAR - traer de archivo y asignar



    _textoCuadro[0] = "JUGADOR - 00seg";
    _textoCuadro[2] = "JUGADOR - 00seg";
    _textoCuadro[1] = "JUGADOR - 00seg";

    //cargo sprite de los cuadros de texto, seteo los cuadros de texto y los posiciono segun el primer cuadro posicionado de ARRIBA hacia ABAJO
    for(int x=0; x<_cantRankingMostrar; x++)
    {
        _spriteCuadroRanking[x].setTexture(_texturaCuadroRanking);
        _textoCuadroTexto[x].setFont(_fuente1);
        _textoCuadroTexto[x].setString(_textoCuadro[x]);

        if(x==0)
        {
            _spriteCuadroRanking[x].setOrigin(_spriteCuadroRanking[x].getGlobalBounds().width /2, _spriteCuadroRanking[x].getGlobalBounds().height/2);
            _spriteCuadroRanking[x].setPosition(_spriteFiguraCentral.getPosition().x, _spriteFiguraCentral.getPosition().y + 100);
            _textoCuadroTexto[x].setCharacterSize(20);
            _textoCuadroTexto[x].setColor(sf::Color::Red);
        }
        else
        {
            _spriteCuadroRanking[x].setOrigin(_spriteCuadroRanking[x].getGlobalBounds().width /2, _spriteCuadroRanking[x].getGlobalBounds().height/2);
            _spriteCuadroRanking[x].setPosition(_spriteCuadroRanking[x-1].getPosition().x, _spriteCuadroRanking[x-1].getPosition().y + 75);
            _textoCuadroTexto[x].setCharacterSize(20);
            _textoCuadroTexto[x].setColor(sf::Color::Red);
        }
        _textoCuadroTexto[x].setOrigin(_textoCuadroTexto[x].getLocalBounds().width /2, 0);
        //centro el texto en el cuadro de texto
        _textoCuadroTexto[x].setPosition(_spriteCuadroRanking[x].getPosition().x, _spriteCuadroRanking[x].getPosition().y - (_spriteCuadroRanking[x].getLocalBounds().height/2));
    }

    _stringTextoInferior = "Apriete ENTER para volver al menú";
    _textoInferior.setFont(_fuente1);
    _textoInferior.setString(_stringTextoInferior);
    _textoInferior.setCharacterSize(25);
    _textoInferior.setColor(sf::Color::Red);
    _textoInferior.setOrigin(_textoInferior.getLocalBounds().width /2, 0);
    _textoInferior.setPosition(_spriteFondoRanking.getGlobalBounds().width /2 , _spriteFondoRanking.getGlobalBounds().height - 75);
}

void Ranking::update(){
    Archivo _archivo;
       int posArch=0;

    while(_archivo.leer(posArch)==1)
    {
        _textoCuadro[posArch] = _archivo.getNombre() + " - " + std::to_string(_archivo.getMin()) + "Min " +  std::to_string(_archivo.getSeg()) + "Seg";
        _textoCuadroTexto[posArch].setString(_textoCuadro[posArch]);
        posArch++;
}
}

void Ranking::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_spriteFondoRanking, states);
    target.draw(_spriteFiguraCentral, states);

    for(int x=0; x< _cantRankingMostrar; x++)
    {
        target.draw(_spriteCuadroRanking[x], states);
        target.draw(_textoCuadroTexto[x], states);
    }

    if(pos%10==0)
    {
        target.draw(_textoInferior);
    }
}

void Ranking::procesarTeclado() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        _estaActivo = false;
    }
}

std::string Ranking::toString(){


}

Ranking::~Ranking(){
    delete[] _spriteCuadroRanking;
    delete[] _textoCuadroTexto;
    delete[] _textoCuadro;
}
