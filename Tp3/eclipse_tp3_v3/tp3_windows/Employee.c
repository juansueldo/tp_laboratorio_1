#include "Employee.h"

Employee* employee_new()
{
    Employee* pAuxEmployee;

    pAuxEmployee = (Employee*)malloc(sizeof(Employee));

    return pAuxEmployee;
}
/*Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
}*/
Employee* employee_newParametrosInt(int id,char* nombre,int horasTrabajadas, int sueldo)
{
	Employee* this = NULL;
	this = employee_new();
	if(this != NULL && nombre != NULL)
	{
		if(	employee_setId(this,id == -1) ||
			employee_setNombre(this,nombre) == -1 ||
			employee_setHorasTrabajadas(this,horasTrabajadas) == -1 ||
			employee_setSueldo(this,sueldo) == -1)
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

printf("\n Mostrar empleados \n");

for(int i=0; i < len; i++)
{
    printf(" %5d   %10s   %20d  %8d\n", (this + i)->id, (this + i)->nombre, (this + i)->horasTrabajadas, (this + i)->sueldo);
}
printf("\n\n");

}
int employee_getNextId(LinkedList* pArrayListEmployee)
{
    int maxValue = -1;
    int arrayLength = 0;
    int i;
    int counter = 0;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        if(arrayLength > 0)
        {
            for(i = 0; i < arrayLength; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);

                if(aux != NULL)
                {
                    if(counter == 0)
                    {
                        maxValue = aux->id;
                    }
                    else
                    {
                        if(aux->id > maxValue
                           && aux->id < 1500)
                        {
                            maxValue = aux->id;
                        }
                    }

                    counter++;
                }
            }
        }

        if(counter > 0)
        {
            maxValue++;
        }
        else
        {
            maxValue = 1;
        }
    }

    return maxValue;
}
Employee addEmployee (void)
{
	Employee auxiliar;

	if(utn_getString(auxiliar.nombre, 50, "Ingrese el nombre del Empleado: ", "\nERROR", 1,3))
	{
		printf("\nNO SE INGRESO ES NOMBRE");
	}

	if(utn_getNumero(&auxiliar.horasTrabajadas,"\nIngrese las horas trabajadas: ","\nERROR",8,100,3))
	{
		printf("\nNO SE INGRESARON LAS HORAS TRABAJADAS");
	}
	if(utn_getNumero(&auxiliar.sueldo,"\nIngrese el sueldo: ","\nERROR",1000,100000,3))
	{
		printf("\nNO SE INGRESO EL SUELDO");
	}

	return auxiliar;
}
/*
int addEmployees (eEmployee arrayEmpleados[], int tamanio, int *pIdEmpleado)
{
	int rtn = 0;
	eEmployee auxiliarEmpleados;
	if(arrayEmpleados != NULL && tamanio > 0 && pIdEmpleado != NULL)
	{
	int index = findEmpty (arrayEmpleados, tamanio);
	if (index != -1)
	{
		auxiliarEmpleados = addEmployee();
		auxiliarEmpleados.isEmpty = 0;
		arrayEmpleados[index] = auxiliarEmpleados;
		rtn = 1;
	}
	if(rtn == 1)
	{
		(*pIdEmpleado)++;
		auxiliarEmpleados.id = *pIdEmpleado;
		arrayEmpleados[index] = auxiliarEmpleados;
	}
	}
	return rtn;
}
*/