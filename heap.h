#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <iostream>
using namespace std;

const int MAXIMO = 50;
struct Dato{
    string nombre;
    int prioridad;
};

class heap
{
    public:
        heap();
        virtual ~heap();
        void mostrar();
        void agregar_persona(string nombre, int prioridad);
        void desencolar_uno();
    private:
        Dato vecPersonas[MAXIMO];
        unsigned cantidadPersonas;
        void insertar_en_vector(Dato datosPersona);
        void cambiar(unsigned padre, unsigned hijo);
        bool tiene_hijo_izquierdo(unsigned padre);
        bool tiene_hijo_derecho(unsigned padre);
        unsigned posicion_hijo_izquierdo(unsigned padre);
        unsigned posicion_hijo_derecho(unsigned padre);
        Dato hijo_izquierdo(unsigned padre);
        Dato hijo_derecho(unsigned padre);

};

#endif // HEAP_H
