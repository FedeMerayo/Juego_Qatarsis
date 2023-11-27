#ifndef PANELDECONTROL_H
#define PANELDECONTROL_H
#include <SFML/Graphics.hpp>
#include "Figurita.h"
#include "Repetida.h"
#include "Objeto.h"
#include "Avatar.h"



class Paneldecontrol : public sf::Drawable
{

    private:


    sf::Text  _textoCuadroTexto;
    sf::Font _fuente1;

    sf::Sprite _spritecasitas;
    sf::Texture _texturacasitas[8];
    Figurita *_figuritas[6];
    Repetida *_repetidas[3];
    Objeto *_objetos[3];
    std::string _objetivos[9];
    sf::Sprite _spritepanellateral;
    sf::Texture _texturapanellateral;
    sf::Sprite _spritecuadrotextoinferior;
    sf::Texture _texturacuadrotextoinferior;
    sf::Sprite _spritevictoria;
    sf::Texture _texturavictoria;
    sf::Sprite _spritederrota;
    sf::Texture _texturaderrota;

    bool objetivosactivos=false;
    bool gano=false;
    bool perdio=false;
    public:
    void setfuente(sf::Font fuente);
    void setgano(bool resultado){ gano=resultado;}
    void setperdio(bool resultado){ perdio=resultado;}
        void activarobjetivos(){objetivosactivos=true;};
        void desactivarobjetivos(){objetivosactivos=false;};
        bool getobjetivosactivos (){return objetivosactivos;};
void Cargarcasitas();
    void cargarobjetos(Figurita *Vectorfiguritas,const int cantidadfigus, Objeto *Vectorobjetos, const int cantidadobjetos, Repetida *vectorrepetidas, const int cantidadrepetidas);
    Paneldecontrol();
    void cargarstrings();
    void imprimirobjetivos(int numerodeobjetivo);
    void update();
    sf::FloatRect getBound() const;
    int getcodigocasabicicletero(){return 3;};
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual ~Paneldecontrol();



};

#endif // PANELDECONTROL_H
