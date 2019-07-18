#ifndef ENVIOS_H_INCLUDED
#define ENVIOS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[500];
    int kilometros;
    int tipoDeEntrega;
    int costo;
    float precio;

}Envios;

Envios* envios_new();
Envios* envios_newParametros(char* id,char* nombre,char* kilometros,char* tipoDeEntrega);

void envios_delete(Envios* this);

int envios_setId(Envios* this,int id);
int envios_getId(Envios* this,int* id);

int envios_setNombre(Envios* this,char* nombre);
int envios_getNombre(Envios* this,char* nombre);


int envios_setKilometros(Envios* this,int kilometros);
int envios_getKilometros(Envios* this,int* kilometros);

int envios_setTipoDeEntrega(Envios* this,int tipoDeEntrega);
int envios_getTipoDeEntrega(Envios* this,int* tipoDeEntrega);

int envios_setPrecio(Envios* this,float precio);
int envios_getPrecio(Envios* this,float* precio);

int envios_setCosto(Envios* this,int costo);
int envios_getCosto(Envios* this,int* costo);

#endif // ENVIOS_H_INCLUDED
