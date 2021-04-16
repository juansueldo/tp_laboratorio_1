
#ifndef UTN_MENU_H_
#define UTN_MENU_H_
/* @brief Muesta el menú y toma la opcion igresada por el usuario
 * @param opcion toma la opcion ingresada por el usuario
 * @param operador1 toma el valor ingresado por el usuario
 * @param operador2 toma el valor ingresado por el usuario
 * @param mensajeError muestra el mensaje en caso de error
 * @param min el valor minimo que admite el menu
 * @param max el valor maximo que admite el menu
 * @param salir valor para salir del menu
 * @return retorno cero en caso de exito
 */
int utn_mostrarMenu (int* opcion, int operador1, int operador2,char*mensajeError, int min, int max, int salir);
/* @brief Muestra mensaje en caso de que el operador sea menor o mayor al mininimo y maximo
 * @param operador toma el valor ingresado por el usuario
 * @param min el valor minimo admitido
 * @param max el valor maximo admitido
 * @param mensaje muestra el mensaje en caso que el valor sea menor al min
 * @param mensaje2 muestra el mensaje en caso que el valor sea mayor al max
 *
 */
void utn_validar (int operador, int min, int max, char*mensaje, char* mensaje2);
#endif /* UTN_MENU_H_ */
