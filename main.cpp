#include "funciones.h"
#include "Celula_x.h"
#include "Celula_y.h"
#include "Celula_z.h"
#include "Celula_s.h"
#include "Suero.h"
#include "Anticuerpo.h"
#include "Lista.h"
#include "Juego.h"

using namespace std;

int main(int argc, char** argv){
    //Declaracion de listas de objetos
    Lista <Suero>* lista_dosis_a = 0;
    Lista <Suero>* lista_dosis_b = 0;
    Lista <Celula>* lista_celulas = 0;
    Lista <Anticuerpo>* lista_anticuerpos = 0;
    Nanobot* nanobot = 0;

    menu(lista_celulas, lista_anticuerpos, lista_dosis_a, lista_dosis_b, nanobot);

  return 0;
}
