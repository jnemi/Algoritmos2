#ifndef CELULA_H_INCLUDED
#define CELULA_H_INCLUDED
#include "Microorganismo.h"
#include "Lista.h"

class Celula : public Microorganismo{
   //Atributos
   protected:
     unsigned int cantEnzimas;
     unsigned int cantProteinas;
     string materialGenetico;
     bool unicelular;
     char tipo;
     Lista<int> adyacentes;

   public:

     //Metodos
     char obtener_tipo_celula();
     //Agregar Celulas Adyacentes
     void agregarAdyacente(int);

     //PRE: Recibe un entero [0, cantidad de adyacentes]
     //POS: Devuelve el indice (de la lista de celulas) de una celula adyacente
     int obtenerAdyacente(int);

     //PRE: -
     //POS: Devuelve la cantidad de adyacentes
     int obtenerCantidadAdyacentes();

     //PRE: Recibe un entero [0, cantidad de adyacentes]
     //POS: Elimina un elemento de la lista adyacentes
     void removerAdyacente(int);

     //Setters
     //PRE: Recibir dato valido
     //POS: Asigna valor a cantEnzimas
     void asignarCantEnzimas(unsigned int);

     //PRE: Recibir dato valido
     //POS: Asigna valor a cantProteinas
     void asignarCantProteinas(unsigned int);

     //PRE: Recibir dato valido
     //POS: Asigna valor a materialGenetico
     void asignarMaterialGenetico(string);

     //PRE: Recibir dato valido
     //POS: Asigna verdadero en caso unicelular o falso en caso contrario
     void asignarUnicelular(bool);

     //Getters
     //PRE: -
     //POS: Devuelve la posicion de la celula en el eje X.
     float obtener_posicion_x();
     //PRE: -
     //POS: Devuelve la posicion de la celula en el eje Y.
     float obtener_posicion_y();
     //PRE: -
     //POS: Devuelve la cantidad de enzimas
     unsigned int obtenerCantEnzimas();

     //PRE: -
     //POS: Devuelve la cantidad de proteinas
     unsigned int obtenerCantProteinas();
     //PRE: -
     //POS: devuelve el material geentico
     string obtenerMaterialGnetico();

     //PRE: -
     //POS: devuelve verdadero en caso unicelular y falso en caso contrario
     bool obtenerUnicelular();

     //Mostrar
     //PRE: -
     //POS: Imprime los datos por pantalla
     virtual void mostrar();

     //PRE: Recibe la direccion de la lista de Celulas
     //POS: Contagia una o mas Celulas S adyacentes (si las hay)
     virtual void contagiar(Lista<Celula>*);

     //PRE: Recibir dato valido
     //POS: Asigna el tipo de celula
     void asignar_tipo(char);

     //PRE:
     //POS:
     void duplicar_celula(Lista<Celula>*, char, int);

     //constructor sin parametros
     Celula();

     //constructor con parametros
     Celula(float, float);

     //Destructor
     virtual ~Celula();
};

#endif // CELULA_H_INCLUDED
