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

Juego* juego = 0;

int main(int argc, char** argv){
    Lista <Elemento> *lista_general = new Lista <Elemento>;
    Lista <Celula> *lista_celulas = new Lista <Celula>;
    lectura(lista_general, lista_celulas);

    armado_red_celular(lista_celulas, 3, 1);

    juego = new Juego();
    juego->iniciar("Nanobot", 100, 100, 0);

    juego->correr();

    juego->limpiar();

    //for (int i = 1; i <= lista_celulas->obtener_largo(); i++)
    //    lista_celulas->obtener_valor(i).mostrar();

    //armado_red_celular(lista_celulas, 3, 1);

    delete lista_general;
    delete lista_celulas;
    delete juego;

    cout<<endl<<endl<<"[DEBUG]: PROGRAMA FINALIZADO"<<endl;
  return 0;
}
