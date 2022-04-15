/*
 * datos.h
 *
 *  Created on: 11 abr 2022
 *      Author: usuario
 */

#ifndef DATOS_H_
#define DATOS_H_

int datos(float debitoLatam, float creditoLatam, float debitoAerolineas, float creditoAerolineas, float precioBitcoinLatam, float precioBitcoinAerolineas, float precioPorKmLatam, float precioPorKmAerolineas, int kilometrosIngresados, float diferenciaPrecios, float precioDelVueloLatam,float precioDelVueloAerolineas);
int menuOpciones(void);

///@fn int menuOpciones(void)
///@brief muestra el menu de opciones
///
///@param
///@return retorna a la opcion seleccionada int menuOpciones(void)


///@fn int datos(float,float,float,float,float,float,float,float,float,float,float,int)
///@brief muestras los datos ingresados
///
///@param kilometrosIngresados,precioDelVueloLatam, debitoLatam, creditoLatam, precioBitcoinLatam, precioPorKmLatam, precioDelVueloAerolineas, debitoAerolineas, creditoAerolineas, precioBitcoinAerolineas, precioPorKmAerolineas, diferenciaPrecios
///@return retorna a la opcion seleccionada int datos(float,float,float,float,float,float,float,float,float,float,float,int)
#endif /* DATOS_H_ */
