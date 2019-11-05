#include "Celula.h"

//Constructor sin parametros
Celula::Celula() : Microorganismo(){
}

//Constructor con parametros
Celula::Celula(float x, float y) : Microorganismo(x, y){
}

//Destructor
Celula::~Celula(){
  //cout << "Celula -> ";
}

//Setters
void Celula::asignarCantEnzimas(unsigned int e){
  cantEnzimas = e;
}

void Celula::asignarCantProteinas(unsigned int p){
  cantProteinas = p;
}

void Celula::asignarMaterialGenetico(string m){
  materialGenetico = m;
}

void Celula::asignarUnicelular(bool u){
  unicelular = u;
}

//Getters
unsigned int Celula::obtenerCantEnzimas(){
  return cantEnzimas;
}

unsigned int Celula::obtenerCantProteinas(){
  return cantProteinas;
}

string Celula::obtenerMaterialGnetico(){
  return materialGenetico;
}

bool Celula::obtenerUnicelular(){
  return unicelular;
}

//Mostrar
void Celula::mostrar(){
  Microorganismo::mostrar();
  cout << "Cantidad de enzimas: " << obtenerCantEnzimas() << endl;
  cout << "Cantidad de proteinas: " << obtenerCantEnzimas() << endl;
  cout << "Material Gnetico: " << obtenerMaterialGnetico() << endl;
  if(obtenerUnicelular())
    cout << "Tipo de organismo: Unicelular" << endl;
  else
    cout << "Tipo de organismo: Pluricelular" << endl;
}
