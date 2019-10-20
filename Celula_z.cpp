#include "Celula_z.h"

//Constructor sin parametros
Celula_z::Celula_z() : Celula(){
  porcentajeMutacion = 0;
}

//Constructor con parametros
Celula_z::Celula_z(float x, float y, unsigned int e, unsigned int p, string m, bool u, float pm) : Celula(x, y, e, p, m, u){
  porcentajeMutacion = pm;
}

//Destructor
Celula_z::~Celula_z(){
  cout << "Destruyendo Celula Z -> ";
}

//Setter
void Celula_z::asignarPorcentajeMutacion(float pm){
  porcentajeMutacion = pm;
}

//Getter
float Celula_z::obtenerPorcentajeMutacion(){
  return porcentajeMutacion;
}

//Mostrar
void Celula_z::mostrar(){
  cout << "Celula Z:" << endl;
  Celula::mostrar();
  cout << "Porcentaje de mutacion: " << obtenerPorcentajeMutacion() << "%" << endl;
}
