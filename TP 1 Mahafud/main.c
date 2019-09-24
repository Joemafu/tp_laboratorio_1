#include "calcular.h"

int main()
{
    float A;
    float B;
    int aux;
    int opcion;
    int paraFact;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    double factorialA;
    double factorialB;
    int flag;


    flag = 0;
    /**< Inicializo las variables A y B para que no muestren basura en el menú. */
    A = 0;
    B = 0;
    /**< Inicializo factoriales en 1 para que en caso de que el usuario nunca active la opción 3, la opción 4 devuelva los factoriales de 0 (0! = 1). */
    factorialA = 1;
    factorialB = 1;

    /**< Un "do while" se asegura de que luego de cada paso vuelva al menú, siempre y cuando no seleccione opción 5 (salir). */
    do
    {
        /**< Texto del menú */
        printf("Seleccione una opcion:\n\n1-Ingresar primer operando (A=%f).\n2-Ingresar segundo operando (B=%f).\n3-Calcular todas las operaciones.\n4-Informar resultados.\n5-Salir.\n", A, B);
        scanf("%d", &aux);
        opcion = aux;

        /**< Limpio la pantalla luego de seleccionar una opción. */
        system("cls");

        /**< Una estructura switch administra las 5 opciones del menú. */
        switch (opcion)
        {
            /**< Opción 1 permite setear el valor de A. */
            case 1:
            {
                printf("Ingresar primer operando (A=%f)", A);
                scanf("%f",  &A);
                system("cls");
                flag = 0;
                break;
            }
            /**< Opción 2 permite setear el valor de B. */
            case 2:
            {
                printf("Ingresar segundo operando (B=%f)",B);
                scanf("%f", &B);
                system("cls");
                flag = 0;
                break;
            }
            /**< Opción 3 llama a cada función para realizar las operaciones solicitadas y setea los resultados. */
            case 3:
            {
                flag = 1;
                suma = sumar(A,B);
                resta = restar(A,B);
                division = dividir(A,B);
                multiplicacion = multiplicar(A,B);
                paraFact = (int)A;
                factorialA = sacarFactorial(paraFact);
                paraFact = (int)B;
                factorialB = sacarFactorial(paraFact);
                break;

            }
            /**< Opción 4 ejecuta un print con cada resultado. */
            case 4:
            {
                /**< Muestro el valor de los operandos que ingresó el usuario. */
                printf("A = %f\nB = %f.\n\n", A, B);

                /**< Envío un mensaje de alerta si muestran los resultados sin haber realizado los calculos luego de iniciar el programa, o luego de una modificación en los operandos. */
                if (flag == 0){
                    printf("Atencion, no se ejecuto la opcion 3, los resultados pueden estar desactualizados.\n\n");
                }

                /**< Devuelve el resultado de función sumar. */
                printf("El resultado de A+B es: %f\n", suma);

                /**< Devuelve el resultado de función restar. */
                printf("El resultado de A-B es: %f\n", resta);

                /**< Este if devuelve un mensaje de error si el valor del divisor (B) es 0. En dicho caso la variable división sería = 0 ya que respondería a un if que incluí en la función dividir. */
                if (division==-1)
                {
                    printf("No es posible dividir por 0.\n");
                }
                /**< De no haber error, devuelve el resultado de la división. */
                else
                {
                    printf("El resultado de A/B es: %f\n", division);
                }
                /**< Devuelve el resultado de la función multiplicar. */
                printf("El resultado de A*B es: %f\n", multiplicacion);

                /**< Este if devuelve error en caso de intentar calcular factorial a un negativo. */
                if (factorialA < 0)
                {
                    printf("No se puede calcular el factorial de un numero negativo.\n");
                }
                /**< De otro modo devuelve el resultado correcto. */
                else
                {
                    printf("El factorial de la parte entera de A es: %f\n", factorialA);
                }
                /**< Este if devuelve error en caso de intentar calcular factorial a un negativo. */
                if (factorialB < 0)
                {
                    printf("No se puede calcular el factorial de un numero negativo.\n");
                }
                /**< De otro modo devuelve el resultado correcto. */
                else
                {
                    printf("El factorial de la parte entera de B es: %f\n", factorialB);
                }
                /**< Pauso la ejecución para ver los resultados, limpio la pantalla y vuelvo al menú. */
                system("pause");
                system("cls");
                break;
            }
            /**< Este case me permite salir del do while, sin entrar en el defalut del switch. */
            case 5:
            {
                break;
            }
            /**< Case defalut me devuelve error en caso de ingresar un número que no esté asociado a ninguna opción. */
            default:
            {
                system("cls");
                printf("Seleccione una opcion entre 1 y 5.\n");
                system("pause");
                system("cls");
                break;
            }
        }
    }
    /**< Vuelvo al menú siempre que la opción no sea 5 (Salir). */
    while (opcion != 5);

    return 0;
}
