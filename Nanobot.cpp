#include "Nanobot.h"

//Constructores
Nanobot::Nanobot(){
    posicion_x = 0;
    posicion_y = 0;
}

Nanobot::Nanobot(float x, float y){
    posicion_x = x;
    posicion_y = y;
}

//Setters
void Nanobot::asignar_posicion_x(float x){
    posicion_x = x;
}

void Nanobot::asignar_posicion_y(float y){
    posicion_y = y;
}

//Getters
float Nanobot::obtener_posicion_x(){
    return posicion_x;
}

float Nanobot::obtener_posicion_y(){
    return posicion_y;
}
