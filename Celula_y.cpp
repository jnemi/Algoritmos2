#include "Celula_y.h"

//Constructor sin parametros
Celula_y::Celula_y() : Celula(){
  porcentajeInflamacion = 0;
}

//Constructor con parametros
Celula_y::Celula_y(float x, float y) : Celula(x, y){
    tipo = 'y';
}

//Destructor
Celula_y::~Celula_y(){
  //cout << "Destruyendo Celula Y -> ";
}

//Setter
void Celula_y::asignarPorcentajeInflamacion(float i){
  porcentajeInflamacion = i;
}

//Getter
float Celula_y::obtenerPorcentajeInflamacion(){
  return porcentajeInflamacion;
}

//Mostrar
void Celula_y::mostrar(){
  cout << "Celula Y:" << endl;
  Celula::mostrar();
  cout << "Porcentaje de inflamacion: " << obtenerPorcentajeInflamacion() << "%" << endl;
}
