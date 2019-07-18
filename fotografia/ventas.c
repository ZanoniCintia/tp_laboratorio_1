
#define VENTA_C_INCLUDED
#include "ventas.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




Venta* Venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}


Venta* Venta_newParametros(char* idStr,char * fecha, char* tipo,char* cantidad, char* importe, char* cuit)
{
    Venta* retorno=NULL;
    Venta* pAuxVenta=Venta_new();

    if (idStr!=NULL && fecha!=NULL && tipo!=NULL && cantidad!=NULL && importe!=NULL && cuit!=NULL)
    {


       if(isValidEntero(idStr)&&isValidEntero(cantidad)&&isValidEntero(importe))
       {
            if(Venta_setId(pAuxVenta,atoi(idStr))
               || Venta_setFecha(pAuxVenta,fecha)
               || Venta_settipo(pAuxVenta,tipo)
               || Venta_setCantidad(pAuxVenta,atoi(cantidad))
               || Venta_setImporte(pAuxVenta,atof(importe))
               || Venta_setCuit(pAuxVenta,cuit))
            {
                libros_delete(pAuxVenta);


            }else{
                 retorno = pAuxVenta;
            }
       }


    return retorno;
}

int Venta_delete(Venta* this)
{
    int retorno=-1;

    if (this!=NULL )
    {
        free (this);
        retorno=0;
    }
    return retorno;
}

int Venta_setId(Venta* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,50000))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}


int Venta_getId(Venta* this,int* id)
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}
int Venta_settipo(Venta* this,char* tipo)
{
    int retorno=-1;

    if (this!=NULL && tipo!=NULL)
    {
        strcpy(this->tipo,tipo);
        retorno=0;
    }
    return retorno;
}

int Venta_gettipo(Venta* this,char* tipo)
{
    int retorno=-1;

    if (this!=NULL && tipo!=NULL )
    {
        strcpy(tipo,this->tipo);
        retorno=0;
    }
    return retorno;
}
int Venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if (this!=NULL && cantidad>=0 && isValidInt(cantidad,1,1000))
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if (this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}
int Venta_setImporte(Venta* this, float importe)
{
    int retorno=-1;
    if (this!=NULL && importe>=0 && isValidFloat(importe,0,5000))
    {
        this->importe=importe;
        retorno=0;
    }
    return retorno;
}

int Venta_getImporte(Venta* this, float* importe)
{
    int retorno=-1;
    if (this!=NULL && importe!=NULL)
    {
        *importe=this->importe;
        retorno=0;
    }
    return retorno;
}
int Venta_setCuit(Venta* this,char* cuit)
{
    int retorno=-1;

    if (this!=NULL && cuit!=NULL)//  && isValidCUIT(cuit)
    {
        strcpy(this->cuit,cuit);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuit(Venta* this,char* cuit)
{
    int retorno=-1;

    if (this!=NULL && cuit!=NULL )
    {
        strcpy(cuit,this->cuit);
        retorno=0;
    }
    return retorno;
}

int Venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;

    if (this!=NULL && fecha!=NULL)// && isValidFecha(fecha)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

int Venta_getFecha(Venta* this,char* fecha)
{
    int retorno=-1;

    if (this!=NULL && fecha!=NULL )
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}
