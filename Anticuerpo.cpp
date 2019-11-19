#include "Anticuerpo.h"

//Constructor sin parametros
Anticuerpo::Anticuerpo() : Microorganismo(){
    capturado = false;
    disparado = false;
}

//Constructor con parametros
Anticuerpo::Anticuerpo(float x, float y) : Microorganismo(x, y){
    capturado = false;
    disparado = false;
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

void Anticuerpo::disparar(bool disparado){
    this -> disparado = disparado;
}

bool Anticuerpo::obtener_disparado(){
    return disparado;
}
