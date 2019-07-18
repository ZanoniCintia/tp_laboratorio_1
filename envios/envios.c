#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "envios.h"
#include "validaciones.h"
#include "funciones.h"

Envios* envios_new()
{
    return (Envios*) malloc(sizeof(Envios));
}

Envios* envios_newParametros(char* id,char* nombre,char* kilometros,char* tipoDeEntrega)
{
    Envios* retorno=NULL;
    Envios* pAuxEnvios=envios_new();

    if(id != NULL && nombre != NULL && kilometros != NULL && tipoDeEntrega != NULL )
    {

       if(isValidEntero(id)&&isValidEntero(kilometros))
       {
            if(envios_setId(pAuxEnvios,atoi(id))
               || envios_setNombre(pAuxEnvios,nombre)
               || envios_setKilometros(pAuxEnvios,atoi(kilometros))
               || envios_setTipoDeEntrega(pAuxEnvios,atoi(tipoDeEntrega)))
            {
                envios_delete(pAuxEnvios);


            }else{
                 retorno = pAuxEnvios;
            }
       }

    }
return retorno;
}

void envios_delete(Envios* this)
{

    if(this != NULL)
    {
        free(this);

    }

}

int envios_setId(Envios* this,int id)
{
     int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;

}

int envios_getId(Envios* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}

int envios_setNombre(Envios* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int envios_getNombre(Envios* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL )
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int envios_setKilometros(Envios* this,int kilometros)
{
     int retorno = -1;
    if(this != NULL && kilometros >= 0)
    {
        this->kilometros = kilometros;
        retorno = 0;
    }
    return retorno;

}

int envios_getKilometros(Envios* this,int* kilometros)
{
    int retorno = -1;
    if(this != NULL && kilometros != NULL)
    {
        *kilometros = this->kilometros;
        retorno = 0;
    }
    return retorno;

}
int envios_setTipoDeEntrega(Envios* this,int tipoDeEntrega)
{
     int retorno = -1;
    if(this != NULL && tipoDeEntrega >= 0)
    {
        this->tipoDeEntrega = tipoDeEntrega;
        retorno = 0;
    }
    return retorno;

}

int envios_getTipoDeEntrega(Envios* this,int* tipoDeEntrega)
{
    int retorno = -1;
    if(this != NULL && tipoDeEntrega != NULL)
    {
        *tipoDeEntrega = this->tipoDeEntrega;
        retorno = 0;
    }
    return retorno;

}
int envios_setPrecio(Envios* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio>0 )
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;

}

int envios_getPrecio(Envios* this,float* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}

int envios_setCosto(Envios* this,int costo)
{
     int retorno = -1;
    if(this != NULL && costo >= 0)
    {
        this->costo= costo;
        retorno = 0;
    }
    return retorno;

}

int envios_getCosto(Envios* this,int* costo)
{
    int retorno = -1;
    if(this != NULL && costo != NULL)
    {
        *costo = this->costo;
        retorno = 0;
    }
    return retorno;

}
