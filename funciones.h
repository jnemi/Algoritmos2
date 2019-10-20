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

using namespace std;

void lectura(Elemento **vec, int &mL);

void procesarArchivo(ifstream &archivo, string &dato, int &i, Elemento **vec);

void menu(Elemento **vec, int &mL);

void mostrarDatos(Elemento **vec, int mL);

void mostrarPosicion(Elemento **vec, int mL);

#endif // FUNCIONES_H_INCLUDED
