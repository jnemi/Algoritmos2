#include "Suero.h"

//Constructor sin parametros
Suero::Suero() : Elemento(){
  tipo = '-';
  cantDosis = 0;
}

//Constructor con parametros
Suero::Suero(char t, unsigned int c) : Elemento(){
  tipo = t;
  cantDosis = c;
}

//Destructor
Suero::~Suero(){
  cout << "Destruyendo Suero -> ";
}

//Setters
void Suero::asignarTipo(char t){
  tipo = t;
}

void Suero::asignarCantDosis(unsigned int c){
  cantDosis = c;
}

//Getters
char Suero::obtenerTipo(){
  return tipo;
}

unsigned int Suero::obtenerCantDosis(){
  return cantDosis;
}

//Mostrar
void Suero::mostrar(){
  cout << "Suero:" << endl;
  Elemento::mostrar();
  cout << "Tipo: " << obtenerTipo() << endl;
  cout << "Dosis: " << obtenerCantDosis() << endl;
}
