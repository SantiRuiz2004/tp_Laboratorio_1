/*
 * Inputs.c
 *
 *  Created on: 12 may 2022
 *      Author: Santiago Ruiz Diaz DIV D
 */
#include <stdio.h>
#include <string.h>

void rellenarInt(int* reciboVariable, char mostrarTexto[])
{
	printf(mostrarTexto);
	scanf("%d", reciboVariable);
	fflush(stdin);
}

void rellenarFloat(float* reciboVariable, char mostarTexto[])
{
	printf(mostarTexto);
	scanf("%f", reciboVariable);
	fflush(stdin);
}

void rellenarArray(char reciboArray[], char mostarTexto[])
{
	printf(mostarTexto);
	gets(reciboArray);
	fflush(stdin);
}
