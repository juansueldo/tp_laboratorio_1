#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int utn_getTexto (char *pString)
{
	int retorno = -1;

	if (strlen(pString) > 0)
	{
		for (int i = 0; i < strlen(pString); i++)
		{
			if (isalpha(pString[i]) == 0)
			{
				if (isspace(pString[i]) == 0)
				{
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

int utn_getString(char array[],int max,char mensaje[],char errorMensaje[],char min,int intentos)
{
	int retorno = -1;
	int aux;
	char bufferString[max];
	if(array != NULL && max > 0 &&  mensaje != NULL && errorMensaje != NULL &&  min <= max && intentos >= 0 )
	{
		while(intentos > 0)
		{
			intentos--;
			printf("\n%s",mensaje);
			fflush(stdin);
			scanf("%s",bufferString);

			if(utn_getTexto (bufferString) != 0)
			{
				aux = strlen(bufferString);

			if(aux >= min && aux <= max)
			{
				strcpy(array,bufferString);
				retorno = 0;
				break;
			}
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				//scanf("%s",bufferString);
				//break;
			}
		}
	}
	return retorno;
}

int myGets ( char * pCadena, int longitud)
{
	int retorno=-1;
	if (pCadena != NULL && longitud >0 && fgets (pCadena,longitud,stdin)==pCadena)
	{
		fflush (stdin);
		if (pCadena[ strlen (pCadena)-1] == '\n' )
		{
			pCadena[ strlen (pCadena)-1] = '\0' ;
		}
		retorno=0;
	}
	return retorno;
}

int esNumerica(char* pNum)
{
	int i = 0;
	int retorno = 0;
	if(pNum != NULL && strlen(pNum) > 0)
	{
		while(pNum[i] != '\0')
		{
			if(pNum[i] < '0' || pNum[i] > '9')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int getInt ( int * pNum)
{
	int retorno=-1;
	char buffer[64];
	if (pNum != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer)==0)
		{
			*pNum = atoi (buffer);
			 retorno = 0;
		}
	}
	return retorno;
}

int utn_getNumero(int* pNum,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int retorno = -1;
	if(pNum != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			fflush(stdin);
			if(getInt(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pNum = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}
int esFloat (char* pNum)
{
   int i=0;
   int retorno = -1;
   int cantidadPuntos=0;
   while(pNum[i] != '\0')
   {
       if (pNum[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(pNum[i] < '0' || pNum[i] > '9')
    	   retorno = 0;
       i++;
   }
   return retorno;
}

int getNumFloat (float * pFloat)
{
	int retorno = -1;
	char buffer[64];
	if(pFloat != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esFloat(buffer))
		{
			*pFloat = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
int utn_getFloat(float* pFloat,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	if(pFloat != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("\n %s",mensaje);
			fflush(stdin);
			if(getNumFloat(&bufferFloat)==0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pFloat = bufferFloat;
					retorno = 0;
					break;
				}
			}
			printf("\n %s",mensajeError);
		}
	}

	return retorno;

}
int utn_menu(int *pOpcion, char *mensaje, char *mensajeError, int min, int max, int reintentos)
{

	int retorno = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			fflush(stdin);
			if(getInt(&bufferMenu) == 0)
			{
				if(bufferMenu >= min && bufferMenu <= max)
				{
					*pOpcion = bufferMenu;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
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
	int retorno = -1;
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
			break;

		}
		if(respuesta == 's')
		{
			retorno = 0;
			break;
		}
		else if(respuesta == 'n')
		{
			retorno = 1;
			break;
		}
	}
	return retorno;
}
int utn_getMayusMin (char* name)
{
	int retorno = -1;
	while( *name != '\0' )
     {
       while( !isalpha(*name) && (*name != '\0') )
         name++;

       if( isalpha(*name) )
       {
         if( *name >= 'a' )
           *name = toupper(*name);
         name++;
       }

       while( isalpha(*name) )
       {
         *name = tolower(*name);
         name++;
       }
       retorno = 0;
     }


   return retorno;
}
int validarNombre(char* cadena,int longitud)
{
	int i;
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			//if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i] == ' ')
			//{
				retorno = 0;
				break;
			//}
		}
	}
	return retorno;
}
int validarEntero(int num)
{
    int aux=0;
    int retorno = -1;
    while(aux==0){
        if( isdigit(num)==0)
        {
        	retorno = 0;
        	aux++;
            break;
        }

    }
    return retorno;
}
int validarFlotante(float num)
{
    int aux=0;
    int retorno = -1;
    while(aux==0){
        if( isdigit(num)==0)
        {
        	retorno = 0;
        	aux++;
            break;
        }

    }
    return retorno;
}
int validarTexto(char *cadena) {
	int retorno = 1;

	if (strlen(cadena) > 0)
	{
		for (int i = 0; i < strlen(cadena); i++)
		{
			if (isalpha(cadena[i]) == 0)
			{
				if (isspace(cadena[i]) == 0)
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}
int utn_getStringWithSpaces(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos)
{
	int retorno = -1;
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
			if(validarTexto (buffer) != 0)
			{
			aux = strlen(buffer);

			if(aux >= min && aux <= tamanio)
			{
				strcpy(array,buffer);
				retorno = 0;
				break;
			}
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				gets(buffer);

			}

		}
	}
	return retorno;
}
