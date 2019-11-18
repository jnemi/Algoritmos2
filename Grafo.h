#ifndef GRAFO_H
#define GRAFO_H

#include "datos_de_aeropuerto.h"
#include <string>
#include <iostream>
#include <Celula.h>

using namespace std;

class Vertice;
class Arista;

class Vertice
{
    Microorganismo*     microorganismo;
    Vertice*            siguienteVertice; // Lista de nodos
    Arista*             aristaAdyacente;
    friend class Grafo;
};

class Arista
{
    Arista*     siguienteArista; // Lista de aristas
    Vertice*    verticeAdyacente;
    friend class Grafo;
};

class Grafo
{
    private:
        Vertice* ptrPrimerVertice;
    public:
        Grafo();
        bool        vacio();
        int         tamano();
        Vertice*    getPtrVertice(float, float);
        void        insertarArista(Vertice*, Vertice*);
        void        insertarVertice(Microorganismo*);
        void        eliminarArista(Vertice*, Vertice*);
        void        eliminarVertice(Vertice*);
        void        sacarNodo(Vertice*);
        void        informacionMicroorganismo(float, float);
        void        mostrarMicroorganismoEntrantes(Vertice*);
        void        mostrarMicroorganismosSalientes(Arista*);
        void        imprimirDatosMicroorganismos(Microorganismo*);
        void        listaMicroorganismos();
        int         getNumeroVertice(Vertice*);
};

Grafo::Grafo()
{
    ptrPrimerVertice = NULL;
}

bool Grafo::vacio()
{
    return ( ptrPrimerVertice == NULL );
}

int Grafo::tamano()
{
    int contador = 0;
    Vertice* verticeAuxiliar;
    verticeAuxiliar = ptrPrimerVertice;
    while (verticeAuxiliar != NULL)
    {
        contador++;
        verticeAuxiliar = verticeAuxiliar->siguienteVertice;
    }
    return contador;
}

Vertice* Grafo::getPtrVertice(float coordenadaX, float coordenadaY)
{
    Vertice* actual;
    actual = ptrPrimerVertice;
    while(actual != NULL)
    {
        if ( ( actual->microorganismo->obtenerPosicionX == coordenadaX ) && (actual->microorganismo->obtenerPosicionY) == coordenadaY )
            return actual;
        actual = actual->siguienteVertice;
    }
    return NULL;
}

void Grafo::insertarVertice( Microorganismo* microorganismo )
{
    Vertice* nuevoVertice = new Vertice();
    nuevoVertice->microorganismo = microorganismo;
    nuevoVertice->siguienteVertice = NULL;
    nuevoVertice->aristaAdyacente = NULL;

    if ( vacio() )
        ptrPrimerVertice = nuevoVertice;
    else
    {
        Vertice* verticeAuxiliar;
        verticeAuxiliar = ptrPrimerVertice;
        while(verticeAuxiliar->siguienteVertice != NULL)
            verticeAuxiliar = verticeAuxiliar->siguienteVertice;
        verticeAuxiliar->siguienteVertice = nuevoVertice;
    }
}

void Grafo::insertarArista( Vertice* origen, Vertice* destino)
{
    Arista* nuevaArista = new Arista();
    nuevaArista->siguienteArista = NULL;
    nuevaArista->verticeAdyacente = NULL;

    Arista* aristaAuxiliar; // crea una arista auxiliar para recorrer la lista de aristas
    aristaAuxiliar = origen->aristaAdyacente; // la posiciona en la primera posicion de la lista

    if (aristaAuxiliar == NULL)// si el vertice no tenia ninguna arista, nuevaArista pasa a ser la primera
        origen->aristaAdyacente = nuevaArista;
    else// si no pega la ultima arista al final de la lista de aristas
    {
        while ( aristaAuxiliar->siguienteArista != NULL)
            aristaAuxiliar = aristaAuxiliar->siguienteArista;
        aristaAuxiliar->siguienteArista = nuevaArista;
    }
    nuevaArista->verticeAdyacente = destino;
}

void Grafo::eliminarArista(Vertice* origen, Vertice* destino)
{
    Arista* actual;

    actual = origen->aristaAdyacente; // "actual" es la primera arista de la lista de aristas de un vertice

    if (actual == NULL) // Caso en que el vertice origen no tiene aristas
        return;
    else
    {
        if (actual->verticeAdyacente == destino) // Caso en que la primera arista de la lista (de aristas) conecta al vertice de destino
        {
            origen->aristaAdyacente = actual->siguienteArista; // Conecta al vertice de origen directamente con la segunda arista de la lista
            delete actual; // Y borra la arista que los conectaba
        }
        else // Caso en que la arista a borrar se encuentra entre medio de de lista de aristas
        {
            bool encontrado = false;
            Arista* anterior;

            while (actual != NULL && encontrado == false) // si llego al final de la lista de aristas o encuentro la arista que busco, salgo del bucle
            {
                if (actual->verticeAdyacente == destino)
                {
                    anterior->siguienteArista = actual->siguienteArista;
                    delete actual;
                    encontrado = true;
                }
                anterior = actual;
                actual = actual->siguienteArista;
            }
        }// si no encontre la arista que une esos 2 nodos, es porque no existe
    }
}

void Grafo::eliminarVertice(Vertice* verticeEliminar)
{
    /*Recorro la lista de vertices, por cada uno accedo a sus aristas adyacentes, cuando encuentro una que lo conecte con el nodo
    a eliminar elimino esa arista, asi con todos los vertices. Cuando toca revisar la lista de aristas del vertice a eliminar, salto
    ese ciclo y avanzo al siguiente vertice.*/

    Vertice* actual;
    Arista* aristaAuxiliar;
    bool encontrado = false;

    actual = ptrPrimerVertice;

    while (actual != NULL) // mientras no llege al final de la lista de nodos
    {
        if (actual != verticeEliminar)
        {
            encontrado = false;
            aristaAuxiliar = actual->aristaAdyacente; // toma la primera arista de la lista de aristas
            while(aristaAuxiliar != NULL && encontrado == false) // mientras no llege al final de la lista de aristas y no se haya encontrado el vertice a eliminar
            {
                if (aristaAuxiliar->verticeAdyacente == verticeEliminar)
                {
                    eliminarArista(actual, verticeEliminar);
                    encontrado = true; // salgo del ciclo porque no va a haber otra arista que conecte a esos nodos
                }
                aristaAuxiliar = aristaAuxiliar->siguienteArista;
            }
        }
        actual = actual->siguienteVertice;
    }
    // Una vez elimine todas las aristas que llegan al vertice a eliminar, elimino las aristas que salen del vertice
    while(verticeEliminar->aristaAdyacente != NULL)
        eliminarArista(verticeEliminar, verticeEliminar->aristaAdyacente->verticeAdyacente);//borra siempre la primera arista

    sacarNodo(verticeEliminar);
}

void Grafo::sacarNodo(Vertice* verticeEliminar)
{
    Vertice* actual;
    actual = ptrPrimerVertice; // lo vuelvo a iniciar en el primer nodo del grafo
    if (verticeEliminar == actual) // Caso en que el vertice a eliminar sea el primer vertice que ingrese
    {
        actual = actual->siguienteVertice;
        delete(actual);
    }
    else
    {
        Vertice* anterior;
        while(actual != verticeEliminar) // se detiene cuando actual es el vertice a eliminar
        {
            anterior = actual;
            actual = actual->siguienteVertice;
        }
        anterior->siguienteVertice = actual->siguienteVertice;
        delete(actual);
    }
}

void Grafo::informacionMicroorganismo(float coordenadaX, float coordenadaY)
{
    Vertice* vertice;
    vertice = getPtrVertice(coordenadaX, coordenadaY);
    if (microorganismo)
    {
        cout << "Celulas entrantes a " << vertice->microorganismo->mostrar() << endl;
        mostrarMicroorganismoEntrantes(vertice);
        cout << endl;
        cout << "Celulas salientes de " << vertice->microorganismo->mostrar() << endl;
        mostrarMicroorganismosSalientes(vertice->aristaAdyacente);
        cout << endl;
    }
    else
    {
        cout << "No existe ese microorganismo " << endl;
    }

}

void Grafo::mostrarMicroorganismoEntrantes(Vertice* vertice)
{
    Vertice* actual;
    Arista* aristaAuxiliar;
    bool encontrado;
    int contador =1;

    actual = ptrPrimerVertice;

    while (actual) // mientras no llege al final de la lista de nodos
    {
        encontrado = false;
        if (actual != vertice) // asi, si es igual salta al siguiente vertice
        {
            aristaAuxiliar = actual->aristaAdyacente; // toma la primera arista de la lista de aristas
            while(aristaAuxiliar != NULL && encontrado == false) // mientras no llege al final de la lista de aristas y no se haya encontrado el microorganismo
            {
                if (aristaAuxiliar->verticeAdyacente == vertice)
                {
                    cout << contador << ") ";
                    imprimirDatosMicroorganismos(actual->microorganismo);
                    encontrado = true; // salgo del ciclo porque no va a haber otra arista que conecte a esos microorganismos
                    contador++;
                }
                aristaAuxiliar = aristaAuxiliar->siguienteArista;
            }
        }
        actual = actual->siguienteVertice;
    }
}

void Grafo::mostrarMicroorganismosSalientes(Arista* auxiliar)
{
    Microorganismo* microorganismo;
    int contador = 1;
    while (auxiliar != NULL)
    {
        microorganismo = auxiliar->verticeAdyacente->microorganismo;
        cout << contador << ") ";
        imprimirDatosMicroorganismos(microorganismo);
        auxiliar = auxiliar->siguienteArista;
        contador++;
    }
}

void Grafo::imprimirDatosMicroorganismos(Microorganismo* microorganismo)
{
    cout << microorganismo->mostrar()endl;
}

void Grafo::listaMicroorganismos()
{
    Vertice* actual;
    actual = ptrPrimerVertice;
    cout << "Microorganismos agregados: " << endl << endl;
    while (actual != NULL)
    {
        cout << actual->microorganismo->mostrar() << endl;
        actual = actual->siguienteVertice;
    }
    cout << endl;
}

int Grafo::getNumeroVertice(Vertice* vertice)
{
    Vertice* actual;
    int contador = 1;

    actual = ptrPrimerVertice;
    while(actual != vertice)
    {
        contador++;
        actual = actual->siguienteVertice;
    }
    return contador;
}

#endif
