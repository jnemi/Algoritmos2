#include "funciones.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <stdio.h>
#include "Juego.h"
#include "Entorno.h"
#include "Constants.h"
#include <math.h>

Juego* juego = 0;

//Funcion para leer el archivo
void lectura(Lista <Suero>* lista_dosis_a, Lista <Suero>* lista_dosis_b, Lista <Celula>* lista_celulas, Lista <Anticuerpo>* lista_anticuerpos){
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
      procesar_archivo(archivo, dato, lista_dosis_a, lista_dosis_b, lista_celulas, lista_anticuerpos);
   }


   //Cierro el archivo
   archivo.close();
}

//Funcion para procesar los datos del archivo
void procesar_archivo(ifstream &archivo, string &dato, Lista<Suero> *lista_dosis_a, Lista <Suero>* lista_dosis_b, Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos){
   float aux1, aux2;
   char aux3;
   int aux4;
   if(dato == "celula"){
      //Se crea objeto Celula
      archivo >> dato; //SALTEO EL IDENTIFICADOR NUMERICO
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
            //Se crea objeto Suero
            //aux3 es el tipo
            //aux4 es la cantidad
            archivo >> aux3;
            archivo >> aux4;
            if(aux3 == 'A'){
                for(int i=1; i<=aux4; i++){
                    lista_dosis_a -> extender(new Suero(aux3));
                }
                }else{
                    if(aux3 == 'B'){
                        for(int i=1; i<=aux4; i++){
                            lista_dosis_b -> extender(new Suero(aux3));
                        }
                    }
                }
         }else{
            if (dato == "filamento"){
                int indice_cel1;
                int indice_cel2;
                int peso;
                archivo >> indice_cel1;
                archivo >> indice_cel2;
                archivo >> peso;

                //Conectando Celula A con Celula B
                Celula* cel_aux = lista_celulas->obtener_puntero(indice_cel1);
                cel_aux->agregarAdyacente(indice_cel2);
                cel_aux->asignarPesoAdyacente(peso, cel_aux->obtenerCantidadAdyacentes());
                //Conectando Celula B con Celula A
                cel_aux = lista_celulas->obtener_puntero(indice_cel2);
                cel_aux->agregarAdyacente(indice_cel1);
                cel_aux->asignarPesoAdyacente(peso, cel_aux->obtenerCantidadAdyacentes());
            }
         }
       }
     }
}

void cruzar_celulas(Lista<Celula>* lista, Lista<int>* celulas_conectadas)
{
    int largo = celulas_conectadas->obtener_largo();

    //Creo matriz de pesos
    int pesos[largo][largo];
    for (int i = 0; i < largo; i++){
        for (int j = 0; j < largo; j++){
            if (i > j)
                pesos[i][j] = 1 + rand()%10;
        }
    }

    for (int i = 1; i <= largo; i++)
    {
        for (int j = 1; j <= largo; j++)
        {
            if (i != j){
                int peso;
                if (i > j)
                    peso = pesos[i-1][j-1];
                else
                    peso = pesos[j-1][i-1];
                lista->obtener_puntero(celulas_conectadas->obtener_valor(i))->agregarAdyacente(celulas_conectadas->obtener_valor(j), peso);

            }
        }
    }
}

void armado_red_grafica(SDL_Renderer* renderer, Lista<Celula>* lista_celulas){
    int largo = lista_celulas->obtener_largo();
    float x1, y1, x2, y2;


    for(int i=1; i<=largo; i++){
        Celula* cel_actual = lista_celulas->obtener_puntero(i);
        x1 = cel_actual->obtener_posicion_x();
        y1 = cel_actual->obtener_posicion_y();

        int cantAdyacentes = cel_actual->obtenerCantidadAdyacentes();

        for (int j = 1; j <= cantAdyacentes; j++){
            Celula* adyacente_actual = lista_celulas->obtener_puntero(cel_actual->obtenerAdyacente(j));
            x2 = adyacente_actual->obtener_posicion_x();
            y2 = adyacente_actual->obtener_posicion_y();

            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }

}

void revertir_celula(Lista<Celula>* lista_celulas, Lista<Suero>* lista_dosis_a, Nanobot* nanobot){
    int largo_dosis = lista_dosis_a->obtener_largo();
    int largo_celulas = lista_celulas->obtener_largo();

    int pos_dosis_x, pos_dosis_y, pos_celula_x, pos_celula_y;
    float distancia;
    char tipo;

    for(int i=1; i<=largo_dosis; i++){

        pos_dosis_x = (lista_dosis_a->obtener_puntero(i)->obtener_posicion_x());
        pos_dosis_y = (lista_dosis_a->obtener_puntero(i)->obtener_posicion_y());

        for(int j=1; j<=largo_celulas; j++){

                pos_celula_x = (lista_celulas->obtener_puntero(j)->obtener_posicion_x())-60;
                pos_celula_y = (lista_celulas->obtener_puntero(j)->obtener_posicion_y())-60;

                distancia = sqrt(((pos_celula_x - pos_dosis_x)*(pos_celula_x - pos_dosis_x))+((pos_celula_y - pos_dosis_y)*(pos_celula_y - pos_dosis_y)));

                tipo = lista_celulas->obtener_puntero(j)->obtener_tipo_celula();

                if(distancia <= 60){
                    switch(tipo){
                        case 'z':
                            {
                            Celula* cel_objetivo = lista_celulas->obtener_puntero(j);
                            Celula* revertida = new Celula_y(cel_objetivo->obtenerPosicionX(), cel_objetivo->obtenerPosicionY());

                            for (int i = 1; i <= cel_objetivo->obtenerCantidadAdyacentes(); i++)
                                revertida->agregarAdyacente(cel_objetivo->obtenerAdyacente(i));

                            lista_celulas->reemplazar(j, revertida);
                            }
                            break;
                        case 'y':
                            {
                            Celula* cel_objetivo = lista_celulas->obtener_puntero(j);
                            Celula* revertida = new Celula_x(cel_objetivo->obtenerPosicionX(), cel_objetivo->obtenerPosicionY());

                            for (int i = 1; i <= cel_objetivo->obtenerCantidadAdyacentes(); i++)
                                revertida->agregarAdyacente(cel_objetivo->obtenerAdyacente(i));

                            lista_celulas->reemplazar(j, revertida);
                            }
                            break;
                        case 'x':
                            {
                            Celula* cel_objetivo = lista_celulas->obtener_puntero(j);
                            Celula* revertida = new Celula_s(cel_objetivo->obtenerPosicionX(), cel_objetivo->obtenerPosicionY());

                            for (int i = 1; i <= cel_objetivo->obtenerCantidadAdyacentes(); i++)
                                revertida->agregarAdyacente(cel_objetivo->obtenerAdyacente(i));

                            lista_celulas->reemplazar(j, revertida);
                            }
                            break;
                        case 's':
                            reconectar_red(lista_celulas, j);
                            lista_celulas->borrar(j);
                            actualizar_adyacentes(lista_celulas, j);
                            nanobot->recalcular_mapa(j);
                            break;
                    }
                }
        }
    }
}

void evolucionar_celula(Lista<Celula>* lista_celulas, Lista<Suero>* lista_dosis_b){
    int largo_dosis = lista_dosis_b->obtener_largo();
    int largo_celulas = lista_celulas->obtener_largo();

    int pos_dosis_x, pos_dosis_y, pos_celula_x, pos_celula_y;
    float distancia;
    char tipo;

    for(int i=1; i<=largo_dosis; i++){

        pos_dosis_x = (lista_dosis_b->obtener_puntero(i)->obtener_posicion_x());
        pos_dosis_y = (lista_dosis_b->obtener_puntero(i)->obtener_posicion_y());

        for(int j=1; j<=largo_celulas; j++){

                pos_celula_x = (lista_celulas->obtener_puntero(j)->obtener_posicion_x())-60;
                pos_celula_y = (lista_celulas->obtener_puntero(j)->obtener_posicion_y())-60;

                distancia = sqrt(((pos_celula_x - pos_dosis_x)*(pos_celula_x - pos_dosis_x))+((pos_celula_y - pos_dosis_y)*(pos_celula_y - pos_dosis_y)));

                tipo = lista_celulas->obtener_puntero(j)->obtener_tipo_celula();

                if(distancia <= 60){
                    switch(tipo){
                        case 'z':
                            lista_celulas->obtener_puntero(j)->duplicar_celula(lista_celulas, tipo, j);
                            break;
                        case 'y':
                            {
                            Celula* cel_objetivo = lista_celulas->obtener_puntero(j);
                            Celula* revertida = new Celula_z(cel_objetivo->obtenerPosicionX(), cel_objetivo->obtenerPosicionY());

                            for (int i = 1; i <= cel_objetivo->obtenerCantidadAdyacentes(); i++)
                                revertida->agregarAdyacente(cel_objetivo->obtenerAdyacente(i));

                            lista_celulas->reemplazar(j, revertida);
                            }
                            break;
                        case 'x':
                            {
                            Celula* cel_objetivo = lista_celulas->obtener_puntero(j);
                            Celula* revertida = new Celula_y(cel_objetivo->obtenerPosicionX(), cel_objetivo->obtenerPosicionY());

                            for (int i = 1; i <= cel_objetivo->obtenerCantidadAdyacentes(); i++)
                                revertida->agregarAdyacente(cel_objetivo->obtenerAdyacente(i));

                            lista_celulas->reemplazar(j, revertida);
                            }
                            break;
                        case 's':
                            lista_celulas->obtener_puntero(j)->duplicar_celula(lista_celulas, tipo, j);
                            break;
                    }
                }
        }
    }
}

void reconectar_red(Lista<Celula>* lista_celulas, int punto_de_reconeccion)
{
    Lista<int>* grupo = new Lista<int>;

    Celula* desconexa = lista_celulas->obtener_puntero(punto_de_reconeccion);
    for (int adyacente = 1; adyacente <= desconexa->obtenerCantidadAdyacentes(); adyacente++){
        grupo->extender(new int(desconexa->obtenerAdyacente(adyacente)));
    }
    cruzar_celulas(lista_celulas, grupo);

    delete grupo;
}

void actualizar_adyacentes(Lista<Celula>* lista_celulas, int indice)
{
    Celula* cel_actual;

    for (int indice_actual = 1; indice_actual <= lista_celulas->obtener_largo(); indice_actual++){
        cel_actual = lista_celulas->obtener_puntero(indice_actual);
        int cant_adyacentes_actual = cel_actual->obtenerCantidadAdyacentes();
        int offset = 0;
        for (int num_ady_actual = 1; num_ady_actual <= cant_adyacentes_actual; num_ady_actual++){
            int adyacente_actual = cel_actual->obtenerAdyacente(num_ady_actual - offset);
            if (adyacente_actual == indice){
                cel_actual->removerAdyacente(num_ady_actual - offset);
                offset++;
            }
            if (adyacente_actual > indice){
                int peso_actual = cel_actual->obtenerPesoAdyacente(num_ady_actual - offset);
                cel_actual->removerAdyacente(num_ady_actual - offset);
                cel_actual->agregarAdyacente(adyacente_actual - 1, peso_actual);
                offset++;
            }
        }
    }
}

void infeccion_z(Lista<Celula>* lista_celulas)
{
    for (int indice = 1; indice <= lista_celulas->obtener_largo(); indice++)
    {
        Celula* cel_actual = lista_celulas->obtener_puntero(indice);
        cel_actual->contagiar(lista_celulas);
    }
}

bool estado_juego(Lista<Celula>* lista_celulas)
{
    int cant_cel_s = 0;
    int cant_cel_z = 0;
    for (int i = 1; i <= lista_celulas->obtener_largo(); i++){
        Celula* cel_actual = lista_celulas->obtener_puntero(i);
        if (cel_actual->obtener_tipo_celula() == 's')
            cant_cel_s++;
        if (cel_actual->obtener_tipo_celula() == 'z')
            cant_cel_z++;
    }

    bool jugando = cant_cel_s >= cant_cel_z;
    bool victoria = cant_cel_s >= lista_celulas->obtener_largo();
    if (jugando && victoria)
        cout<<endl<<endl<<"FELICITACIONES! GANASTE. SALVASTE AL SUJETO PERO FUISTE INFECTADO"<<endl<<"CON UNA MUTACION DEL VIRUS. TUS DIAS ESTAN CONTADOS..."<<endl<<endl<<endl;
    if (!jugando)
        cout<<endl<<endl<<"PERDISTE. POR CULPA DE TUS LENTAS MANOS EL SUJETO FALLECIO..."<<endl<<"SERAS DENUNCIADO POR MALA PRAXIS Y PROBABLEMENTE CONDENADO A PRISION."<<endl<<endl<<endl;
    return (jugando && !victoria);
}


void menu(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos, Lista<Suero>* lista_dosis_a, Lista<Suero>* lista_dosis_b, Nanobot* nanobot){
    int opcion;
    bool salir = true;

    cout << "Trabajo Practico n°4: Nanotecnologia" << endl;
    cout << "1- Iniciar Juego." << endl;
    cout << "2- Salir." << endl;

    do{
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:{
                juego = new Juego();

                lista_dosis_a = new Lista <Suero>;
                lista_dosis_b = new Lista <Suero>;
                lista_celulas = new Lista <Celula>;
                lista_anticuerpos = new Lista <Anticuerpo>;
                lectura(lista_dosis_a, lista_dosis_b, lista_celulas, lista_anticuerpos);
                //armado_red_celular(lista_celulas, 3, 1);
                nanobot = new Nanobot(100, 300, lista_celulas);

                juego->iniciar("TP3", 100, 100, 0);
                juego->correr(lista_celulas, lista_anticuerpos, lista_dosis_a, lista_dosis_b, nanobot);
                juego->limpiar();

                delete nanobot;
                delete lista_dosis_a;
                delete lista_dosis_b;
                delete lista_celulas;
                delete lista_anticuerpos;
            }
                break;
            case 2:{
                salir = false;
                cout << endl << endl;
                system("read -p 'Presione enter para continuar...' var");
            }
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                system("read -p 'Presione enter para continuar...' var");
        }
    }while(salir);

    delete juego;
}
