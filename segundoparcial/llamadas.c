#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "llamadas.h"
#include "validaciones.h"
#include "funciones.h"


LLamadas* llamadas_new()
{
    return (LLamadas*) malloc(sizeof(LLamadas));
}
LLamadas* llamadas_newParametros(char* id,char* fecha,char* numeroCliente,char* idProblema,char* solucion)
{
    LLamadas* retorno=NULL;
    LLamadas* pAuxLLamadas=llamadas_new();;

    if(id != NULL && fecha != NULL && numeroCliente != NULL && idProblema != NULL && solucion != NULL)
    {

       if(isValidEntero(id)&&isValidEntero(idProblema)&&isValidEntero(numeroCliente))
       {
            if(llamadas_setId(pAuxLLamadas,atoi(id))
               || llamadas_setFecha(pAuxLLamadas,fecha)
               || llamadas_setNumeroCliente(pAuxLLamadas,atoi(numeroCliente))
               || llamadas_setIdProbelma(pAuxLLamadas,atoi(idProblema))
               || llamadas_setSolucion(pAuxLLamadas,solucion))
            {
                llamadas_delete(pAuxLLamadas);


            }else{
                 retorno = pAuxLLamadas;
            }
       }

    }
return retorno;
}

void llamadas_delete(LLamadas* this)
{

    if(this != NULL)
    {
        free(this);

    }

}
int llamadas_setId(LLamadas* this,int id)
{
     int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;

}

int llamadas_getId(LLamadas* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}
int llamadas_setIdProbelma(LLamadas* this,int idProblema)
{
     int retorno = -1;
    if(this != NULL && idProblema >= 0)
    {
        this->idProblema= idProblema;
        retorno = 0;
    }
    return retorno;

}

int llamadas_getIdProblema(LLamadas* this,int* idProblema)
{
    int retorno = -1;
    if(this != NULL && idProblema != NULL)
    {
        *idProblema = this->idProblema;
        retorno = 0;
    }
    return retorno;

}

int llamadas_setFecha(LLamadas* this,char* fecha)
{
    int retorno=-1;

    if (this!=NULL && fecha!=NULL)// && isValidFecha(fecha)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

int llamadas_getFecha(LLamadas* this,char* fecha)
{
    int retorno=-1;

    if (this!=NULL && fecha!=NULL )
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}
int llamadas_setSolucion(LLamadas* this,char* solucion)
{
    int retorno=-1;

    if (this!=NULL && solucion!=NULL)
    {
        strcpy(this->solucion,solucion);
        retorno=0;
    }
    return retorno;
}

int llamadas_getSolucion(LLamadas* this,char* solucion)
{
    int retorno=-1;

    if (this!=NULL && solucion!=NULL )
    {
        strcpy(solucion,this->solucion);
        retorno=0;
    }
    return retorno;
}
int llamadas_setNumeroCliente(LLamadas* this,int numeroCliente)
{
    int retorno=-1;
    if (this!=NULL && numeroCliente>=0 && isValidInt(numeroCliente,1,999999))
    {
        this->numeroCliente=numeroCliente;
        retorno=0;
    }
    return retorno;
}

int llamadas_getNumeroCliente(LLamadas* this,int* numeroCliente)
{
    int retorno=-1;
    if (this!=NULL && numeroCliente!=NULL)
    {
        *numeroCliente=this->numeroCliente;
        retorno=0;
    }
    return retorno;
}
