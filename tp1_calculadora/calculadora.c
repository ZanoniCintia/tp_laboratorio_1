/** \brief pide un numero al usuario
 *
 * \return el numero ingresado
 */


float pedirPrimerNumero(float *numeroIngresado)
{
    float unNumero;
    printf("\n ingrese el primer operando \n:");
    scanf("%f", &unNumero);
    *numeroIngresado=unNumero;
    return 0;
}
float pedirSegundoNumero(float *segundoNumeroIngresado)
{
    float otroNumero;
    printf("\n ingrese el segundo operando \n:");
    scanf("%f",&otroNumero);
    *segundoNumeroIngresado=otroNumero;
    return 0;

}
/** \brief suma dos numeros ingresados por el usuario
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return  la suma
 *
 */

float calularSuma(float numeroIngresado, float segundoNumeroIngresado)
{
    float resultado;
    printf("\n eligio sumar ");
    resultado= numeroIngresado + segundoNumeroIngresado;
    printf("\n la suma es  :%.2f \n",resultado);
    return 0;
}
/** \brief calcula la resta entre dos numeros ingresados por el usuario
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return resta
 *
 */

float calcularResta(float numeroIngresado,float segundoNumeroIngresado)
{
    float resultado;
    printf("\n eligio restar ");
    resultado= numeroIngresado - segundoNumeroIngresado;
    printf("\n la resta es  :%.2f \n",resultado);
    return 0;
}
/** \brief calcula la division entre dos numeros ingresados por el usuario
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return division
 */

float calcularDivision(float numeroIngresado, float segundoNumeroIngresado)
{
    float resultado;
    if(segundoNumeroIngresado!=0)
    {
        printf("\n eligio dividir ");
        resultado= numeroIngresado/segundoNumeroIngresado;
        printf("\n la division es  :%.2f \n",resultado);
        return 0;
    } else
        {
            printf("ERROR! reingrese segundo operando distinto de cero");
        }
}
/** \brief calcula la multiplicacion entre dos numeros ingresados
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \return multiplicacion
 */

float calcularMultiplicacion(float numeroIngresado, float segundoNumeroIngresado)
{
    float resultado;
    printf("\n eligio multiplicar ");
    resultado = numeroIngresado*segundoNumeroIngresado;
    printf("\n la multiplicacion es  : %.2f \n",resultado);
    return 0;

}
/** \brief calcula el factorial de un numero
 * \param un numero ingresado por el usuario
 * \return factorial
 *
 */

float calcularFactorial(float numeroIngresado)
{
    float resultado;
    float factorial=1;
    float i;

    if(numeroIngresado<0)
    {
        printf("Error, volver a opcion 1\n ");
    }
    else
    {
        if(numeroIngresado==0)
        {
            factorial=1;
        }
        else
        {
            for(i=1;i<=numeroIngresado;i++)
            {
                factorial *= i;

            }
                resultado=factorial;
                printf("\n el factorial es  : %.0f \n",resultado);
        }

    }

    return 0;

}


