#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

typedef struct
{
    int Id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Empleado;

int emp_initEmpleado(Empleado *arrayEmpleado, int len);
int emp_addEmpleado(Empleado *arrayEmpleado,int len , int *Id,char *nombre,char *apellido,float salario,int sector);
int emp_buscarPorId(Empleado *arrayEmpleado, int len, int id);
int emp_mostrarArray(Empleado *arrayEmpleado, int len);
int emp_borrarEmpleado(Empleado *arraEmpleado, int len,int id);
int emp_ordenarMayoraMenor(Empleado *arrayEmpleado,int len);
int emp_ordenarMenoraMayor(Empleado *arrayEmpleado,int len);
int emp_calcularPromedioSalario(Empleado *arrayEmpleado,int len);
int emp_modificarEmpleado(Empleado *arrayEmpleado,int len,int Id);

#endif // ABM_H_INCLUDED
