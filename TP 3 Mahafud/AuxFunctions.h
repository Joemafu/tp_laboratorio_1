#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"

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

/** \brief Expects s/n. Validates (Admits upper and lower case) and returns 1 for 's' y 0 for 'n'.
 *
 * \return int Returns 1 for 's' and 0 for 'n'.
 *
 */
int getConfirm();

/** \brief Expects an LL*, searches for the maximum ID value and returns that value+1 to be used as next ID.
 *
 * \param LinkedList* Memory direction of the linkedlist to search on.
 * \return Returns de max Id value+1.
 *
 */
int getNextId (LinkedList*);

/** \brief Prints a message that receives from param, asks for a string of chars that only accepts numbers,
 *         validates, casts the string into an int and returns it (Only positive values admitted).
 *
 * \param char[] message to print, asking for the int.
 * \return int Returns the numeric string entered by the user as an int value.
 *
 */
int getPositiveInt(char[]);

/** \brief Compares two int values.
 *
 * \param int 1 value
 * \param int 2 value
 * \return returns 1 if first value is higher, -1 if second value is higher, or 0 if they're equal.
 *
 */
int intCmp (int int1,int int2);

/** \brief Prints a categories tab of the Elements using default order.
 *
 * \return Void.
 *
 */
void printTab ();

/** \brief Prints a message to let the user know that the data is under process.
 *
 * \return void
 *
 */
void processing();

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
int showMenuGetOption(char*,int,int);

/** \brief Cleans the screen and prints a message followed by a pause. Then cleans the screen again.
 *
 * \param char[] Message to print.
 * \return Void.
 *
 */
void showMessage(char[]);
