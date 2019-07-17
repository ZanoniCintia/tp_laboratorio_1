#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "llamadas.h"
#include "parser.h"
#include "validaciones.h"
int idMaxArray(LinkedList* pArrayEmpleado);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListLLamadas)
{
    int retorno = -1;
    FILE* fAux=NULL;
    if(path != NULL && pArrayListLLamadas != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_LLamadasFromText(fAux,pArrayListLLamadas))
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
int idMaxArray(LinkedList* pArrayLLamadas)
{
    int retorno = -1;
    LLamadas* pAux;
    int idAux;
    int idMax = -1;
    if(pArrayLLamadas != NULL)
    {
        for(int i = 0; i<ll_len(pArrayLLamadas); i++)
        {
            pAux = ll_get(pArrayLLamadas,i);
            llamadas_getId(pAux, &idAux);
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
int controller_ListLLamadas(LinkedList* pArrayListLLamadas)
{
    int retorno = -1;
    int id;
    char fecha[51];
    int idProblema;
    int numeroCliente;
    char solucion[51];

    LLamadas* pAux;
     printf("entro aca");
    if(pArrayListLLamadas != NULL)
    {
        for(int i =0; i<ll_len(pArrayListLLamadas); i++)
        {
            //printf("entro aca");
            //printf("I:%d - ",i);
            pAux=ll_get(pArrayListLLamadas,i);

            //llamadas_getIdProblema(pArrayListLLamadas,pAux);
            if(pAux != NULL)
            {

                llamadas_getIdProblema(pAux,&idProblema);
                llamadas_getId(pAux,&id);
                llamadas_getFecha(pAux,fecha);
                llamadas_getNumeroCliente(pAux,&numeroCliente);
                llamadas_getSolucion(pAux,solucion);


                switch(idProblema)
                {
                case 1:

                    printf("%d\n",id);
                    printf("%s\n",fecha);
                    printf("%d\n",numeroCliente);
                    printf("No enciende la pc\n");
                    printf ("%s\n\n",solucion);
                    break;
                case 2:
                    printf("%d\n",id);
                    printf("%s\n",fecha);
                    printf("%d\n",numeroCliente);
                    printf("No funciona el mouse\n");
                    printf ("%s\n\n",solucion);
                    break;
                case 3:
                    printf("%d\n",id);
                    printf("%s\n",fecha);
                    printf("%d\n",numeroCliente);
                    printf("No funciona el teclado\n");
                    printf ("%s\n\n",solucion);
                    break;
                case 4:
                    printf("%d\n",id);
                    printf("%s\n",fecha);
                    printf("%d\n",numeroCliente);
                    printf("No hay internet\n");
                    printf ("%s\n\n",solucion);
                    break;
                case 5:
                    printf("%d\n",id);
                    printf("%s\n",fecha);
                    printf("%d\n",numeroCliente);
                    printf("No funciona telefono\n");
                    printf ("%s\n\n",solucion);
                    break;
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
int controller_saveAsText(char* path, LinkedList* pArrayListLLamadas)
{
    int retorno = -1;
    LLamadas* auxLLamadas;
    FILE* pFile;
    int i;
    char fecha[51];
    char solucion[20];
    int idProblema;
    int numeroCliente;
    int id;
    if(path != NULL && pArrayListLLamadas != NULL)
    {
        pFile = fopen(path,"w");
        if(pFile != NULL)
        {
            for(i=0; i<ll_len(pArrayListLLamadas); i++)
            {
                auxLLamadas = ll_get(pArrayListLLamadas,i);
                if(auxLLamadas != NULL)
                {
                    llamadas_getId(auxLLamadas, &id);
                    llamadas_getFecha(auxLLamadas,fecha);
                    llamadas_getIdProblema(auxLLamadas,&idProblema);
                    llamadas_getNumeroCliente(auxLLamadas, &numeroCliente);
                    llamadas_getSolucion(auxLLamadas,solucion);
                    fprintf(pFile,"%d,%s,%d,%d,%s\n",id,fecha,idProblema,numeroCliente,solucion);
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

/*int controller_aumentoVeintePorcientoSueldos(void* p)
{
    int sueldo;
    int horasTrabajo;
     if(p!=NULL)
    {
        employee_getHorasTrabajadas(p,&horasTrabajo);
        employee_getSueldo(p,&sueldo);
        if(horasTrabajo>=120)
        {
            sueldo += ( sueldo * 20)/100;

        }
       employee_setSueldo(p,sueldo);
     }
    return 1;
}*/

int controller_problemas(void* p)
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
}
