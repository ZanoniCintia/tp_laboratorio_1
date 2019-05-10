#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "abm.h"
#include "utn.h"

int emp_initEmpleado(Empleado *arrayEmpleado, int len)
{
    int i;
    int retorno = -1;
    if(arrayEmpleado!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            arrayEmpleado[i].isEmpty=1;
        }
        retorno =0;
    }
    return retorno;

}

int emp_addEmpleado(Empleado *arrayEmpleado,int len, int *Id,char *nombre,char *apellido,float salario,int sector)
{
    int retorno=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty==1)
        {
            arrayEmpleado[i].Id=*Id;
            strncpy(arrayEmpleado[i].name,nombre,51);
            strncpy(arrayEmpleado[i].lastName,apellido,51);
            arrayEmpleado[i].salary=salario;
            arrayEmpleado[i].sector=sector;
            arrayEmpleado[i].isEmpty=0;
            Id++;
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int emp_buscarPorId(Empleado *arrayEmpleado, int len, int id)
{
    int i;
    int retorno = -1;
    if (arrayEmpleado!=NULL && len>0 && id>=0)
    {
        for(i=0; i<len; i++)
        {
            if(arrayEmpleado[i].Id==id)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int emp_mostrarArray(Empleado *arrayEmpleado, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(arrayEmpleado[i].isEmpty==0)
        {
            printf("Id: %d \n", arrayEmpleado[i].Id);
            printf("nombre: %s \n",arrayEmpleado[i].name);
            printf("apellido: %s \n",arrayEmpleado[i].lastName);
            printf("salario: %.2f \n",arrayEmpleado[i].salary);
            printf("sector: %d \n\n",arrayEmpleado[i].sector);


        }
    }
    return 0;
}

int emp_borrarEmpleado(Empleado *arrayEmpleado, int len,int id)
{
    int retorno=-1;
    int auxId=emp_buscarPorId(arrayEmpleado,len,id);
    if(arrayEmpleado!=NULL && len>0 && id>=0)
    {
        if(auxId != -1)
        {
            arrayEmpleado[auxId].isEmpty=1;
            retorno=0;
        }
    }

    return retorno;

}

int emp_ordenarMayoraMenor(Empleado *arrayEmpleado,int len)
{
    int i;
    int j;
    int retorno =-1;
    Empleado aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayEmpleado[i].lastName,arrayEmpleado[j].lastName,50)<0)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;
                retorno =0;
            }
            else if(arrayEmpleado[i].sector<arrayEmpleado[j].sector)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;
                retorno =0;
            }
        }
    }
    emp_mostrarArray(arrayEmpleado,len);
    return retorno;

}
int emp_ordenarMenoraMayor(Empleado *arrayEmpleado,int len)
{
    int i;
    int j;
    int retorno =-1;
    Empleado aux;

    for(i=0; i<len; i++)
    {
        for(j=i+1; j<=len; j++)
        {
            if(strncmp(arrayEmpleado[i].lastName,arrayEmpleado[j].lastName,50)<0)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;
                retorno =0;
            }
            else if(strcmp(arrayEmpleado[i].lastName,arrayEmpleado[j].lastName)==0)
            {
                if(arrayEmpleado[i].sector<arrayEmpleado[j].sector)
                {
                    aux=arrayEmpleado[i];
                    arrayEmpleado[i]=arrayEmpleado[j];
                    arrayEmpleado[j]=aux;
                    retorno =0;
                }
            }
        }


    }

    return retorno;

}

int emp_calcularPromedioSalario(Empleado *arrayEmpleado,int len)
{
    int i;
    int acumuladorSalarioEncimaPromedio=0;
    float acumulador=0;
    int cantidad=0;
    float promedio;
    int retorno = -1;
    for(i=0;i<len;i++)
    {
       if(arrayEmpleado[i].isEmpty==0)
       {
            acumulador+=arrayEmpleado[i].salary;
            cantidad++;
       }
       retorno = 0;
    }
    promedio=acumulador/cantidad;
    printf("el promedio es: %.2f\n",promedio);
    for(i=0;i<len;i++)
    {
        if((arrayEmpleado[i].isEmpty==0)&&(arrayEmpleado[i].salary>promedio))
        {
            acumuladorSalarioEncimaPromedio++;
        }
    }
    printf("la cantidad de empleado con salario mayor al promedio es : %d\n",acumuladorSalarioEncimaPromedio);
    return retorno;
}

int emp_modificarEmpleado(Empleado *arrayEmpleado,int len,int Id)
{
    int retorno=-1;
    int id=-1;
    id=emp_buscarPorId(arrayEmpleado,len,Id);
    if(id!=-1)
    {
        if(!getName("ingrese nuevo nombre:\n","nombre invalido",2,51,3,arrayEmpleado[id].name)
            && !getName("ingrese nuevo apellido:\n","apellido invalido",2,51,3,arrayEmpleado[id].lastName)
            && !getFloat("ingrese nuevo salario:\n","salario invalido",1,50000,3,&arrayEmpleado[id].salary)
            && !getInt("ingrese nuevo sector:\n","sector invalido",1,4,3,&arrayEmpleado[id].sector))
        {
                printf("datos modificados correctamente");
        }else{
                printf("no fue posible modificar los datos");
        }
        retorno = 0;
    }

    return retorno;

}


