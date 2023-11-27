#include "Gameplay.h"


Gameplay::Gameplay() {

    // Accesores
    _estaActivo = false;
    _comienzaJuego = true;
    _apretoescape=false;

    // Inicializaciones

    _paneldecontrol.cargarobjetos(_figuritas,6,_objetos,3,_repetidas,3);
    inicializarpersonajes();
    inicializarfiguritas();
    inicializarobjetos();
    repartirobjetos();
    numerodedialogomama=1;
    numdialogoPipo=1;
    numerodialogoariel=1;
    numerodialogovecino1=1;
    numerodialogovecino2=1;
    numerodialogobici=1;
    numerodialogoexjugador=1;

    strcpy(_nombreJugador,"pepe");

    //Cargando sprites y fuentes
    _texturafondo.loadFromFile("Pasto.png");
    _spritefondo.setTexture(_texturafondo);
    _texturaRio.loadFromFile("Rio.png");
    _spriteRio.setTexture(_texturaRio);
    _spriteRio.setPosition(0,380);
    _fuente1.loadFromFile("geometric_415_black_bt.ttf");
   _texturaCuadroExterno.loadFromFile("CuadroTextoNombre.png");
    _spriteCuadroExterno.setTexture(_texturaCuadroExterno);
    _spriteCuadroExterno.setOrigin(_spriteCuadroExterno.getGlobalBounds().width/2 , _spriteCuadroExterno.getGlobalBounds().height/2);
    _spriteCuadroExterno.setPosition(_spritefondo.getGlobalBounds().width/2 , _spritefondo.getGlobalBounds().height/2);
    _texturaCuadroNombre.loadFromFile("CuadroTextoRanking.png");
    _spriteCuadroNombre.setTexture(_texturaCuadroNombre);
    _spriteCuadroNombre.setOrigin(_spriteCuadroNombre.getGlobalBounds().width/2 , _spriteCuadroNombre.getGlobalBounds().height/2);
    _spriteCuadroNombre.setPosition(_spritefondo.getGlobalBounds().width /2, 300);
    _stringTextoEscribirNombre = "INGRESE NOMBRE DEL JUGADOR";
    _textoEscribirNombre.setString(_stringTextoEscribirNombre);
    _textoEscribirNombre.setFont(_fuente1);
    _textoEscribirNombre.setCharacterSize(20);
    _textoEscribirNombre.setFillColor(sf::Color::Red);
    //_textoEscribirNombre.setOrigin(_textoEscribirNombre.getLocalBounds().width /2, _textoEscribirNombre.getLocalBounds().height /2);
    _textoEscribirNombre.setPosition(_spriteCuadroExterno.getOrigin().x, 200);
    _textoNombre.setString(_stringTextoNombre);


}


void Gameplay::inicializarobjetos(){




    _objetos[0].setcodigoobjeto(0);
    _objetos[0].setsprite(0,"pelotadesinflada.png");
    _objetos[0].setposicionsprite(0,600,390);
    _objetos[0].setsprite(1,"pelotainflada.png");
    _objetos[0].setposicionsprite(1,600,390);

    _objetos[1].setcodigoobjeto(1);
    _objetos[1].setsprite(0,"camisetaargentinasucia.png");
    _objetos[1].setposicionsprite(0,700,390);
    _objetos[1].setsprite(1,"camisetaargentinalimpia.png");
    _objetos[1].setposicionsprite(1,700,390);

    _objetos[2].setcodigoobjeto(2);
    _objetos[2].setsprite(0,"autografosinfirmar.png");
    _objetos[2].setposicionsprite(0,800,385);
    _objetos[2].setsprite(1,"autografofirmado.png");
    _objetos[2].setposicionsprite(1,800,385);




}
void Gameplay::repartirobjetos(){


    Kioskera->addFigurita(Figuritadibu);
    Kioskera->addFigurita(Figuritaalvarez);
    Kioskera->addRepetida(Repetidacristiano);
    Kioskera->addRepetida(Repetidasuarez);
    Kioskera->addRepetida(Repetidaneymar);

    Amigoariel->addFigurita(Figuritadepaul);

    Vecinofavor1->addobjeto(Pelota);
    Vecinofavor1->addFigurita(Figuritalautaro);


    Vecinofavor2->addobjeto(Autografo);
    Vecinofavor2->addFigurita(Figuritadimaria);

    Vecinoexjugador->addobjeto(Camiseta);
    Vecinoexjugador->addFigurita(Figuritamessi);


}

void Gameplay::inicializarpersonajes(){

    Pipohablando->setcodigodepersonaje(11);
    Pipohablando->setcantidaddedialogos(11);
    Pipohablando->setsprite("Personajes_Pipo.png");
    Pipohablando->setdialogo(1,"Ma,puedo ir a comprar un paquete de figus?");//Objetivo 0
    Pipohablando->setdialogo(2,"Vamos! me voy a lo de Ari a ver si tiene una repetida");/// Objetivo 1
    Pipohablando->setdialogo(3,"Se me hace tarde, pero ya casi lleno el album, voy a ir!"); // Objetivo2
    Pipohablando->setdialogo(4,"Si, claro!");// Objetivo 3
    Pipohablando->setdialogo(5,"Solo me faltan 2! me voy corriendo!");// // respuesta a bicicletero
    Pipohablando->setdialogo(6,"Uh el Rifle esta medio loco, pero tengo que intentarlo"); // respuesta a vecinofavor2
    Pipohablando->setdialogo(7,"Hola señor, vengo a pedirle un autografo");
    Pipohablando->setdialogo(8,"si usted me lo da, me dan la figurita de Dimaria");// respuesta a dialogo 1 exjugador
    Pipohablando->setdialogo(9,"Esa, la de Messi, y nada mas");//respuesta a dialogo2 exjugador
    Pipohablando->setdialogo(10, "Es muy tarde! pero no puedo abandonar ahora");// respuesta a dialogo 4 de exjugador
    Pipohablando->setdialogo(11,"Vamos! Lo complete! me tengo que ir rapido para casa!");


    Mamadepipo->setcodigodepersonaje(0);
    Mamadepipo->setsprite("Personajes_mamadepipo.png");
    Mamadepipo->setcantidaddedialogos(1);
    Mamadepipo->setdialogo(1,"Bueno hijo, volve antes de las 20 que salen los figuzombis");


    Kioskera->setcodigodepersonaje(1);
    Kioskera->setsprite("Personajes_Kioskera.png");
    Kioskera->setcantidaddedialogos(1);
    Kioskera->setdialogo(1,"Toma pipo! el ultimo que me queda, suerte!");

    Amigoariel->setcodigodepersonaje(2);
    Amigoariel->setsprite("Personajes_Amigoariel.png");
    Amigoariel->setcantidaddedialogos(3);
    Amigoariel->setdialogo(1,"Hola Pipo, te cambio la de Cristiano por la de Depaul");
//Cambian figus
    Amigoariel->setdialogo(2,"Mi tio tiene varias de la seleccion repetidas");
    Amigoariel->setdialogo(3,"Anda a ver si le sirve alguna de tus repetidas");

    Vecinofavor1->setcodigodepersonaje(3);
    Vecinofavor1->setsprite("Personajes_Vecinofavor1.png");
    Vecinofavor1->setcantidaddedialogos(4);
    Vecinofavor1->setdialogo(1,"Hola Pipo, de las que te faltan tengo la de Lautaro");
    Vecinofavor1->setdialogo(2,"Pero ya tengo todas las repetidas que tenes");
    Vecinofavor1->setdialogo(3,"Si me llevas esta pelota a inflar al bicicletero te la doy");
    Vecinofavor1->setdialogo(4,"Gracias genio, toma la figu");
    Bicicletero->setcodigodepersonaje(4);
    Bicicletero->setsprite("Personajes_Bicicletero.png");
    Bicicletero->setcantidaddedialogos(2);
    Bicicletero->setdialogo(1, "Listo la pelota Pipo. Si todavia no llenaste el album deberias");
    Bicicletero->setdialogo(2," ir a lo del librero que tiene un pilon de figuritas repetidas");

    Vecinofavor2->setcodigodepersonaje(5);
    Vecinofavor2->setsprite("Personajes_Vecinofavor2.png");
    Vecinofavor2->setcantidaddedialogos(5);
    Vecinofavor2->setdialogo(1, "Hola Pipo que tal? si tengo la de Dimaria repetida");
    Vecinofavor2->setdialogo(2, "Las repetidas que tenes las tengo 3 veces cada una");
    Vecinofavor2->setdialogo(3,"solo una cosa me puede llegar a interesar,y es un autografo");
    Vecinofavor2->setdialogo(4," del Rifle Ferreira, el crack de Chacarita que vive en el barrio");
    Vecinofavor2->setdialogo(5,"Gracias campeon! toma!");

    Vecinoexjugador->setcodigodepersonaje(6);
    Vecinoexjugador->setsprite("Personajes_vecinoexjugador.png");
    Vecinoexjugador->setcantidaddedialogos(6);
    Vecinoexjugador->setdialogo(1,"Hola nene, para que me tocas el timbre?");
    Vecinoexjugador->setdialogo(2,"Mira vos, y cuantas mas de faltan?");
    Vecinoexjugador->setdialogo(3,"Solo esa?! mmm... bueno, toma. Yo tambien colecciono figus");
    Vecinoexjugador->setdialogo(4,"Cuando consigas la de dimaria veni.");
// Va a librero y vuelve
    Vecinoexjugador->setdialogo(5,"Llevame esta camiseta al lavadero y te doy la de Messi");
// va a lavadero y vuelve
    Vecinoexjugador->setdialogo(6,"Listo campeon,toma! anda corriendo a tu casa!");

    Lavadero->setcodigodepersonaje(7);
    Lavadero->setsprite("Personajes_Lavadero.png");
    Lavadero->setcantidaddedialogos(1);
    Lavadero->setdialogo(1,"Listo pipo! que haces en la calle esta lleno de figuzombies");
/*
    Personajesinfigus1->setcodigodepersonaje(8);
    Personajesinfigus1->setsprite("Personajes_sinfigus1.png");
    Personajesinfigus1->setcantidaddedialogos(1);
    Personajesinfigus1->setdialogo(1, "Hola Pipo! No tengo ninguna de la seleccion");


    Personajesinfigus2->setcodigodepersonaje(9);
    Personajesinfigus2->setsprite("Personajes_sinfigus2.png");
    Personajesinfigus2->setcantidaddedialogos(1);
    Personajesinfigus2->setdialogo(1,"Hola Pipo! Ya tengo todas las repes que tenes");


    Personajesinfigus3->setcodigodepersonaje(10);
    Personajesinfigus3->setsprite("Personajes_sinfigus3.png");
    Personajesinfigus3->setcantidaddedialogos(1);
    Personajesinfigus3->setdialogo(1,"Hola Pipo! Hola Pipo! No tengo ninguna repetida");
/**/
}

void Gameplay::inicializarfiguritas(){
    _figuritas[0].setsprite("figuritamessi.png");
    _figuritas[0].setcodigodefigurita(0);
    _figuritas[0].setposicionsprite(591,36);


    _figuritas[1].setsprite("figuritaalvarez.png");
    _figuritas[1].setcodigodefigurita(1);
    _figuritas[1].setposicionsprite(691,36);

    _figuritas[2].setsprite("figuritadepaul.png");
    _figuritas[2].setcodigodefigurita(2);
    _figuritas[2].setposicionsprite(793,36);

    _figuritas[3].setsprite("figuritadimaria.png");
    _figuritas[3].setcodigodefigurita(3);
    _figuritas[3].setposicionsprite(591,133);

    _figuritas[4].setsprite("figuritadibu.png");
    _figuritas[4].setcodigodefigurita(4);
    _figuritas[4].setposicionsprite(691,133);

    _figuritas[5].setsprite("figuritalautaro.png");
    _figuritas[5].setcodigodefigurita(5);
    _figuritas[5].setposicionsprite(793,133);

    _repetidas[0].setsprite("figuritacristiano.png");
    _repetidas[0].setcodigodefigurita(0);
    _repetidas[0].setposicionsprite(592,248);

    _repetidas[1].setsprite("figuritasuarez.png");
    _repetidas[1].setcodigodefigurita(1);
    _repetidas[1].setposicionsprite(691,248);

    _repetidas[2].setsprite("figuritaneymar.png");
    _repetidas[2].setcodigodefigurita(2);
    _repetidas[2].setposicionsprite(793,248);


}

/*
void Pausa(){
if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){





}

}
*/
bool Gameplay::getapretoescape(){    return _apretoescape;  }

void Gameplay::setapretoescape(){ // REINICIA EL JUEGO

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        ///Reinicia variables involucradas
        _estaActivo=false;
        _apretoescape=true;
        Objetivos=0;
        numerodedialogomama=1;
        numdialogoPipo=1;
        numerodialogoariel=1;
        numerodialogovecino1=1;
        numerodialogovecino2=1;
        numerodialogobici=1;
        numerodialogoexjugador=1;

        for(int i=0;i<6;i++){

            _figuritas[i].setestadro(false);

        }
        for(int i=0;i<3;i++){

            _repetidas[i].setestadro(false);


        }
        for(int i=0;i<3;i++){

            _objetos[i].setenpantalla(false);
            _objetos[i].resetarsolucionado();

        }
        _paneldecontrol.setgano(false);
        _paneldecontrol.setperdio(false);
        _paneldecontrol.desactivarobjetivos();
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    }


    }

void Gameplay::resetarescape(){     _apretoescape=false;    }


void Gameplay::Desarrollo(){

    if(Objetivos==0)    { // OBJETIVO 0 LA MAMA LE HABLA

        if(!Pipo->getcongelado())
        {
            Pipo->Congelar();//hacer funcion pausa
            Pipohablando->Hablar(numdialogoPipo++);
        }


        if(Pipo->getcongelado())
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(Pipohablando->gethablando())
                {
                    Pipohablando->sethablando(false);
                    Mamadepipo->Hablar(numerodedialogomama);
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));///CONTIENE LOS INPUT EXTRA

                }
                else
                {
                    Pipo->Descongelar();
                    Mamadepipo->sethablando(false);
                    _paneldecontrol.imprimirobjetivos(Objetivos);
                    Objetivos++;
                }

            }

        }
    }

    if(Objetivos==1) { // OBJETIVO 1 VA A LA KIOSKERA

        if(Pipo->iscolision(*_mapa.getcasa(Kioskera->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();//hacer funcion pausa
                Kioskera->Hablar(1);
            }
        }
        if(Pipo->getcongelado())
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))

            {
                if(Kioskera->gethablando())
                {
                    Kioskera->sethablando(false);
                    Kioskera->darfiguritaapipo(Figuritadibu,Pipo);
                    Kioskera->darfiguritaapipo(Figuritaalvarez,Pipo);
                    Kioskera->darfiguritaapipo(Repetidacristiano,Pipo);
                    Kioskera->darfiguritaapipo(Repetidaneymar,Pipo);
                    Kioskera->darfiguritaapipo(Repetidasuarez,Pipo);

                    Pipohablando->Hablar(numdialogoPipo++);
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                }
                else
                {
                    Pipohablando->sethablando(false);
                    Pipo->Descongelar();
                    _paneldecontrol.imprimirobjetivos(1);
                    Objetivos++;

                }

            }
        }



    }

    if(Objetivos==2) { // OBJETIVO 2 VA A LO DE ARIEL

        if(Pipo->iscolision(*_mapa.getcasa(Amigoariel->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();//hacer funcion pausa
                Amigoariel->Hablar(numerodialogoariel++);
            }
        }
        if(Pipo->getcongelado())
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))

            {
                if(numerodialogoariel<=Amigoariel->getcantidaddedialogos())
                {
                    Amigoariel->Hablar(numerodialogoariel++);
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                }
                else
                {
                    if(numdialogoPipo==3)
                    {
                        Amigoariel->sethablando(false);
                        Pipohablando->Hablar(numdialogoPipo++);
                        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                    }
                    else
                    {
                        Pipo->Pipodafigurita(Repetidacristiano,Amigoariel);
                        Amigoariel->darfiguritaapipo(Figuritadepaul,Pipo);
                        Pipohablando->sethablando(false);
                        Pipo->Descongelar();
                        _paneldecontrol.imprimirobjetivos(Objetivos);
                        Objetivos++;
                    }

                }

            }
        }



    }

    if(Objetivos==3)    { // OBJETIVO 3 VA A VECINO 1

        if(Pipo->iscolision(*_mapa.getcasa(Vecinofavor1->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();//hacer funcion pausa
                Vecinofavor1->Hablar(numerodialogovecino1++);
            }
        }
        if(Pipo->getcongelado())
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {

                if(numerodialogovecino1<=Vecinofavor1->getcantidaddedialogos()-1)
                {

                    Vecinofavor1->Hablar(numerodialogovecino1++);

                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));

                }
                else
                {
                    if(numdialogoPipo==4)
                    {
                        Vecinofavor1->sethablando(false);
                        Pipohablando->Hablar(numdialogoPipo++);
                        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                    }
                    else
                    {
                        Vecinofavor1->darobjetoapipo(Pelota,Pipo);
                        Pipohablando->sethablando(false);
                        Pipo->Descongelar();
                        _paneldecontrol.imprimirobjetivos(_paneldecontrol.getcodigocasabicicletero());
                        Objetivos++;
                    }
                }






            }

        }

    }

    if(Objetivos==4)    { // OBJETIVO 4 SOLUCIONA VECINO 1

        if(Pipo->iscolision(*_mapa.getcasa(Bicicletero->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();//hacer funcion pausa
                Bicicletero->Hablar(numerodialogobici++);
            }
        }

        if(Pipo->getcongelado())
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {

                if(numerodialogobici<=Bicicletero->getcantidaddedialogos())
                {

                    Pipo->darobjeto(Pelota,Bicicletero);
                    Bicicletero->solucionarobjeto(Pelota);
                    Bicicletero->Hablar(numerodialogobici++);

                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));


                }
                else
                {

                    if(Bicicletero->gethablando())
                    {
                        Bicicletero->sethablando(false);
                        Pipohablando->Hablar(numdialogoPipo++);
                        Bicicletero->darobjetoapipo(Pelota,Pipo);
                        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                    }
                    else
                    {
                        Pipohablando->sethablando(false);
                        Pipo->Descongelar();
                        _paneldecontrol.imprimirobjetivos(2);


                    }
                }


            }
        }



        if(Pelota->getestado()&&Pelota->getenpantalla())
        {

            if(Pipo->iscolision(*_mapa.getcasa(Vecinofavor1->getcodigodepersonaje())))
            {

                if(!Pipo->getcongelado())
                {
                    Vecinofavor1->Hablar(numerodialogovecino1++);
                    Pipo->Congelar();
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(numerodialogovecino1>Vecinofavor1->getcantidaddedialogos())
                {
                    Vecinofavor1->sethablando(false);
                    Pipo->Descongelar();
                    _paneldecontrol.imprimirobjetivos(Objetivos);
                    Objetivos++;
                    Pipo->Pipodaobjeto(Pelota,Vecinofavor1);
                    Vecinofavor1->darfiguritaapipo(Figuritalautaro,Pipo);
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                }
            }

        }
    }

    if(Objetivos==5)    { // OBJETIVO 5 VA Y SOLUCIONA VECINO 2

        if(Autografo->getenpantalla()==false){
        if(Pipo->iscolision(*_mapa.getcasa(Vecinofavor2->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();//hacer funcion pausa
                Vecinofavor2->Hablar(numerodialogovecino2++);
            }
        }

        if(Pipo->getcongelado())
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {

                if(numerodialogovecino2<=Vecinofavor2->getcantidaddedialogos()-1)
                {

                    Vecinofavor2->Hablar(numerodialogovecino2++);
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));

                }
                else
                {


                    if(Vecinofavor2->gethablando())
                    {

                        Vecinofavor2->sethablando(false);
                        Pipohablando->Hablar(numdialogoPipo++);

                        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                    }
                    else
                    {

                        Vecinofavor2->darobjetoapipo(Autografo,Pipo);
                        Pipohablando->sethablando(false);
                        _paneldecontrol.imprimirobjetivos(Objetivos);
                        Pipo->Descongelar();

                    }



                }

            }
        }
        }

        if(Autografo->getenpantalla()==true&&Autografo->getestado()==false){

        if(Pipo->iscolision(*_mapa.getcasa(Vecinoexjugador->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();
                Vecinoexjugador->Hablar(numerodialogoexjugador++);
            }
        }

        if(Pipo->getcongelado()){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {

                if(numdialogoPipo<=8)
                {
                    Vecinoexjugador->sethablando(false);
                    Pipohablando->Hablar(numdialogoPipo++);
                    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                }
                else
                {

                    if(numerodialogoexjugador==2)
                    {
                        Pipohablando->sethablando(false);
                        Vecinoexjugador->Hablar(numerodialogoexjugador++);
                        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                    }
                    else
                    {

                        if(numdialogoPipo==9)
                        {
                            Vecinoexjugador->sethablando(false);
                            Pipohablando->Hablar(numdialogoPipo++);
                            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                        }
                        else
                        {

                            if(numerodialogoexjugador<5)
                            {
                                Pipohablando->sethablando(false);
                                Vecinoexjugador->Hablar(numerodialogoexjugador++);
                                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                            }
                            else
                            {
                                Vecinoexjugador->solucionarobjeto(Autografo);
                                Pipo->Descongelar();
                                Vecinoexjugador->sethablando(false);
                                _paneldecontrol.imprimirobjetivos(4);

                            }


                        }



                    }

                }


            }
        }
    }
    else{

        if(Autografo->getenpantalla()==true&&Autografo->getestado()==true){

         if(Pipo->iscolision(*_mapa.getcasa(Vecinofavor2->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();//hacer funcion pausa
                Vecinofavor2->Hablar(numerodialogovecino2);

            }
        }

        if(Pipo->getcongelado())
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {

                if(Vecinofavor2->gethablando()){
                            Vecinofavor2->sethablando(false);
                        Pipohablando->Hablar(numdialogoPipo++);

                        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                }
                else{

            Vecinofavor2->darfiguritaapipo(Figuritadimaria,Pipo);
                Pipo->Pipodaobjeto(Autografo,Vecinofavor2);

                    Pipohablando->sethablando(false);
                    Pipo->Descongelar();
                   _paneldecontrol.imprimirobjetivos(5);
                    Objetivos++;

                }

        }

    }
    }
}

    }

    if(Objetivos==6){ // OBJETIVO 6 FAVOR A VECINO EX JUGADOR

        if(Camiseta->getenpantalla()==false&&Camiseta->getestado()==false){
        if(Pipo->iscolision(*_mapa.getcasa(Vecinoexjugador->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();
                Vecinoexjugador->Hablar(numerodialogoexjugador++);
            }
        }

        if(Pipo->getcongelado()){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                Vecinoexjugador->sethablando(false);
                Vecinoexjugador->darobjetoapipo(Camiseta,Pipo);
                Pipo->Descongelar();
                _paneldecontrol.imprimirobjetivos(6);
            }
        }
        }
        if(Camiseta->getestado()==false&&Camiseta->getenpantalla()==true){

        if(Pipo->iscolision(*_mapa.getcasa(Lavadero->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();
              Lavadero->Hablar(1);

               }
        }

        if(Pipo->getcongelado()){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                Lavadero->solucionarobjeto(Camiseta);
                Lavadero->sethablando(false);
                Pipo->Descongelar();
                _paneldecontrol.imprimirobjetivos(5);
            }

        }

}
if(Camiseta->getestado()==true&&Camiseta->getenpantalla()==true){

      if(Pipo->iscolision(*_mapa.getcasa(Vecinoexjugador->getcodigodepersonaje())))
        {

            if(!Pipo->getcongelado())
            {
                Pipo->Congelar();
                Vecinoexjugador->Hablar(numerodialogoexjugador);
                 }
        }

        if(Pipo->getcongelado()){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(numerodialogoexjugador==Vecinoexjugador->getcantidaddedialogos()){
                Vecinoexjugador->sethablando(false);
                Pipohablando->Hablar(numdialogoPipo);
                numerodialogoexjugador++;
                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
                }
                else{
                Pipohablando->sethablando(false);
                _paneldecontrol.imprimirobjetivos(7);
                Vecinoexjugador->darfiguritaapipo(Figuritamessi,Pipo);
                 Pipo->Pipodaobjeto(Camiseta,Vecinoexjugador);
                 Objetivos++;
                Pipo->Descongelar();
                }
                }
                }
            }
                }

    if(Objetivos==7){ // OBJETIVO 7 LLEGAR A LA CASA Y GANAR


                 if(Pipo->iscolision(*_mapa.getcasa(Mamadepipo->getcodigodepersonaje())))
        {
            _paneldecontrol.setgano(true);
            Pipo->Congelar();
            std::cout<< "Ganaste!";
            _tiempoGanador=_tiempo1;
            grabarRanking();
            }


            }
}

void Gameplay::colisionesdemapa(){
    limitesdelmapa(); // Limites exteriores

    for(int i=0; i<14; i++) // Cuadras
    {
        if(_pipo.iscolision(*_mapa.getcuadras(i)))
        {
            _pipo.setposicion(_pipo.getposicionanterior());

        }

}
}

void Gameplay::limitesdelmapa(){
    if(_pipo.getxorigen()-_pipo.getancho()/2<10)
    {
        _pipo.setposicion(_pipo.getposicionanterior());
    }

    ///LIMITE DERECHO
    if(_pipo.getxorigen()+_pipo.getancho()/2>_mapa.getspriteCalles().getGlobalBounds().width + 10)
    {
        _pipo.setposicion(_pipo.getposicionanterior());
    }

    /// LIMITESUPERIOR
    if(_pipo.getyorigen()-_pipo.getalto()/2<10)
    {
        _pipo.setposicion(_pipo.getposicionanterior());
    }

    ///LIMITE INFERIOR
    if(_pipo.getyorigen()+_pipo.getalto()/2>_mapa.getspriteCalles().getGlobalBounds().height + 10)
    {
        _pipo.setposicion(_pipo.getposicionanterior());
    }
}

void Gameplay::update(){
   if(_comienzaJuego)
    {
   //     if(pausa==true){
        _tiempo1 = _reloj1.getElapsedTime();
     //   }

    }
    _avatar.set_tiempo(_tiempo1);
    _avatar.update();
    _pipo.update();
    _paneldecontrol.update();
    Desarrollo();
    colisionesdemapa();
    setapretoescape();

      std::cout<<_tiempo1.asSeconds() << std::endl; //solo para chequear por consola que anda el reloj
//    ver que hace este if, para ver donde arranca el reloj



}

sf::FloatRect  Gameplay::getBound() const{
    return _spritefondo.getGlobalBounds();
}

void Gameplay::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    target.draw(_spritefondo, states);
    target.draw(_mapa,states);
    target.draw(_spriteRio, states);
    target.draw(_pipo,states);

    target.draw(_paneldecontrol, states);
    target.draw(_avatar, states);

   for (int i=0; i<12; i++)
    {

        target.draw(_personajes[i], states);

    }


    if(_comienzaJuego==false)
    {
        target.draw(_spriteCuadroExterno);
        target.draw(_spriteCuadroNombre);
        target.draw(_textoNombre);
        target.draw(_textoEscribirNombre);
    }


}

void Gameplay::grabarRanking(){
    Archivo archivo;
    Archivo aux;
    bool modifico = false;
    int pos =0;

    while(archivo.leer(pos)==1 && modifico==false)
    {
        switch(pos)
        {   case 0:
                if(archivo.getMin() > _tiempoGanador.asSeconds()/60 || (archivo.getMin() == _tiempoGanador.asSeconds()/60 && archivo.getSeg() > (float)fmod(_tiempoGanador.asSeconds(),60)))
                {
                //hay que validar aca si leyo, se supone que ya filtro antes
                aux.leer(1);
                aux.modificar(2);
                archivo.modificar(1);

                archivo.setNombre(_nombreJugador);
                archivo.setMin(_tiempoGanador.asSeconds()/60);
                archivo.setSeg((float)fmod(_tiempoGanador.asSeconds(),60)); //fmod para saber el resto entre float
                archivo.modificar(0);
                modifico = true;
                }
            break;
            case 1:
                if(archivo.getMin() > _tiempoGanador.asSeconds()/60 || (archivo.getMin() == _tiempoGanador.asSeconds()/60 && archivo.getSeg() > (float)fmod(_tiempoGanador.asSeconds(),60)))
                {
                //hay que validar aca si leyo, se supone que ya filtro antes
                archivo.modificar(2);

                archivo.setNombre(_nombreJugador);
                archivo.setMin(_tiempoGanador.asSeconds()/60);
                archivo.setSeg((float)fmod(_tiempoGanador.asSeconds(),60));
                archivo.modificar(1);
                modifico = true;
                }
            break;
            case 2:
                if(archivo.getMin() > _tiempoGanador.asSeconds()/60 || (archivo.getMin() == _tiempoGanador.asSeconds()/60 && archivo.getSeg() > (float)fmod(_tiempoGanador.asSeconds(),60)))
                {
                archivo.setNombre(_nombreJugador);
                archivo.setMin(_tiempoGanador.asSeconds()/60);
                archivo.setSeg((float)fmod(_tiempoGanador.asSeconds(),60));
                archivo.modificar(2);
                modifico = true;
                }
            break;
        }
        pos++;
    }
}

Gameplay::~Gameplay() {}
