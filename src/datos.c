/*
 * datos.c
 *
 *  Created on: 11 abr 2022
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>

int datos(float debitoLatam, float creditoLatam, float debitoAerolineas, float creditoAerolineas, float precioBitcoinLatam, float precioBitcoinAerolineas, float precioPorKmLatam, float precioPorKmAerolineas, int kilometrosIngresados, float diferenciaPrecios, float precioDelVueloLatam,float precioDelVueloAerolineas)
{
printf("Kilometros Ingresados: %d Kms \n"
		"Informe de resultados:\n"
		"Precio de Latam: %.2f\n"
		"a)El con tarjeta de debito para Latam es : %.2f\n"
		"b)El precio con tarjeta de credito para Latam: %.2f\n"
		"c)El con Bitcoin para Latam es : %.6f\n"
		"d)El precio por Kilometro en Latam es: %.4f\n"
		"Precio de Aerolineas: %.2f\n"
		"a)El con tarjeta de debito para Aerolineas es : %.2f\n"
		"b)El precio con tarjeta de credito para Aerolineas : %.2f\n"
		"c)El precio con Bitcoin para Aerolineas es : %.6f\n"
		"d)El precio por Kilometro en Aerolineas es : %.4f\n"
		"La diferencia de precios es de: %.2f", kilometrosIngresados,precioDelVueloLatam, debitoLatam, creditoLatam, precioBitcoinLatam, precioPorKmLatam, precioDelVueloAerolineas, debitoAerolineas, creditoAerolineas, precioBitcoinAerolineas, precioPorKmAerolineas, diferenciaPrecios);

return 0;
}
int menuOpciones(void)
{
	printf("\n1- Ingresar Kilómetros. \n"
		       "2- Ingresar Precio de Vuelos. \n"
		       "3- Calcular todos los costos. \n"
		       "4- Informar Resultados. \n"
		       "5- Carga forzada de datos. \n"
		       "6- Salir. \n"
		       "\n Ingrese la opción deseada: ");
	return 0;
}

