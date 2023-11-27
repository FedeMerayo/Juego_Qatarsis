#ifndef ARCHIVO_H
#define ARCHIVO_H
#include<string.h>
#include<stdio.h>
#include<iostream>
#include <SFML/Graphics.hpp>

class Archivo
{
    public:
        Archivo();

        bool leer(int pos);
        bool grabar();
        bool modificar(int pos);

        void setNombre(const char *nom){strcpy(_nombreJugador, nom);}
        void setMin(int minu){_min = minu;}
        void setSeg(int seg){_seg = seg;}


        std::string getNombre(){return _nombreJugador;}
        int getMin(){return _min;}
        int getSeg(){return _seg;}

        ~Archivo();

    private:

        char  _nombreJugador[10];
        int _min;
        int  _seg;
};

#endif // ARCHIVO_H
