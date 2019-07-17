#ifndef LLAMADAS_H_INCLUDED
#define LLAMADAS_H_INCLUDED
typedef struct
{
    int id;
    char fecha[500];
    int numeroCliente;
    int idProblema;
    char solucion[11];

}LLamadas;

LLamadas* llamadas_new();
LLamadas* llamadas_newParametros(char* id,char* fecha,char* numeroCliente,char* idProblema,char* solucionado);

void llamadas_delete(LLamadas* this);

int llamadas_setId(LLamadas* this,int id);
int llamadas_getId(LLamadas* this,int* id);

int llamadas_setFecha(LLamadas* this,char* fecha);
int llamadas_getFecha(LLamadas* this,char* fecha);

int llamadas_setIdProbelma(LLamadas* this,int idProblema);
int llamadas_getIdProblema(LLamadas* this,int* idProblema);

int llamadas_setSolucion(LLamadas* this,char* solucion);
int llamadas_getSolucion(LLamadas* this,char* solucion);

int llamadas_setNumeroCliente(LLamadas* this,int numeroCliente);
int llamadas_getNumeroCliente(LLamadas* this,int* numeroCliente);
#endif // LLAMADAS_H_INCLUDED
