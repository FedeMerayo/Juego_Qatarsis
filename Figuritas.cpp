#include "Figuritas.h"

Figuritas::Figuritas()
{

}

void Figuritas::Pegada()
{
    pegada=true;
}

void Figuritas::setcodigodefigurita(int codigo)
{
    _codigodefigurita=codigo;
}

int Figuritas::getcodigodefigurita()
{
    return _codigodefigurita;
}

Figuritas::~Figuritas()
{
    //dtor
}
