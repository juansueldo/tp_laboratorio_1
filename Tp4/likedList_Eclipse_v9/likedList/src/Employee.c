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
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* this = employee_new();
    void *retorno = NULL;
    if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
    	id = atoi(idStr);
    	horasTrabajadas = atoi(horasTrabajadasStr);
    	sueldo = atoi(sueldoStr);

    	if(!employee_setId(this, id) &&
    	!employee_setNombre(this, nombreStr) &&
    	!employee_setSueldo(this, sueldo) &&
    	!employee_setHorasTrabajadas(this, horasTrabajadas))
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
Employee* employee_newParametrosInt(int id, char* nombre,int horasTrabajadas, int sueldo)
{
    void *retorno = NULL;
    Employee* this = employee_new();
    if( this!=NULL && id > 0 && nombre != NULL && horasTrabajadas > 0 && sueldo > 0)
    {
        if( !employee_setId(this, id) &&
            !employee_setNombre(this,nombre) &&
            !employee_setHorasTrabajadas(this,horasTrabajadas) &&
            !employee_setSueldo(this,sueldo))
        {
            retorno = this;
        }
        else
        {
            employee_delete(this);
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
    	utn_getMayusMin(this->nombre,EMPLOYEE_NOMBRE_MAX);
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
		if(!utn_getString(nombre, EMPLOYEE_NOMBRE_MAX, "INGRESE EL NUEVO NOMBRE: ", "\nERROR", 1,3)
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
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
        resultado = pAuxEmployee1->id - pAuxEmployee2->id;

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
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
    	utn_getMayusMin(pAuxEmployee1->nombre, EMPLOYEE_NOMBRE_MAX);
    	utn_getMayusMin(pAuxEmployee2->nombre, EMPLOYEE_NOMBRE_MAX);
        comparar = strcmp(pAuxEmployee1->nombre, pAuxEmployee2->nombre);
    }

    return comparar;
}

int employee_compareByhorasTrabajadas(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
        resultado = pAuxEmployee1->horasTrabajadas - pAuxEmployee2->horasTrabajadas;

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
    Employee* pAuxEmployee1 = (Employee*)pThis1;
    Employee* pAuxEmployee2 = (Employee*)pThis2;

    if(pAuxEmployee1 != NULL && pAuxEmployee2 != NULL)
    {
        resultado = pAuxEmployee1->sueldo - pAuxEmployee2->sueldo;

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
