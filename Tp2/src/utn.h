
#ifndef UTN_H_
#define UTN_H_

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
int unt_getRespuesta (char* mensaje,char*mensajeError, int reintentos);
int utn_getTexto (char *pData);
int utn_getMayusMin (char name[], int tam);
int utn_getTextoEspacios (char *pData);
int utn_getMinuscula (char letra);

#endif /* UTN_H_ */
