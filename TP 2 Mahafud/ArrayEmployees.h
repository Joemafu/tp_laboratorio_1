#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ELEMENTS 1000


///2 "ArrayEmployees" library.

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} typedef Employee;


///2.1 Function initEmployees:

/** \brief To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array.
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


///2.2 Function addEmployees:

/**\brief add in an existing list of employees the values received as parameters
*         in the first empty position.
*
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee*, int len, int id, char name[],char lastName[],float salary,int sector);


///2.3 Function findEmployeeById

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);


///2.4 Function removeEmployee:

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


///2.5 Function sortEmployees:

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployeesByLastNameAndSector(Employee* list, int len, int order);


///2.6 Function printEmployees:

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);


/** \brief Gets an options menu as a string, minimal and maximal valid option, prints the menu and gets
 *         selected option by scanf. Validate than the option is between the values provided by \param
 *         and returns it as an int.
 *
 * \param char[] Message to print as a menu (it must include an enumerated options list).
 * \param int Minimal option accepted.
 * \param int Maximal option accepted.
 * \return int Returns -1 in error case (non valid option) - Or the option number selected in case of success.
 *
 *
 */
int showMenuGetOption(char[],int,int);


/** \brief Cleans the screen and prints a message followed by a pause. Then cleans the screen again.
 *
 * \param char[] Message to print.
 * \return Void.
 *
 */
void showMessage(char[]);


/** \brief Prints a message and expects for a float value.
 *
 * \param char[] Gets the message to print.
 * \return float Returns the float value provided by the user.
 *
 */
float getPositiveFloat(char[]);


/** \brief Prints a message asking for confirmation by s/n. Validates (Admits upper and lower case) and
 *         returns 1 for 's' y 0 for 'n'.
 *
 * \return int Returns 1 for 's' and 0 for 'n'.
 *
 */
int getConfirm();


/** \brief Prints an employee's data by index number.
 *
 * \param Struct* Array.
 * \param Number of index of the element to print.
 * \return Returns -1 when the index is not found or it is associated to an isEmpty (erased) element.
 *         in case of success, returns the index.
 *
 */
int printAnEmployee (Employee*, int);


/** \brief Goes over all the array checking if isEmpty==1. In case of true in EVERY element, returns 1. If not, returns 0.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Returns 1 if it's all empty, 0 if not.
 *
 */
int checkAllEmpty (Employee*, int);


/** \brief Prints a categories tab of the employees using the same order than the function printAnEmployee.
 *
 * \return Void.
 *
 */
void printTab ();


/** \brief Creates and prints a stat report of salaries.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Void.
 *
 */
void informSalaryStat(Employee*, int);


/** \brief Prints every element of the structure sorted by last name and sector.
 *
 * \param Struct* Array.
 * \param int Number of indexes.
 * \return Void.
 *
 */
void informStaff(Employee*, int, int);


/** \brief Function with testing purpose only.
 *
 * \param Struct *Array.
 * \return Void
 *
 */
void hardcodeEmployees (Employee*);


/** \brief Prints a message that receives by para, expects a string, upper and lower cases, spaces and apostrophes
 *         admitted. Validates and in case of success it gets associated to the string provided by param and returns 1.
 *
 * \param Message to print, asking the user to enter a string.
 * \param String where the input data is going to get saved.
 * \param Maximum number of characters that the string allows.
 * \return Returns 1 in case of success, and the string gets saved.
 *
 */
int getAlphabeticalString (char[], char[],int);


/** \brief Prints a message that receives from param, asks for a string of chars that only accepts numbers,
 *         validates, casts the string into an int and returns it.
 *
 * \param char[] message to print, asking for the int.
 * \return int Returns the numeric string entered by the user as an int value.
 *
 */
int getPositiveInt(char[]);


/** \brief Runs the navigation menu.
 *
 * \return Void
 *
 */
void runMenu ();
