#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "llamadas.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LLamadasFromText(FILE* pFile , LinkedList* pArrayListLLamadas)
{

    int retorno=-1;
    char bufferId[4096];
    char bufferFecha[4096];
    char bufferIdProblema[4096];
    char bufferNumeroCliente[4096];
    char bufferSolucion[4096];
    LLamadas* pLLamadas;
    if(pFile !=NULL && pArrayListLLamadas != NULL)
    {

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucion);
            pLLamadas= llamadas_newParametros(bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucion);
            if(pLLamadas != NULL)
            {
                ll_add(pArrayListLLamadas, pLLamadas);
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
