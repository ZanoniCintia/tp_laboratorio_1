#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ventas.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
int main()
{

    LinkedList* listaVenta = ll_newLinkedList();
    controller_loadFromText("data.csv",listaVenta);
    controller_ListVentas(listaVenta);
    controller_saveAsTextVentas("informes",listaVenta);
    return 0;
}
