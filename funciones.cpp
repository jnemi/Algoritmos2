#include "funciones.h"

//Funcion para leer el archivo
void lectura(Elemento **vec, int &mL){
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
   int i=0;

   //Recorro el archivo
   while((archivo >> dato)&&(i < 100)){
      procesarArchivo(archivo, dato, i, vec);
      i++;
   }

   //Asigno maximo logico
   mL = i;
   //Cierro el archivo
   archivo.close();
}

//Funcion para procesar los datos del archivo
void procesarArchivo(ifstream &archivo, string &dato, int &i, Elemento **vec){
   float aux1, aux2;
   char aux3;
   unsigned int aux4;
   if(dato == "celula"){
      //Se crea objeto Celula
      archivo >> dato;
      archivo >> aux1;
      archivo >> aux2;
      if(dato == "X"){
        vec[i] = new Celula_x(aux1, aux2, 0, 0, "-", true, 0);
      }else{
        if(dato == "Y"){
          vec[i] = new Celula_y(aux1, aux2, 0, 0, "-", true, 0);
        }else{
          if(dato == "Z"){
            vec[i] = new Celula_z(aux1, aux2, 0, 0, "-", true, 0);
          }else{
            vec[i] = new Celula_s(aux1, aux2, 0, 0, "-", true);
          }
        }
      }
   }else{
     if(dato == "anticuerpo"){
       //se crea objeto anticuerpo
       archivo >> aux1;
       archivo >> aux2;
       vec[i] = new Anticuerpo(aux1, aux2);
     }else{
          if(dato == "dosis"){
            //se crea objeto dosis
            archivo >> aux3;
            //aux3 = dato;
            archivo >> aux4;
            vec[i] = new Suero(aux3, aux4);
         }
       }
     }
   }

   //Menu
   void menu(Elemento **vec, int &mL){
      //Variable para elegir una opcion del menu
      unsigned int opcion;
      //Variable para salir del ciclo del menu
      bool salir = true;
      //Variable para informar en el menu si se proceso o no el archivo
      bool procesado = false;

      cout  << "Trabajo Practico numero 2: Polimorfismo" << endl << endl;
      system("read -p 'Presione enter para continuar...' var");
      cout << endl << "                MENU" << endl << endl;
      cout << "1- Procesar archivo de texto." << endl;
      cout << "2- Mostrar todos los datos del vector." << endl;
      cout << "3- Mostrar los datos de una posicion especifica del vector." << endl;
      cout << "4- Finalizar programa." << endl;

      do{
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:
          lectura(vec, mL);
          procesado = true;
          cout << endl << "Proceso finalizado." << endl << endl;
          system("read -p 'Presione enter para continuar...' var");
          break;
        case 2:
          if(procesado)
            mostrarDatos(vec, mL);
          else
            cout << "Debe procesar el archivo para acceder a esta opcion." << endl;
          system("read -p 'Presione enter para continuar...' var");
          break;
        case 3:
          if(procesado)
            mostrarPosicion(vec, mL);
          else
            cout << "Debe procesar el archivo para acceder a esta opcion." << endl;
          system("read -p 'Presione enter para continuar...' var");
          break;
        case 4:
          cout << endl << "Programa finalizado." << endl;
          for(int i=0; i<mL; i++)
            delete vec[i];
          salir = false;
          break;
        default:
          cout << "Opcion incorrecta" << endl;
      }
     }while(salir);
   }

   //Mostrar todos los datos del vector
   void mostrarDatos(Elemento **vec, int mL){
      for(int i=0; i<mL; i++){
        vec[i] -> mostrar();
        cout << "---------------" << endl;
      }
   }

   //Mostrar los datos de una posicion especifica del vector
   void mostrarPosicion(Elemento **vec, int mL){
      int posicion;
      cout << "Ingrese la posicion del vector: ";
      cin >> posicion;
      //Validacion de la posicion
      while((posicion >= mL)||(posicion < 0)){
         cout << endl << "Posicion incorrecta, vuelva a ingresarla." << endl;
         cout << "Ingrese la posicion del vector: ";
         cin >> posicion;
      }
      //Muestra datos del vector en la posicion especficada
      cout << endl <<  "--------------" << endl;
      vec[posicion] -> mostrar();
      cout << "--------------" << endl;
   }
