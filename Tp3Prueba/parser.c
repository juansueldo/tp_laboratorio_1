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
	int id;
    int horasTrabajadas;
    int sueldo;
    int cantidad;
    int retorno = -1;
    char buffer[4][30];
    Employee* pAuxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    	printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        do
        {
        	cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
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
        }while(!feof(pFile));
        free(pAuxEmployee);
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
	return 1;
}