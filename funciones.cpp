#include "funciones.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <stdio.h>
#include "Juego.h"
#include "Entorno.h"
#include "Constants.h"

//Funcion para leer el archivo
void lectura(Lista <Elemento>* lista_general, Lista <Celula>* lista_celulas, Lista <Anticuerpo>* lista_anticuerpos){
   ifstream archivo;
   //Abro el archivo para lectura
   archivo.open("estado.txt");

   //Compruebo la existencia del archivo
   if(!archivo){
      cout << "Archivo inexistente." << endl << endl << endl;
      system("read -p 'Presione enter para continuar...' var");
      exit(1);
   }

   //Variables para recorrer el archivo
   string dato;

   //Recorro el archivo
   while(archivo >> dato){
      procesar_archivo(archivo, dato, lista_general, lista_celulas, lista_anticuerpos);
   }


   //Cierro el archivo
   archivo.close();
}

//Funcion para procesar los datos del archivo
void procesar_archivo(ifstream &archivo, string &dato, Lista<Elemento> *lista_general, Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos){
   float aux1, aux2;
   char aux3;
   unsigned int aux4;
   if(dato == "celula"){
      //Se crea objeto Celula
      archivo >> dato;
      archivo >> aux1;
      archivo >> aux2;
      if(dato == "X")
        lista_celulas -> extender(new Celula_x(aux1, aux2));
      else if(dato == "Y")
        lista_celulas -> extender(new Celula_y(aux1, aux2));
      else if(dato == "Z")
        lista_celulas -> extender(new Celula_z(aux1, aux2));
      else
        lista_celulas -> extender(new Celula_s(aux1, aux2));
   }else{
     if(dato == "anticuerpo"){
       //se crea objeto anticuerpo
       archivo >> aux1;
       archivo >> aux2;
       lista_anticuerpos -> extender(new Anticuerpo(aux1, aux2));
     }else{
          if(dato == "dosis"){
            //se crea objeto dosis
            archivo >> aux3;
            //aux3 = dato;
            archivo >> aux4;
            lista_general -> extender(new Suero(aux3, aux4));
         }
       }
     }
}

void armado_red_celular(Lista<Celula>* lista, int elementosXGrupo, int interseccion){
    //cout<<"[DEBUG]: Configurando la red celular"<<endl<<endl;
    int cantGrupos = ((lista->obtener_largo() - 1) / (elementosXGrupo - interseccion)) + 1;
    //cout<<"         Hay "<<lista->obtener_largo()<<" elemento en la lista"<<endl;
    //cout<<"         Armando grupos con "<<elementosXGrupo<<" elementos por grupo, ";
    //cout<<"con "<<interseccion<<" elementos intersectando..."<<endl<<endl;

    //cout<<"[DEBUG]: Preparando "<<cantGrupos<<" grupos..."<<endl<<endl;

    for (int a = 1; a <= cantGrupos; a++)
    {
        Lista<int> grupo;

        int principioGrupo = 1 + (a - 1)*(elementosXGrupo - interseccion);

        //cout<<"[DEBUG]: Grupo "<<a<<", iniciando en "<<principioGrupo<<"("<<aux<<" -> "<<&(aux->obtener_valor())<<"):"<<endl;

        for (int k = 1; k <= elementosXGrupo; k++)
        {
            int indice_actual = principioGrupo + k - 1;
            if (indice_actual <= lista->obtener_largo())
                grupo.extender(new int(indice_actual));
        }
        cout<<endl<<"[DEBUG]: Iniciando cruce..."<<endl;
        cruzar_celulas(lista, &grupo);
    }
}

void cruzar_celulas(Lista<Celula>* lista, Lista<int>* celulas_conectadas)
{
    int largo = celulas_conectadas->obtener_largo();
    for (int i = 1; i <= largo; i++)
    {
        for (int j = 1; j <= largo; j++)
        {
            if (i != j){
                cout<<"[DEBUG]: Cruzando "<<celulas_conectadas->obtener_valor(i)<<"("<<i<<")"<<" con "<<celulas_conectadas->obtener_valor(j)<<"("<<j<<") ";

                lista->obtener_puntero(celulas_conectadas->obtener_valor(i))->agregarAdyacente(celulas_conectadas->obtener_valor(j));

                //celulas_conectadas->obtener_valor(i)->agregarAdyacente(&(celulas_conectadas->obtener_valor(j)));
            }
        }
    }
}

void armado_red_grafica(SDL_Renderer* renderer, Lista<Celula>* lista){
    int largo = lista->obtener_largo();
    float x1, y1, x2, y2;


    for(int i=1; i<=largo; i++){
        Celula* cel_actual = lista->obtener_puntero(i);
        x1 = cel_actual->obtener_posicion_x();
        y1 = cel_actual->obtener_posicion_y();

        int cantAdyacentes = cel_actual->obtenerCantidadAdyacentes();

        for (int j = 1; j <= cantAdyacentes; j++){
            Celula* adyacente_actual = lista->obtener_puntero(cel_actual->obtenerAdyacente(j));
            x2 = adyacente_actual->obtener_posicion_x();
            y2 = adyacente_actual->obtener_posicion_y();

            //cout << "LA LINEA VA DE (" << x1 << "," << y1 << ") a (" << x2 << "," << y2 << ")";
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }

}
