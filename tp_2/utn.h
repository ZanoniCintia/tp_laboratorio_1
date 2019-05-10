#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
int getString ( char* msg,char* msgError,int minimo, int maximo, int reintentos,char* resultado);
int getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado);
int isValidName (char* cadena);
int getFloat(char* msg,char* msgError,float minimo,float maximo,int reintentos,float* resultado);
int isValidFloat(char* numero, float minimo,float maximo);
int getInt(char* msg,char* msgError,int minimo,int maximo,int reintentos,int *resultado);
int isValidInt(int numero,int minimo,int maximo);

#endif // UTN_H_INCLUDED
