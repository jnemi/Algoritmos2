//
// Created by caropistillo
//

#include "Juego.h"
#include <iostream>

using namespace std;

const int SCREEN_FPS = 30;

bool apretando1 = false;
bool apretando2 = false;
int direccion_celula = 0; //Inicializado en direccion nula
bool apretandoNum = false;

bool Juego::iniciar(const char *title, int xpos, int ypos, int flags) {

   return entorno.iniciar(title,xpos,ypos,flags);
}


Juego::Juego() : reloj(3200)
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
    running = estado_juego(lista_celulas);

    nanobot->actualizar();

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

    if(inputManager -> isKeyDown(KEY_1) && !apretando1){
        apretando1 = true;
        entorno.inyectar_dosis_a(nanobot, lista_dosis_a);
    }

    apretando1 = !(inputManager -> isKeyUp(KEY_1));

    if(inputManager -> isKeyDown(KEY_2) && !apretando2){
        apretando2 = true;
        entorno.inyectar_dosis_b(nanobot, lista_dosis_b);
    }

    apretando2 = !(inputManager -> isKeyUp(KEY_2));


    if(inputManager->isKeyDown(KEY_A)){
        revertir_celula(lista_celulas, lista_dosis_a, nanobot);
    }

    if(inputManager->isKeyDown(KEY_B)){
        evolucionar_celula(lista_celulas, lista_dosis_b);
    }

    if(inputManager->isKeyDown(KEY_C)){

        if (inputManager->isKeyDown(KEY_1) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 1;
            cout<<1;
        }else
        if (inputManager->isKeyDown(KEY_2) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 2;
            cout<<2;
        }else
        if (inputManager->isKeyDown(KEY_3) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 3;
            cout<<3;
        }else
        if (inputManager->isKeyDown(KEY_4) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 4;
            cout<<4;
        }else
        if (inputManager->isKeyDown(KEY_5) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 5;
            cout<<5;
        }else
        if (inputManager->isKeyDown(KEY_6) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 6;
            cout<<6;
        }else
        if (inputManager->isKeyDown(KEY_7) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 7;
            cout<<7;
        }else
        if (inputManager->isKeyDown(KEY_8) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 8;
            cout<<8;
        }else
        if (inputManager->isKeyDown(KEY_9) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10 + 9;
            cout<<9;
        }else
        if (inputManager->isKeyDown(KEY_0) && !apretandoNum){
            apretandoNum = true;
            direccion_celula = direccion_celula*10;
            cout<<0;
        }

        if (apretandoNum && inputManager->isKeyUp(KEY_1)&& inputManager->isKeyUp(KEY_2)&& inputManager->isKeyUp(KEY_3)&& inputManager->isKeyUp(KEY_4)&& inputManager->isKeyUp(KEY_5)&& inputManager->isKeyUp(KEY_6)&& inputManager->isKeyUp(KEY_7)&& inputManager->isKeyUp(KEY_8)&& inputManager->isKeyUp(KEY_9)&& inputManager->isKeyUp(KEY_0)){
            apretandoNum = false;
        }

    }

    if (direccion_celula != 0 && inputManager->isKeyUp(KEY_C)){
        apretandoNum = false;
        int largo_lista_celulas = lista_celulas->obtener_largo();
        cout<<endl<<"Ingresaste: "<<direccion_celula<<endl;
        if (direccion_celula <= largo_lista_celulas)
            nanobot->ir_a(direccion_celula);
        direccion_celula = 0;
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
                        reconectar_red(lista_celulas, j);
                        lista_celulas -> borrar(j);
                        actualizar_adyacentes(lista_celulas, j);
                        nanobot->recalcular_mapa(j);
                        lista_anticuerpos -> borrar(i);

                        /*
                            reconectar_red(lista_celulas, j);
                            lista_celulas->borrar(j);
                            actualizar_adyacentes(lista_celulas, j);
                        */
                    }
                }
            }
        }
    }

    //Your code here
}
