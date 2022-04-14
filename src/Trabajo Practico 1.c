/*
 ============================================================================
 Name        : Trabajo Practico 1
 Author      : Santiago Ruiz Diaz, DIV D
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculosTP.h"
#include "datos.h"

int main(void)
{
	int opcion;
	int kilometrosIngresados = 0;
	float precioDelVueloLatam = 0;
	float precioDelVueloAerolineas = 0;
	float debitoLatam;
	float creditoLatam;
	float creditoAerolineas;
	float debitoAerolineas;
	float precioBitcoinLatam;
	float precioBitcoinAerolineas;
	float precioPorKmLatam;
	float precioPorKmAerolineas;
	float diferenciaPrecios;
	int contador = 0;

	setbuf(stdout,NULL);
	do
	{
		menuOpciones();
		scanf("%d", &opcion);

		switch(opcion)
		{
		case 1:
			printf("\nIngrese su cantidad de kilometros: " );
			scanf("%d", &kilometrosIngresados);
			break;
		case 2:
			printf("\nIngrese el precio del vuelo (Aerolineas): ");
			scanf("%f", &precioDelVueloAerolineas );

			printf("\nIngrese el precio del vuelo (Latam): ");
			scanf("%f", &precioDelVueloLatam );
			break;
		case 3:
		if(precioDelVueloLatam == 0 && precioDelVueloAerolineas == 0 && kilometrosIngresados == 0)
		{
			printf("Error, el numero ingresado debe ser mayor a 1 o mas\n");
		}
		else
		{
		contador = 1;
		debitoLatam = debito(precioDelVueloLatam );
		creditoLatam = credito(precioDelVueloLatam);



		debitoAerolineas = debito(precioDelVueloAerolineas);
		creditoAerolineas = credito(precioDelVueloAerolineas);

		precioBitcoinLatam = bitcoin(precioDelVueloLatam);
		precioBitcoinAerolineas = bitcoin (precioDelVueloAerolineas);


		precioPorKmLatam = precioKm(precioDelVueloLatam, kilometrosIngresados );


		precioPorKmAerolineas = precioKm(precioDelVueloAerolineas, kilometrosIngresados );


		diferenciaPrecios = diferenciaPrecio(precioDelVueloLatam, precioDelVueloAerolineas );
		}
			break;
		case 4:
			if(contador == 0 )
			{
				printf("Error, no se realizo ningun calculo\n");

			}
			else{
			datos(debitoLatam, creditoLatam, debitoAerolineas, creditoAerolineas, precioBitcoinLatam, precioBitcoinAerolineas, precioPorKmLatam, precioPorKmAerolineas, kilometrosIngresados, diferenciaPrecios, precioDelVueloLatam, precioDelVueloAerolineas);
			}
			break;
		case 5:
			kilometrosIngresados = 7090;
			precioDelVueloLatam = 159339;
			precioDelVueloAerolineas = 162965;

			debitoLatam = debito(precioDelVueloLatam);
			creditoLatam = credito(precioDelVueloLatam);

			debitoAerolineas = debito(precioDelVueloAerolineas);
			creditoAerolineas = credito(precioDelVueloAerolineas);

			precioBitcoinLatam = bitcoin(precioDelVueloLatam);

			precioBitcoinAerolineas = bitcoin (precioDelVueloAerolineas);

			precioPorKmLatam = precioKm(precioDelVueloLatam, kilometrosIngresados);

			precioPorKmAerolineas = precioKm(precioDelVueloAerolineas, kilometrosIngresados);

			diferenciaPrecios = diferenciaPrecio(precioDelVueloAerolineas, precioDelVueloLatam);

			datos(debitoLatam, creditoLatam, debitoAerolineas, creditoAerolineas, precioBitcoinLatam, precioBitcoinAerolineas, precioPorKmLatam, precioPorKmAerolineas, kilometrosIngresados, diferenciaPrecios, precioDelVueloLatam, precioDelVueloAerolineas);
			break;
		case 6:
			printf("Adios");
		}
	}while(opcion < 6);

	return 0;
}

