#include "Celula_s.h"

//Constructor sin parametros
Celula_s::Celula_s() : Celula(){
}

//Constructor con parametros
Celula_s::Celula_s(float x, float y, unsigned int e, unsigned int p, string m, bool u) : Celula(x, y, e, p, m, u){
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
