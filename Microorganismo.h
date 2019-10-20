#ifndef MICROORGANISMO_H_INCLUDED
#define MICROORGANISMO_H_INCLUDED
#include "Elemento.h"

class Microorganismo : public Elemento{
   //atributos
   protected:
     float posicion_x;
     float posicion_y;

   //Metodos
   public:
     //Setters
     //PRE: numero real entre 0 y 1000
     //POS: asigna la posicion en x
     void asignarPosicionX(float);

     //PRE: numero real entre 0 y 600
     //POS: asigna la posicion en y
     void asignarPosicionY(float);

     //Getters
     //PRE: -
     //POS: devuelve la posicion en x
     float obtenerPosicionX();

     //PRE: -
     //POS: devuelve la posicion en y
     float obtenerPosicionY();

     //Mostrar
     //PRE:-
     //POS: Imprime los datos por pantalla
     virtual void mostrar();

     //Constructor sin parametors
     Microorganismo();

     //Constructor con parametros
     Microorganismo(float, float);

     //Destructor
     virtual ~Microorganismo();
};

#endif // MICROORGANISMO_H_INCLUDED
