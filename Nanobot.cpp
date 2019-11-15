#include "Nanobot.h"

//Constructores
Nanobot::Nanobot(){
    posicion_x = 0;
    posicion_y = 0;
}

Nanobot::Nanobot(int x, int y){
    posicion_x = x;
    posicion_y = y;
}

//Setters
void Nanobot::asignar_posicion_x(int x){
    posicion_x = x;
}

void Nanobot::asignar_posicion_y(int y){
    posicion_y = y;
}

//Getters
int Nanobot::obtener_posicion_x(){
    return posicion_x;
}

int Nanobot::obtener_posicion_y(){
    return posicion_y;
}
