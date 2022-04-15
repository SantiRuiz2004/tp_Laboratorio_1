/*
 * calculosTP.h
 *
 *  Created on: 11 abr 2022
 *      Author: usuario
 */

#ifndef CALCULOSTP_H_
#define CALCULOSTP_H_

float debito(float precio);
float credito(float precio);
float bitcoin(float precio);
float precioKm(float precio, int kilometros);
float diferenciaPrecio(float precioUno, float precioDos);

///@fn float debito(float precio)
///@brief realiza el calculo de descuento con tarjeta de debito
///
///@param debitoLatam,debitoAerolineas
///@descuento retorna la opcion seleccionada float debito(float precio)


///@fn float credito(float,float)
///@brief realiza el calculo de interes con tarjeta de credito
///
///@param creditoLatam,creditoAerolineas
///@credito1 retorna la opcion seleccionada float credito(float precio)


///@fn float bitcoin (float precio)
///@brief realiza la conversion del precio en bitcoin
///
///@param precioBitcoinLatam,precioBitcoinAerolineas
///@bitcoinUno retorna a la opcion seleccionada float bitcoin(float precio)

///@fn float precioKm(float precio)
///@brief realiza el calculo del precio por Kilometro
///
///@param kilometrosIngresados, precioDelvueloLatam,precioDelvueloAerolineas
///@precioKmUno retorna la opcion seleccionada float precioKm(precio)

///@fn float diferencaPrecio(float, float)
///@brief realiza el calculo de resta para saber la diferencia  de precios
///
///@param precioDelvueloLatam,precioDelvueloAerolineas
///@diferencia retorna a la opcion seleccionada float diferenciaPrecio(float,float)
#endif /* CALCULOSTP_H_ */
