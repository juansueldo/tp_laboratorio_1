/*
 * utn_calculos.h
 *
 *  Created on: 5 abr. 2021
 *      Author: Juan Sueldo
 */

#ifndef UTN_CALCULOS_H_
#define UTN_CALCULOS_H_

/* @brief Realiza la suma de dos enteros
 * @param operador1 recibe el primer operador ingresado por el usuario
 * @param operador2 recibe el segundo operador ingresado por el usuario
 * @param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * @param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * @param mensajeError mensaje en caso de error
 * @return retorno es igual a cero en caso de exito
 */
int utn_getSuma (int operador1, int operador2, int*pResultado,char*mensaje, char*mensajeError);
/* @brief Realiza la resta de dos enteros
 * @param operador1 recibe el primer operador ingresado por el usuario
 * @param operador2 recibe el segunto operador ingresado por el usuario
 * @param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * @param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * @param mensajeError mensaje en caso de error
 * @return retorno es igual a cero en caso de exito
 */
int utn_getResta (int operador1, int operador2, int*pResultado,char*mensaje, char*mensajeError);
/* @brief Realiza la division entre dos enteros
 * @param operador1 recibe el primer operador ingresado por el usuario
 * @param operador2 recibe el segunto operador ingresado por el usuario
 * @param resultado puntero del resultado, allí se dejara el resultado de la operacion del tipo flotante
 * @param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * @param mensajeError mensaje en caso de error
 * @return retorno es igual a cero en caso de exito
 */
float utn_getDividir (int operador1, int operador2,float* pResultado, char*mensaje, char*mensajeError);
/* @brief Realiza el producto entre dos enteros
 * @param operador1 recibe el primer operador ingresado por el usuario
 * @param operador2 recibe el segunto operador ingresado por el usuario
 * @param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * @param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * @param mensajeError mensaje en caso de error
 * @return retorno es igual a cero en caso de exito
 */
int utn_getMultiplicar (int operador1, int operador2, int*pResultado, char*mensaje, char*mensajeError);
/* @brief Utiliza el operador ingresado por el usuario, muestra el resultado, muestra mensaje de exito y mensaje de error
 * @param operador recibe el primer operador ingresado por el usuario
 * @param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * @param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * @param mensajeError mensaje en caso de error
 * @return retorno es igual a cero en caso de exito
 */
double utn_getFactorial (int operador, double* pResultado , char*mensaje, char*mensajeError);

#endif /* UTN_CALCULOS_H_ */
