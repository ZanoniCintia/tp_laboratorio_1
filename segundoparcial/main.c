#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "llamadas.h"
#include "funciones.h"
#include "validaciones.h"
int main()
{
    int option = 0;
    int resultado=0;
    LinkedList* listaLlamadas = ll_newLinkedList();
    LinkedList* auxLL;                                                                           // LinkedList* listaVenta = ll_newLinkedList();
       // printf("\n1-Cargar archivo\n");
       // printf("2-Imprimir llamadas\n");
       //printf("3-Generar archivo de llamadas\n");
        //printf("4-Salir\n");
        //getInt("ingrese una opcion: ","ingrese una opcion valida",1,5,3,&option);
                                                                              //controller_loadFromText("data.csv",listaVenta);
     do{
        getEntero("\n1-Cargar archivo\n2-Imprimir llamadas\n3-Generar archivo de llamadas\n4-Salir\n","error",1,4,1,&option);
        switch(option)
        {
            case 1:
                system("clear");
                controller_loadFromText("DATA_final1.csv",listaLlamadas);

            break;

            case 2:
                controller_ListLLamadas(listaLlamadas);
                //system("clear");

            break;

            case 3:
                getEntero("Ingrese numero del problema a listar :\n1:No enciende la pc\n2:No funciona el mouse\n3:No funciona el teclado\n4:No hay internet\n5:No funciona telefono\n","Error:ingrese de 1 a 5",1,5,3,&resultado);
                switch(resultado)
                {
                    case 1:
                        auxLL = ll_filter(listaLlamadas,problema1);
                        controller_saveAsText("archivoLlamadas.csv",auxLL);
                    break;

                    case 2:
                        auxLL = ll_filter(listaLlamadas,problema2);
                        //controller_saveAsText("archivoLlamadas.csv",auxLL);
                    break;

                    case 3:
                         auxLL = ll_filter(listaLlamadas,problema3);
                         //controller_saveAsText("archivoLlamadas.csv",auxLL);
                    break;

                    case 4:
                        auxLL = ll_filter(listaLlamadas,problema4);
                        //controller_saveAsText("archivoLlamadas.csv",auxLL);
                    break;

                    case 5:
                        auxLL = ll_filter(listaLlamadas,problema5);
                        //controller_saveAsText("archivoLlamadas.csv",auxLL);
                    break;

                }
                controller_saveAsText("archivoLlamadas.csv",auxLL);
            break;

            case 4:
            break;
        }


                                                                               //controller_ListVenta(listaVenta);
    }while(option != 4);                                                                        //controller_saveAsTextInformes("informes",listaVenta);
    return 0;
}
