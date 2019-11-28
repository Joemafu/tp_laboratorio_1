#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "AuxFunctions.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option;
    LinkedList* employeeList = ll_newLinkedList();
    do
    {
        option=showMenuGetOption("Menu:\n\n\
         1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n\
         2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n\
         3. Alta de empleado\n\
         4. Modificar datos de empleado\n\
         5. Baja de empleado\n\
         6. Listar empleados\n\
         7. Ordenar empleados\n\
         8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n\
         9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n\
        10. Salir\n",1,11);
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",employeeList);
            break;
        case 2:
            controller_loadFromBinary("data.bin",employeeList);
            break;
        case 3:
            controller_addEmployee(employeeList);
            break;
        case 4:
            controller_editEmployee(employeeList);
            break;
        case 5:
            controller_removeEmployee(employeeList);
            break;
        case 6:
            controller_ListEmployee(employeeList);
            break;
        case 7:
            controller_sortEmployee(employeeList);
            break;
        case 8:
            controller_saveAsText("data.csv",employeeList);
            break;
        case 9:
            controller_saveAsBinary("data.bin",employeeList);
            break;
        case 10:
            ll_deleteLinkedList(employeeList);
            break;
        }
    }
    while(option != 10);

    return 0;
}
