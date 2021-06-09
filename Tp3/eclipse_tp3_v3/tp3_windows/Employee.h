#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

#define EMPLOYEE_NOMBRE_MAX 60
#define EMPLOYEE_HORA_MAX 500
#define EMPLOYEE_SUELDO_MAX 900000
#define EMPLOYEE_MAX 2000
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
Employee* employee_newParametrosInt(int* id,char* nombre,int* horasTrabajadas, int* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_getNextId(LinkedList* pArrayListEmployee);
Employee addEmployee (void);
int employee_print(Employee* this);
int getIndexByEmployeeID(LinkedList* pArrayListEmployee, int id);
Employee employee_change (Employee* this, int opcion);
int employee_compareByID(void* pElement1, void* pElement2);
int employee_compareBynombre(void* pElement1, void* pElement2);
int employee_compareByhorasTrabajadas(void* pElement1, void* pElement2);
int employee_compareBysueldo(void* pElement1, void* pElement2);

#endif // employee_H_INCLUDED
