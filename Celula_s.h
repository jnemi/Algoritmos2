#ifndef CELULA_S_H_INCLUDED
#define CELULA_S_H_INCLUDED
#include "Celula.h"

class Celula_s : public Celula{
   //Atributos
   private:
   //Metodos
   public:
       //Mostrar
       //PRE: -
       //POS: Imprime los datos por pantalla
       void mostrar();

       //Constructor sin parametros
       Celula_s();

       //Constructor con parametros
       Celula_s(float, float, unsigned int, unsigned int, string, bool);

       //Destructor
       ~Celula_s();
};

#endif // CELULA_S_H_INCLUDED
