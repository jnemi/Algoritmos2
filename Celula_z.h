#ifndef CELULA_Z_H_INCLUDED
#define CELULA_Z_H_INCLUDED
#include "Celula.h"
#include "Celula_x.h"
#include <stdlib.h>
#include <time.h>

class Celula_z : public Celula{
   //Atributos
   private:
       float porcentajeMutacion;
   //Metodos
   public:
       //Setters
       //PRE: Recibir dato valido
       //POS: Asigna valor a porcentajeInflamacion
       void asignarPorcentajeMutacion(float);

       //Getters
       //PRE: -
       //POS: Devuelve el porcentaje de inflamacion
       float obtenerPorcentajeMutacion();

       //Mostrar
       //PRE: -
       //POS: Imprime los datos por pantalla
       void mostrar();

       //PRE: Recibe la direccion de la lista de Celulas
       //POS: Contagia una o mas Celulas S adyacentes (si las hay)
       void contagiar(Lista<Celula>*);

       //Constructor sin parametros
       Celula_z();

       //Constructor con parametros
       Celula_z(float, float);

       //Destructor
       ~Celula_z();
};

#endif // CELULA_Z_H_INCLUDED
