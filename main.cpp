#include "funciones.h"
#include "Celula_x.h"
#include "Celula_y.h"
#include "Celula_z.h"
#include "Celula_s.h"
#include "Suero.h"
#include "Anticuerpo.h"

using namespace std;

//Constante para el tamaño maximo del vector
const int LARGO = 100;

int main(){
    //Creo vector de punteros a Elemento
    Elemento *vec[LARGO];
    //Variable maximo logico
    int mL;
    //Menu
    menu(vec, mL);

  return 0;
}
