#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

using namespace std;

template <typename Objeto>

class Nodo
{
private:
    Nodo<Objeto>* siguiente;
    Nodo<Objeto>* anterior;
    Objeto* valor;
public:

    //PRE: Recibe un puntero a un objeto en el heap
    //POS: Asigna el puntero al valor del Nodo
    Nodo(Objeto*);

    //PRE: El valor del Nodo debe apuntar a una direccion valida
    //POS: Libera el espacio de memoria asignado al objeto al que apunta
    ~Nodo();

    //PRE: Recibe un puntero a un objeto en el heap
    //POS: Asigna el ountero al valor del Nodo
    void asignar_valor(Objeto*);

    //PRE: Recibe un puntero a un Nodo (del mismo tipo) en el heap
    //PRE: Asigna el Nodo siguiente
    void asignar_siguiente(Nodo<Objeto>*);

    //PRE: Recibe un puntero a un Nodo (del mismo tipo) en el heap
    //PRE: Asigna el Nodo anterior
    void asignar_anterior(Nodo<Objeto>*);

    //PRE: El valor del Nodo debe apuntar a una direccion valida
    //POS: Devuelve el objeto al que apunta el Nodo por referencia
    Objeto& obtener_valor();

    //PRE: El valor del Nodo debe apuntar a una direccion valida
    //POS: Devuelve la direccion de memoria del objeto al que apunta el Nodo
    Objeto* obtener_puntero();

    //PRE: -
    //POS: Devuelve la direccion de memoria del siguiente Nodo
    Nodo<Objeto>* obtener_siguiente();

    //PRE: -
    //POS: Devuelve la direccion de memoria del Nodo anterior
    Nodo<Objeto>* obtener_anterior();
};

template <typename Objeto>
Nodo<Objeto>::Nodo(Objeto* obj)
{
    asignar_valor(obj);
}

template <typename Objeto>
Nodo<Objeto>::~Nodo()
{
    delete valor;
    //cout<<"Nodo eliminado"<<endl;
}

template <typename Objeto>
void Nodo<Objeto>::asignar_valor(Objeto* objeto_apuntado)
{
    valor = objeto_apuntado;
}

template <typename Objeto>
void Nodo<Objeto>::asignar_siguiente(Nodo<Objeto>* nodo_apuntado)
{
    siguiente = nodo_apuntado;
}

template <typename Objeto>
void Nodo<Objeto>::asignar_anterior(Nodo<Objeto>* nodo_apuntado)
{
    anterior = nodo_apuntado;
}

template <typename Objeto>
Objeto& Nodo<Objeto>::obtener_valor()
{
    return *(valor);
}

template <typename Objeto>
Objeto* Nodo<Objeto>::obtener_puntero()
{
    return valor;
}

template <typename Objeto>
Nodo<Objeto>* Nodo<Objeto>::obtener_siguiente()
{
    return siguiente;
}

template <typename Objeto>
Nodo<Objeto>* Nodo<Objeto>::obtener_anterior()
{
    return anterior;
}
#endif // NODO_H_INCLUDED
