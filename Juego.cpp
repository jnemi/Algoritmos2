//
// Created by caropistillo
//

#include "Juego.h"

using namespace std;

const int SCREEN_FPS = 30;

bool Juego::iniciar(const char *title, int xpos, int ypos, int flags) {

   return entorno.iniciar(title,xpos,ypos,flags);
}


Juego::Juego() : reloj(600)
{
	running = false;
}

void Juego::correr(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos, Lista<Suero>* lista_dosis_a, Lista<Suero>* lista_dosis_b, Nanobot *nanobot) {
	running = true;
	FPSManager fpsManager(SCREEN_FPS);

	bool tope = true;

    reloj.asignar_referencia_lista_celulas(lista_celulas);

	while(running) {
		fpsManager.start();

		manejarEventos(lista_celulas, lista_anticuerpos, lista_dosis_a, lista_dosis_b, tope, nanobot);
		renderizar(lista_celulas, lista_anticuerpos, lista_dosis_a, lista_dosis_b, nanobot);

		fpsManager.stop();
	}
}

void Juego::renderizar(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos, Lista<Suero>* lista_dosis_a, Lista<Suero>* lista_dosis_b, Nanobot *nanobot) {

    entorno.renderizarTodo(lista_celulas, lista_anticuerpos, lista_dosis_a, lista_dosis_b, nanobot);

}

void Juego::limpiar() {

    entorno.limpiar();
}

// Se encarga de manejar los eventos de teclado a traves de la clase "InputManager"
// En general, para saber si una tecla esta siendo presionada se utilizara
// el metodo "isKeyDown(KEY)". Para saber que KEY pasar por parametro, consultar
// el archivo "InputTable.h" que mapea codigos de teclado de SDL.
void Juego::manejarEventos(Lista<Celula>* lista_celulas, Lista<Anticuerpo>* lista_anticuerpos, Lista <Suero>* lista_dosis_a, Lista <Suero>* lista_dosis_b, bool &tope, Nanobot *nanobot) {

    reloj.tick();

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

    if(inputManager -> isKeyDown(KEY_1)){
        entorno.inyectar_dosis_a(nanobot, lista_dosis_a);
    }

    if(inputManager -> isKeyDown(KEY_2)){
        entorno.inyectar_dosis_b(nanobot, lista_dosis_b);
    }

    if(inputManager->isKeyDown(KEY_A)){
        revertir_celula(lista_celulas, lista_dosis_a);
    }

    if(inputManager->isKeyDown(KEY_B)){
        evolucionar_celula(lista_celulas, lista_dosis_b);
    }

    if(inputManager->isKeyDown(KEY_DOWN)){
        entorno.desplazar_abajo(nanobot);
    }

    if(inputManager->isKeyDown(KEY_UP)){
        entorno.desplazar_arriba(nanobot);
    }

    if(inputManager->isKeyDown(KEY_RIGHT)){
        entorno.desplazar_derecha(nanobot);
    }

    if(inputManager->isKeyDown(KEY_LEFT)){
        entorno.desplazar_izquierda(nanobot);
    }
    if (lista_anticuerpos -> obtener_largo() != 0){

        for (int i = 1; i <= lista_anticuerpos -> obtener_largo(); i++){

            Anticuerpo* p = &lista_anticuerpos -> obtener_valor(i);

            if (entorno.verificar_anticuerpo(*p, nanobot) && p -> obtener_direccion() == LIBRE){
                p -> capturar(true);
            }

            if(inputManager->isKeyDown(KEY_Z)&&inputManager->isKeyDown(KEY_RIGHT)){
                entorno.liberar(*p, DERECHA);
            }

            if (inputManager->isKeyDown(KEY_Z)&&inputManager->isKeyDown(KEY_UP)){
                entorno.liberar(*p, ARRIBA);
            }

            if (inputManager->isKeyDown(KEY_Z)&&inputManager->isKeyDown(KEY_DOWN)){
                entorno.liberar(*p, ABAJO);
            }

            if (inputManager->isKeyDown(KEY_Z)&&inputManager->isKeyDown(KEY_LEFT)){
                entorno.liberar(*p, IZQUIERDA);
            }


            if (i % 2 != 0 && p -> obtener_direccion() == LIBRE){

                if (p -> obtenerPosicionY() < 10){
                        tope = false;
                }

                if (p -> obtenerPosicionY() > 550){
                        tope = true;
                }

                if (tope){
                    entorno.mover_arriba(*p);
                }else{
                    entorno.mover_abajo(*p);
                }
            }

            if (i % 2 == 0 && p -> obtener_direccion() == LIBRE){

                if (p -> obtenerPosicionX() < 10){
                    tope = false;
                }

                if (p -> obtenerPosicionX() > 900){
                    tope = true;
                }

                if (tope){
                    entorno.mover_izquierda(*p);
                }else{
                    entorno.mover_derecha(*p);
                }
            }

            entorno.volar(*p);

            for (int j = 1; j <= lista_celulas -> obtener_largo(); j++){

                Celula* c = &lista_celulas-> obtener_valor(j);

                if (c-> obtener_tipo_celula() == 'z'){

                    if (entorno.verificarZ(*p, *c)){
                        lista_celulas -> borrar(j);
                        lista_anticuerpos -> borrar(i);
                    }
                }
            }
        }
    }

    //Your code here
}
