#ifndef NANOBOT_H_INCLUDED
#define NANOBOT_H_INCLUDED
#include "Elemento.h"
#include <cstdlib>
#include <math.h>
#include "Lista.h"
#include "Celula.h"


struct Vector2
{
    int x;
    int y;
};

struct Posta
{
    float costo = INFINITY; //Costo de recorrido hasta llegar a esta Posta
    int camino = -1; //Indice de la ultima celula por la que se pasa para llegar hasta esta Posta
};


using namespace std;

class Nanobot : public Elemento{
    //atributos
    private:
        Vector2 posicion;
        Vector2 destino;
        int velocidad = 1;
        Lista<Celula>* lista_celulas; //No es responsabilidad del Nanobot liberarla
        int indice_celula_cercana = 0;
        Lista<Posta> mapa;
        Lista<Posta> ruta;
        bool red_mapeada = false;

    public:
        //constructores
        //sin parametros
        Nanobot();
        //con parametros
        Nanobot(int, int, Lista<Celula>*);

        //metodos
        //PRE: Recibe un par de coordenadas x e y, y el costo de desplazamiento
        //POS: Modifica el destino hasta las coordenadas pasadas y su velocidad
        void desplazar(int, int, int);

        void actualizar();

        //PRE: Recibe una lista de Celulas no vacia
        //POS: Se desplaza a la celula mas cercana
        void ir_a_cercana();

        //PRE: Recibe un indice de una Celula != a donde esta el bot. La red debe estar mapeada
        //POS: Traza la ruta a esa celula
        void ir_a(int);

        //PRE: Llamar si la red se modifica por borrar alguna Celula. Pasar el indice de la celula destruida
        //POS: Maneja los procesos necesarios para llegar a destino si estaba viajando
        void recalcular_mapa(int);

        //PRE: Recibe la lista de Celulas, y un entero correspondiente al indice de alguna de estas Celulas
        //POS: Devuelve una lista de Postas ordenada segun los indices de las Celulas, mapeando los
        //     recorridos mas cortos a las mismas desde la Celula correspondiente al indice ingresado
        void mapear(int);

        //SETTERS
        //PRE: recibir un dato valido
        //POS: asigna posicion en x al nanobot
        void asignar_posicion_x(int);
        //PRE: recibir un dato valido
        //POS: asigna posicion en y al nanobot
        void asignar_posicion_y(int);
        //GETTERS
        //PRE: -
        //POS: Devuelve la posicion en x del nanobot
        int obtener_posicion_x();
        //PRE: -
        //POS: Devuelve la posicion en y del nanobot
        int obtener_posicion_y();
};


#endif // NANOBOT_H_INCLUDED
