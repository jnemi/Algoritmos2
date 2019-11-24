#include "Reloj.h"


Reloj::Reloj(unsigned int duracion)
{
    duracion_ciclo = duracion;
    cronometro = 0;
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
        //
    }

    //FIN DE ACCIONES DEL RELOJ

    return cronometro;
}
