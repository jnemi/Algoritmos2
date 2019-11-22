#ifndef SUERO_H_INCLUDED
#define SUERO_H_INCLUDED
#include "Elemento.h"

class Suero : public Elemento{
    //Atributos
    private:
        char tipo;
        int posicion_x;
        int posicion_y;
        bool renderizado;

    //Metodos
    public:
        //Setters
        //PRE: Recibe un caracter 'A' o 'B'
        //POS: Asigna el tipo de dosis
        void asignarTipo(char);

        //PRE: Reciibir dato valido
        //POS: asigna la posicion en x
        void asignar_posicion_x(int);

        //PRE: Reciibir dato valido
        //POS: Asigna la posicion en y
        void asignar_posicion_y(int);

        //PRE: Reciibir dato valido
        //POS: asigna verdadero o falso para saber si se renderiza o no
        void asignar_renderizado(bool);

        //Getters
        //PRE: -
        //POS: Devuelve el tipo
        char obtenerTipo();

        //Mostrar
        //PRE: -
        //POS: Imprime los datos por pantalla
        void mostrar();

        //PRE: -
        //POS: Devuelve la posicion en x
        int obtener_posicion_x();

        //PRE: -
        //POS: Devuelve la posicion en y
        int obtener_posicion_y();

        //PRE: -
        //POS: Devuelve el valor de renderizado(booleano)
        bool obtener_renderizado();

        //constructor sin parametros
        Suero();

        //constructor con parametros
        Suero(char);

        //destructor
        ~Suero();
};

#endif // SUERO_H_INCLUDED
