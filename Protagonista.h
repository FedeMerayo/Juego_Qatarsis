#ifndef PROTAGONISTA_H
#define PROTAGONISTA_H
#include <SFML/Graphics.hpp>
#include "Personajes.h"
#include "Objeto.h"
#include "Figurita.h"
#include "Repetida.h"
#include "Colisionable.h"

class Protagonista : public Personajes, public Colisionable
{
private:

    sf:: Vector2f _velocidad;
    sf:: Vector2f _posicionanterior;
    sf::Sprite _spriteprotagonista;
    sf::Texture _texturaprotagonista;
    sf:: Vector2i _divSpriteProta;
    //sf:: Vector2f _frameSize;
    sf:: Vector2i _dimTextureRect;
    sf:: Vector2i _frameActual;
    sf:: Vector2i _frameAnterior;
    int _banderaFrame;
    bool _congelado;
public:
    void Pipodaobjeto(Objeto *objeto, Personajes *personaje);
    void Pipodafigurita(Figurita *figurita, Personajes *personaje);
    Protagonista();
    void update();
    float getxorigen(), getyorigen(), getalto(), getancho();
    void setposicionanterior(sf::Vector2f posicionanterior);
    sf:: Vector2f getposicionanterior();
    void setposicion(sf::Vector2f nuevaposicion);
    void Congelar();
    bool getcongelado();
void Descongelar();
    /// Sprites y Draw
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::FloatRect getBound() const;
    sf::Sprite getSprite() {  return _spriteprotagonista; }
    //void _setFrame(sf::Sprite, sf::Vector2i numero_frame);
    sf::Vector2i getFrameActual();
    void setFrameAnterior(sf::Vector2i frameAnterior);
    void setTextureRect(int x, int y);
    virtual ~Protagonista();
};

#endif // PROTAGONISTA_H
