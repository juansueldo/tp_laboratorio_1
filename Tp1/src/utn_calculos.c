/*
 * utn_calculos.c
 *
 *  Created on: 5 abr. 2021
 *      Author: operador
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * brief Utiliza los dos operadores ingresados por el usuario, muestra el resultado, muestra mensaje de exito y mensaje de error
 * param operador1 recibe el primer operador ingresado por el usuario
 * param operador2 recibe el segunto operador ingresado por el usuario
 * param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * param mensajeError mensaje en caso de error
 */

int utn_getSuma (int operador1, int operador2, int*pResultado,char*mensaje, char*mensajeError)
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
/*
 * brief Utiliza los dos operadores ingresados por el usuario, muestra el resultado, muestra mensaje de exito y mensaje de error
 * param operador1 recibe el primer operador ingresado por el usuario
 * param operador2 recibe el segunto operador ingresado por el usuario
 * param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * param mensajeError mensaje en caso de error
 */
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
/*
 * brief Utiliza los dos operadores ingresados por el usuario, muestra el resultado, muestra mensaje de exito y mensaje de error
 * param operador1 recibe el primer operador ingresado por el usuario
 * param operador2 recibe el segunto operador ingresado por el usuario
 * param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * param mensajeError mensaje en caso de error
 */
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
/*
 * brief Utiliza los dos operadores ingresados por el usuario, muestra el resultado, muestra mensaje de exito y mensaje de error
 * param operador1 recibe el primer operador ingresado por el usuario
 * param operador2 recibe el segunto operador ingresado por el usuario
 * param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * param mensajeError mensaje en caso de error
 */
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
/*
 * brief Utiliza el operador ingresado por el usuario, muestra el resultado, muestra mensaje de exito y mensaje de error
 * param operador recibe el primer operador ingresado por el usuario
 * param resultado puntero del resultado, allí se dejara el resultado de la operacion
 * param mensaje mensaje a mostrar en caso de que se pudo realizar la operacion
 * param mensajeError mensaje en caso de error
 */
int utn_getFactorial (int operador, double* pResultado , char*mensaje, char*mensajeError)
{
	int retorno = -1;
	double bufferResultado = 1;

	if(mensaje != NULL && pResultado != NULL )
	{
		if(operador <= 0 || operador > 20)
		{
			printf("%s",mensajeError);
			retorno = 1;
		}
		else
		{
			while(operador > 1)
			{
				bufferResultado *= operador;
				operador --;
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
