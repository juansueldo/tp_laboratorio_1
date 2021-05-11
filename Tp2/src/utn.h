
#ifndef UTN_H_
#define UTN_H_

int utn_getChar(char* caracter,char* mensaje,char* errorMensaje,char min,char max,int intentos);
int utn_getString(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos);
int esNumerica(char* cadena);
int myGets(char* cadena,int longitud);
int getInt(int *pResultado);
int getFloat(float *pResultado);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir);
int esNumericoFlotante(char str[]);
int unt_gerRespuesta (char* mensaje,char*mensajeError, int reintentos);
int esSoloLetras(char str[]);
int utn_getSoloString (char cadena[], int tam);
int utn_getMayusMin (char name[], int tam);


#endif /* UTN_H_ */
