#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* auxLL;
    //char nombre[300];
    //int id;
    //int horasTrabajadas;
   // int sueldo;
   // Employee* pAux;
  //  char c;

    do{

        getEntero("\nMenu:\n\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n 3. Alta de empleado\n 4. Modificar datos de empleado\n 5. Baja de empleado\n 6. Listar empleados\n 7. Ordenar empleados\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n 10.Modificar sueldo \n 11.Menos de 100 horas\n 12.Eliminar menos de 100 horas \n13.Salir\nIngrese una opcion:","Error, opcion invalida",0,10,1,&option);
        system("clear");
        switch(option)
        {
            case 1:
                system("clear");
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2:
                controller_loadFromBinary("dataBkp.bin",listaEmpleados);
                break;

            case 3:
                system("clear");
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                system("clear");
                printf("cantidad:%d\n",ll_len(listaEmpleados));
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if(!controller_saveAsText("dataBkp.csv",listaEmpleados))
                {
                    printf("Datos guardados correctamente\n");
                }
                break;
            case 9:
                controller_saveAsBinary("dataBkp.bin",listaEmpleados);
                break;
            case 10:
                ll_map(listaEmpleados,controller_aumentoVeintePorcientoSueldos);
                controller_saveAsText("sueldos.csv",listaEmpleados);
                break;
            case 11:
                auxLL = ll_filter(listaEmpleados,controller_menosDeCienHoras);
                controller_saveAsText("pocasHoras.csv",auxLL);
            break;
            case 12:
                ll_reduce(listaEmpleados,controller_menosDeCienHoras);
                controller_saveAsText("pocasHorasFuera.csv",listaEmpleados);
                break;
            case 13:
                break;

        }
    }while(option != 13);

    /*
    FILE* pFILE=fopen("data.csv","r");
    Employee* pAux;
    char nombre[300];
    int id;
    int horasTrabajadas;
    int sueldo;

    parser_EmployeeFromText(pFILE,listaEmpleados);
    for(int i =0;i<ll_len(listaEmpleados);i++)
    {
        pAux=(Employee*)ll_get(listaEmpleados,i);
        if(pAux != NULL)
        {
            employee_getId(pAux,&id);
            employee_getHorasTrabajadas(pAux,&horasTrabajadas);
            employee_getSueldo(pAux,&sueldo);
            employee_getNombre(pAux,nombre);
            printf("ID: %d  Nombre: %s -- Horas trabajadas: %d -- Sueldo: %d\n",id,nombre,horasTrabajadas,sueldo);
        }
    }
    */
    return 0;
}
