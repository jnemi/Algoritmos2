#include "Celula_z.h"

//Constructor sin parametros
Celula_z::Celula_z() : Celula(){
  porcentajeMutacion = 0;
}

//Constructor con parametros
Celula_z::Celula_z(float x, float y) : Celula(x, y){
    tipo = 'z';
}

//Destructor
Celula_z::~Celula_z(){
  //cout << "Destruyendo Celula Z -> ";
}

void Celula_z::contagiar(Lista<Celula>* lista_celulas)
{
 //NUEVA VERSION
    for (int indice = 1; indice <= adyacentes.obtener_largo(); indice++){
        Celula* cel_objetivo = lista_celulas->obtener_puntero(adyacentes.obtener_valor(indice));
        if (cel_objetivo->obtener_tipo_celula() == 's'){
        Celula* contagiada = new Celula_x(cel_objetivo->obtenerPosicionX(), cel_objetivo->obtenerPosicionY());
            for (int i = 1; i <= cel_objetivo->obtenerCantidadAdyacentes(); i++)
                contagiada->agregarAdyacente(cel_objetivo->obtenerAdyacente(i));
        lista_celulas->reemplazar(adyacentes.obtener_valor(indice), contagiada);
        }
    }
}

//Setter
void Celula_z::asignarPorcentajeMutacion(float pm){
  porcentajeMutacion = pm;
}

//Getter
float Celula_z::obtenerPorcentajeMutacion(){
  return porcentajeMutacion;
}

//Mostrar
void Celula_z::mostrar(){
  cout << "Celula Z:" << endl;
  Celula::mostrar();
  cout << "Porcentaje de mutacion: " << obtenerPorcentajeMutacion() << "%" << endl;
}
