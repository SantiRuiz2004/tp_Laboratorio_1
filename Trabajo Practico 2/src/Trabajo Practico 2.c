/*
 ============================================================================
 Name        : Trabajo Practico 2.c
 Author      : Santiago Ruiz Diaz DIV D
 Version     :
 Copyright   : Your copyright notice
 Description : Objetivo:
*Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
*no puede tener más de 2000 pasajeros.
*
*El sistema deberá tener el siguiente menú de opciones:
*1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
*número de Id. El resto de los campos se le pedirá al usuario.
*2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
*o Precio o Tipo de pasajero o Código de vuelo
*3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
*4. INFORMAR:
*1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
*2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
*promedio.
*3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Inputs.h"


int main(void)
{
	setbuf(stdout,NULL);

	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flyCodeAux[30];
	int typePassengerAux;
	int idABuscar;
	int posicionDada;
	int opcionSubMenu;
	int opcionMenuInformar;
	int idABorrar;
	int opcion;
	int largo = 2000;
	float precioPromedio;
	float precioFinal;
	int tipoPasajero = 3;
	int promedioPasajeros;
	Passenger pasajeros[largo];
	initPassengers(pasajeros,largo);
	StatusFlyAndTypePassenger estadoDelVueloYTipoPasajero[tipoPasajero];

	do
	{
		menuOpciones();
		scanf("%d", &opcion);
		fflush(stdin);

		switch(opcion)
		{

			case 1:

				idAux ++;

				rellenarArray(nameAux, "\nIngrese el nombre del pasajero: ");

				rellenarArray(lastNameAux, "\nIngrese el apellido del pasajero: ");

				rellenarFloat(&priceAux, "\nIngrese el precio del vuelo: ");

				rellenarArray(flyCodeAux, "\nIngrese el codigo de vuelo: ");

				rellenarInt(&typePassengerAux, "\nIngrese el tipo de pasajero: ");

				addPassenger(pasajeros,largo, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flyCodeAux);

				break;

			case 2:
				rellenarInt(&idABuscar, "\nIngrese el id a modifcar.\n");
				posicionDada = findPassengerById(pasajeros, largo, idABuscar);

				do
				{
					subMenu();
					scanf("%d", &opcionSubMenu);
					fflush(stdin);

					switch(opcionSubMenu)
					{
					case 1:
						rellenarArray(pasajeros[posicionDada].name, "\nIngrese el nombre modificado:\n");
						break;

					case 2:
						rellenarArray(pasajeros[posicionDada].lastname, "\nIngrese el apellido modificado:\n");
						break;

					case 3:
						rellenarFloat(&pasajeros[posicionDada].price, "\nIngrese el precio modificado:\n");
						break;

					case 4:
						rellenarArray(pasajeros[posicionDada].flycode, "\nIngrese el codigo de vuelo modificado:\n");
						break;

					case 5:
						rellenarInt(&pasajeros[posicionDada].typePassenger, "\nIngrese el tipo de pasajero modificado.\n");
						break;

					case 6:
						printf("\nVolviendo al menu Principal...\n");
						break;

					default:
						printf("\nOpcion invalida, ingrese devuelta:");
						break;
					}
				}while(opcionSubMenu != 6);
				break;
			case 3:
				rellenarInt(&idABorrar, "\nIngrese el id a borrar: \n");

				if(idABorrar > -1)
				{
					if(removePassenger(pasajeros,largo,idABorrar) == 0)
					{
						printf("\nSe ha eliminado con exito al pasajero");
					}
					else
					{
						printf("\nHubo un error y no se pudo borrar al pasajero.\n");
					}
				}
				else
				{
					printf("\nError, no hay ningun pasajero con ese ID\n\n");
				}

				removePassenger(pasajeros, largo, idABorrar);
				break;
			case 4:
				do
				{
					MenuInformar();
					scanf("%d", &opcionMenuInformar);
					fflush(stdin);

					switch(opcionMenuInformar)
					{
					case 1:
						if(sortPassengers(pasajeros, largo , 1) == 0)
						{
							if(printPassenger(pasajeros,estadoDelVueloYTipoPasajero,largo,tipoPasajero) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia\n");
							}
						}
						else
						{
							printf("\nNo se pudo ordenar a los pasajeros por apellido");
						}
					break;
					case 2:
						if(averagePassenger(pasajeros,largo , &precioFinal, &precioPromedio) == 0)
							{
						     promedioPasajeros = aboveAveragePassenger(pasajeros, largo, precioPromedio);
							 printf("\nEl precio final de los vuelos es de $%.2f.\nEn promedio cada pasajero pagó $%.2f."
						     "\nEn total hay %d pasajeros que paga por encima del promedio.\n", precioFinal, precioPromedio, promedioPasajeros);
							}
					break;
					case 3:
						if(sortPassengers(pasajeros,largo,1) == 0)
						{
							if(printPassenger(pasajeros,estadoDelVueloYTipoPasajero,largo,tipoPasajero) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
					break;
					case 4:
						printf("\nVolviendo al menu Principal....\n");
					break;
					default:
						printf("\nIngrese la opcion correcta 1-4\n");
						break;
					}
				}while(opcionMenuInformar != 4);
				break;
			case 5:

				idAux ++;
				strcpy(nameAux,"Nicolas");
				strcpy(lastNameAux,"Lopez");
				priceAux = 2500;
				typePassengerAux = 1;
				strcpy(flyCodeAux,"Codigo: R6E8TE78");
				addPassenger(pasajeros,largo,idAux,nameAux,lastNameAux,priceAux,typePassengerAux,flyCodeAux);

				idAux ++;
				strcpy(nameAux,"Jose");
				strcpy(lastNameAux,"Gimenez");
				priceAux = 2000;
				typePassengerAux = 2;
				strcpy(flyCodeAux,"Codigo: 9FS8F9G3");
				addPassenger(pasajeros,largo,idAux,nameAux,lastNameAux,priceAux,typePassengerAux,flyCodeAux);

				idAux ++;
				strcpy(nameAux,"Maria");
				strcpy(lastNameAux,"Duarte");
				priceAux = 1500;
				typePassengerAux = 3;
				strcpy(flyCodeAux,"Codigo: j8v9d7fa");
				addPassenger(pasajeros,largo,idAux,nameAux,lastNameAux,priceAux,typePassengerAux,flyCodeAux);

				idAux ++;
				strcpy(nameAux,"Yanina");
				strcpy(lastNameAux,"Diaz");
				priceAux = 1550;
				typePassengerAux = 1;
				strcpy(flyCodeAux,"Codigo: F9Sfs98F");
				addPassenger(pasajeros,largo,idAux,nameAux,lastNameAux,priceAux,typePassengerAux,flyCodeAux);

				idAux ++;
				strcpy(nameAux,"Santiago");
				strcpy(lastNameAux,"Ruiz");
				priceAux = 4500;
				typePassengerAux = 3;
				strcpy(flyCodeAux,"Codigo: G0S9C0A0");
				addPassenger(pasajeros,largo,idAux,nameAux,lastNameAux,priceAux,typePassengerAux,flyCodeAux);
				break;

			case 6:
				printf("\nApagando Sistema, Adios...\n");
				break;
			  }
	}while(opcion != 6);


	return 0;
}
