#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funciones.h"
#include "Celula_x.h"
#include "Celula_y.h"
#include "Celula_z.h"
#include "Celula_s.h"
#include "Suero.h"
#include "Anticuerpo.h"
#include <fstream>
#include "Lista.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace std;

void lectura(Lista<Elemento>*, Lista<Celula>*, Lista<Anticuerpo>*);

void procesar_archivo(ifstream &archivo, string &dato, Lista<Elemento>*, Lista<Celula>*, Lista<Anticuerpo>*);

void armado_red_celular(Lista<Celula>*, int, int);

void cruzar_celulas(Lista<Celula>* , Lista<int>*);

void armado_red_grafica(SDL_Renderer*, Lista<Celula>*);
#endif // FUNCIONES_H_INCLUDED
