#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "envios.h"
#include "parser.h"
#include "validaciones.h"
//int idMaxArray(LinkedList* pArrayLibros);
/** \brief Carga los datos  desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEnvios)
{
    int retorno = -1;
    FILE* fAux=NULL;
    if(path != NULL && pArrayListEnvios != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_EnviosFromText(fAux,pArrayListEnvios))
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
/*int idMaxArray(LinkedList* pArrayLibros)
{
    int retorno = -1;
    eLibros* pAux;
    int idAux;
    int idMax = -1;
    if(pArrayLibros != NULL)
    {
        for(int i = 0; i<ll_len(pArrayLibros); i++)
        {
            pAux = ll_get(pArrayLibros,i);
            libros_getId(pAux, &idAux);
            if(idAux>idMax)
            {
                idMax = idAux;
            }
        }
    }
    retorno = idMax;
    return retorno;
}*/
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
int controller_ListEnvios(LinkedList* pArrayListEnvios)
{
    int retorno = -1;
    int id;
    char nombre[51];
    int kilometros;
    int tipoDeEntregas;

    Envios* pAux;
     //printf("entro aca");
    if(pArrayListEnvios != NULL)
    {
        for(int i =0; i<ll_len(pArrayListEnvios); i++)
        {
            //printf("entro aca");
            //printf("I:%d - ",i);
            pAux=ll_get(pArrayListEnvios,i);

            //llamadas_getIdProblema(pArrayListLLamadas,pAux);
            if(pAux != NULL)
            {

                envios_getId(pAux,&id);
                envios_getNombre(pAux,nombre);
                envios_getKilometros(pAux,&kilometros);
                envios_getTipoDeEntrega(pAux,&tipoDeEntregas);



                switch(tipoDeEntregas)
                {
                case 1:

                    printf("%d --",id);
                    printf("%s --",nombre);
                    printf("%d --",kilometros);
                    printf("normal\n\n");
                    break;
                case 2:
                    printf("%d --",id);
                    printf("%s --",nombre);
                    printf("%d --",kilometros);
                    printf("express\n\n");
                    break;
                case 3:
                    printf("%d --",id);
                    printf("%s --",nombre);
                    printf("%d --",kilometros);
                    printf("Segun disponibilidad\n\n");

                }

            }
        }
        retorno = 0;
    }

    return retorno;
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
int controller_saveAsText(char* path, LinkedList* pArrayListEnvios)
{
    int retorno = -1;
    Envios* auxEnvios;
    FILE* pFile;
    int i;
    int id;
    char nombre[51];
    int kilometros;
    int tipoDeEntrega;
    float precio;
    int costo;

    if(path != NULL && pArrayListEnvios != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListEnvios); i++)
            {
                auxEnvios = ll_get(pArrayListEnvios,i);
                if(auxEnvios != NULL)
                {
                    envios_getId(auxEnvios, &id);
                    envios_getNombre(auxEnvios,nombre);
                    envios_getKilometros(auxEnvios,&kilometros);
                    envios_getTipoDeEntrega(auxEnvios, &tipoDeEntrega);
                    envios_getPrecio(auxEnvios,&precio);
                    envios_getCosto(auxEnvios,&costo);
                    fprintf(pFile,"%d,%s,%d,%d,%.2f,%d\n",id,nombre,kilometros,tipoDeEntrega,precio,costo);
                }
            }
            retorno = 0;
            fclose(pFile);
        }

    }

    return retorno;
}


int controller_costoTipoEntrega(void* p)
{
    int tipo;
    int costo;
     if(p!=NULL)
    {

        envios_getTipoDeEntrega((Envios*)p,&tipo);
        envios_getCosto(p,&costo);
        if(tipo==1)
        {
            costo=330;
        }else if(tipo==2)
            {
                 costo = 560;

            }else if(tipo==3){
                costo =80;

            }
        envios_setCosto((Envios*)p,costo);
     }

    return 1;
}
int controller_aumentoPorKilometros(void* p)
{
    float precio=0;
    int kilometros;
     if(p!=NULL)
    {

        envios_getPrecio((Envios*)p,&precio);
        envios_getKilometros(p,&kilometros);
        if(kilometros<=50)
        {
            precio=67;
            precio=precio*kilometros;
        }else if(kilometros>50)
            {
                 precio = 80;
                 precio=precio*kilometros;
            }

        envios_setPrecio((Envios*)p,precio);
     }

    return 1;
}
