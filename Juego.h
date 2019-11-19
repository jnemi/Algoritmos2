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


using namespace std;


class Juego {
private:
    bool running;
    Entorno entorno;

public:
    Juego();
    ~Juego(){}
    bool iniciar(const char* titulo, int xPos, int yPos, int flags);
    void correr(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos, Nanobot *nanobot);
    void renderizar(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos, Nanobot *nanobot);
    void manejarEventos(Lista<Anticuerpo>* lista_anticuerpos, bool &tope, Nanobot *nanobot);
    void limpiar();
};


#endif //JUEGO_H
