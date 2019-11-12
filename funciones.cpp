#include "funciones.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <stdio.h>
#include "Juego.h"
#include "Entorno.h"
#include "Constants.h"

//Funcion para leer el archivo
void lectura(Lista<Elemento>* lista_general, Lista <Celula> *lista_celulas){
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
      procesar_archivo(archivo, dato, lista_general, lista_celulas);
   }


   //Cierro el archivo
   archivo.close();
}

//Funcion para procesar los datos del archivo
void procesar_archivo(ifstream &archivo, string &dato, Lista<Elemento> *lista_general, Lista<Celula>* lista_celulas){
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
       lista_general -> extender(new Anticuerpo(aux1, aux2));
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
        Lista<Celula*> grupo;

        Nodo<Celula>* aux;
        int principioGrupo = 1 + (a - 1)*(elementosXGrupo - interseccion);
        aux = lista->buscar_nodo(principioGrupo);

        //cout<<"[DEBUG]: Grupo "<<a<<", iniciando en "<<principioGrupo<<"("<<aux<<" -> "<<&(aux->obtener_valor())<<"):"<<endl;

        for (int k = 1; k <= elementosXGrupo; k++)
        {
            /*
            Celula* pCelulaAux = &(aux->obtener_valor());
            grupo.extender(&pCelulaAux);
            */


            if (aux != 0){
                cout<<"         Ejecutando linea 95";
                Celula** pCelulaAux = new Celula*;
                cout<<" 97";
                *pCelulaAux = &(aux->obtener_valor());
                cout<<" 99";
                aux = aux->obtener_siguiente();
                cout<<" 101";
                grupo.extender(pCelulaAux);
                cout<<" OK"<<endl;
                cout<<"         "<<&(pCelulaAux)<<"->"<<&(*pCelulaAux)<<"->"<<&(**pCelulaAux)<<endl;
            }
        }
        cout<<endl<<"[DEBUG]: Iniciando cruce..."<<endl;
        cruzar_celulas(&grupo);
    }
}

void cruzar_celulas(Lista<Celula*>* celulas_conectadas)
{
    int largo = celulas_conectadas->obtener_largo();
    for (int i = 1; i <= largo; i++)
    {
        for (int j = 1; j <= largo; j++)
        {
            if (i != j){
                cout<<"[DEBUG]: Cruzando "<<celulas_conectadas->obtener_valor(i)<<"("<<i<<")"<<" con "<<celulas_conectadas->obtener_valor(j)<<"("<<j<<") ";
                Celula* celula = celulas_conectadas->obtener_valor(i);
                Celula** adyacente = &(celulas_conectadas->obtener_valor(j));
                if (celula != 0 && *adyacente != 0)
                    celula->agregarAdyacente(adyacente);
                else
                    cout<<"[DEBUG]: Cruce rechazado"<<endl;
                //celulas_conectadas->obtener_valor(i)->agregarAdyacente(&(celulas_conectadas->obtener_valor(j)));
            }
        }
    }
}

void armado_red_grafica(SDL_Renderer* renderer, Lista<Celula>* lista){
    int largo = lista->obtener_largo();
    float x1, y1, x2, y2;

    for(int i=1; i<=largo; i++){
        x1 = lista->obtener_valor(i).obtener_posicion_x();
        y1 = lista->obtener_valor(i).obtener_posicion_y();

        x2 = lista->obtener_valor(i+1).obtener_posicion_x();
        y2 = lista->obtener_valor(i+1).obtener_posicion_y();

        //cout << "LA LINEA VA DE (" << x1 << "," << y1 << ") a (" << x2 << "," << y2 << ")";

        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}
