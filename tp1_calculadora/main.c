#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroIngresado;
    float otroNumero;
    float resultado;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando \n");
        printf("2- Ingresar 2do operando \n");
        printf("3- Calcular la suma \n");
        printf("4- Calcular la resta \n");
        printf("5- Calcular la division \n");
        printf("6- Calcular la multiplicacion \n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                pedirPrimerNumero(&numeroIngresado);
                break;
            case 2:
                pedirSegundoNumero(&otroNumero);
                break;
            case 3:
                calularSuma(numeroIngresado, otroNumero);
                break;
            case 4:
                calcularResta(numeroIngresado,otroNumero);

                break;
            case 5:
                calcularDivision(numeroIngresado,otroNumero);
                break;
            case 6:
                calcularMultiplicacion(numeroIngresado,otroNumero);
                break;
            case 7:
                calcularFactorial(numeroIngresado);
                break;
            case 8:
                calularSuma(numeroIngresado, otroNumero);
                calcularResta(numeroIngresado,otroNumero);
                calcularDivision(numeroIngresado,otroNumero);
                calcularMultiplicacion(numeroIngresado,otroNumero);
                calcularFactorial(numeroIngresado);
                break;
            case 9:
                seguir = 'n';
                break;
        }


   } return 0;
}
