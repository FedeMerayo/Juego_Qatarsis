#ifndef AVATAR_H
#define AVATAR_H
#include <SFML/Graphics.hpp>

class Avatar : public sf::Drawable
{
    public:
        Avatar();
        void setNombreJugador(std::string nombre);
        std::string getNombreJugador();

        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Sprite getSprite();
        void set_tiempo(sf::Time tiempo);

    private:
         sf::Sprite _spriteAvatar;
        sf::Texture _texturaAvatar;
        std:: string _nombreJugador;

        sf::Font _fuente1;
        sf::Text _textoCronometro;
        sf::Text _textoNombre;

        sf::Time  _tiempo2; // deberiamos hacerlo float
};

#endif // AVATAR_H
