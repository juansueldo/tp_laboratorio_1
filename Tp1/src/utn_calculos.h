/*
 * utn_calculos.h
 *
 *  Created on: 5 abr. 2021
 *      Author: operador
 */

#ifndef UTN_CALCULOS_H_
#define UTN_CALCULOS_H_

int utn_getSuma (int operador1, int operador2, int*resultado,char*mensaje, char*mensajeError);
int utn_getResta (int operador1, int operador2, int*resultado,char*mensaje, char*mensajeError);
float utn_getDividir (int operador1, int operador2,float* resultado, char*mensaje, char*mensajeError);
int utn_getMultiplicar (int operador1, int operador2, int*resultado, char*mensaje, char*mensajeError);
int utn_getFactorial (int operador, double* resultado , char*mensaje, char*mensajeError);

#endif /* UTN_CALCULOS_H_ */
