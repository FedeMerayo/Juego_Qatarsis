#ifndef FIGURITA_H
#define FIGURITA_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Figurita : public sf::Drawable
{

    protected:
    //  Sprites
    sf::Sprite _spritefigurita;
    sf::Texture _texturafigurita;

    //  Propiedades
    int _codigodefigurita;
    bool pegada=false;

    public:
    Figurita();
    //  Funciones
    void Pegar();
    bool getestado();

    void setcodigodefigurita(int codigo);
    int getcodigodefigurita();
    void setestadro(bool estado){pegada=estado;};
    //  Sprites y draw
    void setposicionsprite(float x, float y);
    void setsprite(std::string nombredearchivo);
    sf::Sprite getSprite();
    sf::FloatRect getBound() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual ~Figurita();

};

#endif // FIGURITA_H
