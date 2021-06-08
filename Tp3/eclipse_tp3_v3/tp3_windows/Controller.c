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
    int verificar;
    int retorno = -1;
    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
        	verificar = parser_EmployeeFromText(file, pArrayListEmployee);
        	retorno = 0;
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

            pAuxEmployee = employee_newParametrosInt(&id, auxiliar.nombre, &auxiliar.horasTrabajadas, &auxiliar.sueldo);

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
    int returnValue = 0;
    int id;
    int max;
    int index;
    int editMenu;
    Employee* pAuxEmployee = employee_new();
    Employee* pEditEmployee;

    if(pArrayListEmployee != NULL && pAuxEmployee != NULL)
    {
        max = employee_getNextId(pArrayListEmployee) - 1;

        if(max > 0 && !utn_getNumero(&id, "INGRESE EL ID: ", "\nERROR", 1,2000,3))
        {
            index = getIndexByEmployeeID(pArrayListEmployee, id);

            if(index != -1)
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, index);

                if(pAuxEmployee != NULL)
                {
                    pEditEmployee = employee_newParametrosInt(&id, pAuxEmployee->nombre, &pAuxEmployee->horasTrabajadas, &pAuxEmployee->sueldo);

                    do
                    {

                        if(employee_print(pEditEmployee) == 0)
                        {
                            break;
                        }

                        menu_editarEmpleado(&editMenu);

                        switch(editMenu)
                        {
                        case 1: /**< Editar el Nombre. >*/
                            if(!utn_getString(pEditEmployee->nombre, 50,"Ingrese nuevo Nombre: ", "\nERROR", 1, 3)
                               && employee_setNombre(pEditEmployee, pEditEmployee->nombre))
                            {
                                printf("Nombre cambiado, elija la opcion %d para aplicarlo.\n", 4);
                            }
                            break;
                        case 2: /**< Editar las Horas Trabajadas. >*/
                            if(!utn_getNumero(&pEditEmployee->horasTrabajadas, "Ingrese las Horas Trabajadas: ", "\nERROR", 0, 500,3)
                               && employee_setHorasTrabajadas(pEditEmployee, pEditEmployee->horasTrabajadas))
                            {
                                printf("Horas Trabajadas cambiadas, elija la opcion %d para aplicarlo.\n", 4);
                            }
                            break;
                        case 3: /**< Editar el Salario. >*/
                            if(!utn_getNumero(&pEditEmployee->sueldo, "Ingresa el nuevo Salario: ", "\nERROR", 0, 100000,3)
                               && employee_setSueldo(pEditEmployee, pEditEmployee->sueldo))
                            {
                                printf("Salario cambiado, elija la opcion %d para aplicarlo.\n", 4);
                            }
                            break;
                        case 4: /**< Confirmar cambios y volver al menu principal. >*/
                           // inputs_clearScreen();

                            printf("El siguiente Empleado:\n");
                            if(employee_print(pAuxEmployee))
                            {
                                printf("Sera modificado de la siguiente forma:\n");
                                if(employee_print(pEditEmployee)
                                  // && inputs_userResponse("Acepta la modificacion? [S] o [N]: ")
                                   && ll_set(pArrayListEmployee, index, (Employee*)pEditEmployee) == 0)
                                {
                                    returnValue = 1;
                                }
                            }

                            break;
                        }


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
	Employee* pAuxEmployee;
	employee_print(pAuxEmployee);
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

