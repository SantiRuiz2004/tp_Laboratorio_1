/*
 * calculosTP.c
 *
 *  Created on: 11 abr 2022
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>

float debito(float precio)
{
	float descuento;
	descuento = precio * 10/100;
	descuento = precio - descuento;

return descuento;
}
float credito(float precio)
{
	float credito1;
	credito1 = precio * 25/100;
	credito1 = precio + credito1;

return credito1;
}
float bitcoin(float precio)
{
	float bitcoinUno;

	bitcoinUno = precio / 4606954.55;

return bitcoinUno;
}
float precioKm(float precio, int kilometros)
{
float precioKmUno;

precioKmUno = (float) precio / kilometros;

return precioKmUno;
}
float diferenciaPrecio(float precioUno, float precioDos)
{
float diferencia;

if(precioUno < precioDos)
{
	diferencia = precioDos - precioUno;
}
else
{
	diferencia = precioUno - precioDos;
}

return diferencia;
}









