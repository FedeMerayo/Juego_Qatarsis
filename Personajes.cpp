#include "Personajes.h"


Personajes::Personajes()

{
    inicializarpunteros();
    _vectordedialogos=nullptr;
    _codigodepersonaje=0;
    _hablando=false;
    _dialogoactual=0;
    _cantidaddedialogos=0;

    _fuente1.loadFromFile("geometric_415_black_bt.ttf");
    _textoCuadroTexto.setFont(_fuente1);
    _textoCuadroTexto.setCharacterSize(22);
    _textoCuadroTexto.setColor(sf::Color::Black);
    _textoCuadroTexto.setScale(1,1);
    _textoCuadroTexto.setPosition(235,300);
    _spritepersonajecuadrotexto.setPosition(25,100);

}

void Personajes::Hablar(int numerodedialogo)
{
    if(this->getcodigodepersonaje()==11){

    _textoCuadroTexto.setPosition(150,300);
    }

    _hablando=true;
    _textoCuadroTexto.setString(getdialogo(numerodedialogo));
    std::cout << getdialogo(numerodedialogo) << std::endl;
}

void Personajes::setcantidaddedialogos(int cantidad)
{
    if (_cantidaddedialogos!=0)
    {
        std::cout << "personaje ya tiene dialogos.";
    }
    _cantidaddedialogos=cantidad;

    if (_cantidaddedialogos!=0)
    {
        _vectordedialogos= new std::string [_cantidaddedialogos];
    }
    if(_vectordedialogos==nullptr)
    {
        std::cout << "no se pudo iniciar al puntero vector de dialogos";
        system("pause");
    }
}



void Personajes::setdialogo(int numerodedialogo, std::string dialogo)
{

    if (_cantidaddedialogos>0)
    {
        if (numerodedialogo>_cantidaddedialogos)
        {
            std::cout << "El personaje tiene solo "<< _cantidaddedialogos << "dialogos";
            system("pause");
        }
        else
        {
            _vectordedialogos[numerodedialogo-1]=dialogo;
        }
    }

}


std::string Personajes::getdialogo(int numerodedialogo)
{

    if (numerodedialogo>_cantidaddedialogos)
    {
            std::cout << "El personaje tiene solo "<< _cantidaddedialogos << "dialogos";
            system("pause");
    }
    else
    {
        return _vectordedialogos[numerodedialogo-1];
    }
}

bool Personajes::gethablando()
{
    return _hablando;
}
void Personajes::sethablando(bool hablando)
{
    _hablando=hablando;
}


void Personajes::inicializarpunteros() {}
void Personajes::update() {}
/// Acciones

// ADDS
void Personajes::addFigurita(Figurita *figuritajugador)
{

    _figuritas[figuritajugador->getcodigodefigurita()]=true;

}
void Personajes::addRepetida(Repetida *figuritarepetida)
{

    _figuritas[figuritarepetida->getcodigodefigurita()]=true;

}
void Personajes::addobjeto(Objeto *objeto)
{

    _objetos[objeto->getcodigoobjeto()]=true;
}
void Personajes::darobjetoapipo(Objeto *objeto, Personajes *personaje)
{

    personaje->addobjeto(objeto);
    objeto->imprimir();

}
// Dar
void Personajes::darfiguritaapipo(Figurita *figurita, Personajes *personaje)
{

    personaje->addFigurita(figurita);
    figurita->Pegar();
}
void Personajes::darfigurita(Figurita *figurita, Personajes *personaje)
{

    personaje->addFigurita(figurita);
    _figuritas[figurita->getcodigodefigurita()]=true;

}
void Personajes::darobjeto(Objeto *objeto, Personajes *personaje)
{

    personaje->addobjeto(objeto);
    _objetos[objeto->getcodigoobjeto()]=false;

}
// Solucionar
void Personajes::solucionarobjeto(Objeto *objeto)
{
    objeto->solucionado();
}
/// seteo dialogos
void Personajes::setcodigodepersonaje(int codigo)
{
    _codigodepersonaje=codigo;
}
int Personajes::getcodigodepersonaje()
{
    return _codigodepersonaje;
}
///	Sprites y draw
void Personajes::setsprite(std::string nombredearchivo)
{
    _texturapersonajecuadrotexto.loadFromFile(nombredearchivo);
    _spritepersonajecuadrotexto.setTexture(_texturapersonajecuadrotexto);

}
void Personajes::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    if(_hablando==true)
    {
        target.draw(_spritepersonajecuadrotexto,states);
        target.draw(_textoCuadroTexto,states);

    }

}
Personajes::~Personajes()
{
    delete[] _vectordedialogos;

}

