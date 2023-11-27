#ifndef REPETIDA_H
#define REPETIDA_H
#include "Figurita.h"

class Repetida : public Figurita
{
    public:
        Repetida();
        virtual ~Repetida();
    void setactiva(bool estado){
    activa=estado;
    }

    protected:

    private:
        bool activa=false;
};

#endif // REPETIDA_H
