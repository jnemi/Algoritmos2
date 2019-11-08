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

using namespace std;

void lectura(Lista<Elemento>*, Lista<Celula>*);

void procesar_archivo(ifstream &archivo, string &dato, Lista<Elemento>*, Lista<Celula>*);

void armado_red_celular(Lista<Celula>*, int, int);

void cruzar_celulas(Lista<Celula*>*);

#endif // FUNCIONES_H_INCLUDED
