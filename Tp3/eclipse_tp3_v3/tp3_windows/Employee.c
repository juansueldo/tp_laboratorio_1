#include "Employee.h"

Employee* employee_new()
{
    Employee* ppAuxEmployeeEmployee;

    ppAuxEmployeeEmployee = (Employee*)malloc(sizeof(Employee));

    return ppAuxEmployeeEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(	employee_setId(this,atoi(idStr) == -1) ||
			employee_setNombre(this,nombreStr) == -1 ||
			employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) == -1 ||
			employee_setSueldo(this,atoi(sueldoStr)) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}
Employee* employee_newParametrosInt(int* id,char* nombre,int* horasTrabajadas, int* sueldo)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && nombre != NULL)
	{
		if(	employee_setId(this,*id == -1) ||
			employee_setNombre(this,nombre) == -1 ||
			employee_setHorasTrabajadas(this,*horasTrabajadas) == -1 ||
			employee_setSueldo(this,*sueldo) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}
void employee_delete()
{
	Employee* this;
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
		retorno = 0;
		*id = this->id;
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
void mostrarEmpleados(Employee* this, int len)
{

//printf("\n Mostrar empleados \n");

for(int i=0; i < len; i++)
{
    printf(" %5d   %10s   %20d  %8d\n", (this + i)->id, (this + i)->nombre, (this + i)->horasTrabajadas, (this + i)->sueldo);
}
printf("\n\n");

}
int employee_getNextId(LinkedList* pArrayListEmployee)
{
    int idMayor = -1;
    int arrayLength = 0;
    int i;
    Employee* pAuxEmployee;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        if(arrayLength > 0)
        {
            for(i = 0; i < arrayLength; i++)
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                if(pAuxEmployee != NULL)
                {
                    idMayor = pAuxEmployee->id;

                    if(pAuxEmployee->id > idMayor && pAuxEmployee->id < EMPLOYEE_MAX)
                    {
                        idMayor = pAuxEmployee->id;
                    }
                 }
                }
            }
    }

    return idMayor;
}
Employee addEmployee (void)
{
	Employee pAuxEmployeeiliar;

	if(utn_getString(pAuxEmployeeiliar.nombre, 50, "Ingrese el nombre del Empleado: ", "\nERROR", 1,3))
	{
		printf("\nNO SE INGRESO ES NOMBRE");
	}

	if(utn_getNumero(&pAuxEmployeeiliar.horasTrabajadas,"\nIngrese las horas trabajadas: ","\nERROR",8,100,3))
	{
		printf("\nNO SE INGRESARON LAS HORAS TRABAJADAS");
	}
	if(utn_getNumero(&pAuxEmployeeiliar.sueldo,"\nIngrese el sueldo: ","\nERROR",1000,100000,3))
	{
		printf("\nNO SE INGRESO EL SUELDO");
	}

	return pAuxEmployeeiliar;
}
int employee_print(Employee* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	printf("|*******|**********************|*******|************|\n");
    	printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
    	printf("|*******|**********************|*******|************|\n");
    	utn_getMayusMin(this->nombre,EMPLOYEE_NOMBRE_MAX);
    	printf("| %5d | %20s | %5d | %10d |\n",
    		            	this->id, this->nombre,
							this->horasTrabajadas, this->sueldo);
        printf("|*******|**********************|*******|************|\n");

        retorno = 0;
    }

    return retorno;
}
Employee employee_change (Employee* this, int opcion)
{
	Employee* ppAuxEmployeeEmployee = this;

	switch(opcion)
	{
	case 1:
		if(utn_getString(ppAuxEmployeeEmployee->nombre, 50, "Ingrese el nombre del Empleado: ", "\nERROR", 1,3)
				&& employee_setNombre(ppAuxEmployeeEmployee, ppAuxEmployeeEmployee->nombre))
		{
        //printf("Nombre cambiado, elija la opcion %d para aplicarlo.\n", MENU_EDIT_MAX);
		}
    break;
	case 2: /**< Editar las Horas Trabajadas. >*/
    if(!utn_getNumero(&ppAuxEmployeeEmployee->horasTrabajadas, "Ingrese las horas trabajadas: ", "\nERROR", 1, 1000,3)
       && employee_setHorasTrabajadas(ppAuxEmployeeEmployee, ppAuxEmployeeEmployee->horasTrabajadas))
    {
        //printf("Horas Trabajadas cambiadas, elija la opcion %d para aplicarlo.\n", MENU_EDIT_MAX);
    }
    break;
	case 3: /**< Editar el Salario. >*/
    if(!utn_getNumero(&ppAuxEmployeeEmployee->sueldo, "Ingrese el nuevo sueldo: ", "\nERROR", 1, 1000000,3)
       && employee_setSueldo(ppAuxEmployeeEmployee, ppAuxEmployeeEmployee->sueldo))
    {
        //printf("Salario cambiado, elija la opcion %d para aplicarlo.\n", MENU_EDIT_MAX);
    }
    break;
	}

	return *ppAuxEmployeeEmployee;

}

int getIndexByEmployeeID(LinkedList* pArrayListEmployee, int id)
{
    int retorno;
    int arrayLength;
    int i;
    Employee* pAuxEmployee;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        if(arrayLength > 0)
        {
            for(i = 0; i < arrayLength; i++)
            {
                pAuxEmployee = ll_get(pArrayListEmployee, i);

                if(pAuxEmployee != NULL && pAuxEmployee->id == id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }

    return retorno;
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
