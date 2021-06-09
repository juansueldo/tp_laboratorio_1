#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int verificar;
    int retorno = -1;
    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
        	verificar = parser_EmployeeFromText(file, pArrayListEmployee);
        	if(verificar == 0)
        	{
        		retorno = 0;
        	}

        }
    }

    fclose(file);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int verificar;
    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "rb");

        if(file != NULL)
        {
        	verificar = parser_EmployeeFromBinary(file, pArrayListEmployee);
        	if(verificar == 0)
        	{
        		retorno = 0;
        	}
        }
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[EMPLOYEE_NOMBRE_MAX];
    Employee* aux = NULL;

    if(pArrayListEmployee != NULL)
    {
        id = employee_getNextId(pArrayListEmployee);

        if(id != -1
           && !utn_getString(nombre, EMPLOYEE_NOMBRE_MAX,"\nINGRESE EL NOMBRE DEL EMPLEADO: ", "\nERROR", 1, 3)
           && !utn_getNumero(&horasTrabajadas, "\nINGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 0, EMPLOYEE_HORA_MAX, 3)
           && !utn_getNumero(&sueldo, "\nINGRESE EL SUELDO: ", "\nERROR", 0, EMPLOYEE_SUELDO_MAX, 3))
        {
        	utn_getMayusMin(nombre,EMPLOYEE_NOMBRE_MAX);
        	aux = employee_newParametrosInt(&id+1, nombre, &horasTrabajadas, &sueldo);
            if(aux != NULL && ll_add(pArrayListEmployee, (Employee*)aux) == 0)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    int index;
    int editMenu;
    Employee* pAuxEmployee = employee_new();
    //Employee* pEditEmployee;

    if(pArrayListEmployee != NULL && pAuxEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getNumero(&id, "\nINGRESE EL ID: ", "\nERROR", 1,2000,3)==0)
        {
            index = getIndexByEmployeeID(pArrayListEmployee, id);
            printf("Index %d",index);
            printf("\nID %d",id);
            if(index+1 == id)
            {

            	pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, index);
            	employee_print(pAuxEmployee);

            	if(utn_getRespuesta ("\nDesea modificar este empleado? [S] o [N]: ","\nERROR", 3) == 0)
            	{
            	do
            	{
                    menu_editarEmpleado(&editMenu);
                    employee_change (pAuxEmployee, editMenu);

                }while(editMenu != 4);
            	}
              }
            else
            {
                printf("No se encontro el Empleado ingresado.\n");
            }
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    int index;
    Employee* aux = employee_new();

    if(pArrayListEmployee != NULL && aux != NULL)
    {
    	controller_ListEmployee(pArrayListEmployee);
    	if(utn_getNumero(&id, "\nINGRESE EL ID: ", "\nERROR", 1,2000,3)==0)
    	{
    		index = getIndexByEmployeeID(pArrayListEmployee, id);
    	     if(index+1 == id)
    	      {
                aux = (Employee*)ll_get(pArrayListEmployee, index);

                if(aux != NULL)
                {
                	employee_print(aux);
                	if(utn_getRespuesta ("\nDesea dar de baja el Empleado? [S] o [N]: ","\nERROR", 3) == 0)
                	{
                		if(ll_remove(pArrayListEmployee, index) == 0)
                		{
                			retorno = 1;
                			employee_delete(aux);
                			aux = NULL;
                    }
                	}
                }
            }
            else
            {
                printf("No se encontro el Empleado ingresado.\n");
            }
        }
    }

    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int employeeQty;
    Employee* aux;


    if(pArrayListEmployee != NULL)
    {
        employeeQty = ll_len(pArrayListEmployee);
        void* ll_get(LinkedList* this, int index);

        printf("|*******|**********************|*******|************|\n");
        printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
        printf("|*******|**********************|*******|************|\n");

        for(int i = 0 ; i < employeeQty; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);
                aux->id = i+1;
                if(aux != NULL)
                {
                	utn_getMayusMin(aux->nombre,EMPLOYEE_NOMBRE_MAX);
                    printf("| %5d | %20s | %5d | %10d |\n",
                           aux->id, aux->nombre,
                           aux->horasTrabajadas, aux->sueldo);
                }

            }

    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int sortMenu;
    int sortOption;

    if(pArrayListEmployee != NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            do
            {
                menu_sort(&sortMenu);
                if((sortMenu >= 1 && sortMenu < 5)
                   && !utn_getNumero(&sortOption, "Ingrese para ordenar: [1] Ascendente - [2] Descendente: ", "\nERROR", 1, 2,3))
                {

                    switch(sortMenu)
                    {
                    case 1:
                        if(ll_sort(pArrayListEmployee, employee_compareByID, sortOption) == 0)
                        {
                            printf("Ordenado por ID finalizado.\n");
                        }
                        break;
                    case 2:
                        if(ll_sort(pArrayListEmployee, employee_compareBynombre, sortOption) == 0)
                        {
                            printf("Ordenado por Nombre finalizado.\n");
                        }
                        break;
                    case 3:
                        if(ll_sort(pArrayListEmployee, employee_compareByhorasTrabajadas, sortOption) == 0)
                        {
                            printf("Ordenado por Horas Trabajadas finalizado.\n");
                        }
                        break;
                    case 4:
                        if(ll_sort(pArrayListEmployee, employee_compareBysueldo, sortOption) == 0)
                        {
                            printf("Ordenado por Salario finalizado.\n");
                        }
                        break;
                    }
                }

            }while(sortMenu != 5);
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file = NULL;
    int retorno = -1;
    int employeeQTY;
    int i;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        employeeQTY = ll_len(pArrayListEmployee);

        file = fopen(path, "w");

        if(file != NULL
           && employeeQTY > 0 && employeeQTY <= EMPLOYEE_MAX
           && fprintf(file, "id,nombre,horasTrabajadas,sueldo\n") != -1)
        {
            for(i = 0; i < employeeQTY; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);

                if(aux == NULL
                   || fprintf(file, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo) == -1)
                {
                    break;
                }
            }
        }

        if(i > 0 && i == employeeQTY)
        {
        	retorno = 0;
        }
    }

    fclose(file);

    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file = NULL;
    int retorno = 0;
    int employeeQTY;
    int i;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        employeeQTY = ll_len(pArrayListEmployee);

        file = fopen(path, "wb");

        if(file != NULL && employeeQTY > 0 && employeeQTY <= EMPLOYEE_MAX)
        {
            for(i = 0; i < employeeQTY; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);

                if(aux == NULL
                   || fwrite((Employee*)aux, sizeof(Employee), 1, file) != 1)
                {
                    break;
                }
            }
        }

        if(i > 0 && i == employeeQTY)
        {
            retorno = 1;
        }
    }

    fclose(file);

    return retorno;
}

