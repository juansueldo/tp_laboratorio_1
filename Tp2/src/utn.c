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
int utn_getTexto (char *pString)
{
	int rtn = -1;

	if (strlen(pString) > 0)
	{
		for (int i = 0; i < strlen(pString); i++)
		{
			if (isalpha(pString[i]) == 0)
			{
				if (isspace(pString[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}

	return rtn;
}

int utn_getString(char array[],int max,char mensaje[],char errorMensaje[],char min,int intentos)
{
	int rtn = -1;
	int aux;
	char bufferString[max];
	int i;
	if(array != NULL && max > 0 &&  mensaje != NULL && errorMensaje != NULL &&  min <= max && intentos >= 0 )
	{
		printf("\n%s",mensaje);
		fflush(stdin);
		scanf("%s",bufferString);

		for (i = 0; i < intentos; ++i)
		{
			if(utn_getTexto (bufferString) != 0)
			{
			aux = strlen(bufferString);

			if(aux >= min && aux <= max)
			{
				strcpy(array,bufferString);
				rtn = 0;
				break;
			}
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				scanf("%s",bufferString);

			}

		}
	}
	return rtn;
}

int utn_getNumero(char num[])
{
	int i;
	int rtn = -1;
    for (i = 0; i < strlen(num); i++)
    {
        if(!isdigit(num[i]) )
        {

            break;
        }
        else
        {
        	rtn = i;
        }
    }
    return rtn;
}

int utn_getInt(char* num)
{
	int i = 0;
	int rtn = -1;
	if(num != NULL && strlen(num) > 0)
	{
		while(num[i] != '\0')
		{
			if(num[i] < '0' || num[i] > '9')
			{
				rtn = 0;
				break;
			}
			i++;
		}
	}
	return rtn;
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
		if(myGets(buffer,sizeof(buffer)) == 0 && utn_getIsInt(buffer)!=0)
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
int utn_menu(int *pOpcion, char *mensaje, char *mensajeError, int min, int max)
{

	int rtn = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max)
	{
		printf("%s", mensaje);
		scanf("%d", &bufferMenu);

		if (bufferMenu >= min && bufferMenu <= max)
		{
			*pOpcion = bufferMenu;
			rtn = 0;
		}
		else
		{
			printf("%s", mensajeError);
		}
	}
	return rtn;
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




