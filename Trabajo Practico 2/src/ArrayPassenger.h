/*
 * ArrayPassanger.h
 *
 *  Created on: 12 may 2022
 *      Author: Santiago Ruiz Diaz DIV D
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define VACIO -1

struct
{
int id;
char name[51];
char lastname[51];
float price;
char flycode[10];
int typePassenger;
int isEmpty;
int statusFlight;
}typedef Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
typedef struct
{
	int statusFlight;
	char descripcionSF[15];
	int typePassenger;
	char descripcionTP[15];
} StatusFlyAndTypePassenger;

int menuOpciones(void);
int subMenu(void);
int MenuInformar(void);

int initPassengers(Passenger* list, int len);
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok

*/

int addPassenger(Passenger *list, int len, int id, char name[], char lastname[],float price, int typePassenger, char flycode[]);
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int findPassengerById(Passenger *list, int len, int id);
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int removePassenger(Passenger *list, int len, int id);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int sortPassengers(Passenger *list, int len, int order);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
*  \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printPassenger(Passenger* list, StatusFlyAndTypePassenger* statusType ,int length, int lenStatusType);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/

int averagePassenger(Passenger* list, int len, float* totalPrice, float* average);
/// @brief count how many passengers pay above the average price
///
/// @param list Passenger*
/// @param len int
/// @param average average price of flights
/// @return int (-1) if error [Invalid length or NULL pointer or the list are empty] or the number of passengers above the average

int aboveAveragePassenger(Passenger* list, int len, float average);


#endif /* ARRAYPASSENGER_H_ */
