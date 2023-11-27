#include "Archivo.h"

Archivo::Archivo()
{

}

bool Archivo::leer(int pos)
{
    FILE *p;
    p=fopen("rankingJUEGO.dat", "rb");
    if(p==NULL) return false;
    fseek(p, sizeof *this*pos,0);
    int leyo=fread(this, sizeof *this,1, p);
    fclose(p);
    return leyo;
}

bool Archivo::grabar()
{
    FILE *p;
    p=fopen("rankingJUEGO.dat", "ab");
    if(p==NULL) return -1;
    int grabo=fwrite(this, sizeof *this,1, p);
    fclose(p);
    return grabo;
}

bool Archivo::modificar(int pos)
{
    FILE *p;
    p=fopen("rankingJUEGO.dat", "rb+");
    if(p==NULL) return false;
    fseek(p,sizeof(this)*pos,0);
    bool grabo=fwrite(this, sizeof (Archivo), 1, p);
    fclose(p);
    return grabo;
}

/*bool Archivo::modificar(std::string nombre, sf::Time tiempo, int pos)
{
    FILE *p;
    p=fopen("rankingJUEGO.dat", "rb+");
    if(p==NULL) return false;
    fseek(p,sizeof(this)*pos,0);
    bool grabo=fwrite(&arch, sizeof arch, 1, p);
    fclose(p);
    return grabo;
}*/

Archivo::~Archivo()
{

}
