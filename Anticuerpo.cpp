#include "Anticuerpo.h"

//Constructor sin parametros
Anticuerpo::Anticuerpo() : Microorganismo(){
}

//Constructor con parametros
Anticuerpo::Anticuerpo(float x, float y) : Microorganismo(x, y){
}

//Destructor
Anticuerpo::~Anticuerpo(){
  //cout << "Destruyendo Anticuerpo -> ";
}

//Mostrar
void Anticuerpo::mostrar(){
  cout << "Anticuerpo:" << endl;
  Microorganismo::mostrar();
}

float Anticuerpo::obtener_posicion_x(){
    return posicion_x;
}

float Anticuerpo::obtener_posicion_y(){
    return posicion_y;
}
