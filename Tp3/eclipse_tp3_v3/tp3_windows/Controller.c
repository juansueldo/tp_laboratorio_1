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
    Employee* pAuxEmployee = employee_new();

    if(pArrayListEmployee != NULL)
    {
    	if(ll_isEmpty(pArrayListEmployee))
    	{
    		retorno = -1;
    	}
        id = employee_getNextId(pArrayListEmployee);

        if(id != -1
           && !utn_getString(nombre, EMPLOYEE_NOMBRE_MAX,"\nINGRESE EL NOMBRE DEL EMPLEADO: ", "\nERROR", 1, 3)
           && !utn_getNumero(&horasTrabajadas, "\nINGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 0, EMPLOYEE_HORA_MAX, 3)
           && !utn_getNumero(&sueldo, "\nINGRESE EL SUELDO: ", "\nERROR", 0, EMPLOYEE_SUELDO_MAX, 3))
        {

        	utn_getMayusMin(nombre,EMPLOYEE_NOMBRE_MAX);
        	pAuxEmployee = employee_newParametrosInt(&id, nombre, &horasTrabajadas, &sueldo);
            if(pAuxEmployee != NULL && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
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
    int retorno = -1;
    int id;
    int editMenu;
    Employee* pAuxEmployee = employee_new();

    if(pArrayListEmployee != NULL && pAuxEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getNumero(&id, "\nINGRESE EL ID: ", "\nERROR", 1,EMPLOYEE_MAX,3)==0)
        {
        	pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, id-1);

            	employee_print(pAuxEmployee);

            	if(utn_getRespuesta ("\nDesea modificar este empleado? [S] o [N]: ","\nERROR", 3) == 0)
            	{
            	do
            	{
                    menu_editarEmpleado(&editMenu);
                    employee_change (pAuxEmployee, editMenu);
                    retorno = 0;
                }while(editMenu != 4);
            	}
              }
            else
            {
                printf("No se encontro el Empleado ingresado.\n");
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
    int retorno = -1;
    int id;
    Employee* pAuxEmployee = employee_new();

    if(pArrayListEmployee != NULL && pAuxEmployee != NULL)
    {
    	controller_ListEmployee(pArrayListEmployee);
    	if(utn_getNumero(&id, "\nINGRESE EL ID: ", "\nERROR", 1,2000,3)==0)
    	{
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, id-1);

                if(pAuxEmployee != NULL)
                {
                	employee_print(pAuxEmployee);
                	if(utn_getRespuesta ("\nDesea dar de baja el Empleado? [S] o [N]: ","\nERROR", 3) == 0)
                	{
                		if(ll_remove(pArrayListEmployee, id) == 0)
                		{
                			retorno = 0;
                			employee_delete(pAuxEmployee);
                			pAuxEmployee = NULL;
                    }
                	}
                }
            }
            else
            {
                printf("No se encontro el Empleado ingresado.\n");
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
    int i;
    int employeeQty;
    int id;
	char nombre[EMPLOYEE_NOMBRE_MAX];
	int horasTrabajadas;
	int sueldo;
    Employee* pAuxEmployee = NULL;

    if(pArrayListEmployee != NULL)
    {
        employeeQty = ll_len(pArrayListEmployee);
        printf("|*******|**********************|*******|************|\n");
        printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
        printf("|*******|**********************|*******|************|\n");
        for(i = 0 ; i < employeeQty; i++)
         {
        	pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
        	//employee_print(pAuxEmployee);
        	if(pAuxEmployee!= NULL && employee_getId(pAuxEmployee, &id)==0
					&& employee_getNombre(pAuxEmployee, nombre)==0
					&& employee_getHorasTrabajadas(pAuxEmployee, &horasTrabajadas)==0
					&& employee_getSueldo(pAuxEmployee, &sueldo)==0)
        	{
        			id = employee_getId2(pAuxEmployee);
                	utn_getMayusMin(nombre,EMPLOYEE_NOMBRE_MAX);
                    printf("| %5d | %20s | %5d | %10d |\n",
                    		i+1,nombre,horasTrabajadas, sueldo);
        	}
          }

        retorno = 0;

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
    int retorno = -1;
    int opcionMenu;
    int orden;

    if(pArrayListEmployee != NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            do
            {
                menu_sort(&opcionMenu);
                utn_getNumero(&orden, "Ingrese para ordenar: [1] Ascendente - [0] Descendente: ", "\nERROR", 1, 0,3);

                    switch(opcionMenu)
                    {
                    case 1:
                       if(ll_sort(pArrayListEmployee, employee_compareByID, orden) == 0)
                        {
                            printf("Ordenado por ID finalizado.\n");
                        }
                        break;
                    case 2:
                        if(ll_sort(pArrayListEmployee, employee_compareBynombre, orden) == 0)
                        {
                            printf("Ordenado por Nombre finalizado.\n");
                        }
                        break;
                    case 3:
                        if(ll_sort(pArrayListEmployee, employee_compareByhorasTrabajadas, orden) == 0)
                        {
                            printf("Ordenado por Horas Trabajadas finalizado.\n");
                        }
                        break;
                    case 4:
                        if(ll_sort(pArrayListEmployee, employee_compareBysueldo, orden) == 0)
                        {
                            printf("Ordenado por Salario finalizado.\n");
                        }
                        break;
                    }
                    retorno = 0;

            }while(opcionMenu != 5);
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
    Employee* pAuxEmployee;

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
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                if(pAuxEmployee == NULL || fprintf(file, "%d,%s,%d,%d\n", pAuxEmployee->id, pAuxEmployee->nombre, pAuxEmployee->horasTrabajadas, pAuxEmployee->sueldo) == -1)
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
    //free(pAuxEmployee);
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
    int retorno = -1;
    int employeeQTY;
    int i;
    Employee* pAuxEmployee;

    if(pArrayListEmployee != NULL)
    {
        employeeQTY = ll_len(pArrayListEmployee);

        file = fopen(path, "wb");

        if(file != NULL && employeeQTY > 0 && employeeQTY <= EMPLOYEE_MAX)
        {
            for(i = 0; i < employeeQTY; i++)
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                if(pAuxEmployee == NULL || fwrite((Employee*)pAuxEmployee, sizeof(Employee), 1, file) != 1)
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
    //free(pAuxEmployee);
    return retorno;
}

