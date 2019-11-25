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
    //PRE: Recibir dato valido
    //POS: Asigna verdadero en caso de tener un anticuerpo capturado y falso en caso contrario
    void capturar(bool);
    //PRE: Recibir dato valido
    //POS: Asigna la direccion
    void asignar_direccion(Direccion);

    //Getters
    //PRE: -
    //POS: Decuelve la posicion en x
    float obtener_posicion_x();
    //PRE: -
    //POS: Decuelve la posicion en y
    float obtener_posicion_y();
    //PRE: -
    //POS: Devuelve verdadero en caso de tener un anticuerpo capturado
    bool obtener_capturado();
    //PRE: -
    //POS: Devuelve la direccion
    Direccion obtener_direccion();

    //Destructor
    ~Anticuerpo();
};

#endif // ANTICUERPO_H_INCLUDED
