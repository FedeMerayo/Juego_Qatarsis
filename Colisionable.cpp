#include "Colisionable.h"

bool Colisionable::iscolision (Colisionable &obj) const
{
    return getBound().intersects(obj.getBound());
}
