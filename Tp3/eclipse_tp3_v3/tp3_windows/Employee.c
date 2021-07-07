#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* pAuxEmployee;

    pAuxEmployee = (Employee*)malloc(sizeof(Employee));

    return pAuxEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = employee_new();
    void *retorno = NULL;
    if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {

    	if(!employee_setId(this, atoi(idStr)) &&
    	!employee_setNombre(this, nombreStr) &&
    	!employee_setSueldo(this, atoi(sueldoStr)) &&
    	!employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)))
    	{
    		retorno = this;
    	}
    	else
    	{
    		employee_delete(this);
    		retorno = this;
    	}
    }
    return retorno;
}
void employee_delete(Employee *this)
{

    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;

	}
	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        utn_getMayusMin(nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}
int employee_print(Employee* this)
{
    int retorno = -1;
    int id;
    char nombre[EMPLOYEE_NOMBRE_MAX];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL && employee_getId(this, &id)==0
    				&& employee_getNombre(this, nombre)==0
					&& employee_getHorasTrabajadas(this, &horasTrabajadas)==0
					&& employee_getSueldo(this, &sueldo)==0)
    {
    	printf("|*******|**********************|*******|************|\n");
    	printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
    	printf("|*******|**********************|*******|************|\n");
    	utn_getMayusMin(this->nombre);
    	printf("| %5d | %20s | %5d | %10d |\n",
    		            	id, nombre, horasTrabajadas, sueldo);
        printf("|*******|**********************|*******|************|\n");

        retorno = 0;
    }

    return retorno;
}
Employee employee_change (Employee* this, int opcion)
{
	Employee* pAuxEmployee = this;
	char nombre[EMPLOYEE_NOMBRE_MAX];
	int horasTrabajadas;
	int sueldo;
	switch(opcion)
	{
	case 1:
		if(!utn_getStringWithSpaces(nombre, EMPLOYEE_NOMBRE_MAX, "INGRESE EL NUEVO NOMBRE: ", "\nERROR", 1,3)
				&& employee_setNombre(pAuxEmployee,nombre))
		{
			printf("\nEL NOMBRE NO FUE CAMBIADO\n");
		}
		else
		{
			employee_getNombre(pAuxEmployee, nombre);
			printf("\nNOMBRE CAMBIADO\n");
		}
    break;
	case 2:
		if(!utn_getNumero(&horasTrabajadas, "INGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 1, EMPLOYEE_HORA_MAX,3)
				&& employee_setHorasTrabajadas(pAuxEmployee, horasTrabajadas))
		{
			printf("\nLAS HORAS TRABAJADAS NO FUERON CAMBIADAS\n");
		}
		else
		{
			employee_getHorasTrabajadas(pAuxEmployee, &horasTrabajadas);
			printf("\nHORAS TRABAJADAS CAMBIADAS\n");
		}
    break;
	case 3:
		if(!utn_getNumero(&sueldo, "INGRESE EL NUEVO SUELDO: ", "\nERROR", 1, EMPLOYEE_SUELDO_MAX,3)
				&& employee_setSueldo(pAuxEmployee, sueldo))
		{
			printf("\nEL SUELDO NO FUE CAMBIADO\n");
		}
		else
		{
			employee_getSueldo(pAuxEmployee, &sueldo);
			printf("\nSUELDO CAMBIADO\n");
		}
    break;
	}

	return *pAuxEmployee;

}
int employee_compareByID(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    int id1;
    int id2;
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
    	employee_getId(pAuxEmployee1, &id1);
    	employee_getId(pAuxEmployee2, &id2);

        resultado = id1 - id2;

        if(resultado > 0)
        {
            comparar = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparar = -1;
            }
            else
            {
                comparar = 0;
            }
        }
    }

    return comparar;
}

int employee_compareBynombre(void* pThis1, void* pThis2)
{
    int comparar;
    char nombre1[EMPLOYEE_NOMBRE_MAX];
    char nombre2[EMPLOYEE_NOMBRE_MAX];
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
    	employee_getNombre(pAuxEmployee1, nombre1);
    	employee_getNombre(pAuxEmployee2, nombre2);

        comparar = strcmp(nombre1, nombre2);
    }

    return comparar;
}

int employee_compareByhorasTrabajadas(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    int horasTrabajadas1;
    int horasTrabajadas2;
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
    	employee_getHorasTrabajadas(pAuxEmployee1, &horasTrabajadas1);
    	employee_getHorasTrabajadas(pAuxEmployee2, &horasTrabajadas2);

        resultado = horasTrabajadas1 - horasTrabajadas2;

        if(resultado > 0)
        {
            comparar = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparar = -1;
            }
            else
            {
                comparar = 0;
            }
        }
    }

    return comparar;
}

int employee_compareBysueldo(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    int sueldo1;
    int sueldo2;
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
    	employee_getSueldo(pAuxEmployee1, &sueldo1);
    	employee_getSueldo(pAuxEmployee2, &sueldo2);
        resultado = sueldo1 - sueldo2;

        if(resultado > 0)
        {
            comparar = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparar = -1;
            }
            else
            {
                comparar = 0;
            }
        }
    }

    return comparar;
}
