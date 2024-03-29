#include "Suero.h"

//Constructor sin parametros
Suero::Suero() : Elemento(){
  asignarTipo('-');
  //Asigna por defecto una posicion muy grande para que no cause problemas al recorrer la lista
  //Al momento de inyectar una dosis se asigna el nuevo valor
  asignar_posicion_x(10000);
  asignar_posicion_y(10000);
  asignar_renderizado(false);
}

//Constructor con parametros
Suero::Suero(char t) : Elemento(){
  asignarTipo(t);
  //Asigna por defecto una posicion muy grande para que no cause problemas al recorrer la lista
  //Al momento de inyectar una dosis se asigna el nuevo valor
  asignar_posicion_x(10000);
  asignar_posicion_y(10000);
  asignar_renderizado(false);
}

//Destructor
Suero::~Suero(){
  //cout << "Destruyendo Suero -> ";
}

//Setters
void Suero::asignarTipo(char t){
  tipo = t;
}

void Suero::asignar_posicion_x(int x){
    posicion_x = x;
}

void Suero::asignar_posicion_y(int y){
    posicion_y = y;
}

void Suero::asignar_renderizado(bool r){
    renderizado = r;
}

//Getters
char Suero::obtenerTipo(){
  return tipo;
}

int Suero::obtener_posicion_x(){
    return posicion_x;
}

int Suero::obtener_posicion_y(){
    return posicion_y;
}

bool Suero::obtener_renderizado(){
    return renderizado;
}

//Mostrar
void Suero::mostrar(){
  cout << "Suero:" << endl;
  Elemento::mostrar();
  cout << "Tipo: " << obtenerTipo() << endl;
}
