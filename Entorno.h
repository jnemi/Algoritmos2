#ifndef ENTORNO_H
#define ENTORNO_H

#include "Textura.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "ImageLoader.h"
#include "funciones.h"
#include "Celula.h"
#include "Lista.h"
#include "Nanobot.h"

enum imagenes{FONDO,NANOBOT,CELULA_S,CELULA_X,CELULA_Y,CELULA_Z,ANTICUERPO,DOSIS_A,DOSIS_B};
enum dosis{A,B};

class Entorno
{
    private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    ImageLoader* loaderA;
    ImageLoader* loaderB;
    Textura texturas[9];
    int estadoDosisA,estadoDosisB;
    Textura numeros[10];

    public:
        Entorno();
        ~Entorno();
        void cargarTexturas();
        void renderizar(imagenes imagen,float, float);
        bool iniciar(const char *titulo, int xPos, int yPos, int flags);
        void renderizarTodo(Lista<Celula>*, Lista<Anticuerpo>*, Lista<Suero>*, Lista<Suero>*, Nanobot*);
        void limpiar();
        void explotarDosis(dosis dosis);
        bool dosisAExplotando();
        bool dosisBExplotando();
        void renderizarNumero(int i,float x, float y);
        //PRE: -
        //POS: Renderiza una dosis A en la posicion del nanobot
        void inyectar_dosis_a(Nanobot*, Lista <Suero>* lista_dosis_a);
        //PRE: -
        //POS: Renderiza una dosis B en la posicion del nanobot
        void inyectar_dosis_b(Nanobot*, Lista <Suero>* lisa_dosis_b);
        //PRE: -
        //POS: Desplaza el nanobot arriba
        void desplazar_arriba(Nanobot *nanobot);
        //PRE: -
        //POS: Desplaza el nanobot abajo
        void desplazar_abajo(Nanobot *nanobot);
        //PRE: -
        //POS: Desplaza el nanobot a la derecha
        void desplazar_derecha(Nanobot *nanobot);
        //PRE: -
        //POS: Desplaza el nanobot a la izquierda
        void desplazar_izquierda(Nanobot *nanobot);

        //PRE: -
        //POS: Desplaza un anticuerpo arriba
        void mover_arriba(Microorganismo &anticuerpo);
        //PRE: -
        //POS: Desplaza un anticuerpo abajo
        void mover_abajo(Microorganismo &anticuerpo);
        //PRE: -
        //POS: Desplaza un anticuerpo a la derecha
        void mover_derecha(Microorganismo &anticuerpo);
        //PRE: -
        //POS: Desplaza un anticuerpo a la izquierda
        void mover_izquierda(Microorganismo &anticuerpo);


        //PRE: El parámetro debe ser una referencia a un objeto anticuerpo
        //POS: Devuelve true si la posición del anticuerpo coincide con la
        //del nanobot
        bool verificar_anticuerpo(Microorganismo &anticuerpo, Nanobot* nanobot);

        void liberar(Anticuerpo &anticuerpo, Direccion direccion);

        void volar(Anticuerpo &anticuerpo);

        bool verificarZ(Microorganismo &anticuerpo, Celula &celula);
};

#endif // ENTORNO_H
