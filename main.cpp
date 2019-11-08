#include "funciones.h"
#include "Celula_x.h"
#include "Celula_y.h"
#include "Celula_z.h"
#include "Celula_s.h"
#include "Suero.h"
#include "Anticuerpo.h"
#include "Lista.h"

using namespace std;



int main(){
    Lista <Elemento> *lista_general = new Lista <Elemento>;
    Lista <Celula> *lista_celulas = new Lista <Celula>;
    lectura(lista_general, lista_celulas);

    armado_red_celular(lista_celulas, 3, 1);

    for (int i = 1; i <= lista_celulas->obtener_largo(); i++)
        lista_celulas->obtener_valor(i).mostrar();

    //armado_red_celular(lista_celulas, 3, 1);

    delete lista_general;
    delete lista_celulas;
  return 0;
}
