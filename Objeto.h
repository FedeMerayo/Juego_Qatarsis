#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Objeto : public sf::Drawable
{

    private:

       //  Sprites
    sf::Sprite _spriteobjeto[2];
    sf::Texture _texturaobjeto[2];


    //  Propiedades
    bool _solucionado=false;
    bool _enpantalla=false;
    int _codigodeobjeto;

    public:

    Objeto();
 //  Funciones
    void imprimir();
    bool getenpantalla() {return _enpantalla;}
    bool getestado(){return _solucionado;}
    int getcodigoobjeto();
    void resetarsolucionado(){_solucionado=false;}
    void setenpantalla(bool enpantalla){_enpantalla=enpantalla;}
    void setcodigoobjeto(int codigo);
    void solucionado();

    //  Sprites y draw
      void setposicionsprite(int numerodesprite,float x, float y);
    void setsprite(int numerodesprite, std::string nombredearchivo);
      sf::FloatRect getBound() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual ~Objeto();

};

#endif // OBJETO_H
