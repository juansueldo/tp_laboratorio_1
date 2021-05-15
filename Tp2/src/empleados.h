#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
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

/*
 * @brief recibe una estructura y la inicializa
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int initEmployees (eEmployee arrayEmpleados[],int tamanio);
/*
 * @brief recibe una estructura y la inicializa
 * @param arraySector estructura que incluye los sectores
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int initSector (eSector arraySector[],int tamanio);
/*
 * @brief recorre la estrucutra en busca de un campo libre
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que el campo esta vacio
 */
int findEmpty (eEmployee arrayEmpleados[],int tamanio);
/*
 * @brief recorre la estrucutra, busca que el id ingresado coincida con el que se busca
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @para id que se ingresa para comprar
 * @return retorna cero en caso de coincidencia
 */
int findEmployeeById(eEmployee arrayEmpleados[],int tamanio,int id);
/*
 * @brief pide al usuario los datos y los carga en el auxiliar
 * @return auxiliar donde se cargaron los datos ingresados por el usuario
 */
eEmployee addEmployee (void);
/*
 * @brief carga en la estructura arrayEmpleados los datos ingresados por el usuario
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que se cargaran todos los datos
 */
int addEmployees (eEmployee arrayEmpleados[], int tamanio, int *pIdEmpleado);
/*
 * @brief pide al usuario los datos y los carga en el auxiliar
 * @return auxiliar donde se cargaron los datos ingresados por el usuario
 */
eEmployee changeEmployee(eEmployee arrayEmpleados, int campoModificar);
/*
 * @brief modifica la estructura arrayEmpleados, con los nuevos datos ingresados por el usuario
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que se modificaran los datos
 */
int changeEmployees (eEmployee arrayEmpleados[], int tamanio, eSector arraySector[], int cant);
/*
 * @brief vincula el nombre del sector con el idSector
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @param arraySector estructura que incluye los sectores
 * @param cant cantidad de elementos
 * @return retorna cero  cuando el id conicide con el detalle del sector
 */
int getNombreSector (eSector arraySector[],int cant,int sector,char detalleSector[20]);
/*
 * @brief muestra un empleado
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @param arraySector estructura que incluye los sectores
 * @param cant cantidad de elementos
 */
void printEmployee (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[],int cant);
/*
 * @brief muestra todos los empleados ingresados por el usuario
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @param arraySector estructura que incluye los sectores
 * @param cant cantidad de elementos
 * @return retorna cero en caso de que hayan empleados a mostrar
 */
int printEmployees (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[], int cant);
/*
 * @brief da de baja el empleado solicitado por el usuario
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @param arraySector estructura que incluye los sectores
 * @param cant cantidad de elementos
 * @return retorna cero en caso de que haya dado de baja un empleado
 */
int removeEmployee(eEmployee arrayEmpleados[], int tamanio, eSector arraySector[], int cant);
/*
 * @brief de acuerdo al criterio elegido, ordena los empleados ingresados por orden alfabetico de apellido y por sector en caso de coincidencia
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @param criterio criterio elegido por el usuario para ordenar
 * @return retorna cero en caso de que el ordenamiento sea exitoso
 */
int sortEmployees (eEmployee empleados[], int tamanio, int criterio);
/*
 * @brief obtiene el promedio de los sueldos ingresados por usuario, imprime en pantalla el total de los sueldos y el promedio
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @param promedio puntero que guarda el resultado de la operacion
 * @return retorna cero en caso de que realizarse el promedio
 */
void getpromedio (eEmployee empleados[], int tamanio, float* promedio);
/*
 * @brief muestra todos los empleados ingresados por el usuario que superen el sueldo promedio
 * @param arrayEmpleados estructura que incluye los campos empleados
 * @param tamanio cantidad de elementos
 * @param arraySector estructura que incluye los sectores
 * @param cant cantidad de elementos
 * @return retorna cero en caso de que hayan empleados a mostrar que superen el sueldo promedio
 */
int printEmployeesProm (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[], int cant);

#endif /* EMPLEADOS_H_ */
