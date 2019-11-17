#include "Entorno.h"
#include "Nanobot.h"
#include "Anticuerpo.h"
#include<iostream>
using namespace std;

#include "Constants.h"

Nanobot nanobot(0, 560);

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
    loaderA->loadSprite(DOSIS_PATH,estadoDosisA,renderer,&texturas[DOSIS_A]);
    loaderB->loadSprite(DOSIS_PATH,estadoDosisB,renderer,&texturas[DOSIS_B]);
}

Entorno::~Entorno()
{
	window = NULL;
	renderer = NULL;
}

void Entorno::renderizarTodo(Lista<Celula>* lista, Lista<Anticuerpo>* lista_anticuerpos)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer); // clear the renderer to the draw color
	renderizar(FONDO,0,0);
	renderizar(NANOBOT, nanobot.obtener_posicion_x(), nanobot.obtener_posicion_y());
	//renderizar(NANOBOT,0,SCREEN_HEIGHT-NANOBOT_HEIGHT);
	//Prepara el Draw para dibujar una linea negra
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //Inserte codigo para dibujar lineas
    //armado_red_grafica(renderer, lista);
    //Inserte codigo para renderizar imagenes
    int largo = lista->obtener_largo();
    float x, y;
    char tipo_celula;



    for(int i=1; i<=largo; i++){
        x = lista->obtener_valor(i).obtener_posicion_x();
        y = lista->obtener_valor(i).obtener_posicion_y();
        tipo_celula = lista->obtener_valor(i).obtener_tipo_celula();

        cout << "La imagen va en (" << x << "," << y << ")" << endl;

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
        renderizar(ANTICUERPO, x-25, y-25);
    }

	SDL_RenderPresent(renderer); // draw to the screen
}

void Entorno::limpiar()
{
    for(int i=0;i<7;i++)
        texturas[i].free();
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

void Entorno::desplazar_arriba(){
    int aux = nanobot.obtener_posicion_y();
    aux--;
    nanobot.asignar_posicion_y(aux);
}

void Entorno::desplazar_abajo(){
    int aux = nanobot.obtener_posicion_y();
    aux++;
    nanobot.asignar_posicion_y(aux);
}

void Entorno::desplazar_derecha(){
    int aux = nanobot.obtener_posicion_x();
    aux++;
    nanobot.asignar_posicion_x(aux);
}

void Entorno::desplazar_izquierda(){
    int aux = nanobot.obtener_posicion_x();
    aux--;
    nanobot.asignar_posicion_x(aux);
}

void Entorno::mover_arriba(Microorganismo &anticuerpo){
    float aux = anticuerpo.obtenerPosicionY();
    aux--;
    anticuerpo.asignarPosicionY(aux);
}

void Entorno::mover_abajo(Anticuerpo &anticuerpo){
    float aux = anticuerpo.obtener_posicion_y();
    aux++;
    anticuerpo.asignarPosicionY(aux);
}

void Entorno::mover_derecha(Anticuerpo &anticuerpo){
    float aux = anticuerpo.obtener_posicion_x();
    aux++;
    anticuerpo.asignarPosicionX(aux);
}

void Entorno::mover_izquierda(Anticuerpo &anticuerpo){
    float aux = anticuerpo.obtener_posicion_x();
    aux--;
    anticuerpo.asignarPosicionX(aux);
}
