#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ventas.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
int idMaxArray(LinkedList* pArrayLibros);
/** \brief Carga los datos  desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListVentas)
{
    int retorno = -1;
    FILE* fAux=NULL;
    if(path != NULL && pArrayListVentas != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_VentasFromText(fAux,pArrayListVentas))
            {

                printf("El archivo se cargo existosamente en modo texto!");
                retorno = 0;
            }
        }
        //fclose(fAux);
    }
    return retorno;
}

int idMaxArray(LinkedList* pArrayVenta)
{
    int retorno = -1;
    Venta* pAux;
    int idAux;
    int idMax = -1;
    if(pArrayVenta != NULL)
    {
        for(int i = 0; i<ll_len(pArrayVenta); i++)
        {
            pAux = ll_get(pArrayVenta,i);
            Venta_getId(pAux, &idAux);
            if(idAux>idMax)
            {
                idMax = idAux;
            }
        }
    }
    retorno = idMax;
    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListVentas(LinkedList* pArrayListVentas)
{
    int retorno = -1;
    int id;
    char fecha[51];
    char tipo[51];
    float precio;
    char cuit[51];

    Venta* pAux;
     printf("entro aca");
    if(pArrayListVentas != NULL)
    {
        for(int i =0; i<ll_len(pArrayListVentas); i++)
        {
            //printf("entro aca");
            //printf("I:%d - ",i);
            pAux=ll_get(pArrayListVentas,i);

            //llamadas_getIdProblema(pArrayListLLamadas,pAux);
            if(pAux != NULL)
            {

                Venta_getId(pAux,&id);
                Venta_getFecha(pAux,fecha);
                Venta_gettipo(pAux,tipo);
                Venta_getImporte(pAux,&precio);
                Venta_getCuit(pAux,cuit);

            }
        retorno = 0;
        }


    }
    return retorno;
}
//printf("Menu 6 -----





/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsTextVentas(char* path , LinkedList* pArrayListVenta)
{
    int retorno = -1;
    int totalPolaroid=0;
    int totalFotos=0;
    int ventasMayor150=0;
    int ventasMayor300=0;

    FILE *pFile = NULL;

    if(path != NULL && pArrayListVenta != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            totalFotos=cantidadFotos(pArrayListVenta);

            ventasMayor150=ll_count(pArrayListVenta,montoMayor150);
            ventasMayor300=ll_count(pArrayListVenta,montoMayor300);
            totalPolaroid=ll_count(pArrayListVenta,PolaroidReveladas);

            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad Total de fotos: %d\n", totalFotos);
            fprintf(pFile, "- Cantidad de ventas por un monto mayor a $150: %d \n",ventasMayor150);
            fprintf(pFile, "- Cantidad de ventas por un monto mayor a $300: %d \n",ventasMayor300);
            fprintf(pFile, "- Cantidad de polaroids: %d\n", totalPolaroid);
            //fprintf(pFile, "- Importe promedio por Entrega: %.2f\n", promedioPorEntrega);
            fprintf(pFile, "*****************************");

            retorno = 0;
        }
        if (retorno==0)
        {
            printf ("\nLista guardada correctamente.\n");
        }else
            printf ("\nNo se pudo guardar la lista correctamente.\n");
        fclose(pFile);
    }
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee *pEmployee=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                //printf("%s\n",pEmployee->nombre);
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
        }
        retorno = 0;
        fclose(pFile);
    }

    return retorno;
    //return 1;
}*/

int cantidadFotos(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int cantidadFotos=0;
    int acumulador=0;

    if (pArrayList!=NULL)
    {
        Venta* pAux;
        for (i=0;i<ll_len(pArrayList);i++)
        {
            pAux=ll_get(pArrayList,i);
            if(Venta_getCantidad(pAux,&cantidadFotos)==0)
            {
                acumulador = cantidadFotos+acumulador;
            }
            retorno=acumulador;
            //printf("Acumulador: %d",acumulador);
        }
    }
    return retorno;
}
int montoMayor150(void* p)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (p!=NULL)
    {
        Venta_getImporte(p,&auxImporte);
        Venta_getCantidad(p,&cantidad);
        total= auxImporte*cantidad;
        if (total>150)
        {

            retorno=1;
        }
    }

    return retorno;
}

int montoMayor300(void* p)
{
    int retorno=0;
    float auxImporte;
    int cantidad;
    float total;

    if (p!=NULL)
    {
        Venta_getImporte(p,&auxImporte);
        Venta_getCantidad(p,&cantidad);
        total= auxImporte*cantidad;
        //printf ("Total: %f",total);
        if (total>300)
        {
            retorno=1;
        }
    }

    return retorno;
}

int PolaroidReveladas(void* p)
{
    int retorno = 0;
    Venta* auxVenta = (Venta*)p;

    if ((strcmp(auxVenta->tipo,"POLAROID_11x9")==0) || (strcmp(auxVenta->tipo,"POLAROID_10x10")==0))
    {
        retorno=1;
    }
    return retorno;
}

int cantidadPolaroid(LinkedList* arrayListVentas)
{
    int retorno=-1;
    int i;
    //char tipo;
    int cantidad;
    int acumulador;
    Venta* pAux;

    if (arrayListVentas!=NULL)
    {
        for (i=0;i<ll_len(arrayListVentas);i++)
        {
            pAux=ll_get(arrayListVentas,i);
            if ((strcmp(pAux->tipo,"POLAROID_11X9")==0) || (strcmp(pAux->tipo,"POLAROID_10X10")==0))
            {
                Venta_getCantidad(pAux,&cantidad);
                acumulador=cantidad+acumulador;
            }
        }
        retorno=acumulador;
    }
    return retorno;
}
