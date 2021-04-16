
#include <stdio.h>
#include <stdlib.h>

int utn_getSuma (int operador1, int operador2, int*pResultado,char*mensaje, char*mensajeError)
{
	int retorno = -1;
	int bufferResultado;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(operador1 > 0 || operador2 >0)
		{
			bufferResultado = operador1 + operador2;
			*pResultado = bufferResultado;
			printf("%s",mensaje);
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeError);
		}

	}
	return retorno;

}

int utn_getResta (int operador1, int operador2, int*pResultado,char*mensaje, char*mensajeError)
{
	int retorno = -1;
	int bufferResultado;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(operador1 > 0 || operador2 >0)
		{
			bufferResultado = operador1 - operador2;
			*pResultado = bufferResultado;
			printf("%s",mensaje);
			retorno = 0;
		}
		else
		{
			printf("%s",mensajeError);
		}

	}
	return retorno;

}

float utn_getDividir (int operador1, int operador2,float* pResultado, char*mensaje, char*mensajeError)
{
	int retorno = -1;
	float bufferResultado;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL)
	{
	if(operador2 != 0)
	{
		bufferResultado = (float)operador1 / operador2;
		*pResultado = bufferResultado;
		printf("%s",mensaje);
		retorno = 0;
	}
	else
	{
		printf("%s",mensajeError);
		retorno = 1;
	}
	}
	return retorno;
}

int utn_getMultiplicar (int operador1, int operador2, int*pResultado, char*mensaje, char*mensajeError)
{
	int retorno = -1;
	int bufferResultado;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL)
		{
			if(operador1 > 0 || operador2 >0)
			{
				bufferResultado = operador1 * operador2;
				*pResultado = bufferResultado;
				printf("%s",mensaje);
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
			}

		}
		return retorno;
}

double utn_getFactorial (int operador, double* pResultado , char*mensaje, char*mensajeError)
{
	int retorno = -1;
	int i;
	double bufferResultado = 1;

	if(mensaje != NULL && pResultado != NULL )
	{
		if(operador <= 0 || operador > 170)
		{
			printf("%s",mensajeError);
			retorno = 1;
		}
		else
		{
			for(i = 1; i <= operador; i++)
			{
				bufferResultado = bufferResultado * i;
				*pResultado = bufferResultado;

				retorno = 0;
			}
		}
		if(retorno == 0)
		{
			printf("%s",mensaje);
		}

	}
	return retorno;
}
