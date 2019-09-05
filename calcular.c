#include "calcular.h"

/**< Función que suma. */
float sumar(float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;
    return resultado;
}
/**< Función que resta. */
float restar(float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}

/**< Función que multiplica. */
float multiplicar(float num1, float num2)
{
    float resultado;
    resultado = num1 * num2;
    return resultado;
}

/**< Función que divide. */
float dividir(float num1, float num2)
{
    float resultado;
    resultado = (float) num1 / (float) num2;

    /**< Este if hace que la función devuelva valor 0 en caso de que el divisor sea 0, de modo que en main pueda disparar un mensaje de error cuando esto suceda. */
    if(num2 == 0){
        resultado = 0;
    }
    return resultado;
}

/**< Función que calcula el factorial de un número. NOTA: en caso de ingresar un número con coma, solo tiene en cuenta la parte entera para el cálculo. */
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

