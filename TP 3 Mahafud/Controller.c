#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int len;
    len=ll_len(pArrayListEmployee);
    if(len>0)
    {
        showMessage("Ya hay empleados cargados en el sistema.\n");
    }
    else
    {
        FILE* pFile;
        pFile = fopen(path,"r");
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        fclose(pFile);
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int len;
    len=ll_len(pArrayListEmployee);
    if(len>0)
    {
        showMessage("Ya hay empleados cargados en el sistema.\n");
    }
    else
    {
        FILE* pFile;
        pFile = fopen(path,"rb");
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        fclose(pFile);
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    Employee* emp;
    emp=employee_new();
    employee_setId(emp,getNextId(pArrayListEmployee));
    if(getConfirm()==1)
    {
        ll_add(pArrayListEmployee,emp);
        showMessage("El empleado se cargo con exito.\n");
        ret=1;
    }
    else
    {
        showMessage("Se cancelo la carga del empleado.\n");
        ret=1;
    }

    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int founded=0;
    int id;
    int id2;
    int workedHours;
    int salary;
    int len;
    int auxInt;
    int option;
    int flagModified=0;
    char newName[128];
    char name[128];
    Employee* auxEmp;

    len=ll_len(pArrayListEmployee);
    if(len==0)
    {
        showMessage("No hay empleados cargados.\n");
    }
    else
    {
        employee_showEveryone(pArrayListEmployee);

        id=getPositiveInt("\nIngrese el ID del empleado que desea modificar:\n");
        system("cls");

        for(i=0; i<len; i++)
        {
            auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmp,&id2);
            if(id2==id)
            {
                founded=1;
                do
                {
                    if(flagModified==1)
                    {
                        printf("Desea hacer alguna otra modificacion?\n\nID: %d \nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n\n",auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
                    }
                    else
                    {
                        printf("Esta por modificar al siguiente empleado:\n\nID: %d \nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n\n",auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
                    }
                    option=showMenuGetOption("Indique el campo que desea modificar:\n1)Nombre\n2)Horas trabajadas\n3)Sueldo\n4)Volver al menu principal\n",1,4);
                    switch(option)
                    {
                    case 1:
                        getAlphabeticalString("Ingrese nuevo nombre: ",newName,50);
                        employee_getNombre(auxEmp,name);
                        printf("\nEsta por modificar %s por %s\n",name,newName);
                        if(getConfirm()==1)
                        {
                            employee_setNombre(auxEmp,newName);
                            showMessage("Se modifico el campo indicado.\n");
                        }
                        else
                        {
                            showMessage("Se cancelo la modificacion.\n");
                        }
                        break;
                    case 2:
                        auxInt=getPositiveInt("Ingrese nueva cantidad de horas trabajadas: ");
                        employee_getHorasTrabajadas(auxEmp,&workedHours);
                        printf("\nEsta por modificar %d por %d\n",workedHours,auxInt);
                        if(getConfirm()==1)
                        {
                            employee_setHorasTrabajadas(auxEmp,auxInt);
                            showMessage("Se modifico el campo indicado.\n");
                        }
                        else
                        {
                            showMessage("Se cancelo la modificacion.\n");
                        }
                        break;
                    case 3:
                        auxInt=getPositiveInt("Ingrese nuevo sueldo: ");
                        employee_getSueldo(auxEmp,&salary);
                        printf("\nEsta por modificar %d por %d\n",salary,auxInt);
                        if(getConfirm()==1)
                        {
                            employee_setSueldo(auxEmp,auxInt);
                            showMessage("Se modifico el campo indicado.\n");
                        }
                        else
                        {
                            showMessage("Se cancelo la modificacion.\n");
                        }
                        break;
                    case 4:
                        if(flagModified==1)
                        {
                            showMessage("Modificaciones aplicadas, volviendo al menu.\n");
                        }
                        else
                        {
                            showMessage("Se cancelo la modificacion, volviendo al menu.\n");
                        }
                        break;
                    }
                    flagModified=1;
                }
                while(option!=4);
            }
        }
        if(founded==0)
        {
            showMessage("El ID ingresado no se encuentra cargado en el sistema.\n");
        }
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    len=ll_len(pArrayListEmployee);
    if(len==0)
    {
        showMessage("No hay empleados cargados.\n");
    }
    else
    {
        employee_showEveryone(pArrayListEmployee);
        employee_delete(pArrayListEmployee,len);
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    len=ll_len(pArrayListEmployee);
    if(len==0)
    {
        showMessage("No hay empleados cargados.\n");
    }
    else
    {
        employee_showEveryone(pArrayListEmployee);
        system("pause");
        system("cls");
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    int option;
    len=ll_len(pArrayListEmployee);
    if(len==0)
    {
        showMessage("No hay empleados cargados.\n");
    }
    else
    {
        option=showMenuGetOption("Indique el campo a tomar en cuenta para el ordenamiento:\n1)ID\n2)Nombre\n3)Horas trabajadas\n4)Sueldo\n5)Cancelar\n",1,5);
        switch(option)
        {
        case 1:
            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
            {
                processing();
                ll_sort(pArrayListEmployee,compareById,1);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            else
            {
                processing();
                ll_sort(pArrayListEmployee,compareById,0);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            break;
        case 2:
            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
            {
                processing();
                ll_sort(pArrayListEmployee,compareByName,1);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            else
            {
                processing();
                ll_sort(pArrayListEmployee,compareByName,0);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            break;
        case 3:
            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
            {
                processing();
                ll_sort(pArrayListEmployee,compareByWorkedHours,1);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            else
            {
                processing();
                ll_sort(pArrayListEmployee,compareByWorkedHours,0);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            break;
        case 4:
            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
            {
                processing();
                ll_sort(pArrayListEmployee,compareBySalary,1);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            else
            {
                processing();
                ll_sort(pArrayListEmployee,compareBySalary,0);
                system("cls");
                controller_ListEmployee(pArrayListEmployee);
            }
            break;
        case 5:
            break;
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* * \return int 1 en caso de éxito, 0 en caso de cancelado, -1 no pudo crear/guardar el archivo.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    int ret=1;
    int id=0;
    int workedHours=0;
    int salary=0;
    char name[51];
    FILE* pArchive;
    Employee* aux;
    len=ll_len(pArrayListEmployee);
    if(len==0)
    {
        printf("No hay empleados cargados, si se guarda ahora se perderan los datos almacenados en el archivo \"%s\".\n",path);
        if(getConfirm()==0)
        {
            showMessage("Se cancelo la operacion.\n");
            ret=0;
        }
    }
    pArchive=fopen(path,"w");
    if(pArchive == NULL)
    {
        showMessage("El archivo no pudo abrirse.\n");
        ret=-1;
    }
    else
    {
        fprintf(pArchive, "ID,Nombre,Horas trabajadas,Sueldo");

        for(i=0; i<len; i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(aux,&id);
            employee_getNombre(aux,name);
            employee_getHorasTrabajadas(aux,&workedHours);
            employee_getSueldo(aux,&salary);

            fprintf(pArchive,"\n%d,%s,%d,%d",id,name,workedHours,salary);
        }
        fclose(pArchive);
    }
    if(ret==1)
    {
        showMessage("Se guardo el listado correctamente.\n");
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 en caso de éxito, 0 en caso de cancelado, -1 no pudo crear/guardar el archivo.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    int ret=1;
    FILE* pArchive;
    Employee*pAux;
    len=ll_len(pArrayListEmployee);
    if(len==0)
    {
        printf("No hay empleados cargados, si se guarda ahora se perderan los datos almacenados en el archivo \"%s\".\n",path);
        if(getConfirm()==0)
        {
            showMessage("Se cancelo la operacion.\n");
            ret=0;
        }
    }
    pArchive=fopen(path,"wb");

    if(pArchive == NULL)
    {
        showMessage("El archivo no pudo abrirse.\n");
        ret=-1;
    }
    else
    {
        len=ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            pAux=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pAux,sizeof(Employee),1,pArchive);
        }
        fclose(pArchive);
    }
    if(ret==1)
    {
        showMessage("Se guardo el listado correctamente.\n");
    }
    return ret;
}

