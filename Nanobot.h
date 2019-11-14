#ifndef NANOBOT_H_INCLUDED
#define NANOBOT_H_INCLUDED
#include "Elemento.h"

using namespace std;

class Nanobot : public Elemento{
    //atributos
    private:
        int posicion_x;
        int posicion_y;

    public:
        //constructores
        //sin parametros
        Nanobot();
        //con parametros
        Nanobot(int, int);
        //metodos
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
