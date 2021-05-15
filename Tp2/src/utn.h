
#ifndef UTN_H_
#define UTN_H_
/* @brief Pide el numero al caracter y valida que este
 * @param auxiliarNum toma el dato ingresado por el usuario
 * @param i la cantidad de elementos que caben en auxiliarNum
 * @param operador variable en la cual se guardara el dato ingresado en caso de ser un numero
 * @param mensaje que solicita el ingreso de un dato
 * @param mensajeError en caso de reintento vuelve a pedir el dao
 * @return retorna el valor del operador entero
 */
int utn_getChar(char* caracter,char* mensaje,char* errorMensaje,char min,char max,int intentos);
int utn_getString(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos);
int utn_getIsInt(char* cadena);
int myGets(char* cadena,int longitud);
int utn_getEntero(int *pResultado);
int utn_getNumFloat(float *pResultado);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir);
int utn_getIsFloat(char str[]);
int utn_getRespuesta (char* mensaje,char*mensajeError, int reintentos);
int utn_getTexto (char *pData);
int utn_getMayusMin (char name[], int tam);
int utn_getTextoEspacios (char *pData);
int utn_getLower(char* letra);

/* isdigit
 * utn_getString
 * utn_getFloat
 * utn_getNumero
 * utn_getMayusMin
 * utn_getRespuesta
 *
*/
#endif /* UTN_H_ */
