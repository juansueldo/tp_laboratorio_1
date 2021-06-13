#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "utn.h"
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
    //int idAux;
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
    	if(ll_isEmpty(pArrayListEmployee) == 1)
    	{
    		if(!utn_getString(nombre, EMPLOYEE_NOMBRE_MAX,"\nINGRESE EL NOMBRE DEL EMPLEADO: ", "\nERROR", 1, 3)
    		           && !utn_getNumero(&horasTrabajadas, "\nINGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 0, EMPLOYEE_HORA_MAX, 3)
    		           && !utn_getNumero(&sueldo, "\nINGRESE EL SUELDO: ", "\nERROR", 0, EMPLOYEE_SUELDO_MAX, 3))
    		  {
    		      utn_getMayusMin(nombre,EMPLOYEE_NOMBRE_MAX);
    		      pAuxEmployee = employee_newParametrosInt(1, nombre, horasTrabajadas, sueldo);
    		      if(pAuxEmployee != NULL && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
    		       {
    		                retorno = 0;
    		       }

    		   }
    	}
    	else if(ll_isEmpty(pArrayListEmployee) == 0)
		{
    		id = controller_nextId(pArrayListEmployee);

    		if(id != -1
    				&& !utn_getString(nombre, EMPLOYEE_NOMBRE_MAX,"\nINGRESE EL NOMBRE DEL EMPLEADO: ", "\nERROR", 1, 3)
					&& !utn_getNumero(&horasTrabajadas, "\nINGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 0, EMPLOYEE_HORA_MAX, 3)
					&& !utn_getNumero(&sueldo, "\nINGRESE EL SUELDO: ", "\nERROR", 0, EMPLOYEE_SUELDO_MAX, 3))
        {
        	utn_getMayusMin(nombre,EMPLOYEE_NOMBRE_MAX);
        	pAuxEmployee = employee_newParametrosInt(id, nombre, horasTrabajadas, sueldo);
            if(pAuxEmployee != NULL && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
            {
                retorno = 0;
            }

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

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0)
    {
        controller_ListEmployee(pArrayListEmployee);
        if(utn_getNumero(&id, "\nINGRESE EL ID DEL EMPLEADO A MODIFICAR: ", "\nERROR", 1,EMPLOYEE_MAX,3)==0)
        {
        	pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, id-1);
        	if(pAuxEmployee != NULL)
        	{
            	employee_print(pAuxEmployee);

            	if(utn_getRespuesta ("\nQUIERE MODIFICAR ESTE EMPLEADO? [S] o [N]: ","\nERROR", 3) == 0)
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
                printf("NO EXISTE EL EMPLEADO INGRESADO.\n");
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
    int retorno = -1;
    int id;
    int index;
    Employee* ppAuxEmployeeEmployee = employee_new();

    if(pArrayListEmployee != NULL && ppAuxEmployeeEmployee != NULL)
    {
    	controller_ListEmployee(pArrayListEmployee);
    	if(utn_getNumero(&id, "\nINGRESE EL ID DEL EMPLEADO A ELIMINAR: ", "\nERROR", 1,2000,3)==0)
    	{
             index = controller_getIndexById(pArrayListEmployee, id);
             if(ppAuxEmployeeEmployee != NULL && index+1 == id)
                {
                	ppAuxEmployeeEmployee = (Employee*)ll_get(pArrayListEmployee, index);
                	employee_print(ppAuxEmployeeEmployee);
                	if(utn_getRespuesta ("\nQUIERE DAR DE BAJA ESTE EMPLEADO? [S] o [N]: ","\nERROR", 3) == 0)
                	{
                		ll_remove(pArrayListEmployee, index);
                		retorno = 0;
                		employee_delete(ppAuxEmployeeEmployee);
                		ppAuxEmployeeEmployee = NULL;

                	}
                }
                else
                {
                     printf("NO EXISTE EL EMPLEADO INGRESADO.\n");
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
    int i;
    int id;
    int pantalla = 999;
    int respuesta;
    int respuesta2;
	char nombre[EMPLOYEE_NOMBRE_MAX];
	int horasTrabajadas;
	int sueldo;
    Employee* ppAuxEmployeeEmployee = NULL;

    if(pArrayListEmployee != NULL)
    {
    	if(ll_len(pArrayListEmployee)>0)
    	{
        printf("|*******|**********************|*******|************|\n");
        printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
        printf("|*******|**********************|*******|************|\n");
        do
        {
        for(i = 0 ; i < ll_len(pArrayListEmployee); i++)
        {
        	ppAuxEmployeeEmployee = (Employee*)ll_get(pArrayListEmployee, i);
        	employee_getId(ppAuxEmployeeEmployee, &id);
			employee_getNombre(ppAuxEmployeeEmployee, nombre);
			employee_getHorasTrabajadas(ppAuxEmployeeEmployee, &horasTrabajadas);
			employee_getSueldo(ppAuxEmployeeEmployee, &sueldo);

            utn_getMayusMin(nombre,EMPLOYEE_NOMBRE_MAX);
            printf("| %5d | %20s | %5d | %10d |\n", id,nombre,horasTrabajadas, sueldo);
        	if(i == pantalla)
             {
        		do
        		{
        			respuesta = utn_getRespuesta ("\nPRESIONE [S] PARA CONTINUAR: ","\nERROR", 3);
        			pantalla+=999;
        		}while(respuesta != 0);
              }
        	}
        	respuesta2 = utn_getRespuesta ("\nPRESIONE [S] PARA CONTINUAR: ","\nERROR", 3);

        }while(respuesta2 != 0);
        retorno = 0;

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
    int retorno = -1;
    int opcionMenu;
    int orden;

    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
            do
            {
                menu_sort(&opcionMenu);
                if(opcionMenu > 0 && opcionMenu < 5)
                {
                	orden = utn_getRespuesta ("\nQUIERE ORDENAR DE MANERA ASCENDENTE [S] DESCENDENTE [N]: ","\nERROR", 3);
                	if(orden < 0)
                	{
                		printf("\nNO SE REALIZO EL ORDENAMIENTO\n");
                	}
                	else
                	{
                		printf("\nPROCESANDO ORDENAMIENTO...\n");
                		printf("ESTO PUEDE TARDAR UNOS MINUTOS...\n");
                	}
                    switch(opcionMenu)
                    {
                    case 1:

                       if(ll_sort(pArrayListEmployee, employee_compareByID, orden) == 0)
                        {
                            printf("OREDENAMIENTO POR ID EXITOSO.\n");
                        }
                        break;
                    case 2:
                        if(ll_sort(pArrayListEmployee, employee_compareBynombre, orden) == 0)
                        {
                            printf("ORDENAMIENTO POR NOMBRE EXITOSO\n");
                        }
                        break;
                    case 3:
                        if(ll_sort(pArrayListEmployee, employee_compareByhorasTrabajadas, orden) == 0)
                        {
                            printf("ORDENAMIETO POR HORAS EXITOSO\n");
                        }
                        break;
                    case 4:
                        if(ll_sort(pArrayListEmployee, employee_compareBysueldo, orden) == 0)
                        {
                            printf("ORDENTAMIENTO POR SUELDO EXITOSO\n");
                        }
                        break;
                    }
                    retorno = 0;
                }
            }while(opcionMenu != 5);
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
    Employee* ppAuxEmployeeEmployee;

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
                ppAuxEmployeeEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                if(ppAuxEmployeeEmployee == NULL || fprintf(file, "%d,%s,%d,%d\n", ppAuxEmployeeEmployee->id, ppAuxEmployeeEmployee->nombre, ppAuxEmployeeEmployee->horasTrabajadas, ppAuxEmployeeEmployee->sueldo) == -1)
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
    free(ppAuxEmployeeEmployee);
    free(pArrayListEmployee);
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
    free(pAuxEmployee);
    //free(pArrayListEmployee);
    return retorno;
}
int controller_nextId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int idpAuxEmployee;
    int idMax;
    Employee *pEmployee;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if(i == 0)
            {
                employee_getId(pEmployee, &idMax);
            }
            else
            {
                employee_getId(pEmployee, &idpAuxEmployee);
                if(idpAuxEmployee > idMax)
                {
                    idMax = idpAuxEmployee;
                }
            }
            retorno = idMax+1;
        }
       // retorno = idMax+1;
    }
    return retorno;
}
int controller_getIndexById (LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
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
