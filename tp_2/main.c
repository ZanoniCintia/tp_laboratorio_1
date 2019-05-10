#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#include "utn.h"
#include <string.h>
#define PERSONAL 1000

int main()
{

    int opcion=0;
    int id=0;
    int contadorAlta=1;
    char nombre[51];
    char apellido[51];
    int sector;
    float salario;

    Empleado lista[PERSONAL];
    emp_initEmpleado(lista,PERSONAL);
    printf("\n***Registro de personal***\n\n");

    lista[0].isEmpty=0;
    strcpy(lista[0].name,"Cintia");
    strcpy(lista[0].lastName,"Zanoni");
    lista[0].salary=1000.20;
    lista[0].sector=1;
    lista[0].Id=0;

    lista[1].isEmpty=0;
    strcpy(lista[1].name,"Joe");
    strcpy(lista[1].lastName,"Morello");
    lista[1].salary=5000.20;
    lista[1].sector=2;
    lista[1].Id=1;

    lista[2].isEmpty=0;
    strcpy(lista[2].name,"Bryanna");
    strcpy(lista[2].lastName,"Barrios");
    lista[2].salary=3000.20;
    lista[2].sector=3;
    lista[2].Id=2;

    do
    {
        printf("1-Alta de empleado\n");
        printf("2-Baja de empleado\n");
        printf("3-Modificacion de datos\n");
        printf("4-visualizar informe de personal\n");
        printf("5-salir\n");
        getInt("ingrese una opcion: ","ingrese una opcion valida",1,5,3,&opcion);

        switch(opcion)
        {
            case 1:
            if(!getName("ingrese un nombre: ","Error, reingrese nombre: ",2,51,3,nombre)
                && !getName("ingrese apellido :","error, reingrese apellido",2,51,3,apellido)
                && !getFloat("ingrese salario :","error, reingrese salario",1,50000,3,&salario)
                && !getInt("ingrese sector:\n 1.ventas\n 2.cajas \n 3.administracion \n 4.seguridad","error, ingrese un sector valido",1,4,3,&sector)
                && emp_addEmpleado(lista,PERSONAL,&id,nombre,apellido,salario,sector))
            {
                printf("carga exitosa");
                contadorAlta++;
            }else{
                    printf("error de carga");
            }
            break;

            case 2:
            if(contadorAlta!=0)
            {
                if(!getInt("ingrese id para borrar","error,reingrese id",0,1000,3,&id)&&(!emp_borrarEmpleado(lista,PERSONAL,id)))
                {   printf("Baja exitosa");
                    contadorAlta--;
                }

            }
            break;

            case 3:
            if(contadorAlta!=0)
            {   if(!getInt("ingrese id para modificar","error,reingrese id",0,1000,3,&id)&&(
                emp_modificarEmpleado(lista,PERSONAL,id)))
                {
                    printf("modificacion exitosa");
                }
            }
            break;

            case 4:
            if(contadorAlta!=0)
            {
                emp_mostrarArray(lista,PERSONAL);
                getInt("ingrese :\n1- para ordenar por nombre/sector:\n2-para calcular promedio de salario:\n","opcion invalida",1,2,3,&opcion);
                switch(opcion)
                {
                    case 1:
                    emp_ordenarMayoraMenor(lista,PERSONAL);
                    break;
                    case 2:
                    emp_calcularPromedioSalario(lista,PERSONAL);
                    break;
                }
                break;
            }
            case 5:
            break;
        }

   }while(opcion!=5);

    return 0;
}
