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

    //Setters
    void capturar(bool);

    void asignar_direccion(Direccion);

    //Getters
    float obtener_posicion_x();

    float obtener_posicion_y();

    bool obtener_capturado();

    Direccion obtener_direccion();

    //Destructor
    ~Anticuerpo();
};

#endif // ANTICUERPO_H_INCLUDED
