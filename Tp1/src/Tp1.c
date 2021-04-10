/*
 ============================================================================
 Name        : TpCalculadora.c
 Author      : Juan Sueldo
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_menu.h"
#include "utn_calculos.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int opcion;
	int operador1 =0;
	int operador2 =0;
	int suma;
	int resta;
	int multiplicacion;
	int division;
	int factorial1;
	int factorial2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorial1;
	int resultadoFactorial2;



	do
	{
		menu = utn_mostrarMenu (&opcion, operador1, operador2,"La opcion no es valida.\n",1,5,5);
		if(menu == 0)
		{
		switch(opcion)
		{
		case 1:
		    printf("\nIngrese el primer operandor:\n");
		    scanf("%d",&operador1);
		    printf("\nPrimer operandor ingresado es: %d\n",operador1);
			break;

		case 2:
			printf("\nIngrese el segundo operandor:\n");
			scanf("%d",&operador2);
			printf("\nSegundo operandor ingresado es: %d\n",operador2);
			break;

		case 3:
			if(operador1 == 0 && operador2 == 0)
			{
				printf("\nDebe ingresar al menos un valor para continuar\n");
			}
			else
			{
				suma = utn_getSuma(operador1, operador2, &resultadoSuma,"A.Se realizo la suma\n","\nLos operadores tienen que ser distintos a cero");

				resta = utn_getResta(operador1, operador2, &resultadoResta,"B.Se realizo la resta\n","\nLos operadores tienen que ser distintos a cero");

				division = utn_getDividir(operador1, operador2, &resultadoDivision,"C.Se realizo la division\n","C.No es posible dividir por cero\n");

				multiplicacion = utn_getMultiplicar(operador1, operador2,&resultadoMultiplicacion,"D.Se realizo la multiplicacion\n","\nLos operadores tienen que ser distintos a cero");

				factorial1 = utn_getFactorial(operador1, &resultadoFactorial1,"E.Se realizo el factoreo de A\n","E.El operador A tiene que ser mayor a cero y menor que 10\n");

				factorial2 = utn_getFactorial(operador2, &resultadoFactorial2,"F.Se realizo el factoreo de B\n","F.El operador B tiene que ser mayor a cero y menor que 10\n");

			}
			break;
		case 4:
			if(operador1 == 0 && operador2 == 0)
			{
			printf("Debe ingresar al menos un valor para continuar\n");
			}
			if(suma != 0 && resta != 0 && division != 0 && multiplicacion != 0 && factorial1 != 0 && factorial2 != 0)
			{
				printf("Antes debe realizar las operaciones.\n");
			}

				if(suma == 0)
				{
					printf("A.El resultado de A+B es: %d\n",resultadoSuma);
				}

				if(resta == 0)
				{
					printf("B.El resultado de A-B es: %d\n",resultadoResta);
				}

				if(division == 0)
				{
					printf("C.El resultado de A/B es: %.2f\n", resultadoDivision);
				}
				else if(division == 1)
				{
					printf("C.No es posible dividir por cero\n");
				}

				if(multiplicacion == 0)
				{
					printf("D.El resultado de A*B es: %d\n",resultadoMultiplicacion);
				}

				if(factorial1 == 0)
				{
					printf("E.El resultado del factorial de A es: %d\n",resultadoFactorial1);
				}
				else if(factorial1 == 1)
				{
					   printf("E.No se puede calcular el factorial de A\n");
				}
				if(factorial2 == 0)
				{
					printf("F.El resultado del factorial de B es: %d\n",resultadoFactorial2);
				}
				else if(factorial2 == 1)
				{
					printf("E.No se puede calcular el factorial de B\n");
				}
			break;
		case 5:
			printf("Fin");
			break;

		}
	}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
