#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libros.h"
#include "validaciones.h"
#include "funciones.h"





eLibros* libros_new()
{
    return (eLibros*) malloc(sizeof(eLibros));
}
eLibros* libros_newParametros(char* id,char* titulo,char* autor,char* precio,char* editorialId)
{
    eLibros* retorno=NULL;
    eLibros* pAuxLibros=libros_new();

    if(id != NULL && titulo != NULL && autor != NULL && precio != NULL && editorialId != NULL)
    {

       if(isValidEntero(id)&&isValidEntero(precio)&&isValidEntero(editorialId))
       {
            if(libros_setId(pAuxLibros,atoi(id))
               || libros_setTitulo(pAuxLibros,titulo)
               || libros_setAutor(pAuxLibros,autor)
               || libros_setPrecio(pAuxLibros,atof(precio))
               || libros_setEditorialId(pAuxLibros,atoi(editorialId)))
            {
                libros_delete(pAuxLibros);


            }else{
                 retorno = pAuxLibros;
            }
       }

    }
return retorno;
}

void libros_delete(eLibros* this)
{

    if(this != NULL)
    {
        free(this);

    }

}

int libros_setId(eLibros* this,int id)
{
     int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;

}

int libros_getId(eLibros* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;

}
int libros_setTitulo(eLibros* this,char* titulo)
{
    int retorno=-1;

    if (this!=NULL && titulo!=NULL)
    {
        strcpy(this->titulo,titulo);
        retorno=0;
    }
    return retorno;
}

int libros_getTitulo(eLibros* this,char* titulo)
{
    int retorno=-1;

    if (this!=NULL && titulo!=NULL )
    {
        strcpy(titulo,this->titulo);
        retorno=0;
    }
    return retorno;
}
int libros_setAutor(eLibros* this,char* autor)
{
    int retorno=-1;

    if (this!=NULL && autor!=NULL)
    {
        strcpy(this->autor,autor);
        retorno=0;
    }
    return retorno;
}

int libros_getAutor(eLibros* this,char* autor)
{
    int retorno=-1;

    if (this!=NULL && autor!=NULL )
    {
        strcpy(autor,this->autor);
        retorno=0;
    }
    return retorno;
}

int libros_setPrecio(eLibros* this,float precio)
{
    int retorno = -1;
    if(this != NULL && precio>0 )
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;

}

int libros_getPrecio(eLibros* this,float* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = 0;
    }
    return retorno;
}

int libros_setEditorialId(eLibros* this,int editorialId)
{
     int retorno = -1;
    if(this != NULL && editorialId >= 0)
    {
        this->editorialId = editorialId;
        retorno = 0;
    }
    return retorno;

}

int libros_getEditorialId(eLibros* this,int* editorialId)
{
    int retorno = -1;
    if(this != NULL && editorialId != NULL)
    {
        *editorialId = this->editorialId;
        retorno = 0;
    }
    return retorno;

}
