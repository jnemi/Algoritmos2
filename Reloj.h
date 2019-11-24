#ifndef RELOJ_H_INCLUDED
#define RELOJ_H_INCLUDED

class Reloj
{
private:
    unsigned int cronometro;
    unsigned int duracion_ciclo;

    bool acciones_por_ciclo(unsigned int);

public:

    //Constructor
    //PRE: Recibe la duracion por ciclo del reloj
    Reloj(unsigned int);

    //PRE: -
    //POS: Incrementa el cronometro e inicia las acciones correspondientes
    unsigned int tick();
};

#endif // RELOJ_H_INCLUDED
