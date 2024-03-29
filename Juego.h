//
// Created by caropistillo
//

#ifndef JUEGO_H
#define JUEGO_H

#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>

#include "FPSManager.h"
#include "Textura.h"
#include "InputManager.h"
#include "Entorno.h"
#include "Lista.h"
#include "Celula.h"
#include "Anticuerpo.h"
#include "Reloj.h"


using namespace std;


class Juego {
private:
    bool running;
    Entorno entorno;
    Reloj reloj;

public:
    Juego();
    ~Juego(){}
    bool iniciar(const char* titulo, int xPos, int yPos, int flags);
    void correr(Lista<Celula>*, Lista<Anticuerpo>*, Lista <Suero>*, Lista <Suero>*, Nanobot*);
    void renderizar(Lista<Celula>*, Lista<Anticuerpo>*, Lista<Suero>*, Lista<Suero>*, Nanobot*);
    void manejarEventos(Lista<Celula>*, Lista<Anticuerpo>*, Lista <Suero>*, Lista <Suero>*, bool &tope, Nanobot*);
    void limpiar();
};


#endif //JUEGO_H
