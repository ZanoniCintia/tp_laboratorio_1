#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ventas.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"
int idMaxArray(LinkedList* pArrayLibros);
/** \brief Carga los datos  desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListVentas)
{
    int retorno = -1;
    FILE* fAux=NULL;
    if(path != NULL && pArrayListVentas != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_VentasFromText(fAux,pArrayListVentas))
            {

                printf("El archivo se cargo existosamente en modo texto!");
                retorno = 0;
            }
        }
        //fclose(fAux);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL && !parser_EmployeeFromBinary(pFile,pArrayListEmployee))
        {
            printf("El archivo se cargo existosamente en modo binario!");
            retorno = 0;
        }
    }
    return retorno;
}*/

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[50];
    char horasTrabajadas[20];
    char sueldo[20];
    char idTex[20];
    int id;
    int retorno=-1;
    Employee* pAuxiliar;


    if(pArrayListEmployee!=NULL)
    {
        id=idMaxArray(pArrayListEmployee)+1;
        sprintf(idTex,"%d",id);

        if( !getName("\n Ingrese nombre de empleado: ", "\n Error",1,50,1,nombre) &&
                !getInt("\n Ingrese horas trabajadas: ", "\n Error",1,21,1,horasTrabajadas) &&
                !getInt("\n Ingrese sueldo: ", "\n Error",1,21,1,sueldo))
        {
            pAuxiliar= employee_newParametros(idTex,nombre,horasTrabajadas,sueldo);
            if(pAuxiliar != NULL)
            {
                ll_add(pArrayListEmployee,pAuxiliar);
                retorno = 0;
            }
        }

    }

    return retorno;
}*/
int idMaxArray(LinkedList* pArrayVenta)
{
    int retorno = -1;
    Venta* pAux;
    int idAux;
    int idMax = -1;
    if(pArrayVenta != NULL)
    {
        for(int i = 0; i<ll_len(pArrayVenta); i++)
        {
            pAux = ll_get(pArrayVenta,i);
            Venta_getId(pAux, &idAux);
            if(idAux>idMax)
            {
                idMax = idAux;
            }
        }
    }
    retorno = idMax;
    return retorno;
}
/*int buscarPorId(LinkedList* pArrayEmpleado, int id)
{
    int i;
    int retorno = -1;
    Employee* auxEmployee = NULL;
    int idEmployee;
    if (pArrayEmpleado!=NULL && id>=0)
    {
        for(i=0; i<ll_len(pArrayEmpleado); i++)
        {
            auxEmployee = ll_get(pArrayEmpleado,i);
            if(auxEmployee != NULL)
            {

            employee_getId(auxEmployee,&idEmployee);
            if(idEmployee == id)
            {
                retorno=i;
                break;
            }

            }
        }
    }

    return retorno;
}*/

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListVentas(LinkedList* pArrayListVentas)
{
    int retorno = -1;
    int id;
    char fecha[51];
    char tipo[51];
    float precio;
    char cuit[51];

    Venta* pAux;
     printf("entro aca");
    if(pArrayListVentas != NULL)
    {
        for(int i =0; i<ll_len(pArrayListVentas); i++)
        {
            //printf("entro aca");
            //printf("I:%d - ",i);
            pAux=ll_get(pArrayListVentas,i);

            //llamadas_getIdProblema(pArrayListLLamadas,pAux);
            if(pAux != NULL)
            {

                Venta_getId(pAux,&id);
                Venta_getFecha(pAux,fecha);
                Venta_gettipo(pAux,tipo);
                Venta_getImporte(pAux,&precio);
                Venta_getCuit(pAux,cuit);

            }
        retorno = 0;
        }

    return retorno;
    }
}
//printf("Menu 6 -----



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int posEmployee=-1;
    int idEmployee;
    int opcion;
    Employee* auxEmployee;
    char nombre[51];
    char horasTrabajadas[51];
    char sueldo[51];
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(!getEntero("Ingrese el ID a modificar","ID invalido",0,ll_len(pArrayListEmployee),1,&idEmployee))
        {
            posEmployee=buscarPorId(pArrayListEmployee,idEmployee);
            auxEmployee = ll_get(pArrayListEmployee,posEmployee);
            getEntero("1)Modificar Nombre\n2)Modificar horas trabajadas\n3)Modificar sueldo\n","Opcion invalida!\n",1,3,1,&opcion);
            switch(opcion)
            {
                case 1:
                    if(!getName("Ingrese nuevo nombre:","nombre invalido",2,51,3,nombre))
                    {
                        if(!employee_setNombre(auxEmployee,nombre))
                        {
                            printf("Nombre modificado correctamente");
                        }
                    }
                    break;
                case 2:
                    if(!getInt("Ingrese nuevo horas trabajadas:\n","Horas invalidas",1,5,3,horasTrabajadas))
                    {
                        employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadas));
                        printf("Horas modificadas correctamente");
                    }
                    break;
                case 3:
                    if(!getInt("Ingrese nuevo sueldo:\n","Sueldo invalido",1,8,3,sueldo))
                    {
                        employee_setSueldo(auxEmployee,atoi(sueldo));
                        printf("Sueldo modificado correctamente");
                    }
                    break;

            }
            retorno = 0;
        }
    }
    return retorno;
}*/

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int IDABorrar;
    int posIDABorrar;
    Employee* auxEmployee;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        getEntero("Ingrese ID a borrar: \n","ID no encontrado",0,ll_len(pArrayListEmployee),1,&IDABorrar);
        posIDABorrar = buscarPorId(pArrayListEmployee,IDABorrar);
        auxEmployee = ll_pop(pArrayListEmployee,posIDABorrar);
        if(auxEmployee != NULL)
        {
            employee_delete(auxEmployee);
            printf("Empleado eliminado correctamente");
            retorno = 0;
        }
    }
    return retorno;
}*/

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee,employee_comparacionNombre,0);
        retorno = 0;
    }
    return retorno;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsTextVentas(char* path, LinkedList* pArrayListVentas)
{
    int retorno = -1;
    Venta* auxVentas;
    FILE* pFile;
    int i;
    int id;
    char fecha[51];
    char tipo[20];
    float precio;
    char cuit[51];

    if(path != NULL && pArrayListVentas != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListVentas); i++)
            {
                auxVentas = ll_get(pArrayListVentas,i);
                if(auxVentas != NULL)
                {
                    Venta_getId(auxVentas, &id);
                    Venta_getFecha(auxVentas,fecha);
                    Venta_gettipo(auxVentas,tipo);
                    Venta_getImporte(auxVentas, &precio);
                    Venta_getCuit(auxVentas,cuit);
                    fprintf(pFile,"%d,%s,%s,%.2f,%s\n",id,fecha,tipo,precio,cuit);
                }
            }
            retorno = 0;
            fclose(pFile);
        }

    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee *pEmployee=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                //printf("%s\n",pEmployee->nombre);
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
        }
        retorno = 0;
        fclose(pFile);
    }

    return retorno;
    //return 1;
}*/

/*int controller_descuentoVeintePorciento(void* p)
{
    float precio;
    //int editorialId;
     if(p!=NULL)
    {

        libros_getPrecio((Venta*)p,&precio);
        //libros_getEditorialId(p,&editorialId);

        precio -= ( precio * 20)/100;


       libros_setPrecio((Venta*)p,precio);
     }
    return 1;
}
int controller_descuentoDiezPorciento(void*p)
{
    float precio;
    //int editorialId;
     if(p!=NULL)
    {

        libros_getPrecio((Venta*)p,&precio);
        //libros_getEditorialId(p,&editorialId);

        precio -= ( precio * 10)/100;


       libros_setPrecio((Venta*)p,precio);
     }
    return 1;
}
int controller_CriterioOrdenAscendente(void* this1, void* this2)
{

    int retorno = 0;
    int editorialId;
    int editorialIdDos;
    Venta* auxLibros;
    Venta* auxLibrosDos;
    if(this1 != NULL && this2 != NULL)
    {
        auxLibros = (Venta*)this1;
        auxLibrosDos = (Venta*)this2;
        libros_getEditorialId(auxLibros,&editorialId);
        libros_getEditorialId(auxLibrosDos,&editorialIdDos);

        if(editorialId>editorialIdDos)
            retorno = 1;
        else
            retorno = -1;
    }
    return retorno;
}

int controller_sortLibros(LinkedList* pArrayListLibros)
{
    int retorno = -1;
    if(pArrayListLibros != NULL)
    {
        ll_sort(pArrayListLibros,controller_CriterioOrdenAscendente,0);
        retorno = 0;
    }
    return retorno;
}*/


/*int controller_problemas(void* p)
{
    int problema;
    int retorno = 0;
    if(p!=NULL)
    {
        llamadas_getIdProblema(p,&problema);
        if(problema>0 && problema<=5)
        {
            retorno = 1;

        }
    }

    return retorno;
}
int problema1(void* p)
{
    int retorno = 0;
    int idProblema;
    if(p != NULL)
    {
        llamadas_getIdProblema((LLamadas*)p,&idProblema);
        if(idProblema == 1)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int problema2(void* p)
{
    int retorno = 0;
    int idProblema;
    if(p != NULL)
    {
        llamadas_getIdProblema((LLamadas*)p,&idProblema);
        if(idProblema == 2)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int problema3(void* p)
{
    int retorno = 0;
    int idProblema;
    if(p != NULL)
    {
        llamadas_getIdProblema((LLamadas*)p,&idProblema);
        if(idProblema == 3)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int problema4(void* p)
{
    int retorno = 0;
    int idProblema;
    if(p != NULL)
    {
        llamadas_getIdProblema((LLamadas*)p,&idProblema);
        if(idProblema == 4)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int problema5(void* p)
{
    int retorno = 0;
    int idProblema;
    if(p != NULL)
    {
        llamadas_getIdProblema((LLamadas*)p,&idProblema);
        if(idProblema == 5)
        {
            retorno = 1;
        }
    }
    return retorno;
}*/
