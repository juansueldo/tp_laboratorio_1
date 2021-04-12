#include <stdio.h>
#include <stdlib.h>
/*brief Toma la opcion ingresada por el usuario, valida la opcion elegida, pide el ingreso de los operadores por parte del usuario y muestra mensaje en caso de error
 * param opcion toma la opcion ingresada por el usuario
 * param operador1 toma el valor ingresado por el usuario
 * param operador2 toma el valor ingresado por el usuario
 * param mensajeError puntero que muestra el mensaje en caso de error
 * param min el valor minimo que admite el menu
 * param max el valor maximo que admite el menu
 * param salir valor para salir del menu
 */
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

