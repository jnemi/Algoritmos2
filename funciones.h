#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funciones.h"
#include "Celula_x.h"
#include "Celula_y.h"
#include "Celula_z.h"
#include "Celula_s.h"
#include "Suero.h"
#include "Anticuerpo.h"
#include "Nanobot.h"
#include <fstream>
#include "Lista.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace std;

void lectura(Lista<Suero>*, Lista<Suero>*, Lista<Celula>*, Lista<Anticuerpo>*);

void procesar_archivo(ifstream &archivo, string &dato, Lista<Suero>*, Lista <Suero>*, Lista<Celula>*, Lista<Anticuerpo>*);

void armado_red_celular(Lista<Celula>*, int, int);

void cruzar_celulas(Lista<Celula>* , Lista<int>*);

void armado_red_grafica(SDL_Renderer*, Lista<Celula>*);

void revertir_celula(Lista<Celula>*, Lista<Suero>*);

void evolucionar_celula(Lista<Celula>*, Lista<Suero>*);

void reconectar_red(Lista<Celula>*, int);

void actualizar_adyacentes(Lista<Celula>*, int);

void infeccion_z(Lista<Celula>*);

void menu(Lista<Celula>*, Lista<Anticuerpo>*, Lista<Suero>*, Lista<Suero>*, Nanobot*);

#endif // FUNCIONES_H_INCLUDED
