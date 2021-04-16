/*
 ============================================================================
 Name:         Tp1Calculadora.c
 Alumno:       Juan Sueldo
 Division:     1 E
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

#define MAX 10
int main(void) {
	system("cls") ;
	setbuf(stdout, NULL);
	int menu;
	int opcion;
	char auxiliarOperador1[MAX];
	char auxiliarOperador2[MAX];
	int operador1 =0;
	int operador2 = 0;
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
	double resultadoFactorial1;
	double resultadoFactorial2;

	do
	{
		menu = utn_mostrarMenu (&opcion, operador1, operador2,"\nERROR. La opcion no es valida.\n",1,5,5);
		if(menu == 0)
		{
		switch(opcion)
		{
		case 1:
			operador1 = utn_validarNumero (auxiliarOperador1,MAX,operador1,"\nIngrese el primer operador(Debe ser un numero entero):\n","\nIngrese el primer operador(Debe ser un numero entero):\n");
		    utn_validar (operador1, 1, 170, "\nEl numero debe ser mayor a 1 para calcular el factorial","\nEl numero debe ser menor o igual a 170 para calcular el factorial\n");

			break;

		case 2:
			operador2 = utn_validarNumero (auxiliarOperador2,MAX,operador2,"\nIngrese el segundo operador(Debe ser un numero entero):\n","\nERROR. Ingrese el segundo operador(Debe ser un numero entero):\n");
			utn_validar (operador2, 1, 170, "\nEl numero debe ser mayor a 1 para calcular el factorial","\nEl numero debe ser menor o igual a 170 para calcular el factorial\n");

			break;

		case 3:
			if(operador1 == 0 && operador2 == 0)
			{
				printf("\nDebe ingresar al menos un valor para continuar\n");
			}
			else
			{
				suma = utn_getSuma(operador1, operador2, &resultadoSuma,"\nA.Se realizo la suma\n","\nA.Los operadores tienen que ser distintos a cero");

				resta = utn_getResta(operador1, operador2, &resultadoResta,"B.Se realizo la resta\n","\nB.Los operadores tienen que ser distintos a cero");

				division = utn_getDividir(operador1, operador2, &resultadoDivision,"C.Se realizo la division\n","C.No es posible dividir por cero\n");

				multiplicacion = utn_getMultiplicar(operador1, operador2,&resultadoMultiplicacion,"D.Se realizo la multiplicacion\n","\nD.Los operadores tienen que ser distintos a cero");

				factorial1 = utn_getFactorial(operador1, &resultadoFactorial1,"E.Se realizo el factoreo de A\n","E.El operador A tiene que ser mayor a cero, o menor o igual que 170 para realizar el factorial\n");

				factorial2 = utn_getFactorial(operador2, &resultadoFactorial2,"F.Se realizo el factoreo de B\n","F.El operador B tiene que ser mayor a cero, o menor o igual que 170 para realizar el factorial\n");

			}
			break;
		case 4:
			if(operador1 == 0 && operador2 == 0)
			{
			printf("\nDebe ingresar al menos un valor para continuar\n");
			}
			if((operador1 != 0 || operador2 != 0) && suma != 0 && resta != 0 && division != 0 && multiplicacion != 0 && factorial1 != 0 && factorial2 != 0)
			{
				printf("\nAntes debe realizar las operaciones.\n");
			}

				if(suma == 0)
				{
					printf("\nA.El resultado de A+B es: %d\n",resultadoSuma);
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
					printf("E.El resultado del factorial de A es: %.0f\n",resultadoFactorial1);
				}
				else if(factorial1 == 1)
				{
					   printf("E.No se puede calcular el factorial de A\n");
				}
				if(factorial2 == 0)
				{
					printf("F.El resultado del factorial de B es: %.0f\n",resultadoFactorial2);
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
