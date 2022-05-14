/*
 * ArrayPassanger.c
 *
 *  Created on: 12 may 2022
 *      Author: Santiago Ruiz Diaz DIV D
 */

#include "ArrayPassenger.h"

#include <stdio.h>
#include <string.h>
#define OCUPADO 0
int menuOpciones(void)
{
	printf(	"\n1- Ingresar pasajero.\n"
						"2- Modificar pasajero.\n"
						"3- Eliminar pasajero.\n"
						"4- Informar pasajeros.\n"
						"5- Ingreso forzado de pasajeros.\n"
						"6- Salir.\n"
						"\nIngrese la opcion deseada:");
	return 0;
}

int subMenu(void)
{
	printf(	"\n1- Modificar nombre.\n"
								"2- Modificar apellido.\n"
								"3- Modificar precio.\n"
								"4- Modificar codigo de vuelo.\n"
								"5- Modificar tipo de pasajero.\n"
								"6- Salir.\n"
								"\nIngrese la opcion deseada:");
	return 0;
}
int MenuInformar(void)
{
	printf("\nMenú para informar pasajeros:\n"
					"1- Listado de pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
					"2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
					"3- Listado de los pasajeros por Código de vuelo y estados de vuelos 'ACTIVO'\n"
					"4- Volver al menú principal\n"
					"\nIngrese la opcion deseada: ");
	return 0;
}
int initPassengers(Passenger* list, int len)
{
	int i = 0;

	for(; i < len; i++)
	{
		list[i].isEmpty = VACIO;
	}

	return 0;
}
int addPassenger(Passenger *list, int len, int id, char name[], char lastname[],float price, int typePassenger, char flycode[])
{
	int i = 0;
	for (; i < len; i++) {
		if (list[i].isEmpty == VACIO) {
			list[i].isEmpty = 0;
			list[i].id = id;
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].name, name);
			strcpy(list[i].lastname, lastname);
			strcpy(list[i].flycode, flycode);

			printf("La id del pasajero es: %d", id);

			i = len + 1;
		}

	}
	return 0;
}
int findPassengerById(Passenger *list, int len, int id) {
	int i;
	int posicionQueDevuelve;

	for (i = 0; i < len; i++) {
		if (list[i].id == id) {
			posicionQueDevuelve = i;
			i = len + 1;
		}
	}

	return posicionQueDevuelve;
}
int removePassenger(Passenger *list, int len, int id) {
	int posicionABorrar = -1;
	int retorno = 0;
	posicionABorrar = findPassengerById(list, len, id);

	if (posicionABorrar == -1) {
		retorno = -1;
	}

	list[posicionABorrar].isEmpty = -1;

	return retorno;
}
int sortPassengers(Passenger *list, int len, int order)
{
	int i;
	int j;
	int value = 0;

	Passenger listAux;

	for(i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[j].isEmpty != -1)
			{
				if (order == 1)
				{

					value = strcmp(list[i].lastname, list[j].lastname);
				}
				else
				{
					value = strcmp(list[j].lastname, list[i].lastname);
				}

				int pruebaVariable;
				pruebaVariable = strcmp(list[i].lastname, list[i-1].lastname);

				if(pruebaVariable == 0)
				{
					i ++;
					j = i+1;
				}
				if (value == 1)
				{
					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastname, list[i].lastname);
					listAux.price = list[i].price;
					strcpy(listAux.flycode, list[i].flycode);
					listAux.typePassenger = list[i].typePassenger;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastname, list[j].lastname);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastname, listAux.lastname);
					list[j].price = listAux.price;
					strcpy(list[j].flycode, listAux.flycode);
					list[j].typePassenger = listAux.typePassenger;
				}
			}
		}
	}
	return 0;
}
int printPassenger(Passenger* list, StatusFlyAndTypePassenger* statusType ,int length, int lenStatusType)
{
	int retorno = -1;
	int i;

	if (list != NULL)
	{
		if (length >= 0)
		{
			printf("\nID     Nombre \t\t Apellido \t    Precio \t Codigo de Vuelo\tTipo de Pasajero \tEstado del vuelo\n");
			for (i = 0; i < length; i++)
			{
				if(list[i].isEmpty == OCUPADO)
				{
					for(int j = 0; j < lenStatusType; j++)
					{
						if(list[i].statusFlight == statusType[j].statusFlight)
						{
							for(int k = 0; k < lenStatusType; k++)
							{
								if(list[i].typePassenger == statusType[k].typePassenger)
								{
									printf("%-6d %-17s %-18s %-12.2f %-22s %-23s %s\n", list[i].id, list[i].lastname, list[i].name,list[i].price, list[i].flycode, statusType[k].descripcionTP, statusType[j].descripcionSF);
									break;
								}
							}
							break;
						}
					}
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}
int averagePassenger(Passenger* list, int len, float* totalPrice, float* average)
{
	int retorna = -1;
	int counter = 0;
	float localPrecioTotal;

	if(list != NULL)
	{
		if(len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].price >= 0)
				{
					counter++;
					localPrecioTotal+= list[i].price;
					retorna = 0;
				}
			}
		}
	}
	*average = localPrecioTotal / counter;
	*totalPrice = localPrecioTotal;

	return retorna;
}
int aboveAveragePassenger(Passenger* list, int len, float average)
{
	int retorno = -1;
	int counter = 0;

	if(list != NULL)
	{
		if(len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].price > average)
				{
					counter++;
					retorno = counter;
				}
			}
		}
	}

	return retorno;
}

