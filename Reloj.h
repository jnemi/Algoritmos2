#ifndef RELOJ_H_INCLUDED
#define RELOJ_H_INCLUDED
#include "Lista.h"
#include "Celula.h"

class Reloj
{
private:
    unsigned int cronometro;
    unsigned int duracion_ciclo;
    Lista<Celula>* lista_celulas;

    bool acciones_por_ciclo(unsigned int);

public:

    //Constructor
    //PRE: Recibe la duracion por ciclo del reloj
    Reloj(unsigned int);

    //PRE: -
    //POS: Incrementa el cronometro e inicia las acciones correspondientes
    unsigned int tick();

    void asignar_referencia_lista_celulas(Lista<Celula>*);
};

#endif // RELOJ_H_INCLUDED
