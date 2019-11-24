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

//Juego* juego = 0;

int main(int argc, char** argv){
    Lista <Suero>* lista_dosis_a = new Lista <Suero>;
    Lista <Suero>* lista_dosis_b = new Lista <Suero>;
    Lista <Celula>* lista_celulas = new Lista <Celula>;
    Lista <Anticuerpo>* lista_anticuerpos = new Lista <Anticuerpo>;
    Nanobot* nanobot = new Nanobot(0, 550);

    lectura(lista_dosis_a, lista_dosis_b, lista_celulas, lista_anticuerpos);

    armado_red_celular(lista_celulas, 3, 1);

    menu(lista_celulas, lista_anticuerpos, lista_dosis_a, lista_dosis_b, nanobot);

    //for (int i = 1; i <= lista_celulas->obtener_largo(); i++)
    //    lista_celulas->obtener_valor(i).mostrar();

    delete lista_dosis_a;
    delete lista_dosis_b;
    delete lista_celulas;
    delete lista_anticuerpos;

    cout<<endl<<endl<<"[DEBUG]: PROGRAMA FINALIZADO"<<endl;
  return 0;
}
