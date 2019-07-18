#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envios.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EnviosFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{

    int retorno=-1;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferKilometros[4096];
    char bufferTipoDeEnvios[4096];
    Envios* pEnvios;
    if(pFile !=NULL && pArrayListEnvios != NULL)
    {

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre, bufferKilometros,bufferTipoDeEnvios);
            pEnvios= envios_newParametros(bufferId,bufferNombre, bufferKilometros,bufferTipoDeEnvios);
            if(pEnvios != NULL)
            {
                ll_add(pArrayListEnvios, pEnvios);
                //printf("\n%d", ll_len(pArrayListLLamadas));
                retorno = 0;
            }
        }
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
/*int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
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

}*/
