#ifndef CELULA_Y_H_INCLUDED
#define CELULA_Y_H_INCLUDED
#include "Celula.h"

class Celula_y : public Celula{
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
       Celula_y();

       //Constructor con parametros
       Celula_y(float, float, unsigned int, unsigned int, string, bool, float);

       //Destructor
       ~Celula_y();
};

#endif // CELULA_Y_H_INCLUDED
