#include "Celula_z.h"

//Constructor sin parametros
Celula_z::Celula_z() : Celula(){
  porcentajeMutacion = 0;
}

//Constructor con parametros
Celula_z::Celula_z(float x, float y) : Celula(x, y){
    tipo = 'z';
}

//Destructor
Celula_z::~Celula_z(){
  //cout << "Destruyendo Celula Z -> ";
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
