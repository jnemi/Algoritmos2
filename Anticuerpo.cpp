#include "Anticuerpo.h"

//Constructor sin parametros
Anticuerpo::Anticuerpo() : Microorganismo(){
    capturado = false;
    direccion = LIBRE;
}

//Constructor con parametros
Anticuerpo::Anticuerpo(float x, float y) : Microorganismo(x, y){
    capturado = false;
    direccion = LIBRE;
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

void Anticuerpo::capturar(bool capturado){
    this -> capturado = capturado;
}

bool Anticuerpo::obtener_capturado(){
    return capturado;
}

void Anticuerpo::asignar_direccion(Direccion direccion){
    this -> direccion = direccion;
}

Direccion Anticuerpo::obtener_direccion(){
    return direccion;
}
