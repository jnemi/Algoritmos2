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

void Anticuerpo::capturar(bool capturado){
    this -> capturado = capturado;
}

void Anticuerpo::asignar_direccion(Direccion direccion){
    this -> direccion = direccion;
}

bool Anticuerpo::obtener_capturado(){
    return capturado;
}

Direccion Anticuerpo::obtener_direccion(){
    return direccion;
}
