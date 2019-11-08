#include "Employee.h"

Employee* employee_new()
{
    Employee* emp;
    char nameStr[51];
    int auxInt;
    int r=1;
    emp=(Employee*)malloc(sizeof(Employee));

    getAlphabeticalString("Ingrese el nombre del empleado a cargar: ",nameStr,50);
    r+=employee_setNombre(emp,nameStr);

    auxInt=getPositiveInt("\nIngrese la cantidad de horas trabajadas: ");
    r+=employee_setHorasTrabajadas(emp,auxInt);

    auxInt=getPositiveInt("\nIngrese el sueldo: ");
    r+=employee_setSueldo(emp,auxInt);

    if(r<4)
    {
        showMessage("Error al cargar el nuevo empleado.\n");
    }

    return emp;
}

Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr)
{
    Employee* emp;
    emp=(Employee*)malloc(sizeof(Employee));

    employee_setId(emp,atoi(idStr));
    employee_setNombre(emp,nameStr);
    employee_setHorasTrabajadas(emp,atoi(workedHoursStr));

    return emp;
}

void employee_delete(LinkedList* pArrayListEmployee,int len)
{
    int i;
    int founded=0;
    int id;
    Employee* aux;

    id=getPositiveInt("\nIngrese el ID del empleado que desea eliminar:\n");
    system("cls");

    for(i=0; i<len; i++)
    {
        aux=(Employee*)ll_get(pArrayListEmployee,i);
        if(aux->id==id)
        {
            printf("Esta por eliminar al siguiente empleado:\n\nID: %d \nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
            founded=1;
            if(getConfirm()==1)
            {
                ll_remove(pArrayListEmployee,ll_indexOf(pArrayListEmployee,aux));
                showMessage("Se elimino al empleado correctamente.\n");
            }
            else
            {
                showMessage("Se cancelo la operacion.\n");
            }

            break;
        }
    }
    if(founded==0)
    {
        showMessage("El ID ingresado no se encuentra cargado en el sistema.\n");
    }
}

int employee_setId(Employee* this,int id)
{
    this->id=id;
    return 1;
}

int employee_getId(Employee* this,int* id)
{
    *id=this->id;
    return 1;
}

int employee_setNombre(Employee* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 1;
}

int employee_getNombre(Employee* this,char* nombre)
{
    strcpy(nombre,this->nombre);
    return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    this->horasTrabajadas=horasTrabajadas;
    return 1;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    *horasTrabajadas=this->horasTrabajadas;
    return 1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    this->sueldo=sueldo;
    return 1;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    *sueldo=this->sueldo;

    return 1;
}

int compareById (void* p1, void* p2)
{
    Employee* e1 = (Employee*) p1;
    Employee* e2 = (Employee*) p2;

    return intCmp(e1->id,e2->id);
}

int compareByName (void* p1, void* p2)
{
    Employee* e1 = (Employee*) p1;
    Employee* e2 = (Employee*) p2;

    return stricmp(e1->nombre,e2->nombre);
}

int compareByWorkedHours (void* p1, void* p2)
{
    Employee* e1 = (Employee*) p1;
    Employee* e2 = (Employee*) p2;

    return intCmp(e1->horasTrabajadas,e2->horasTrabajadas);
}

int compareBySalary (void* p1, void* p2)
{
    Employee* e1 = (Employee*) p1;
    Employee* e2 = (Employee*) p2;

    return intCmp(e1->sueldo,e2->sueldo);
}

void employee_showEveryone(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    int auxId;
    int auxSalary;
    int auxWorkedHours;
    char name[128];
    Employee* aux;
    len=ll_len(pArrayListEmployee);
    printf("Hay %d empleados cargados\n\n", len);

    printTab();

    for(i=0; i<len; i++)
    {
        aux=(Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(aux,&auxId);
        employee_getNombre(aux,name);
        employee_getHorasTrabajadas(aux,&auxWorkedHours);
        employee_getSueldo(aux,&auxSalary);
        printf("%-5d %-25s %-18d %d\n",auxId,name,auxWorkedHours,auxSalary);
    }
}
