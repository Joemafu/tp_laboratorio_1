#include "calcular.h"

/**< Funci�n que suma. */
float sumar(float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;
    return resultado;
}
/**< Funci�n que resta. */
float restar(float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}

/**< Funci�n que multiplica. */
float multiplicar(float num1, float num2)
{
    float resultado;
    resultado = num1 * num2;
    return resultado;
}

/**< Funci�n que divide. */
float dividir(float num1, float num2)
{
    float resultado;
    resultado = (float) num1 / (float) num2;

    /**< Este if hace que la funci�n devuelva valor 0 en caso de que el divisor sea 0, de modo que en main pueda disparar un mensaje de error cuando esto suceda. */
    if(num2 == 0){
        resultado = 0;
    }
    return resultado;
}

/**< Funci�n que calcula el factorial de un n�mero. NOTA: en caso de ingresar un n�mero con coma, solo tiene en cuenta la parte entera para el c�lculo. */
double sacarFactorial(int num)
{
    double factorial;
    factorial = num;

    /**< Una forma de calcular el factorial. */
    while (num>1) {
        num--;
        factorial = factorial * num;
    }
    /**< Con este if seteo factorial de 0 = 1. */
    if (num == 0){
        factorial = 1;
    }

    return (factorial);
}

