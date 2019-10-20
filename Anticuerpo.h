#ifndef ANTICUERPO_H_INCLUDED
#define ANTICUERPO_H_INCLUDED
#include "Microorganismo.h"

class Anticuerpo : public Microorganismo{
  public:
    //Setters
    //PRE: Recibir dato valido
    //POS: Asigna valor a la posicion en x
    void asignarPosicionX(float);

    //PRE: Recibir dato valido
    //POS: Asigna valor a la posicion en y
    void asignarPosicionY(float);

    //Getters
    //PRE: -
    //POS: Devuelve la posicion en x
    float obtenerPosicionX();

    //PRE: -
    //POS: Devuelve la posicion en y
    float obtenerPosicionY();

    //Mostrar
    //PRE: -
    //POS: Imprime los datos por pantalla
    void mostrar();

    //Constructor sin parametros
    Anticuerpo();

    //Constructor con parametros
    Anticuerpo(float, float);

    //Destructor
    ~Anticuerpo();
};

#endif // ANTICUERPO_H_INCLUDED
