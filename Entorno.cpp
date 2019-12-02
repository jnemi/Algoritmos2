#include "Entorno.h"
#include "Nanobot.h"
#include "Anticuerpo.h"
#include<iostream>
using namespace std;

#include "Constants.h"

//variables globales para el renderizado de dosis
int indice_a = 1;
int indice_b = 1;

Entorno::Entorno()
{
    estadoDosisA = 1;
    estadoDosisB = 1;
    loaderA = new ImageLoader(COMMON_RED, COMMON_GREEN,COMMON_BLUE);
    loaderB = new ImageLoader(SECONDARY_RED,SECONDARY_GREEN,SECONDARY_BLUE);
}

bool Entorno::iniciar(const char *title, int xpos, int ypos, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

    cerr<<"SDL no se pudo inicializar."<<endl;
    return false;

    } else {

        window = SDL_CreateWindow(title, xpos, ypos, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
        if (window == 0) {

        	cerr<<"Fallo al crear ventana."<<endl;
            return false;

        } else {

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == 0) {
            	cerr<<"Fallo al crear Renderer"<<endl;
                return false;
            } else {
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                	cerr<<"SDL_image no pudo inicializarse."<<endl;
                    return false;
                }
                cargarTexturas();
            }
        }
    }
    // everything inited successfully,
    return true;
}


void Entorno::renderizar(imagenes imagen, float x, float y)
{
    switch(imagen)
    {
        case FONDO:
            texturas[FONDO].render(x,y,SCREEN_WIDTH,SCREEN_HEIGHT,renderer);
            break;
        case NANOBOT:
            texturas[NANOBOT].render(x,y,NANOBOT_WIDTH,NANOBOT_HEIGHT,renderer);
            break;
        case CELULA_S:
            texturas[CELULA_S].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case CELULA_X:
            texturas[CELULA_X].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case CELULA_Y:
            texturas[CELULA_Y].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case CELULA_Z:
            texturas[CELULA_Z].render(x,y,CELULA_SIZE,CELULA_SIZE,renderer);
            break;
        case ANTICUERPO:
            texturas[ANTICUERPO].render(x,y,ANTICUERPO_WIDTH,ANTICUERPO_HEIGHT,renderer);
            break;
        case DOSIS_A:
            if(estadoDosisA<LAST_DOSIS_SPRITE)
                texturas[DOSIS_A].render(x,y,DOSIS_WIDTH,DOSIS_HEIGHT,renderer);
            break;
        case DOSIS_B:
            if(estadoDosisB<LAST_DOSIS_SPRITE)
                texturas[DOSIS_B].render(x,y,DOSIS_WIDTH,DOSIS_HEIGHT,renderer);
            break;

    }
}

void Entorno::cargarTexturas()
{
    for(int i=0;i<7;i++)
    {
        texturas[i].cargarDesdeArchivo(PATHS[i],renderer);
    }
    for(int i=0;i<10;i++)
    {
    	numeros[i].cargarDesdeArchivo(PATHS_NUMEROS[i],renderer);
    }
    loaderA->loadSprite(DOSIS_PATH,estadoDosisA,renderer,&texturas[DOSIS_A]);
    loaderB->loadSprite(DOSIS_PATH,estadoDosisB,renderer,&texturas[DOSIS_B]);
}

Entorno::~Entorno()
{
	window = NULL;
	renderer = NULL;
}

void Entorno::renderizarTodo(Lista<Celula>* lista, Lista<Anticuerpo>* lista_anticuerpos, Lista<Suero>* lista_dosis_a, Lista<Suero>* lista_dosis_b, Nanobot *nanobot)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer); // clear the renderer to the draw color
	renderizar(FONDO,0,0);
	renderizar(NANOBOT, nanobot->obtener_posicion_x(), nanobot->obtener_posicion_y());
	//Prepara el Draw para dibujar una linea negra
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //Inserte codigo para dibujar lineas
    armado_red_grafica(renderer, lista);
    //Inserte codigo para renderizar imagenes
    int largo = lista->obtener_largo();
    float x, y;
    char tipo_celula;

    for(int i=1; i<=largo; i++){
        x = lista->obtener_valor(i).obtener_posicion_x();
        y = lista->obtener_valor(i).obtener_posicion_y();
        tipo_celula = lista->obtener_valor(i).obtener_tipo_celula();

        //cout << "La imagen va en (" << x << "," << y << ")" << endl;

        switch(tipo_celula){
            case 'x':
                renderizar(CELULA_X, x-25, y-25);
                break;
            case 'y':
                renderizar(CELULA_Y, x-25, y-25);
                break;
            case 'z':
                renderizar(CELULA_Z, x-25, y-25);
                break;
            case 's':
                renderizar(CELULA_S, x-25, y-25);
                break;
        }
    }

    int tam = lista_anticuerpos -> obtener_largo();

    for(int i = 1; i <= tam; i++){
        x = lista_anticuerpos -> obtener_valor(i).obtener_posicion_x();
        y = lista_anticuerpos -> obtener_valor(i).obtener_posicion_y();

        if (lista_anticuerpos -> obtener_valor(i).obtener_capturado()){
            lista_anticuerpos -> obtener_valor(i).asignarPosicionX(nanobot -> obtener_posicion_x());
            lista_anticuerpos -> obtener_valor(i).asignarPosicionY(nanobot -> obtener_posicion_y());
        }

        renderizar(ANTICUERPO, x-25, y-25);
    }

    int longitud_a = lista_dosis_a->obtener_largo();
    int Ax, Ay, Bx, By;

    for(int r=1; r<=longitud_a; r++){
        if(lista_dosis_a->obtener_puntero(r)->obtener_renderizado()){
            Ax = lista_dosis_a->obtener_puntero(r)->obtener_posicion_x();
            Ay = lista_dosis_a->obtener_puntero(r)->obtener_posicion_y();
            renderizar(DOSIS_A, Ax, Ay);
        }

    }

    int longitud_b = lista_dosis_b->obtener_largo();

    for(int j=1; j<=longitud_b; j++){
        if(lista_dosis_b->obtener_puntero(j)->obtener_renderizado()){
            Bx = lista_dosis_b->obtener_puntero(j)->obtener_posicion_x();
            By = lista_dosis_b->obtener_puntero(j)->obtener_posicion_y();
            renderizar(DOSIS_B, Bx, By);
        }
    }

    //Renderizado de pesos
    int longitud = lista->obtener_largo();
    int peso, pos_x, pos_y;

    for(int i=1; i<=longitud; i++){
        Celula* cel_actual = lista->obtener_puntero(i);
	int cantAdyacentes = cel_actual->obtenerCantidadAdyacentes();

	for (int j=1; j<=cantAdyacentes; j++){
            Celula* adyacente_actual = lista->obtener_puntero(cel_actual->obtenerAdyacente(j));
            peso = adyacente_actual->obtenerPesoAdyacente(j);

            pos_x = promedio(cel_actual->obtenerPosicionX(), adyacente_actual->obtenerPosicionX());
            pos_y = promedio(cel_actual->obtenerPosicionY(), adyacente_actual->obtenerPosicionY());

            //cout << "PESO: " << peso << endl;
            //cout << "CUANTAS CIFRAS: " << cuantasCifras(peso) << endl;

            if(peso <= 9){
                //renderizarNumero(peso, pos_x, pos_y-5);
            }else{
                int vec[cuantas_cifras(peso)+1];
                dividir_en_digitos(peso, cuantas_cifras(peso), vec);
                for(int r=1; r<=cuantas_cifras(peso); r++){
                    pos_x += 15;
                    renderizarNumero(vec[r], pos_x, pos_y-5);
                }
            }
        }
    }


	SDL_RenderPresent(renderer); // draw to the screen
}

void Entorno::limpiar()
{
    for(int i=0;i<7;i++)
        texturas[i].free();
    for(int i=0;i<10;i++)
        numeros[i].free();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

}

void Entorno::explotarDosis(dosis dosis)
{
    switch(dosis){
        case A:
            if(estadoDosisA<=LAST_DOSIS_SPRITE){
                this->loaderA->loadSprite(DOSIS_PATH,estadoDosisA,renderer,&texturas[DOSIS_A]);
                ++estadoDosisA;
            }
        break;

        case B:
            if(estadoDosisB<=LAST_DOSIS_SPRITE){
                this->loaderB->loadSprite(DOSIS_PATH,estadoDosisB,renderer,&texturas[DOSIS_B]);
                ++estadoDosisB;
            }
    }
}

bool Entorno::dosisAExplotando()
{
    return estadoDosisA>1;
}

bool Entorno::dosisBExplotando()
{
    return estadoDosisB>1;
}

void Entorno::desplazar_arriba(Nanobot *nanobot){
    int aux = nanobot->obtener_posicion_y();
    aux--;
    nanobot->asignar_posicion_y(aux);
}

void Entorno::desplazar_abajo(Nanobot *nanobot){
    int aux = nanobot->obtener_posicion_y();
    aux++;
    nanobot->asignar_posicion_y(aux);
}

void Entorno::desplazar_derecha(Nanobot *nanobot){
    int aux = nanobot->obtener_posicion_x();
    aux++;
    nanobot->asignar_posicion_x(aux);
}

void Entorno::desplazar_izquierda(Nanobot *nanobot){
    int aux = nanobot->obtener_posicion_x();
    aux--;
    nanobot->asignar_posicion_x(aux);
}

void Entorno::mover_arriba(Microorganismo &anticuerpo){
    float aux = anticuerpo.obtenerPosicionY();
    aux--;
    anticuerpo.asignarPosicionY(aux);
}

void Entorno::mover_abajo(Microorganismo &anticuerpo){
    float aux = anticuerpo.obtenerPosicionY();
    aux++;
    anticuerpo.asignarPosicionY(aux);
}

void Entorno::mover_derecha(Microorganismo &anticuerpo){
    float aux = anticuerpo.obtenerPosicionX();
    aux++;
    anticuerpo.asignarPosicionX(aux);
}

void Entorno::mover_izquierda(Microorganismo &anticuerpo){
    float aux = anticuerpo.obtenerPosicionX();
    aux--;
    anticuerpo.asignarPosicionX(aux);
}

bool Entorno::verificar_anticuerpo(Microorganismo &anticuerpo, Nanobot* nanobot){
    float x = nanobot -> obtener_posicion_x();
    float y = nanobot -> obtener_posicion_y();

    float ax = anticuerpo.obtenerPosicionX();
    float ay = anticuerpo.obtenerPosicionY();

    if ((x < ax && ax < x + 85) && (y < ay && ay < y + 50)){
        return true;
    }else{
        return false;
    }
}

void Entorno::liberar(Anticuerpo &anticuerpo, Direccion direccion){

    if (anticuerpo.obtener_capturado()){
        anticuerpo.capturar(false);
        anticuerpo.asignar_direccion(direccion);
    }
}

void Entorno::volar(Anticuerpo &anticuerpo){

    if (anticuerpo.obtener_direccion() == DERECHA){
        float aux = anticuerpo.obtenerPosicionX();
        aux = aux + 5;
        anticuerpo.asignarPosicionX(aux);
    }else{

        if (anticuerpo.obtener_direccion() == ARRIBA){
            float aux = anticuerpo.obtenerPosicionY();
            aux = aux - 5;
            anticuerpo.asignarPosicionY(aux);
        }else{

            if (anticuerpo.obtener_direccion() == ABAJO){
                float aux = anticuerpo.obtenerPosicionY();
                aux = aux + 5;
                anticuerpo.asignarPosicionY(aux);
            }else{

                if (anticuerpo.obtener_direccion() == IZQUIERDA){
                    float aux = anticuerpo.obtenerPosicionX();
                    aux = aux - 5;
                    anticuerpo.asignarPosicionX(aux);
                }
            }
        }
    }
}

void Entorno::inyectar_dosis_a(Nanobot* nanobot, Lista <Suero>* lista_dosis_a){
    if(indice_a <= 15){
        lista_dosis_a->obtener_puntero(indice_a)->asignar_renderizado(true);
        lista_dosis_a->obtener_puntero(indice_a)->asignar_posicion_x((nanobot->obtener_posicion_x())-50);
        lista_dosis_a->obtener_puntero(indice_a)->asignar_posicion_y((nanobot->obtener_posicion_y())-50);
        indice_a++;
    }
}

void Entorno::inyectar_dosis_b(Nanobot* nanobot, Lista <Suero>* lista_dosis_b){
    if(indice_b <= 15){
        lista_dosis_b->obtener_puntero(indice_b)->asignar_renderizado(true);
        lista_dosis_b->obtener_puntero(indice_b)->asignar_posicion_x((nanobot->obtener_posicion_x())-50);
        lista_dosis_b->obtener_puntero(indice_b)->asignar_posicion_y((nanobot->obtener_posicion_y())-50);
        indice_b++;
    }
}

bool Entorno::verificarZ(Microorganismo &anticuerpo, Celula &celula){
    float ax = anticuerpo.obtenerPosicionX();
    float ay = anticuerpo.obtenerPosicionY();

    float x = celula.obtenerPosicionX();
    float y = celula.obtenerPosicionY();

    if ((x - 45 < ax && ax < x + 45) && (y - 45 < ay && ay < y + 45)){
        return true;
    }else{
        return false;
    }
}

void Entorno::renderizarNumero(int i,float x, float y)
{
    numeros[i].render(x,y,NUMERO_WIDTH,NUMERO_HEIGHT,renderer);
}
