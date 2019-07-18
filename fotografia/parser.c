#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ventas.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListVentas)
{

    int retorno=-1;
    char bufferId[4096];
    char bufferfecha[4096];
    char buffertipo[4096];
    char buffercantidad[51];
    char bufferPrecio[4096];
    char buffercuit[4096];
    Venta* pVentas;
    if(pFile !=NULL && pArrayListVentas != NULL)
    {

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferfecha,buffertipo,buffercantidad,bufferPrecio,buffercuit);
            pVentas= Venta_newParametros(bufferId,bufferfecha,buffertipo,buffercantidad,bufferPrecio,buffercuit);
            if(pVentas != NULL)
            {
                ll_add(pArrayListVentas, pVentas);
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
