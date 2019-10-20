#include "Anticuerpo.h"

//Constructor sin parametros
Anticuerpo::Anticuerpo() : Microorganismo(){
}

//Constructor con parametros
Anticuerpo::Anticuerpo(float x, float y) : Microorganismo(x, y){
}

//Destructor
Anticuerpo::~Anticuerpo(){
  cout << "Destruyendo Anticuerpo -> ";
}

//Setters
void Anticuerpo::asignarPosicionX(float x){
  posicion_x = x;
}

void Anticuerpo::asignarPosicionY(float y){
  posicion_y = y;
}

//Getters
float Anticuerpo::obtenerPosicionX(){
  return posicion_x;
}

float Anticuerpo::obtenerPosicionY(){
  return posicion_y;
}

//Mostrar
void Anticuerpo::mostrar(){
  cout << "Anticuerpo:" << endl;
  Microorganismo::mostrar();
}
