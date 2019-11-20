#ifndef ANTICUERPO_H_INCLUDED
#define ANTICUERPO_H_INCLUDED
#include "Microorganismo.h"

enum Direccion{ARRIBA,ABAJO,DERECHA,IZQUIERDA,LIBRE};

class Anticuerpo : public Microorganismo{
  private:

      bool capturado;
      Direccion direccion;

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

    void asignar_direccion(Direccion);

    Direccion obtener_direccion();

    //Destructor
    ~Anticuerpo();
};

#endif // ANTICUERPO_H_INCLUDED
