#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int retorno=-1;
    int cantidad;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    Employee* pEmployee;
    if(pFile !=NULL && pArrayListEmployee != NULL)
    {
        do
        {
            cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            if(cantidad==4)
            {
                pEmployee=employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                if(pEmployee !=NULL)
                {
                    ll_add(pArrayListEmployee,pEmployee);
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee auxEmployee;
    Employee* employee;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            employee = employee_newFileBinario(auxEmployee);
            fread(&auxEmployee,sizeof(Employee),1,pFile);
            if(employee != NULL)
            {
                ll_add(pArrayListEmployee,employee);
            }
            else
            {
                employee_delete(employee);
            }
        }
        retorno = 0;
    }
    fclose(pFile);
    return retorno;

}
