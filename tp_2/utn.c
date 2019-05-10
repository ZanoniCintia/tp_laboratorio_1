#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#define TRUE 0
#define FALSE 1


int getString ( char* msg,char* msgError,int minimo, int maximo, int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            __fpurge(stdin);
            fgets(bufferStr,sizeof(bufferStr)-1,stdin);

            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <=maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}
int isValidName (char* cadena)
{
    int retorno = -1;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getFloat(char* msg,char* msgError,float minimo,float maximo,int reintentos,float* resultado)
{
    char buffer[4096];
    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
          do {
          if(!getString(msg,msgError,1,15,reintentos,buffer))
          {

                if(isValidFloat(buffer,minimo,maximo))
                {
                    *resultado=atof(buffer);
                    retorno =0;
                    break;
                }else{
                    printf("%s",msgError);
                }
               reintentos--;
           }
           }while(reintentos>=0);
    }
    return retorno;

}
int isValidFloat(char* numero, float minimo,float maximo)
{
    int retorno = 0;
    float aux;
    if(atof(numero)!=0)
    {
        aux=atof(numero);

        if(aux>=minimo && aux<=maximo)
        {

            retorno = 1;
        }

    }
    return retorno;
}
int getInt(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    int buffer;

    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            printf("%s",msg);
            scanf("%d",&buffer);
            if(isValidInt(buffer,minimo,maximo))
            {
                *resultado=buffer;
                retorno =0;
                break;
            }else{

                printf("%s",msgError);
            }
            reintentos--;
            }while(reintentos>=0);
    }
    return retorno;

}

int isValidInt(int numero,int minimo,int maximo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
        return 0;

}

