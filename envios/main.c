#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envios.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
int main()
{
    int option = 0;
    //int resultado=0;
    LinkedList* listaEnvios = ll_newLinkedList();
    //LinkedList* auxLL;                                                                           // LinkedList* listaVenta = ll_newLinkedList();
                                                                           //controller_loadFromText("data.csv",listaVenta);
     do{
        getEntero("\n1-Cargar archivo\n2-Imprimir envios\n3-Generar archivo de costos\n4-Salir\n","error",1,5,1,&option);
        switch(option)
        {
            case 1:
                system("clear");
                controller_loadFromText("data_final2.csv",listaEnvios);

            break;

            case 2:
                controller_ListEnvios(listaEnvios);
            break;

            case 3:

                ll_map(listaEnvios,controller_aumentoPorKilometros);
                ll_map(listaEnvios,controller_costoTipoEntrega);
                controller_saveAsText("costos.csv",listaEnvios);
                //controller_saveAsText("mapeado.csv",auxLL);
            break;

            case 4:

            break;
        }



    }while(option != 4);
    return 0;
}
