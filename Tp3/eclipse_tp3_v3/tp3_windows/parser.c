#include "parser.h"

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
    char buffer[4][EMPLOYEE_NOMBRE_MAX];
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
        		idAux = controller_nextId(pArrayListEmployee);
        		if(idAux > 0)
        		{
        			itoa(idAux,buffer[0],10);
        			pAuxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
        		}
        		else
        		{
        			pAuxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
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
    Employee* pAuxEmployee = NULL;
    int id;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	id = controller_nextId(pArrayListEmployee);
        do
        {
        	pAuxEmployee = employee_new();
            if(fread((Employee*)pAuxEmployee, sizeof(Employee), 1, pFile) == 1)
            {
            	if(id > 0)
            	{
            		employee_setId(pAuxEmployee, id++);
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
