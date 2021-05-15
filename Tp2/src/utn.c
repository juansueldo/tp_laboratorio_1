#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* isdigit
 * utn_getString
 * utn_getFloat
 * utn_getNumero
 * utn_getMayusMin
 * utn_getRespuesta
 *
*/

/*
 * @brief Comprueba si el dato ingresado y lo valida si es un caracter o espacio
 * @param pDato puntero que toma el dato ingresado
 * @retorno retorna cero en caso de que el dato sea un caracter o espacio
 */
int utn_getTexto (char *pDato)
{
	int rtn = -1;

		if (strlen(pDato) > 0)
		{
			for (int i = 0; i < strlen(pDato); i++)
			{
				if (isalpha(pDato[i]) == 0)
				{
					if (isspace(pDato[i]) == 0)
					{
						rtn = 0;
						break;
					}
				}
			}
		}

	return rtn;
}
int utn_getString(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos)
{
	int ret = -1;
	int aux;
	char buffer[tamanio];
	int i;
	if(array != NULL && tamanio > 0 &&  mensaje != NULL && errorMensaje != NULL &&  min <= tamanio && intentos >= 0 )
	{
		printf("\n%s",mensaje);
		fflush(stdin);
		scanf("%s",buffer);

		for (i = 0; i < intentos; ++i)
		{
			if(utn_getTexto (buffer) != 0)
			{
			aux = strlen(buffer);

			if(aux >= min && aux <= tamanio)
			{
				strcpy(array,buffer);
				ret = 0;
				break;
			}
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				scanf("%s",buffer);

			}

		}
	}
	return ret;
}
int utn_getIsInt(char* cadena)
{
	int i=0;
	int ret = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				ret = 0;
				break;
			}
			i++;
		}
	}
	return ret;
}
int utn_getIsFloat(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int myGets(char* cadena,int longitud)
{
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin) == cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}


int utn_getEntero(int *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && utn_getIsInt(buffer))
		{
			*pResultado = atoi(buffer);
			ret = 0;
		}
	}
	return ret;
}
int utn_getNumFloat(float *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && utn_getIsFloat(buffer))
		{
			*pResultado = atof(buffer);
			ret = 0;
		}
	}
	return ret;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int ret = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("\n %s",mensaje);
			fflush(stdin);
			if(utn_getEntero(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					ret = 0;
					break;
				}
			}
			printf("\n %s",mensajeError);
		}
	}


	return ret;

}
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int ret = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("\n %s",mensaje);
			fflush(stdin);
			if(utn_getNumFloat(&bufferFloat)==0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					ret = 0;
					break;
				}
			}
			printf("\n %s",mensajeError);
		}
	}


	return ret;

}
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir)
{

	int retorno = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max && salir != 0) {
		printf("%s", mensaje);
		scanf("%d", &bufferMenu);

		if (bufferMenu >= min && bufferMenu <= max) {
			*opcion = bufferMenu;
			retorno = 0;
		} else {
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
int utn_getLower(char* letra)
{
	strlwr(letra);
	return 0;
}
int utn_getRespuesta (char* mensaje,char*mensajeError, int reintentos)
{
	int rtn = -1;
	char respuesta;
	while(reintentos > 0)
	{
		reintentos--;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&respuesta);
		utn_getLower (&respuesta);
		while(respuesta != 's' && respuesta != 'n')
		{
			printf("%s",mensajeError);
		}
		if(respuesta == 's')
		{
			rtn = 0;
			break;
		}
		else if(respuesta == 'n')
		{
			rtn = -1;
			break;
		}
	}
	return rtn;
}
int utn_getMayusMin (char name[], int tam)
{
   strlwr(name);

   name[0] = toupper(name[0]);


   return 0;
}

//*** VALIDACIONES - INICIO
int Validate_OnlyNumberInt(char *pDato) {
	int rtn = 1;

	if (strlen(pDato) > 0) {
		for (int i = 0; i < strlen(pDato); i++) {
			if (isdigit(pDato[i]) == 0) {
				if (i == 0) {
					if (pDato[0] != '-') {
						rtn = 0;
						break;
					}
				} else {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyNumberFloat(char *pDato) {
	int countSigno = 0;
	int rtn = 1;

	if (strlen(pDato) > 0) {
		for (int i = 0; i < strlen(pDato); i++) {

			if (pDato[i] == '.' || pDato[i] == ',') {
				countSigno++;
			} else {
				if (isdigit(pDato[i]) == 0) {
					if (i == 0) {
						if (pDato[0] != '-') {
							rtn = 0;
							break;
						}
					} else {
						rtn = 0;
						break;
					}
				}
			}
		}

		if (countSigno > 1) {
			rtn = 0;
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabet(char *pDato) {
	int rtn = 1;

	if (strlen(pDato) > 0) {
		for (int i = 0; i < strlen(pDato); i++) {
			if (isalpha(pDato[i]) == 0) {
				rtn = 0;
				break;
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}


