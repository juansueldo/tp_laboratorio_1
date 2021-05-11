#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getSoloString (char cadena[], int tam)
{
    int i;
    int rtn = -1;
    for(i = 0; i < tam; i++)
    {
        while(isalpha(cadena[i]) == 1)
        {
           rtn = 0;
        }
    }
    return rtn;
}
int utn_getChar(char* caracter,char* mensaje,char* errorMensaje,char min,char max,int intentos)
{
	int ret = -1;
	char aux;
	char buffer;
	int i;
	if(caracter != NULL &&  mensaje != NULL && errorMensaje != NULL &&  min <= max && intentos >= 0 )
	{

		printf("\n %s",mensaje);
		fflush(stdin);
		scanf("%c",&buffer);
		for (i = 0; i < intentos; ++i)
		{
			aux = isdigit(buffer);
			if(buffer >= min && buffer <= max && aux == 0)
			{

				*caracter = buffer;
				ret = 0;
				break;
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				scanf("\n %c",&buffer);

			}

		}

	}

	return ret;

}
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
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
		gets(buffer);

		for (i = 0; i < intentos; ++i)
		{
			aux = strlen(buffer);

			if(aux >= min && aux <= tamanio)
			{
				strcpy(array,buffer);
				ret = 0;
				break;
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				gets(buffer);

			}

		}
	}
	return ret;
}
int esNumerica(char* cadena)
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
int esNumericoFlotante(char str[])
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


int getInt(int *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			ret = 0;
		}
	}
	return ret;
}
int getFloat(float *pResultado)
{
	int ret = -1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esNumericoFlotante(buffer))
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
			if(getInt(&bufferInt) == 0)
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
			if(getFloat(&bufferFloat)==0)
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
int unt_gerRespuesta (char* mensaje,char*mensajeError, int reintentos)
{
	int rtn = -1;
	char respuesta;
	while(reintentos > 0)
	{
		reintentos--;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&respuesta);
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
int Validate_OnlyNumberInt(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isdigit(pData[i]) == 0) {
				if (i == 0) {
					if (pData[0] != '-') {
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

int Validate_OnlyNumberFloat(char *pData) {
	int countSigno = 0;
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {

			if (pData[i] == '.' || pData[i] == ',') {
				countSigno++;
			} else {
				if (isdigit(pData[i]) == 0) {
					if (i == 0) {
						if (pData[0] != '-') {
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

int Validate_OnlyAlphabet(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				rtn = 0;
				break;
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabetWithSpaces(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
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
