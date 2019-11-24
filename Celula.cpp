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

void Celula::contagiar(Lista<Celula>*)
{
    //Definido en los herederos
}

//Agregar Celulas Adyacentes
void Celula::agregarAdyacente(int nueva_ady)
{
    cout<<"[DEBUG]: Conectando "<<this<<" con "<<nueva_ady;
    adyacentes.extender(new int(nueva_ady));
    cout<<"  COMPLETADO"<<endl;
}

int Celula::obtenerAdyacente(int indice)
{
    return adyacentes.obtener_valor(indice);
}

int Celula::obtenerCantidadAdyacentes()
{
    return adyacentes.obtener_largo();
}

void Celula::removerAdyacente(int indice)
{
    adyacentes.borrar(indice);
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

void Celula::duplicar_celula(Lista<Celula>* lista_celulas, char tipo, int j){
    int x, y, fin;

    x = lista_celulas->obtener_puntero(j)->obtener_posicion_x();
    y = lista_celulas->obtener_puntero(j)->obtener_posicion_y();

    if((x < 475)){
                x = x + 100;
            }else{
                x = x - 100;
            }
            if(y < 275){
                y = y + 100;
            }else{
                y = y - 100;
            }

    switch(tipo){
        case 's':
            lista_celulas->extender(new Celula(x, y));
            fin = lista_celulas->obtener_largo();
            lista_celulas->obtener_puntero(fin)->asignar_tipo(tipo);
            break;
        case 'x':
            lista_celulas->extender(new Celula(x, y));
            fin = lista_celulas->obtener_largo();
            lista_celulas->obtener_puntero(fin)->asignar_tipo(tipo);
            break;
        case 'y':
            lista_celulas->extender(new Celula(x, y));
            fin = lista_celulas->obtener_largo();
            lista_celulas->obtener_puntero(fin)->asignar_tipo(tipo);
            break;
        case 'z':
            lista_celulas->extender(new Celula(x, y));
            fin = lista_celulas->obtener_largo();
            lista_celulas->obtener_puntero(fin)->asignar_tipo(tipo);
            break;
    }
}

//Mostrar
void Celula::mostrar(){
  Microorganismo::mostrar();
  cout<<"****************************"<<endl;
  cout<<"Direccion: "<<this<<endl;
  cout<<"****************************"<<endl;
  cout<<">>Adyacentes: "<<endl;
  for (int i = 1; i <= adyacentes.obtener_largo(); i++)
    cout<<"        Cel: "<<(adyacentes.obtener_valor(i))<<endl;
  cout << "Cantidad de enzimas: " << obtenerCantEnzimas() << endl;
  cout << "Cantidad de proteinas: " << obtenerCantEnzimas() << endl;
  cout << "Material Gnetico: " << obtenerMaterialGnetico() << endl;
  if(obtenerUnicelular())
    cout << "Tipo de organismo: Unicelular" << endl;
  else
    cout << "Tipo de organismo: Pluricelular" << endl;
  cout<<"_______________________________________________________________"<<endl;
}
