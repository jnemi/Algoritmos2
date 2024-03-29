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
#include <math.h>

using namespace std;

//Abre y recorre el archivo de texto
void lectura(Lista<Suero>*, Lista<Suero>*, Lista<Celula>*, Lista<Anticuerpo>*);

//Procesa los datos del archivo de texto extendiendo las listas de objetos
void procesar_archivo(ifstream &archivo, string &dato, Lista<Suero>*, Lista <Suero>*, Lista<Celula>*, Lista<Anticuerpo>*);

//Crea las listas de adyacentes
void cruzar_celulas(Lista<Celula>* , Lista<int>*);

//Renderiza las rectas de la red que unen celulas adyacentes
void armado_red_grafica(SDL_Renderer*, Lista<Celula>*);

//Define el comportamiento de las celulas en caso de que se explote una dosis A
void revertir_celula(Lista<Celula>*, Lista<Suero>*, Nanobot*);

//Define el comportamiento de las celulas en caso de que se explote una dosis B
void evolucionar_celula(Lista<Celula>*, Lista<Suero>*);

//Vuelve a concetar la red en casod e que se elimine una celula
void reconectar_red(Lista<Celula>*, int);

//Actualiza la lista de celulas adyacentes
void actualizar_adyacentes(Lista<Celula>*, int);

//Contagia las celulas adyacentes a las de tipo Z cada cierto periodo de tiempo
void infeccion_z(Lista<Celula>*);

//Menu para inciar el juego
void menu(Lista<Celula>*, Lista<Anticuerpo>*, Lista<Suero>*, Lista<Suero>*, Nanobot*);

//Se encarga de revisar si el jugador gana o pierde
bool estado_juego(Lista<Celula>*);

//devulve la cantidad de cifras de un numero
int cuantas_cifras(int);

//divide un numero en digitos y los coloca en un vector. Recibe el numero, la cantidad de digitos y un vector donde alojarlos
void dividir_en_digitos(int, int, int vec[]);

//devuelve el promedio entre dos enteros
int promedio(int, int);

#endif // FUNCIONES_H_INCLUDED
