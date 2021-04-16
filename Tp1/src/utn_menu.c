#include <stdio.h>
#include <stdlib.h>

int utn_mostrarMenu (int* opcion, int operador1, int operador2,char*mensajeError, int min, int max, int salir)
{
	int retorno = -1;
	int bufferMenu;

	if(opcion != NULL)
	{
		printf("\nMenu:\n1.Ingresar 1er operando (A= %d)\n2.Ingresar 2do operando (B= %d)\n3.Calcular las operaciones\n4.Mostrar los resultados\n5.Salir\n" ,operador1,operador2);
		scanf("%d",&bufferMenu);
		fflush(stdin);
		if(bufferMenu >= min && bufferMenu <= max)
		{
		*opcion = bufferMenu;
		retorno = 0;
		}
		else
		{
			printf("%s",mensajeError);
		}
	}

	return retorno;
}
void utn_validar (int operador, int min, int max, char*mensaje, char* mensaje2)
{
	if(operador < min)
	{
		printf("%s",mensaje);
	}
	else if(operador > max)
	{
		printf("%s",mensaje2);
	}
}

