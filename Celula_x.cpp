#include "Celula_x.h"

//Constructor sin parametros
Celula_x::Celula_x() : Celula(){
  porcentajeInflamacion = 0;
}

//Constructor con parametros
Celula_x::Celula_x(float x, float y) : Celula(x, y){
}

//Destructor
Celula_x::~Celula_x(){
  //cout << "Destruyendo Celula X -> ";
}

//Setter
void Celula_x::asignarPorcentajeInflamacion(float i){
  porcentajeInflamacion = i;
}

//Getter
float Celula_x::obtenerPorcentajeInflamacion(){
  return porcentajeInflamacion;
}

//Mostrar
void Celula_x::mostrar(){
  cout << "Celula X:" << endl;
  Celula::mostrar();
  cout << "Porcentaje de inflamacion: " << obtenerPorcentajeInflamacion() << "%" << endl;
}
