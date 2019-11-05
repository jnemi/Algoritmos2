#include "Celula_s.h"

//Constructor sin parametros
Celula_s::Celula_s() : Celula(){
}

//Constructor con parametros
Celula_s::Celula_s(float x, float y) : Celula(x, y){
}

//Destructor
Celula_s::~Celula_s(){
  //cout << "Destruyendo Celula S -> ";
}
//Mostrar
void Celula_s::mostrar(){
  cout << "Celula S:" << endl;
  Celula::mostrar();
}
