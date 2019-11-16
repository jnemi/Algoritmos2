#ifndef ANTICUERPO_H_INCLUDED
#define ANTICUERPO_H_INCLUDED
#include "Microorganismo.h"

class Anticuerpo : public Microorganismo{
  public:
    //Mostrar
    //PRE: -
    //POS: Imprime los datos por pantalla
    void mostrar();

    //Constructor sin parametros
    Anticuerpo();

    //Constructor con parametros
    Anticuerpo(float, float);

    //Getters
    float obtener_posicion_x();

    float obtener_posicion_y();

    //Destructor
    ~Anticuerpo();
};

#endif // ANTICUERPO_H_INCLUDED
