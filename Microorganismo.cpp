#include "Microorganismo.h"

//Constructor sin parametros
Microorganismo::Microorganismo() : Elemento(){
  posicion_x = 0;
  posicion_y = 0;
}

//Constructor con parametros
Microorganismo::Microorganismo(float x, float y) : Elemento(){
  posicion_x = x;
  posicion_y = y;
}

//Destructor
Microorganismo::~Microorganismo(){
  cout << "Microorganismo -> ";
}

//Setters
void Microorganismo::asignarPosicionX(float x){
   posicion_x = x;
}

void Microorganismo::asignarPosicionY(float y){
  posicion_y = y;
}

//Getters
float Microorganismo::obtenerPosicionX(){
  return posicion_x;
}

float Microorganismo::obtenerPosicionY(){
  return posicion_y;
}

//Mostrar
void Microorganismo::mostrar(){
  Elemento::mostrar();
  cout << "Posicion en x: " << obtenerPosicionX() << endl;
  cout << "Posicion en y: " << obtenerPosicionY() << endl;
}
