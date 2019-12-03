#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    heap h;
    h.agregar_persona("Carlos",23);
    h.agregar_persona("Jose",14);
    h.agregar_persona("Raul",12);
    h.agregar_persona("Pedro",7);
    h.agregar_persona("DDD",12);
    h.agregar_persona("GGG",12);
    h.mostrar();
    h.desencolar_uno();
    h.desencolar_uno();
    h.desencolar_uno();
    h.desencolar_uno();
    h.desencolar_uno();
    h.desencolar_uno();
    h.desencolar_uno();
    h.mostrar();
    return 0;
}
