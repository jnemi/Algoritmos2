#include "heap.h"

heap::heap()
{
    cantidadPersonas = 0;
}

heap::~heap()
{
    //dtor
}

void heap::mostrar()
{
    cout << "Cantidad de personas: "<<this->cantidadPersonas<<endl<<endl;
    for (unsigned i = 0; i < cantidadPersonas; i++)
    {
        cout<<"Persona numero: "<<i+1<<endl;
        cout<<"Nombre: "<<vecPersonas[i].nombre<<endl;
        cout<<"Prioridad: "<<vecPersonas[i].prioridad<<endl<<endl;
    }
}

void heap::agregar_persona(string nombre,int prioridad)
{
    Dato datosPersona;
    datosPersona.nombre = nombre;
    datosPersona.prioridad = prioridad;
    insertar_en_vector(datosPersona);
    cantidadPersonas++;

}

void heap::insertar_en_vector(Dato datosPersona)
{
    vecPersonas[cantidadPersonas] = datosPersona;  //Agrego el dato al final del vector SIEMPRE!
    unsigned padre = (cantidadPersonas-1)/2; //calculo las posiciones logicas de padre e hijo
    unsigned hijo = cantidadPersonas;
    bool salir = false;
    while ( vecPersonas[padre].prioridad > vecPersonas[hijo].prioridad && (salir == false) )//si son iguales no hace cambios en el vector
    {
        if (hijo != 0)
        {
            cambiar(padre, hijo);
            hijo = padre;
            padre = (hijo-1)/2;
        }
        else
            salir = true;
    }
}

void heap::cambiar(unsigned padre, unsigned hijo)
{
    Dato auxiliar;
    auxiliar = vecPersonas[hijo];
    vecPersonas[hijo] = vecPersonas[padre];
    vecPersonas[padre] = auxiliar;
}

void heap::desencolar_uno()
{
    if (cantidadPersonas > 0)
    {
        cout << "Sacando de la lista a: " << vecPersonas[0].nombre << "  /prioridad: " << vecPersonas[0].prioridad << endl;
        vecPersonas[0] = vecPersonas[cantidadPersonas-1];
        cantidadPersonas--;
        unsigned padre = 0;
        bool salir = false;
        while ( tiene_hijo_izquierdo(padre) && salir == false )
        {
            unsigned menor = posicion_hijo_izquierdo(padre);
            if ( (tiene_hijo_derecho(padre)) && (hijo_derecho(padre).prioridad < hijo_izquierdo(padre).prioridad) )//en caso que sean iguales le paso el izquierdo, que sé que fue el primero en agregarse
                menor = posicion_hijo_derecho(padre);
            if ( vecPersonas[padre].prioridad < vecPersonas[menor].prioridad )//si compara y se da cuenta que no puede seguir bajando porque la prioridad del hijo no es menor o igual al padre sale del bucle
                salir = true;
            else
                cambiar(padre, menor);
            padre = menor;
        }
    }
    else
        cout << "Cola vacia" << endl;
}

bool heap::tiene_hijo_izquierdo(unsigned padre)
{
    return ( posicion_hijo_izquierdo(padre) < cantidadPersonas );
}

bool heap::tiene_hijo_derecho(unsigned padre)
{
    return ( posicion_hijo_derecho(padre) < cantidadPersonas );
}

unsigned heap::posicion_hijo_izquierdo(unsigned padre)
{
    return (2*padre)+1;
}

unsigned heap::posicion_hijo_derecho(unsigned padre)
{
    return (2*padre)+2;
}

Dato heap::hijo_izquierdo(unsigned padre)
{
    return vecPersonas[posicion_hijo_izquierdo(padre)];
}

Dato heap::hijo_derecho(unsigned padre)
{
    return vecPersonas[posicion_hijo_derecho(padre)];
}
