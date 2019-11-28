#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AuxFunctions.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;


/** \brief Creates space in the heap for a new Employee, and asks to the user for the values of each field
 *         except the ID that is autoincremental. Then returns a pointer to the created element.
 *
 * \return Employee* Pointer to en Employee element.
 *
 */
Employee* employee_new();

/** \brief Creates space in the heap for a new Employee, and uses the values that gets by param to set the id,
 *         nombre and horasTrabajadas fields. Then returns a pointer to the created element.
 *
 * \param char* Char array with id value.
 * \param char* Char array with nombre value.
 * \param char* Char array with horasTrabajadas value.
 * \return Employee* Pointer to en Employee element.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);


/** \brief Removes an employee
 *
 * \param LinkedList* Linked List that contains the employee.
 * \param int len Length of the linked list.
 * \return void
 *
 */
void employee_delete(LinkedList* pArrayListEmployee,int len);


/** \brief Expects an Employee pointer and an int value to set the id field of the employee.
 *
 * \param this Employee* Pointer to the employee to be setted.
 * \param id int Value to be set on the id field
 * \return int
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Expects a pointer to Employee and a memory address to an int var, in which it will save
 *         the value of the id field of said employee.
 *
 * \param this Employee* Pointer to en Employee element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int employee_getId(Employee* this,int* id); ///Devuelven 1 en caso de exito.

/** \brief Expects an Employee pointer and an char array to set the nombre field of the employee.
 *
 * \param this Employee* Pointer to the employee to be setted.
 * \param nombre char* Value to be set on the nombre field
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Expects a pointer to Employee and a memory address to a char array, in which it will save
 *         the value of the name field of said employee.
 *
 * \param this Employee* Pointer to en Employee element.
 * \param sueldo int* Memory address to a char array
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);///Devuelven 1 en caso de exito.

/** \brief Expects an Employee pointer and an int value to set the horasTrabajadas field of the employee.
 *
 * \param this Employee* Pointer to the employee to be setted.
 * \param horasTrabajadas int Value to be set on the horasTrabajadas field
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Expects a pointer to Employee and a memory address to an int var, in which it will save
 *         the value of the horasTrabajadas field of said employee.
 *
 * \param this Employee* Pointer to en Employee element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);///Devuelven 1 en caso de exito.

/** \brief Expects an Employee pointer and an int value to set the sueldo field of the employee.
 *
 * \param this Employee* Pointer to the employee to be setted.
 * \param sueldo int Value to be set on the sueldo field
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief Expects a pointer to Employee and a memory address to an int var, in which it will save
 *         the value of the salary field of said employee.
 *
 * \param this Employee* Pointer to en Employee element.
 * \param sueldo int* Memory address to an int var
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);///Devuelven 1 en caso de exito.

/** \brief Prints a list of every element on the array.
 *
 * \param pArrayListEmployee LinkedList*
 * \return void
 *
 */
void employee_showEveryone(LinkedList* pArrayListEmployee);

/** \brief Compares two elements by their ID value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
int compareById (void*, void*);

/** \brief Compares two elements by their name value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
int compareByName (void*, void*);

/** \brief Compares two elements by their worked hours value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
int compareByWorkedHours (void*, void*);

/** \brief Compares two elements by their salary value.
 *
 * \param Element 1
 * \param Element 2
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
int compareBySalary (void*, void*);


#endif // employee_H_INCLUDED
