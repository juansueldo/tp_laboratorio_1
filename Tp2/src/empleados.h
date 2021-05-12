#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define CANT 4
#define TEXTO 51

typedef struct
{
	int id;
	char name[TEXTO];
	char lastName[TEXTO];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;

typedef struct
{
	int sector;
	char detalleSector[TEXTO];
	int isEmpty;
}eSector;

int initEmployees (eEmployee arrayEmpleados[],int tamanio);
int initSector (eSector arraySector[],int tamanio);

int buscarLibre(eEmployee arrayEmpleados[],int tamanio);
int buscarId(eEmployee arrayEmpleados[],int tamanio,int id);

eEmployee cargarEmpleados (void);
int altaEmpleados (eEmployee arrayEmpleados[], int tamanio);

eEmployee modificarUno(eEmployee arrayEmpleados, int campoModificar);
int modificarEmpleados (eEmployee arrayEmpleados[], int tamanio, eSector arraySector[], int cant);

int getNombreSector (eSector arraySector[],int cant,int sector,char detalleSector[20]);

void mostrarEmpleado (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[],int cant);
int mostrarEmpleados (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[], int cant);

int empleadoBaja(eEmployee arrayEmpleados[], int tamanio, eSector arraySector[], int cant);

int utn_ordenarApellido (eEmployee empleados[], int tamanio);
void get_promedio (eEmployee empleados[], int tamanio, float* promedio);
int mostrarEmpleadosProm (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[], int cant);
#endif /* EMPLEADOS_H_ */
