#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
    int id;
    char titulo[500];
    char autor[500];
    float precio;
    int editorialId;

}eLibros;

eLibros* libros_new();
eLibros* libros_newParametros(char* id,char* titulo,char* autor,char* precio,char* editorialId);

void libros_delete(eLibros* this);

int libros_setId(eLibros* this,int id);
int libros_getId(eLibros* this,int* id);

int libros_setTitulo(eLibros* this,char* titulo);
int libros_getTitulo(eLibros* this,char* titulo);

int libros_setAutor(eLibros* this,char* autor);
int libros_getAutor(eLibros* this,char* autor);

int libros_setPrecio(eLibros* this,float precio);
int libros_getPrecio(eLibros* this,float* precio);

int libros_setEditorialId(eLibros* this,int editorialId);
int libros_getEditorialId(eLibros* this,int* editorialId);

#endif // LIBROS_H_INCLUDED
