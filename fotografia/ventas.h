#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

typedef struct
{
    int id;
    char fecha[500];
    char tipo[128];
    int cantidad;
    float importe;
    char cuit[500];
}Venta;


Venta* Venta_new();
Venta* Venta_newParametros(char* idStr,char* fecha, char* tipo, char* cantidad, char* importe, char* cuit);
int Venta_delete(Venta* this);



int Venta_setId(Venta* this,int id);
int Venta_getId(Venta* this,int* id);

int Venta_settipo(Venta* this,char* tipo);
int Venta_gettipo(Venta* this,char* tipo);

int Venta_setFecha(Venta* this,char* fecha);
int Venta_getFecha(Venta* this,char* fecha);

int Venta_setCuit(Venta* this,char* cuit);
int Venta_getCuit(Venta* this,char* cuit);

int Venta_setCantidad(Venta* this,int cantidad);
int Venta_getCantidad(Venta* this,int* cantidad);

int Venta_setImporte(Venta* this, float importe);
int Venta_getImporte(Venta* this,float* importe);



#endif // VENTAS_H_INCLUDED
