#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cantidad;
    int retorno = -1;
    char buffer[4][30];
    int idAux;
    Employee* pAuxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        do
        {
        	cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        	if(cantidad < 4)
            {
        		printf("\nFIN");
            }
        	else
        	{
        		int id = atoi(buffer[0]);
        		int horasTrabajadas = atoi(buffer[2]);
        		int sueldo = atoi(buffer[3]);
        		idAux = controller_nextId(pArrayListEmployee);
        		if(idAux > 0)
        		{
        			id = idAux;
        			pAuxEmployee = employee_newParametrosInt(id, buffer[1], horasTrabajadas, sueldo);
        		}
        		else
        		{
        			pAuxEmployee = employee_newParametrosInt(id, buffer[1], horasTrabajadas, sueldo);
        		}
                if(pAuxEmployee != NULL && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
                {
                    retorno = 0;

                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee auxEmployee;
    Employee* pAuxEmployee = NULL;
    //int id;
    //char nombre[EMPLOYEE_NOMBRE_MAX];
    //int horasTrabajadas;
    //int sueldo;
    int idAux = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            if(fread((Employee*)&auxEmployee, sizeof(Employee), 1, pFile) == 1)
            {
            	idAux = controller_nextId(pArrayListEmployee);
            	if(idAux > 0)
            	{
            		auxEmployee.id = idAux;
            		pAuxEmployee = employee_newParametrosInt(auxEmployee.id, auxEmployee.nombre, auxEmployee.horasTrabajadas, auxEmployee.sueldo);
            	}
            	else
            	{
            	    pAuxEmployee = employee_newParametrosInt(auxEmployee.id, auxEmployee.nombre, auxEmployee.horasTrabajadas, auxEmployee.sueldo);
            	}

                if(pAuxEmployee != NULL && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
                {
                	retorno = 0;
                }
            }
        }while(!feof(pFile));
    }

    return retorno;
}
