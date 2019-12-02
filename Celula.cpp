#include "Celula.h"
#include <cstdlib>
#include <math.h>
#include <random>

//Constructor sin parametros
Celula::Celula() : Microorganismo(){
    contacto = false;
}

//Constructor con parametros
Celula::Celula(float x, float y) : Microorganismo(x, y){
    contacto = false;
}

//Destructor
Celula::~Celula(){
  //cout << "Celula -> ";
}

void Celula::contagiar(Lista<Celula>*)
{
    //Definido en los herederos
}

//Agregar Celulas Adyacentes
void Celula::agregarAdyacente(int nueva_ady)
{
    bool esAdyacente = false;
    for (int ady = 1; ady <= adyacentes.obtener_largo(); ady++){
        esAdyacente = esAdyacente || (adyacentes.obtener_valor(ady).indice == nueva_ady);
    }
    if (!esAdyacente){
        Adyacente* adyacente = new Adyacente;
        adyacente->indice = nueva_ady;
        adyacente->peso = 0;
        adyacentes.extender(adyacente);

        //Asigna un peso al azar
        asignarPesoAdyacente((rand()%10)+1, adyacentes.obtener_largo());
    }
}

void Celula::agregarAdyacente(int nueva_ady, int nuevo_peso)
{
    agregarAdyacente(nueva_ady, nuevo_peso, true);
}

void Celula::agregarAdyacente(int nueva_ady, int nuevo_peso, bool evitarDuplicados)
{
    bool esAdyacente = false;
    if (evitarDuplicados){
        for (int ady = 1; ady <= adyacentes.obtener_largo(); ady++){
            esAdyacente = esAdyacente || (adyacentes.obtener_valor(ady).indice == nueva_ady);
        }
    }
    if (!esAdyacente){
        Adyacente* adyacente = new Adyacente;
        adyacente->indice = nueva_ady;
        adyacente->peso = nuevo_peso;
        adyacentes.extender(adyacente);
    }
}

int Celula::obtenerAdyacente(int indice)
{
    return adyacentes.obtener_valor(indice).indice;
}

int Celula::obtenerCantidadAdyacentes()
{
    return adyacentes.obtener_largo();
}

void Celula::removerAdyacente(int indice)
{
    adyacentes.borrar(indice);
}

void Celula::asignarPesoAdyacente(int pesoNuevo, int indiceAdy)
{
    adyacentes.obtener_puntero(indiceAdy)->peso = pesoNuevo;
}

int Celula::obtenerPesoAdyacente(int indiceAdy)
{
    return adyacentes.obtener_puntero(indiceAdy)->peso;
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
float Celula::obtener_posicion_x(){
    return posicion_x;
}

float Celula::obtener_posicion_y(){
    return posicion_y;
}

char Celula::obtener_tipo_celula(){
    return tipo;
}

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

void Celula::asignar_tipo(char t){
    tipo = t;
}

void Celula::asignar_contacto(bool contacto){
    this -> contacto = contacto;
}

bool Celula::obtener_contacto(){
    return contacto;
}

void Celula::duplicar_celula(Lista<Celula>* lista_celulas, char tipo, int j){
    int x, y;

    Celula* duplicar = lista_celulas->obtener_puntero(j);
    x = duplicar->obtener_posicion_x();
    y = duplicar->obtener_posicion_y();

    //Dependiendo la posicion, renderiza la celula nueva
    //en una posicion que se encuentre dentro de la pantalla
    x = max(30.0, min(x + sqrt(rand()%500001) - 350, 950.0));
    y = max(30.0, min(y + sqrt(rand()%360001) - 300, 550.0));


    Celula* nueva = new Celula(x, y);
    lista_celulas->extender(nueva);

    int peso_nuevo = 1 + rand()%10;
    duplicar->agregarAdyacente(lista_celulas->obtener_largo(), peso_nuevo);
    nueva->agregarAdyacente(j, peso_nuevo);

    switch(tipo){
        case 's':
            nueva->asignar_tipo(tipo);
            break;
        case 'x':
            nueva->asignar_tipo(tipo);
            break;
        case 'y':
            nueva->asignar_tipo(tipo);
            break;
        case 'z':
            nueva->asignar_tipo(tipo);
            break;
    }
}

//Mostrar
void Celula::mostrar(){
  Microorganismo::mostrar();
  //cout<<"****************************"<<endl;
  //cout<<"Direccion: "<<this<<endl;
  //cout<<"****************************"<<endl;
  cout<<">>Adyacentes: "<<endl;
  for (int i = 1; i <= adyacentes.obtener_largo(); i++)
    cout<<"        Cel: "<<(adyacentes.obtener_valor(i).indice)<<" "<<(adyacentes.obtener_valor(i).peso)<<endl;
  //cout << "Cantidad de enzimas: " << obtenerCantEnzimas() << endl;
  //cout << "Cantidad de proteinas: " << obtenerCantEnzimas() << endl;
  //cout << "Material Gnetico: " << obtenerMaterialGnetico() << endl;
  //if(obtenerUnicelular())
    //cout << "Tipo de organismo: Unicelular" << endl;
  //else
    //cout << "Tipo de organismo: Pluricelular" << endl;
  cout<<"_______________________________________________________________"<<endl;
}
