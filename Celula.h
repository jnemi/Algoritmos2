#ifndef CELULA_H_INCLUDED
#define CELULA_H_INCLUDED
#include "Microorganismo.h"
#include "List.h"

class Celula : public Microorganismo{
   //Atributos
   protected:
     unsigned int cantEnzimas;
     unsigned int cantProteinas;
     string materialGenetico;
     bool unicelular;

     List<Celula> adyacentes;

   //Metodos
   public:
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

     //constructor sin parametros
     Celula();

     //constructor con parametros
     Celula(float, float);

     //Destructor
     virtual ~Celula();
};

#endif // CELULA_H_INCLUDED
