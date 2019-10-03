#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)                                                                                             ///2.1 Función initEmployees:
{
    int i;
    int ret;
    if(list!=NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        ret=0;
    }
    else
    {
        ret=-1;
    }
    return ret;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)                                   ///2.2 Función addEmployees:
{
    int i;
    int ret=-1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                list[i].id = id;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                ret=0;
                break;
            }
        }
    }
    return ret;
}


int findEmployeeById(Employee* list, int len,int id)                                                                                    ///2.3 Función findEmployeeById
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
        {
            ret=i;
            break;
        }
    }
    return ret;
}


int removeEmployee(Employee* list, int len, int id)                                                                                     ///2.4 Función removeEmployee:
{
    int i;
    int ret=-1;
    i=findEmployeeById(list, len, id);
    if (i!=-1)
    {
        printf("Esta a punto de dar de baja al siguiente empleado:\n\n");
        printTab();
        printAnEmployee(list, i);
        printf("\ns/n\n");

        if(getConfirm()==1)
        {
            list[i].isEmpty = 1;
            showMessage("El empleado se dio de baja con exito.\n");
            ret=0;
        }
        else
        {
            showMessage("Se cancelo la baja del usuario.\n");
            ret=0;
        }
    }
    return ret;
}


int sortEmployeesByLastNameAndSector(Employee* list, int len, int order)                                                            ///2.5 Función sortEmployees:
{
    int i;
    int j;
    int ret=-1;
    Employee aux[1];

    if(list!=NULL||len<0||order<0||order>1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=1; j<len; j++)
            {
                switch(order)
                {
                case 0:
                    if (stricmp(list[i].lastName,list[j].lastName)>0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].lastName,list[j].lastName)==0) && (list[i].sector>list[j].sector))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                case 1:
                    if (stricmp(list[i].lastName,list[j].lastName)<0)
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    if((stricmp(list[i].lastName,list[j].lastName)==0) && (list[i].sector<list[j].sector))
                    {
                        aux[0]=list[i];
                        list[i]=list[j];
                        list[j]=aux[0];
                    }
                    break;
                }
            }
        }
        ret=0;
    }
    return ret;
}


int printEmployees(Employee* list, int length)                                                                                          ///2.6 Función printEmployees:
{
    int i;
    system("cls");
    printTab();
    for(i=0; i<length; i++)
    {
        printAnEmployee(list, i);
    }
    system("pause");
    system("cls");
    return 0;
}


int showMenuGetOption(char message[], int min, int max)
{
    int option;
    do
    {
        printf(message);
        scanf("%d", &option);
        fflush(stdin);
        system("cls");
        if(option<min||option>max)
        {
            system("cls");
            printf("Indique una opcion valida entre %d y %d.\n\n",min,max);
        }
    }
    while(option <min||option>max);
    return option;
}


void showMessage(char message[])
{
    system("cls");
    printf(message);
    system("pause");
    system("cls");
}


int getConfirm()
{
    int ret=-1;
    do
    {
        ret=getche();
        fflush(stdin);
        if((ret==83)||(ret==115))
        {
            ret=1;
        }
        else if((ret==78)||(ret==110))
        {
            ret=0;
        }
        else
        {
            printf("\n\nIngrese s para confirmar, n para cancelar.\n");
        }
    }
    while(ret!=0&&ret!=1);

    return ret;
}


int getPositiveInt(char message[])
{
    int i=0;
    char string[10]; ///Almacena hasta el 2147483647.
    int ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        for(i=0;string[i]!='\0';i++)
        {
            if(string[i]<48||string[i]>57)
            {
                showMessage("Ingrese un valor numerico valido. (Solo numeros enteros positivos).\n\n");
                ret=-1;
                break;
            }
        }
    }while(ret==-1);
    ret=atoi(string);
    return ret;
}


float getPositiveFloat(char message[])
{
    int i;
    int flagFloatingPoint=0;
    char string[10];
    float ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        for(i=0;string[i]!='\0';i++)
        {
            if(string[i]==46)
            {
                flagFloatingPoint++;
            }
            if((flagFloatingPoint>1)||((string[i]<48||string[i]>57)&&(string[i]!=46)))
            {
                showMessage("Ingrese un valor numerico valido. (Positivos con o sin punto.)");
                ret--;
                flagFloatingPoint=0;
                break;
            }
        }
    }while(ret<0);
    ret=atof(string);
    return ret;
}


void printTab ()
{
    printf("ID\tSECTOR\t\t\tAPELLIDO\t\tNOMBRE\t\tSALARIO\n\n");
    return;
}


int printAnEmployee (Employee* list, int i)
{
    int ret=-1;
    if (list[i].isEmpty==0)
    {
        printf("%04d\t%03d\t\t%18s\t%18s\t%.2f\n",list[i].id,list[i].sector,list[i].lastName,list[i].name,list[i].salary);
        ret=i;
    }
    return ret;
}


int checkAllEmpty (Employee* list, int len)
{
    int i;
    int ret=1;
    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}


void hardcodeEmployees (Employee* list)
{
    int id[13]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    char name[13][51]= {"Homero","Bob","Moe","Apu","Rafa","Juan","Hank","Milhouse","Barney","Lenny","Carl","Extrapalapaquetel","Bart"};
    char lastName[13][51]= {"Simpson","Patinio","Szyslak","Nahasapeemapetilon","Gorgory","Topo","Scorpio","Van Houten","Gomez","Leonard","Carlson","Cabezota Olmeca","Simpson"};
    float salary[13]= {10000,80000,30000,40000,20000,100000,60000,70000,90000,50000,110000,75000,35000};
    int sector[13]= {7,4,4,3,1,3,1,1,7,7,4,3,2};
    int i;

    for(i=0; i<13; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].salary=salary[i];
        list[i].sector=sector[i];
        list[i].isEmpty=0;
    }
    return;
}


void informSalaryStat(Employee* list, int len)
{
    int i;
    int count=0;
    double accumulator;
    float average;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            accumulator+=list[i].salary;
            count++;
        }
    }
    average=accumulator/count;

    system("cls");
    printf("El total de los salarios es de %.2f.\n",accumulator);
    printf("El promedio de los salarios es de %.2f.\n",average);
    count=0;
    for(i=0; i<len; i++)
    {
        if((list[i].isEmpty==0)&&(list[i].salary>average))
        {
            count++;
        }
    }
    if(count==0)
    {
        printf("No hay empleados que superen el promedio de salario.\n\n");
    }
    else
    {
        printf("La cantidad de empleados que superan el promedio de salario es de %d y se enlista/n a continuacion:\n\n",count);
        printTab();
        for(i=0; i<len; i++)
        {
            if((list[i].isEmpty==0)&&(list[i].salary>average))
            {
                printAnEmployee(list,i);
            }
        }
    }
    system("pause");
    return;
}


void informStaff(Employee* list, int len, int order)
{
    sortEmployeesByLastNameAndSector(list,len,order);
    printEmployees(list,len);
    return;
}


int getAlphabeticalString (char message[],char string[],int maxLen)
{
    int i;
    int len;
    int ret=1;

    do
    {
        printf(message);
        gets(string);
        fflush(stdin);
        len=strlen(string);
        ret=1;
        if(len>maxLen)
        {
            system("cls");
            printf("Se supero el maximo de caracteres permitidos para este campo (%d).\n",maxLen);
            system("pause");
            system("cls");
            ret=0;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)))
                {
                    showMessage("Ingreso caracteres no validos, verifique e intente nuevamente.\n\n");
                    ret=0;
                    break;
                }
            }
        }

    }while(len==0||ret==0);


    return ret;
}


void runMenu ()
{
    int option;
    int auxOption;
    Employee listOfEmployees[ELEMENTS];
    char auxName[51];
    char auxLastName[51];
    float auxFloat;
    int id=1;
    int i;
    int confirm;
    char confirmation[85]= {"El campo se modifico con exito. Se muestran los nuevos valores del empleado.\n\n"};
    int auxInt;

    if(initEmployees(listOfEmployees, ELEMENTS)==0)
    {
        do
        {
            system("cls");
            option=showMenuGetOption("Seleccione una opcion:\n\n1)ALTAS:\n2)MODIFICAR:\n3)BAJA:\n4)INFORMAR:\n5)SALIR.\n\n",1,5);
            switch (option)
            {
            case -1:
                showMessage("Error, parametros incorrectos.\n\n");
                break;
            case 1:

///               Descomentar para activar hardcodeo. (Modo test.)
//                if(id==1)
//                {
//                    hardcodeEmployees(listOfEmployees);
//                    id+=13;
//                    break;
//                }

                system("cls");
                if(getAlphabeticalString("Ingrese nombre:\n",auxName,50)==0)
                {
                    break;
                }
                if(getAlphabeticalString("Ingrese Apellido:\n",auxLastName,50)==0)
                {
                    break;
                }
                if((auxFloat=getPositiveFloat("Ingrese Salario:\n"))==-1)
                {
                    break;
                }
                if((auxInt=getPositiveInt("Indique numero de sector:\n"))==-1)
                {
                    break;
                }

                switch (addEmployee(listOfEmployees, ELEMENTS, id, auxName, auxLastName, auxFloat, auxInt))
                {
                case -1:
                    showMessage("No se pudo cargar el empleado.\n");
                    break;
                case 0:
                    i=findEmployeeById(listOfEmployees,ELEMENTS,id);
                    system("cls");
                    printTab();
                    printAnEmployee(listOfEmployees,i);
                    printf("Confirma la carga del empleado?\n\ns/n\n\n");
                    switch(getConfirm())
                    {
                    case 1:
                        showMessage("El empleado se cargo con exito.\n\n");
                        id++;
                        break;
                    case 0:
                        listOfEmployees[i].isEmpty=1;
                        showMessage("Se cancelo la carga.\n\n");
                        break;
                    }

                    break;
                }
                break;
            case 2:
                if(checkAllEmpty(listOfEmployees,ELEMENTS)==0)
                {
                    auxInt=getPositiveInt("Ingrese el ID del empleado a modificar:\n");
                    i=findEmployeeById(listOfEmployees,ELEMENTS,auxInt);
                    if(i>=0&&i<=1000)
                    {
                        printTab();
                        printAnEmployee(listOfEmployees,i);
                        auxOption=showMenuGetOption("\n\nIndique el campo a modificar:\n\n1)Nombre.\n2)Apellido.\n3)Salario.\n4)Sector.\n5)Cancelar.\n",1,5);
                        system("cls");
                        switch(auxOption)
                        {
                        case -1:
                            showMessage("Error, parametros incorrectos.\n\n");
                            break;
                        case 1:
                            if(getAlphabeticalString("Ingrese nuevo nombre:\n",auxName,50)==0)
                                {
                                    break;
                                }
                            system("cls");
                            printTab();
                            printAnEmployee(listOfEmployees,i);
                            printf("\n\nEsta por modificar %s por %s. Esta seguro/a?\n\ns/n\n",listOfEmployees[i].name,auxName);
                            confirm=getConfirm();
                            switch (confirm)
                            {
                            case 1:
                                strcpy(listOfEmployees[i].name,auxName);
                                system("cls");
                                printf(confirmation);
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                system("pause");
                                system("cls");
                                break;

                            case 0:
                                showMessage("Se cancelo la modificacion.\n\n");
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                break;
                            }
                            break;

                        case 2:
                            if(getAlphabeticalString("Ingrese nuevo apellido:\n",auxLastName,50)==0)
                            {
                                break;
                            }
                            system("cls");
                            printTab();
                            printAnEmployee(listOfEmployees,i);
                            printf("\n\nEsta por modificar %s por %s. Esta seguro/a?\n\ns/n\n", listOfEmployees[i].lastName,auxLastName);
                            confirm=getConfirm();
                            switch (confirm)
                            {
                            case 1:
                                strcpy(listOfEmployees[i].lastName,auxLastName);
                                system("cls");
                                printf(confirmation);
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                system("pause");
                                system("cls");
                                break;

                            case 0:
                                showMessage("Se cancelo la modificacion.\n\n");
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                break;
                            }
                            break;

                        case 3:
                            if((auxFloat=getPositiveFloat("Ingrese nuevo salario:\n"))==-1)
                            {
                                break;
                            }
                            system("cls");
                            printTab();
                            printAnEmployee(listOfEmployees,i);
                            printf("\n\nEsta por modificar %.2f por %.2f. Esta seguro/a?\n\ns/n\n", listOfEmployees[i].salary,auxFloat);
                            confirm=getConfirm();
                            switch (confirm)
                            {
                            case 1:
                                listOfEmployees[i].salary=auxFloat;
                                system("cls");
                                printf(confirmation);
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                system("pause");
                                system("cls");
                                break;

                            case 0:
                                showMessage("Se cancelo la modificacion.\n\n");
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                break;
                            }
                            break;

                        case 4:
                            if((auxInt=getPositiveInt("Indique nuevo numero de sector:\n"))==-1)
                            {
                                break;
                            }
                            system("cls");
                            printTab();
                            printAnEmployee(listOfEmployees,i);
                            printf("\n\nEsta por modificar %d por %d. Esta seguro/a?\n\ns/n\n", listOfEmployees[i].sector,auxInt);
                            confirm=getConfirm();
                            switch (confirm)
                            {
                            case 1:
                                listOfEmployees[i].sector=auxInt;
                                system("cls");
                                printf(confirmation);
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                system("pause");
                                system("cls");
                                break;
                            case 0:
                                showMessage("Se cancelo la modificacion.\n\n");
                                printTab();
                                printAnEmployee(listOfEmployees,i);
                                break;
                            }
                            break;

                        case 5:
                            break;
                        }
                    }
                    else
                    {
                        showMessage("El ID ingresado no es valido, verifique e intente nuevamente.\n");
                    }
                }
                else
                {
                    showMessage("No hay empleados cargados.\n");
                }
                break;

            case 3:
                if(checkAllEmpty(listOfEmployees,ELEMENTS)==0)
                {
                    system("cls");
                    auxInt=getPositiveInt("Ingrese el ID del empleado a dar de baja:\n");
                    if(removeEmployee(listOfEmployees,ELEMENTS,auxInt)==-1)
                    {
                        showMessage("El ID no existe o ya fue dado de baja con anterioridad.\n");
                    }
                }
                else
                {
                    showMessage("No hay empleados cargados.\n");
                }
                break;

            case 4:

                if(checkAllEmpty(listOfEmployees,ELEMENTS)==0)
                {
                    system("cls");
                    auxOption=showMenuGetOption("Eliga una opcion:\n\n1)Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2)Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n3)Cancelar.\n\n",1,3);
                    switch(auxOption)
                    {
                    case 1:
                        auxOption=showMenuGetOption("Indique si desea visualizar el listado de forma descendente o ascendente:\n\n1)Descendente.\n2)Ascendente.\n",1,2);
                        auxOption--;
                        informStaff(listOfEmployees,ELEMENTS,auxOption);
                        break;

                    case 2:
                        informSalaryStat(listOfEmployees,ELEMENTS);
                        break;

                    case 3:
                        break;
                    }
                }
                else
                {
                    showMessage("No hay empleados cargados\n");
                }
                break;

            case 5:
                system("cls");
                break;
            }
        }
        while(option!=5);
    }
    else
    {
        printf("Hubo un error al inicializar el array.");
    }
    return;
}
