#ifndef ELEMENTO_H_INCLUDED
#define ELEMENTO_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Elemento{
   //Metodos
   public:
     //mostrar
     //PRE:-
     //POS: Imprime los datos por pantalla
     virtual void mostrar();

     //constructor
     Elemento();

     //Destructor
     virtual ~Elemento();
};

#endif // ELEMENTO_H_INCLUDED
