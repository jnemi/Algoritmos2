#ifndef ANTICUERPO_H_INCLUDED
#define ANTICUERPO_H_INCLUDED
#include "Microorganismo.h"

class Anticuerpo : public Microorganismo{
  private:

      bool capturado;
      bool disparado;

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

    void capturar(bool);

    bool obtener_capturado();

    void disparar(bool);

    bool obtener_disparado();

    //Destructor
    ~Anticuerpo();
};

#endif // ANTICUERPO_H_INCLUDED
