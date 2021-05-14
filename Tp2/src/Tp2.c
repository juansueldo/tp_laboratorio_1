/*
 ============================================================================
 Name        : Tp2.c
 Author      : Juan Sueldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "utn.h"


int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int contador = 999;
	int flagAlta = 0;
	int opcion2;
	int criterioOrdenamiento;


	eEmployee empleados[MAX];
	eSector sector[CANT];

	initEmployees (empleados, MAX);
	initSector (sector, CANT);

	strcpy(sector[0].detalleSector,"RRHH");
	sector[0].sector = 1;
	sector[0].isEmpty = 1;

	strcpy(sector[1].detalleSector,"Programador");
	sector[1].sector = 2;
	sector[1].isEmpty = 1;

	strcpy(sector[2].detalleSector,"Disenio");
	sector[2].sector = 3;
	sector[2].isEmpty = 1;

	strcpy(sector[3].detalleSector,"Otros");
	sector[3].sector = 4;
	sector[3].isEmpty = 1;


	do
	{
		printf("\n*****************************************************************\n");
		utn_menu(&opcion, "1. Alta \n2. Modificar \n3. Baja \n4. Listar \n5. Salir \n*****************************************************************\nIngrese:", "\nNO ES VALIDO\n", 1, 5,5);
		switch(opcion)
		{
		case 1:
			if(addEmployees (empleados, MAX,&contador))
			{
				flagAlta = 1;
				printf("\nALTA EXITOSA\n");
			}
			else
			{
				printf("\nNO SE DIO DE ALTA");
			}
			system("pause");
			break;
		case 2:
			if(flagAlta != 0)
			{
				if(modificarEmpleados(empleados, MAX, sector, CANT) ==0)
				{
					printf("\nSE MODIFICO UN EMPLEADO\n");
				}
				else
				{
					printf("\nNO SE REALIZARON CAMBIOS");
				}
			}
			else
			{
				printf("\nNO SE DIO NINGUNA ALTA\n");
			}
			system("pause");
			break;
		case 3:
			if(flagAlta != 0)
			{
				if(removeEmployee(empleados, MAX, sector, CANT)==0)
				{
					printf("\nSE DIO LA BAJA DE UN EMPLEADO\n");
				}
				else
				{
					printf("\nNO SE DIO DE BAJA\n");
				}
			}
			else
			{
				printf("\nNO SE DIO NINGUNA ALTA\n");
			}
			system("pause");
			break;
		case 4:
			if(flagAlta != 0)
			{
			do
			{
				printf("\n*****************************************************************\n");
				utn_menu(&opcion2, "\n1. Listar por orden alfabetico y sector \n2. Promedio de sueldos y listado de quienes superan el promedio \n3. Volver \n*****************************************************************\n \nIngrese:", "\nNO ES VALIDO\n", 1, 3,3);
				switch(opcion2)
				{
				case 1:
					printf("\nIngrese el criterio de ordenamiento [1] Ascendente [2] Descendente: ");
					fflush(stdin);
					scanf("%d",&criterioOrdenamiento);
					if(sortEmployees (empleados, MAX, criterioOrdenamiento )==0)
					{
						mostrarEmpleados (empleados, MAX, sector, CANT);
					}
					system("pause");
					break;
				case 2:
					if(mostrarEmpleadosProm (empleados, MAX, sector, CANT)==0)
					{

					}
					system("pause");
					break;
				}
			}while(opcion2 != 3);
			}
			else
			{
				printf("\nNO SE DIO NINGUNA ALTA\n");
			}
			system("pause");
			break;
		case 5:
			printf("\nFin.");
			break;
		default:
			("\nERROR. REINGRESE UNA OPCION VALIDA");
			break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}

