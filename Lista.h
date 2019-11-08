#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"

template <typename Objeto>

class Lista
{
private:
    Nodo<Objeto>* primero;
    Nodo<Objeto>* ultimo;
    int largo;
public:
    Lista();
    ~Lista();
    int obtener_largo();
    bool lista_vacia();
    void insertar(Objeto*, int);
    void insertar(Objeto*, Nodo<Objeto>*);
    void extender(Objeto*);
    void borrar(int);
    void borrar(Nodo<Objeto>*);
    Nodo<Objeto>* buscar_nodo(int);
    Objeto& obtener_valor(int);
};

template <typename Objeto>
Lista<Objeto>::Lista()
{
    largo = 0;
}

template <typename Objeto>
Lista<Objeto>::~Lista()
{
    while (!lista_vacia())
        borrar(primero);
}

template <typename Objeto>
int Lista<Objeto>::obtener_largo()
{
    return largo;
}

template <typename Objeto>
bool Lista<Objeto>::lista_vacia()
{
    return (largo <= 0);
}

template <typename Objeto>
void Lista<Objeto>::insertar(Objeto* obj, int indice)
{
    if ((0 < indice) && (indice <= largo))
        insertar(obj, buscar_nodo(indice));
    else
        delete obj;
}

template <typename Objeto>
void Lista<Objeto>::insertar(Objeto* obj, Nodo<Objeto>* aux)
{
    Nodo<Objeto>* nuevo_elemento = new Nodo<Objeto>(obj);
    if (lista_vacia()){
        primero = nuevo_elemento;
        ultimo = nuevo_elemento;
    }else if (aux == primero){
        nuevo_elemento->asignar_siguiente(primero);
        primero->asignar_anterior(nuevo_elemento);
        primero = nuevo_elemento;
    }else if(aux == ultimo){
        nuevo_elemento->asignar_anterior(ultimo);
        ultimo->asignar_siguiente(nuevo_elemento);
        ultimo = nuevo_elemento;
    }else{
        nuevo_elemento->asignar_siguiente(aux);
        nuevo_elemento->asignar_anterior(aux->obtener_anterior());
        nuevo_elemento->obtener_anterior()->asignar_siguiente(nuevo_elemento);
        nuevo_elemento->obtener_siguiente()->asignar_anterior(nuevo_elemento);
    }
    largo++;
}

template <typename Objeto>
void Lista<Objeto>::extender(Objeto* obj)
{
    Nodo<Objeto>* nuevo_elemento = new Nodo<Objeto>(obj);
    if (largo > 0){
        ultimo->asignar_siguiente(nuevo_elemento);
        nuevo_elemento->asignar_anterior(ultimo);
    }
    else{
        primero = nuevo_elemento;
    }
    ultimo = nuevo_elemento;
    largo++;
}

template <typename Objeto>
void Lista<Objeto>::borrar(int indice)
{
    borrar(buscar_nodo(indice));
}

template <typename Objeto>
void Lista<Objeto>::borrar(Nodo<Objeto>* nodo_tomado)
{
    if (!lista_vacia()){
        Nodo<Objeto>* aux = primero;
        if (largo <= 1){
            aux = nodo_tomado;
            primero = 0;
            ultimo = 0;
        }
        else if (nodo_tomado == primero){
            primero = aux->obtener_siguiente();
            primero->asignar_anterior(0);
        }
        else if (nodo_tomado == ultimo){
            aux = ultimo;
            ultimo = aux->obtener_anterior();
            ultimo->asignar_siguiente(0);
        }
        else{
            aux = nodo_tomado;
            aux->obtener_anterior()->asignar_siguiente(aux->obtener_siguiente());
            aux->obtener_siguiente()->asignar_anterior(aux->obtener_anterior());
        }
        delete aux;
        largo--;
    }
}

template <typename Objeto>
Nodo<Objeto>* Lista<Objeto>::buscar_nodo(int indice)
{
    Nodo<Objeto>* buscado;
    if (indice <= (largo/2)){
        buscado = primero;
        for (int i = 1; i < indice; i++)
            buscado = buscado->obtener_siguiente();
    }else{
        buscado = ultimo;
        for (int i = largo; i > indice; i--)
            buscado = buscado->obtener_anterior();
    }
    return buscado;
}

template <typename Objeto>
Objeto& Lista<Objeto>::obtener_valor(int indice)
{
    return buscar_nodo(indice)->obtener_valor();
}


#endif // LISTA_H_INCLUDED
