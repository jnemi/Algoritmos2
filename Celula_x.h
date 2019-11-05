#ifndef CELULA_X_H_INCLUDED
#define CELULA_X_H_INCLUDED
#include "Celula.h"

class Celula_x : public Celula{
   //Atributos
   private:
       float porcentajeInflamacion;
   //Metodos
   public:
       //Setters
       //PRE: Recibir dato valido
       //POS: Asigna valor a porcentajeInflamacion
       void asignarPorcentajeInflamacion(float);

       //Getters
       //PRE: -
       //POS: Devuelve el porcentaje de inflamacion
       float obtenerPorcentajeInflamacion();

       //Mostrar
       //PRE: -
       //POS: Imprime los datos por pantalla
       void mostrar();

       //Constructor sin parametros
       Celula_x();

       //Constructor con parametros
       Celula_x(float, float);

       //Destructpr
       ~Celula_x();
};


#endif // CELULA_X_H_INCLUDED
