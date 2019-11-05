#include "funciones.h"
#include "Celula_x.h"
#include "Celula_y.h"
#include "Celula_z.h"
#include "Celula_s.h"
#include "Suero.h"
#include "Anticuerpo.h"
#include "List.h"

using namespace std;



int main(){
    List <Elemento> *lista_general = new List <Elemento>;
    List <Celula> *lista_celulas = new List <Celula>;
    lectura(lista_general, lista_celulas);

    delete lista_general;
    delete lista_celulas;
  return 0;
}
