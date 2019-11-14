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

void Juego::correr(Lista<Celula>* lista_celulas) {
	running = true;
	FPSManager fpsManager(SCREEN_FPS);


	while(running) {
		fpsManager.start();

		manejarEventos();
		renderizar(lista_celulas);

		fpsManager.stop();
	}
}

void Juego::renderizar(Lista<Celula>* lista_celulas) {

    entorno.renderizarTodo(lista_celulas);

}

void Juego::limpiar() {

    entorno.limpiar();
}

// Se encarga de manejar los eventos de teclado a traves de la clase "InputManager"
// En general, para saber si una tecla esta siendo presionada se utilizara
// el metodo "isKeyDown(KEY)". Para saber que KEY pasar por parametro, consultar
// el archivo "InputTable.h" que mapea codigos de teclado de SDL.
void Juego::manejarEventos() {
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

    //Your code here
}
