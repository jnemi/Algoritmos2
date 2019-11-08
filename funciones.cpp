#include "funciones.h"

//Funcion para leer el archivo
void lectura(Lista<Elemento>* lista_general, Lista <Celula> *lista_celulas){
   ifstream archivo;
   //Abro el archivo para lectura
   archivo.open("estado.txt");

   //Compruebo la existencia del archivo
   if(!archivo){
      cout << "Archivo inexistente." << endl << endl << endl;
      system("read -p 'Presione enter para continuar...' var");
      exit(1);
   }

   //Variables para recorrer el archivo
   string dato;

   //Recorro el archivo
   while(archivo >> dato){
      procesar_archivo(archivo, dato, lista_general, lista_celulas);
   }


   //Cierro el archivo
   archivo.close();
}

//Funcion para procesar los datos del archivo
void procesar_archivo(ifstream &archivo, string &dato, Lista<Elemento> *lista_general, Lista<Celula>* lista_celulas){
   float aux1, aux2;
   char aux3;
   unsigned int aux4;
   if(dato == "celula"){
      //Se crea objeto Celula
      archivo >> dato;
      archivo >> aux1;
      archivo >> aux2;
      if(dato == "X")
        lista_celulas -> extender(new Celula_x(aux1, aux2));
      else if(dato == "Y")
        lista_celulas -> extender(new Celula_y(aux1, aux2));
      else if(dato == "Z")
        lista_celulas -> extender(new Celula_z(aux1, aux2));
      else
        lista_celulas -> extender(new Celula_s(aux1, aux2));
   }else{
     if(dato == "anticuerpo"){
       //se crea objeto anticuerpo
       archivo >> aux1;
       archivo >> aux2;
       lista_general -> extender(new Anticuerpo(aux1, aux2));
     }else{
          if(dato == "dosis"){
            //se crea objeto dosis
            archivo >> aux3;
            //aux3 = dato;
            archivo >> aux4;
            lista_general -> extender(new Suero(aux3, aux4));
         }
       }
     }
}

void armado_red_celulas(Lista<Elemento>* lista){

}
