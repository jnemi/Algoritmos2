//
// Created by caropistillo
//

#include "Juego.h"

using namespace std;

const int SCREEN_FPS = 30;


bool Juego::iniciar(const char *title, int xpos, int ypos, int flags) {

   return entorno.iniciar(title,xpos,ypos,flags);
}


Juego::Juego(){

	running = false;
}

void Juego::correr(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos) {
	running = true;
	FPSManager fpsManager(SCREEN_FPS);

    Anticuerpo* p = &lista_anticuerpos -> obtener_valor(1);
    bool up = true;

    Anticuerpo* k = &lista_anticuerpos -> obtener_valor(2);
    bool tope = true;

	while(running) {
		fpsManager.start();

		manejarEventos(p, up, k, tope);
		renderizar(lista_celulas, lista_anticuerpos);

		fpsManager.stop();
	}
}

void Juego::renderizar(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos) {

    entorno.renderizarTodo(lista_celulas, lista_anticuerpos);

}

void Juego::limpiar() {

    entorno.limpiar();
}

// Se encarga de manejar los eventos de teclado a traves de la clase "InputManager"
// En general, para saber si una tecla esta siendo presionada se utilizara
// el metodo "isKeyDown(KEY)". Para saber que KEY pasar por parametro, consultar
// el archivo "InputTable.h" que mapea codigos de teclado de SDL.
void Juego::manejarEventos(Anticuerpo* p, bool& up, Anticuerpo* k, bool& tope) {
	InputManager* inputManager = InputManager::getInstance();
    inputManager->update();
    if(inputManager->quitRequested()) running = false;

    if(inputManager->isKeyDown(KEY_A)||entorno.dosisAExplotando())
    {
        entorno.explotarDosis(A);
    }

    if(inputManager->isKeyDown(KEY_B)||entorno.dosisBExplotando())
    {
        entorno.explotarDosis(B);
    }

    if(inputManager->isKeyDown(KEY_DOWN)){
        entorno.desplazar_abajo();
    }

    if(inputManager->isKeyDown(KEY_UP)){
        entorno.desplazar_arriba();
    }

    if(inputManager->isKeyDown(KEY_RIGHT)){
        entorno.desplazar_derecha();
    }

    if(inputManager->isKeyDown(KEY_LEFT)){
        entorno.desplazar_izquierda();
    }

    if (p -> obtenerPosicionY() < 10){
        up = false;
    }

    if (p -> obtenerPosicionY() > 550){
        up = true;
    }

    if (up){
        entorno.mover_arriba(*p);
    }else{
        entorno.mover_abajo(*p);
    }

    if (k -> obtenerPosicionX() < 10){
        tope = false;
    }

    if (k -> obtenerPosicionX() > 900){
        tope = true;
    }

    if (tope){
        entorno.mover_izquierda(*k);
    }else{
        entorno.mover_derecha(*k);
    }

    //Your code here
}
