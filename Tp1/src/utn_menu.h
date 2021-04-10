
#ifndef UTN_MENU_H_
#define UTN_MENU_H_
/*brief Toma la opcion ingresada por el usuario, valida la opcion elegida, pide el ingreso de los operadores por parte del usuario y muestra mensaje en caso de error
 * param opcion toma la opcion ingresada por el usuario
 * param operador1 toma el valor ingresado por el usuario
 * param operador2 toma el valor ingresado por el usuario
 * param mensajeError muestra el mensaje en caso de error
 * param min el valor minimo que admite el menu
 * param max el valor maximo que admite el menu
 * param salir valor para salir del menu
 */
int utn_mostrarMenu (int* opcion, int operador1, int operador2,char*mensajeError, int min, int max, int salir);

#endif /* UTN_MENU_H_ */
