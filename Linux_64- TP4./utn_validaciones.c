#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn_validaciones.h"
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
                strncpy(resultado,bufferStr,maximo-1);
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

            if(!isValidName(bufferStr))
            {
                bufferStr[strlen(bufferStr)-1] = '\0';
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
int getInt(char* msg,char* msgError,int minimo,int maximo,int reintentos,char *resultado)
{
    char buffer[4096];

    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
            {
                if(isValidInt(buffer))
                {
                    strncpy(resultado,buffer,maximo);
                    retorno=0;
                    break;
                }else
                    {
                        printf("Horas invalida, reintente");
                    }
            }else{

                printf("%s",msgError);
            }
            reintentos--;
            }while(reintentos>=0);
    }
    return retorno;

}

int isValidInt(char* cadena)
{
    int retorno = 1;
    int i;
    for(i=0;cadena[i]!='\n';i++)
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
int getEntero(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado)
{
    char buffer[4096];

    int retorno = -1;

    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>0)
    {
        do
        {
            printf("%s",msg);
            scanf("%s",buffer);
            if(isValidEntero(buffer))
            {
                *resultado=atoi(buffer);
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

int isValidEntero(char* cadena)
{
    int retorno = 0;
    int i;
    if(cadena != NULL)
    {
        for(i=0; cadena[i]!='\0'; i++)
        {
            if(cadena[i] >= '0' && cadena[i]<='9')
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

