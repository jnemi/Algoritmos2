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
#include "List.h"

using namespace std;

void lectura(List<Elemento>*, List<Celula>*);

void procesar_archivo(ifstream &archivo, string &dato, List<Elemento>*, List<Celula>*);

void armado_red_celulas(List<Elemento>*);

#endif // FUNCIONES_H_INCLUDED
