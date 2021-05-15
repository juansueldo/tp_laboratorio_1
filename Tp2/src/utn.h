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
//int utn_getChar(char* caracter,char* mensaje,char* errorMensaje,char min,char max,int intentos);
/*
 * @brief solicita un texto al usuario, en caso de error otorga reintentos
 * @param array Array donde se cargara el texto ingresado
 * @param max cantidad maxima de caracteres que puede tener la cadena
 * @param mensaje Es el mesaje a ser mostrado
 * @param mensaje Es el mesaje a ser mostrado en caso de error
 * @param min cantidad minima de caracteres que puede tener la cadena
 * @para intentos cantidad de reintentos en caso de error
 * @return retorna cero en caso de que el texto sea valido
 */
int utn_getString(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos);
int utn_getIsInt(char* cadena);
int myGets(char* cadena,int longitud);
int utn_getEntero(int *pResultado);
int utn_getIsFloat(char str[]);
int utn_getNumFloat(float *pResultado);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
/*
 * @brief Pide al usuario el ingreso de un numero, y analiza si el numero esta dentro del rango
 * @param pOpcion Numero ingresado por el usuario
 * @param mensaje Es el mesaje a ser mostrado
 * @param mensaje Es el mesaje a ser mostrado en caso de error
 * @param min Valor minimo admitido
 * @param max Valor maximo admitido
 * @return Retorna cero en caso de que el valor este dentro del rango
 */
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max);
/*
 * @brief imprime mensaje en pantalla solicitando una respuesta al usuario
 * @param mensaje Es el mesaje a ser mostrado
 * @param mensaje Es el mesaje a ser mostrado en caso de error
 * @param reintetos
 * @return retorna cero en caso de que la respuesta sea 's' y -1 si la respuesta es 'n'
 */
int utn_getRespuesta (char* mensaje,char*mensajeError, int reintentos);
/*
 * @brief Comprueba si el dato ingresado y lo valida si es un caracter o espacio
 * @param pString puntero que toma el dato ingresado
 * @retorno retorna cero en caso de que el dato sea un caracter o espacio
 */
int utn_getTexto (char *pString);
/*
 * @brief recibe una cadena y convierte todos sus carateres en minuscular y el primer caracter en mayuscula
 * @param name recibe la cadena
 * @param tam cantidad de caracteres de la cadena
 * @return retorna cero
 */
int utn_getMayusMin (char name[], int tam);
/*
 * @brief Recibe un caracter y lo convierte en minuscula
 * @param letra Caracter que se convertira en minuscula
 * @return Retorna cero cuando se convierte el caracter
 */
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
