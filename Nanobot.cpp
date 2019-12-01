#include "Nanobot.h"
#include <iostream>

//Constructores
Nanobot::Nanobot(){
    posicion.x = 0;
    posicion.y = 0;
    destino = posicion;
}

Nanobot::Nanobot(int x, int y, Lista<Celula>* lista_celulas){
    posicion.x = x;
    posicion.y = y;
    destino = posicion;
    this->lista_celulas = lista_celulas;
    ir_a_cercana();

    //Borrar
    /*
    Posta* posta_borrar = new Posta;
    posta_borrar->camino = 10;
    posta_borrar->costo = 4;
    ruta.extender(posta_borrar);
    */
    ir_a(10);
}

void Nanobot::desplazar(int x, int y, int lentitud)
{
    destino.x = x;
    destino.y = y;
    int dif_x = destino.x - posicion.x;
    int dif_y = destino.y - posicion.y;
    double distancia = sqrt((dif_x)*(dif_x) + (dif_y)*(dif_y));
    this->velocidad = distancia/(lentitud*5);
}

void Nanobot::actualizar()
{
    if (!red_mapeada){
        //Si ademas, habia elementos en ruta y el destino no era la celula cercana, recalcular trayectoria
        if (ruta.obtener_largo() > 0 && ruta.obtener_puntero(1)->camino != indice_celula_cercana)
            ir_a(ruta.obtener_puntero(1)->camino);
    }

    if (posicion.x != destino.x || posicion.y != destino.y){
        Vector2 desplazamiento;
        desplazamiento.x = destino.x - posicion.x;
        desplazamiento.y = destino.y - posicion.y;
        if (abs(desplazamiento.x) <= velocidad && abs(desplazamiento.y) <= velocidad){ //Se coloca en destino para evitar deriva
            posicion.x = destino.x;
            posicion.y = destino.y;

            //Si hay Postas en la ruta, desplazarse
            if (ruta.obtener_largo() > 0){
                Posta* siguiente = ruta.obtener_puntero(ruta.obtener_largo()); //Elijo la ultima Posta agregada
                indice_celula_cercana = siguiente->camino;
                Celula* cel_siguiente = lista_celulas->obtener_puntero(indice_celula_cercana);

                desplazar(cel_siguiente->obtenerPosicionX(), cel_siguiente->obtenerPosicionY(), siguiente->costo);
                ruta.borrar(ruta.obtener_largo());
            }
        }
        else{
            double norma = sqrt(desplazamiento.x*desplazamiento.x + desplazamiento.y*desplazamiento.y);
            posicion.x = posicion.x + round(velocidad * desplazamiento.x/norma);
            posicion.y = posicion.y + round(velocidad * desplazamiento.y/norma);
        }
    }
    else if (ruta.obtener_largo() > 0){
        Posta* siguiente = ruta.obtener_puntero(ruta.obtener_largo()); //Elijo la ultima Posta agregada
        indice_celula_cercana = siguiente->camino;
        Celula* cel_siguiente = lista_celulas->obtener_puntero(indice_celula_cercana);

        desplazar(cel_siguiente->obtenerPosicionX(), cel_siguiente->obtenerPosicionY(), siguiente->costo);
        ruta.borrar(ruta.obtener_largo());
    }
}

void Nanobot::ir_a(int indice_destino)
{
    if (indice_destino != indice_celula_cercana){

        mapear(indice_celula_cercana);

        //Limpio la ruta
        while (ruta.obtener_largo() > 0)
            ruta.borrar(1);

        Posta* recorrido_inverso = new Posta; //Posta para extender la Lista ruta. No borrar
        Posta* posta_actual = mapa.obtener_puntero(indice_destino);         //Referencia a una Posta del Mapa...
        Posta* posta_anterior = mapa.obtener_puntero(posta_actual->camino); //...No alterar

        recorrido_inverso->camino = indice_destino;
        recorrido_inverso->costo = posta_actual->costo - posta_anterior->costo; //Calculamos los costos individuales

        ruta.extender(recorrido_inverso);
        cout<<"Ruta:"<<endl<<recorrido_inverso->camino<<" "<<recorrido_inverso->costo<<endl;

        while (posta_anterior->camino > 0){ //Mientras exista otra posta
            recorrido_inverso = new Posta;
            recorrido_inverso->camino = posta_actual->camino;
            posta_actual = posta_anterior;
            posta_anterior = mapa.obtener_puntero(posta_actual->camino);

            recorrido_inverso->costo = posta_actual->costo - posta_anterior->costo;

            ruta.extender(recorrido_inverso);
            cout<<recorrido_inverso->camino<<" "<<recorrido_inverso->costo<<endl;
        }
    }
}

void Nanobot::recalcular_mapa(int indice_removido)
{
    cout<<"Recalculando mapa"<<endl;
    red_mapeada = false;
    if (indice_removido == indice_celula_cercana){
        cout<<"Cel cercana removida. Buscando cercana nueva..."<<endl;
        ir_a_cercana(); //Si removieron la celula de la nueva posicion del bot, ir a otra
    }
    else{
        if (indice_removido < indice_celula_cercana){
            cout<<"Removido < cel_cercana: "<<indice_celula_cercana<<endl;
            indice_celula_cercana--; //Si removieron una celula de indice inferior, ajustar indice_celula_cercana
            cout<<"Indice cercana ajustado: "<<indice_celula_cercana<<endl;
        }
    }

    if (ruta.obtener_largo() > 0){
        Posta* posta_final = ruta.obtener_puntero(1);
        if (posta_final->camino == indice_removido){
        //Si removieron la Celula destino, detener movimiento
        cout<<"Destino removido... Deteniendo movimiento"<<endl;
        while (ruta.obtener_largo() > 0)
            ruta.borrar(1);
        }else if (posta_final->camino > indice_removido){
                cout<<"Ajustando indice destino"<<endl;
                posta_final->camino = posta_final->camino -1;
            }
    }
}

void Nanobot::ir_a_cercana()
{
    Celula* cel_cercana = 0;
    float dist_cercana = INFINITY;
    for (int i = 1; i <= lista_celulas->obtener_largo(); i++){
        Celula* cel_actual = lista_celulas->obtener_puntero(i);
        Vector2 diferencia;
        diferencia.x = fabs(posicion.x - cel_actual->obtenerPosicionX());
        diferencia.y = fabs(posicion.y - cel_actual->obtenerPosicionY());
        float dist_actual = sqrt(diferencia.x*diferencia.x + diferencia.y*diferencia.y);
        if (dist_cercana > dist_actual){
            cel_cercana = cel_actual;
            dist_cercana = dist_actual;
            indice_celula_cercana = i;
        }
    }
    desplazar(cel_cercana->obtenerPosicionX(), cel_cercana->obtenerPosicionY(), 7);
}

void Nanobot::mapear(int indice_inicial)
{
    int cant_celulas = lista_celulas->obtener_largo();

    //Creo un vector de Postas con mismo largo que lista_celulas
    Posta postas[cant_celulas];
    bool vistas[cant_celulas];

    postas[indice_inicial - 1].costo = 0; //Costo de movimiento desde A hasta A nulo
    postas[indice_inicial - 1].camino = 0; //No hay camino para ir desde A hasta A

    int postas_x_ver = cant_celulas;
    int indice_actual = indice_inicial; //Indice de la celula que se esta usando para mapear los pesos de las adyacentes. 0 indica nulo
    float valor_minimo = INFINITY;

    while (postas_x_ver > 0){
        //Busco la Posta con el minimo costo que no haya sido vista
        for (int i = 1; i <= cant_celulas; i++){
            if (valor_minimo >= postas[i-1].costo && vistas[i-1] != true){ // Si el costo es minimo y no fue visto
                indice_actual = i;
                valor_minimo = postas[i-1].costo;
            }
        }
        valor_minimo = INFINITY;
        vistas[indice_actual - 1] = true;
        postas_x_ver--;

        cout<<"Evaluando en "<<indice_actual<<endl;

        //Evaluo en las celulas adyacentes
        Celula* cel_actual = lista_celulas->obtener_puntero(indice_actual);
        for (int ady = 1; ady <= cel_actual->obtenerCantidadAdyacentes(); ady++){
            int indice_cel_ady = cel_actual->obtenerAdyacente(ady);
            float costo_pasando_x_actual = postas[indice_actual-1].costo + float(cel_actual->obtenerPesoAdyacente(ady));
            if (postas[indice_cel_ady - 1].costo > costo_pasando_x_actual){
                postas[indice_cel_ady - 1].costo = costo_pasando_x_actual;
                postas[indice_cel_ady - 1].camino = indice_actual;
            }
        }
    }

    //Limpia el mapa
    while (mapa.obtener_largo() > 0)
        mapa.borrar(1);

    //Carga las postas en el mapa
    cout<<"Mapa:"<<endl;
    for (int p = 0; p < cant_celulas; p++){
        Posta* posta = new Posta;
        posta->costo = postas[p].costo;
        posta->camino = postas[p].camino;
        mapa.extender(posta);
        cout<<posta->camino<<" "<<posta->costo<<endl;
    }

    red_mapeada = true;
}


//Setters
void Nanobot::asignar_posicion_x(int x){
    posicion.x = x;
}

void Nanobot::asignar_posicion_y(int y){
    posicion.y = y;
}

//Getters
int Nanobot::obtener_posicion_x(){
    return posicion.x;
}

int Nanobot::obtener_posicion_y(){
    return posicion.y;
}
