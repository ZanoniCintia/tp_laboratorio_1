#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "libros.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros)
{

    int retorno=-1;
    char bufferId[4096];
    char bufferTitulo[4096];
    char bufferAutor[4096];
    char bufferPrecio[4096];
    char bufferEditorialId[4096];
    eLibros* pLibros;
    if(pFile !=NULL && pArrayListLibros != NULL)
    {

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTitulo,bufferAutor,bufferPrecio,bufferEditorialId);
            pLibros= libros_newParametros(bufferId,bufferTitulo,bufferAutor,bufferPrecio,bufferEditorialId);
            if(pLibros != NULL)
            {
                ll_add(pArrayListLibros, pLibros);
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
