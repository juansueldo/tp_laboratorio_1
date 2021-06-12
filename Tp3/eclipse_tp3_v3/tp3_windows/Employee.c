#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* pAuxEmployeeEmploye;

    pAuxEmployeeEmploye = (Employee*)malloc(sizeof(Employee));

    return pAuxEmployeeEmploye;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = employee_new();
	 void *retorno = NULL;
	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(	!employee_setId(this,atoi(idStr)) &&
			(employee_setNombre(this,nombreStr) == -1 ||
			employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) == -1 ||
			employee_setSueldo(this,atoi(sueldoStr))== -1))
		{
			employee_delete(this);
			retorno = this;
		}
		else
		{
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
Employee addEmployee (void)
{
	Employee pAuxEmployee;

	if(utn_getString(pAuxEmployee.nombre, 50, "Ingrese el nombre del Empleado: ", "\nERROR", 1,3))
	{
		printf("\nNO SE INGRESO ES NOMBRE");
	}

	if(utn_getNumero(&pAuxEmployee.horasTrabajadas,"\nIngrese las horas trabajadas: ","\nERROR",8,100,3))
	{
		printf("\nNO SE INGRESARON LAS HORAS TRABAJADAS");
	}
	if(utn_getNumero(&pAuxEmployee.sueldo,"\nIngrese el sueldo: ","\nERROR",1000,100000,3))
	{
		printf("\nNO SE INGRESO EL SUELDO");
	}

	return pAuxEmployee;
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
int findEmployeeById(LinkedList* pArrayListEmployee, int id, int *posicionId)
{
    int retorno = -1;
    int i;
    int idAux;
    Employee *pEmployee;
    if(pArrayListEmployee != NULL && id > 0 && posicionId > 0)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &idAux);
                if(id == idAux)
                {
                    *posicionId = i;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int employee_printEmployees(Employee* this, int len)
{
	int retorno = -1;
	int id;
	char nombre[EMPLOYEE_NOMBRE_MAX];
	int horasTrabajadas;
	int sueldo;
    if(this != NULL && len > 0 && employee_getId(this, &id)==0
						&& employee_getNombre(this, nombre)==0
						&& employee_getHorasTrabajadas(this, &horasTrabajadas)==0
						&& employee_getSueldo(this, &sueldo)==0)
    {
    	printf("|*******|**********************|*******|************|\n");
    	printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
    	printf("|*******|**********************|*******|************|\n");
    	for(int i =0; i < len; i++)
    	{
    	utn_getMayusMin(this->nombre,EMPLOYEE_NOMBRE_MAX);
    	printf("| %5d | %20s | %5d | %10d |\n",
    								id, nombre, horasTrabajadas, sueldo);
        printf("|*******|**********************|*******|************|\n");
    	}

        retorno = 0;
    }

    return retorno;
}
Employee employee_change (Employee* this, int opcion)
{
	Employee* pAuxEmployee = this;

	switch(opcion)
	{
	case 1:
		if(utn_getString(pAuxEmployee->nombre, EMPLOYEE_NOMBRE_MAX, "Ingrese el nombre del Empleado: ", "\nERROR", 1,3)
				&& employee_setNombre(pAuxEmployee, pAuxEmployee->nombre))
		{
			printf("\nEL NOMBRE NO FUE CAMBIADO\n");
		}
		else
		{
			printf("\nNOMBRE CAMBIADO\n");
		}
    break;
	case 2:
		if(!utn_getNumero(&pAuxEmployee->horasTrabajadas, "Ingrese las horas trabajadas: ", "\nERROR", 1, 1000,3)
				&& employee_setHorasTrabajadas(pAuxEmployee, pAuxEmployee->horasTrabajadas))
		{
			printf("\nLAS HORAS TRABAJADAS NO FUERON CAMBIADAS\n");
		}
		else
		{
			printf("\nHORAS TRABAJADAS CAMBIADAS\n");
		}
    break;
	case 3:
		if(!utn_getNumero(&pAuxEmployee->sueldo, "Ingrese el nuevo sueldo: ", "\nERROR", 1, 1000000,3)
				&& employee_setSueldo(pAuxEmployee, pAuxEmployee->sueldo))
		{
			printf("\nEL SUELDO NO FUE CAMBIADO\n");
		}
		else
		{
			printf("\nSUELDO CAMBIADO\n");
		}
    break;
	}

	return *pAuxEmployee;

}
int employee_compareByID(void* pElement1, void* pElement2)
{
    int compare;
    int result;
    Employee* aux1 = (Employee*)pElement1;
    Employee* aux2 = (Employee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->id - aux2->id;

        if(result > 0)
        {
            compare = 1;
        }
        else
        {
            if(result < 0)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}

int employee_compareBynombre(void* pElement1, void* pElement2)
{
    int compare;
    Employee* aux1 = (Employee*)pElement1;
    Employee* aux2 = (Employee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
    	utn_getMayusMin(aux1->nombre, EMPLOYEE_NOMBRE_MAX);
    	utn_getMayusMin(aux2->nombre, EMPLOYEE_NOMBRE_MAX);
        compare = strcmp(aux1->nombre, aux2->nombre);
    }

    return compare;
}

int employee_compareByhorasTrabajadas(void* pElement1, void* pElement2)
{
    int compare;
    int result;
    Employee* aux1 = (Employee*)pElement1;
    Employee* aux2 = (Employee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->horasTrabajadas - aux2->horasTrabajadas;

        if(result > 0)
        {
            compare = 1;
        }
        else
        {
            if(result < 0)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}

int employee_compareBysueldo(void* pElement1, void* pElement2)
{
    int compare;
    int result;
    Employee* aux1 = (Employee*)pElement1;
    Employee* aux2 = (Employee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->sueldo- aux2->sueldo;

        if(result > 0)
        {
            compare = 1;
        }
        else
        {
            if(result < 0)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}
