#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file = NULL;
    int id;
    int horasTrabajadas;
    int sueldo;
    int cantidad;
    int retorno = -1;
    char buffer[4][30];
    Employee* pAuxEmployee;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
        	    	fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        	    	printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        	        do
        	        {
        	        	cantidad = fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        	        	if(cantidad < 4)
        	            {
        	        		printf("\nFIN");//break;
        	            }
        	        	else
        	        	{
        	            	id = atoi(buffer[0]);
        	            	horasTrabajadas = atoi(buffer[2]);
        	            	sueldo = atoi(buffer[3]);

        	            	pAuxEmployee = employee_newParametrosInt(id, buffer[1], horasTrabajadas, sueldo);
        	            	printf(" %5d   %10s   %20d  %8d\n\n", id, buffer[1], horasTrabajadas, sueldo);

        	                if(pAuxEmployee != NULL
        	                   && ll_len(pArrayListEmployee) < 1500
        	                   && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
        	                {
        	                    retorno = 0;

        	                }
        	            }
        	        }while(!feof(file));


        }
        else
        {
        	printf("\nNO SE PUEDE MOSTRAR");
        }

    }

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

    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "rb");

        if(file != NULL)
        {
        	retorno = parser_EmployeeFromBinary(file, pArrayListEmployee);
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
    Employee* pAuxEmployee = NULL;

    if(pArrayListEmployee != NULL)
    {
        id = employee_getNextId(pArrayListEmployee);

        if(id != -1)
        {
        	Employee auxiliar = addEmployee ();
        	utn_getMayusMin(auxiliar.nombre,50);
        	addEmployee ();
            pAuxEmployee = employee_newParametrosInt(id, auxiliar.nombre, auxiliar.horasTrabajadas, auxiliar.sueldo);

            if(pAuxEmployee != NULL
               && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
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
    int returnValue = 0;
    int id;
    int max;
    int index;
    int lifeCycle;
    int editMenu;
    Employee* pAuxEmployee = employee_new();
    Employee* afterEdit;

    if(pArrayListEmployee != NULL && pAuxEmployee != NULL)
    {
        max = employee_getNextId(pArrayListEmployee) - 1;

        if(max > 0 && !utn_getNumero(&id, "Ingrese el ID del Empleado que desea editar: ", "\nERROR", 1, max,3))
        {
            index = getIndexByEmployeeID(pArrayListEmployee, id);

            if(index != -1)
            {
            	pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, index);

                if(pAuxEmployee != NULL)
                {
                    afterEdit = employee_newParametrosInt(id, pAuxEmployee->nombre, pAuxEmployee->horasTrabajadas, pAuxEmployee->sueldo);

                    do
                    {
                        //inputs_clearScreen();

                        if(employee_print(afterEdit) == 0)
                        {
                            break;
                        }

                        menu_editarEmpleado(&editMenu);

                        employee_change (pAuxEmployee, editMenu);

                        //if(editMenu < MENU_EDIT_MAX)
                        //{
                         //   inputs_pauseScreen(ENTER_MESSAGE);
                        //}
                    }while(editMenu != 4);
                }
            }
            else
            {
                printf("No se encontro el Empleado ingresado.\n");
            }
        }
    }

    return returnValue;
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
}

