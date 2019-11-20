#ifndef NANOBOT_H_INCLUDED
#define NANOBOT_H_INCLUDED
#include "Elemento.h"

using namespace std;

class Nanobot : public Elemento{
    //atributos
    private:
        float posicion_x;
        float posicion_y;

    public:
        //constructores
        //sin parametros
        Nanobot();
        //con parametros
        Nanobot(float, float);
        //metodos
        //SETTERS
        //PRE: recibir un dato valido
        //POS: asigna posicion en x al nanobot
        void asignar_posicion_x(float);
        //PRE: recibir un dato valido
        //POS: asigna posicion en y al nanobot
        void asignar_posicion_y(float);
        //GETTERS
        //PRE: -
        //POS: Devuelve la posicion en x del nanobot
        float obtener_posicion_x();
        //PRE: -
        //POS: Devuelve la posicion en y del nanobot
        float obtener_posicion_y();
};


#endif // NANOBOT_H_INCLUDED
