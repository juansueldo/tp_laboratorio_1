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
    char buffer[4][30];
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
            	pAuxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(pAuxEmployee != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX
                   && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
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

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((Employee*)&auxEmployee, sizeof(Employee), 1, pFile) == 1)
            {
                pAuxEmployee = employee_newParametrosInt (auxEmployee.id, auxEmployee.nombre, auxEmployee.horasTrabajadas, auxEmployee.sueldo);
                if(pAuxEmployee != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX
                   && ll_add(pArrayListEmployee, (Employee*)pAuxEmployee) == 0)
                {
                	retorno = 0;
                }
            }
        }
    }

    return retorno;
}
