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
    Nodo(Objeto*);
    ~Nodo();
    void asignar_valor(Objeto*);
    void asignar_siguiente(Nodo<Objeto>*);
    void asignar_anterior(Nodo<Objeto>*);
    Objeto& obtener_valor();
    Nodo<Objeto>* obtener_siguiente();
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
    cout<<"Nodo eliminado"<<endl;
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
