#include "Reloj.h"
#include "funciones.h"


Reloj::Reloj(unsigned int duracion)
{
    duracion_ciclo = duracion;
    cronometro = 0;
}

void Reloj::asignar_referencia_lista_celulas(Lista<Celula>* referencia)
{
    lista_celulas = referencia;
}

bool Reloj::acciones_por_ciclo(unsigned int cant_acciones)
{
    int ticks_por_accion = duracion_ciclo / cant_acciones;
    //cronometro mod ticks por accion
    return 0 == (cronometro - (cronometro / ticks_por_accion) * ticks_por_accion);
}

unsigned int Reloj::tick()
{
    cronometro++;
    if (cronometro >= duracion_ciclo)
        cronometro = 0;

    //INICIO DE ACCIONES DEL RELOJ

    if (acciones_por_ciclo(5))
    {
        infeccion_z(lista_celulas);
    }

    if (acciones_por_ciclo(7))
    {
        for(int j=1; j<=lista_celulas->obtener_largo(); j++){
            char tipo = lista_celulas->obtener_puntero(j)->obtener_tipo_celula();
            if (tipo == 'y')
                lista_celulas->obtener_puntero(j)->asignar_tipo('z');
        }
    }

    if (acciones_por_ciclo(2))
    {
        for(int j=1; j<=lista_celulas->obtener_largo(); j++){
            char tipo = lista_celulas->obtener_puntero(j)->obtener_tipo_celula();
            if (tipo == 'x')
                lista_celulas->obtener_puntero(j)->asignar_tipo('y');
        }
    }

    //FIN DE ACCIONES DEL RELOJ

    return cronometro;
}
