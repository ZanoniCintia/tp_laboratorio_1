#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "libros.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"

int main()
{
    int option = 0;
    int resultado=0;
    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* auxLL;                                                                           // LinkedList* listaVenta = ll_newLinkedList();
       // printf("\n1-Cargar archivo\n");
       // printf("2-Imprimir llamadas\n");
       //printf("3-Generar archivo de llamadas\n");
        //printf("4-Salir\n");
        //getInt("ingrese una opcion: ","ingrese una opcion valida",1,5,3,&option);
                                                                              //controller_loadFromText("data.csv",listaVenta);
     do{
        getEntero("\n1-Cargar archivo\n2-Ordenar lista por ID editorial\n3-Generar archivo de libros con descuento\n4-Salir\n","error",1,4,1,&option);
        switch(option)
        {
            case 1:
                system("clear");
                controller_loadFromText("data.csv",listaLibros);

            break;

            case 2:
                 //system("clear");
                //ll_sort(listaLibros,controller_CriterioOrdenAscendente,0);
                controller_sortLibros(listaLibros);


            break;

            case 3:
                getEntero("Ingrese numero de editorial :\n1:PLANETA descuento 20% \n2:SIGLO XXI EDITORES descuento 10%\n","Error",1,2,3,&resultado);
                switch(resultado)
                {
                    case 1:
                        ll_map(listaLibros,controller_descuentoVeintePorciento);
                        controller_saveAsText("mapeado.csv",listaLibros);
                    break;

                    case 2:
                        ll_map(listaLibros,controller_descuentoDiezPorciento);
                        controller_saveAsText("mapeado.csv",listaLibros);
                    break;

                }
                //controller_saveAsText("mapeado.csv",auxLL);
            break;

            case 4:
            break;
        }



    }while(option != 4);
    return 0;
}
