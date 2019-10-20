#ifndef SUERO_H_INCLUDED
#define SUERO_H_INCLUDED
#include "Elemento.h"

class Suero : public Elemento{
    //Atributos
    private:
        char tipo;
        unsigned int cantDosis;

    //Metodos
    public:
        //Setters
        //PRE: Recibe un caracter 'A' o 'B'
        //POS: Asigna el tipo de dosis
        void asignarTipo(char);

        //PRE: Recibir dato valido
        //POS: Asigna la cantidad de dosis
        void asignarCantDosis(unsigned int);

        //Getters
        //PRE: -
        //POS: Devuelve el tipo
        char obtenerTipo();

        //PRE: -
        //POS: Devuelve la cantidad de dosis
        unsigned int obtenerCantDosis();

        //Mostrar
        //PRE: -
        //POS: Imprime los datos por pantalla
        void mostrar();

        //constructor sin parametros
        Suero();

        //constructor con parametros
        Suero(char, unsigned int);

        //destructor
        ~Suero();
};

#endif // SUERO_H_INCLUDED
