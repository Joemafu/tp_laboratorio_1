#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r;
    int i=0;
    int errorFlag=0;
    char var1[50];
    char var3[50];
    char var2[50];
    char var4[50];
    Employee* emp;
    if(pFile == NULL)
    {
        showMessage("El archivo no pudo abrirse.\n");
        r=0;
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4)
            {
                emp = employee_newParametros(var1,var2,var3);
                employee_setSueldo(emp,atoi(var4));

                if(ll_add(pArrayListEmployee,emp)!=0)
                {
                    errorFlag=1;
                }
                i++;
            }
            else
            {
                showMessage("No se cargaron los empleados.\n");
                r=0;
                break;
            }
        }
        while(!feof(pFile));
        if(errorFlag==1)
        {
            showMessage("Hubo un error al cargar uno o más empleados desde el archivo.\n");
            r=0;
        }
        else
        {
            showMessage("Se cargaron los datos con exito.\n\n");
            r=1;
        }
    }
    return r;
}

/** \brief Parsea los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int errorFlag=0;
    char var1[50];
    char var2[50];
    Employee auxEmp;
    Employee lastEmp;
    Employee* emp;
    if(pFile == NULL)
    {
        showMessage("El archivo no pudo abrirse.\n");
    }
    else
    {
        while(!feof(pFile))
        {
            fread(&auxEmp,sizeof(Employee),1,pFile);

            if(lastEmp.id!=auxEmp.id)
            {
                emp = employee_newParametros(itoa(auxEmp.id,var1,10),auxEmp.nombre,itoa(auxEmp.horasTrabajadas,var2,10));
                employee_setSueldo(emp,auxEmp.sueldo);

                if(ll_add(pArrayListEmployee,emp)!=0)
                {
                    printf("Error al dar de alta al empleado.\n");
                }
                lastEmp=*emp;
            }
        }
        if(errorFlag==1)
        {
            showMessage("Hubo un error al cargar uno o más empleados desde el archivo.\n");
        }
        else
        {
            showMessage("Se cargaron los datos con exito.\n\n");
        }
    }
    return 1;
}
