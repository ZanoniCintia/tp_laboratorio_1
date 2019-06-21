
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn_validaciones.h"


Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* retorno = NULL;
    Employee* pEmployee=employee_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL &&  sueldo != NULL && pEmployee != NULL)
    {
        if(isValidEntero(idStr) && isValidEntero(horasTrabajadasStr) && isValidEntero(sueldo))
        {
                if( employee_setId(pEmployee,atoi(idStr))
                    || employee_setNombre(pEmployee,nombreStr)
                    || employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr))
                    || employee_setSueldo(pEmployee,atoi(sueldo))
                   )
                    {
                        employee_delete(pEmployee);
                    }else
                        {
                            retorno = pEmployee;
                        }
        }
    }

    return retorno;
}
Employee* employee_newFileBinario(Employee empleado)
{
    Employee* retorno = NULL;
    Employee* pAuxEmployee = employee_new();
    if(pAuxEmployee != NULL)
    {
        if(employee_setId(pAuxEmployee,empleado.id)||employee_setNombre(pAuxEmployee,empleado.nombre)
            ||employee_setHorasTrabajadas(pAuxEmployee,empleado.horasTrabajadas)||employee_setSueldo(pAuxEmployee,empleado.sueldo))
        {
            employee_delete(pAuxEmployee);
        }else
            {
                retorno = pAuxEmployee;
            }
    }
    return retorno;
}


void employee_delete(Employee* this)
{

    if(this != NULL)
    {
        free(this);

    }

}

int employee_setId(Employee* this,int id)
{
     int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;

}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre!= NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL )//&& isValidNumber(horasTrabajadas))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;

}
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo> 0 && sueldo<=50000)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_comparacionNombre(void* this1, void* this2)
{
    int retorno = 0;
    char nombre[60];
    char nombreDos[60];
    int resultadoComparacion;
    Employee* auxEmployee;
    Employee* auxEmployeeDos;
    if(this1 != NULL && this2 != NULL)
    {
        auxEmployee = (Employee*)this1;
        auxEmployeeDos = (Employee*)this2;
        employee_getNombre(auxEmployee, nombre);
        employee_getNombre(auxEmployeeDos,nombreDos);
        resultadoComparacion = strcmp(nombre,nombreDos);
        if(resultadoComparacion > 0)
            retorno = 1;
        else if(resultadoComparacion<0)
            retorno = -1;
    }
    return retorno;
}

