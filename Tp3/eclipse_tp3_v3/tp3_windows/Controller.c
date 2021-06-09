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
    Employee* pEditEmployee;

    if(pArrayListEmployee != NULL && pAuxEmployee != NULL)
    {
        //max = employee_getNextId(pArrayListEmployee) - 1;
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getNumero(&id, "INGRESE EL ID: ", "\nERROR", 1,2000,3)==0)
        {
            index = getIndexByEmployeeID(pArrayListEmployee, id);

            if(index+1 == id)
            {
            	pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, index);
                /*pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, index);

                if(pAuxEmployee != NULL)
                {
                    pEditEmployee = employee_newParametrosInt(&id, pAuxEmployee->nombre, &pAuxEmployee->horasTrabajadas, &pAuxEmployee->sueldo);

                    do
                    {

                        if(employee_print(pEditEmployee) != 0)
                        {
                            break;
                        }*/

                        menu_editarEmpleado(&editMenu);


                        switch(editMenu)
                        {
                        case 1: /**< Editar el Nombre. >*/
                            if(utn_getString(pEditEmployee->nombre, 50,"Ingrese nuevo Nombre: ", "\nERROR", 1, 3)==0)
                              // && employee_setNombre(pEditEmployee, pEditEmployee->nombre))
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
                                    retorno = 1;
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
     //   }
   // }

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
    int returnValue = 0;
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
            returnValue = 1;
        }
    }

    fclose(file);

    return returnValue;
}

