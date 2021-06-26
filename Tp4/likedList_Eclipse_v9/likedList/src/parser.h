#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param path char* archivo que contiene los datos a parsear
 * @param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * @return int retorna 0 si los datos se fueron parseados, y -1 sino se parsearon
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * @param path char* archivo que contiene los datos a parsear
 * @param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * @return int retorna 0 si los datos se fueron parseados, y -1 sino se parsearon
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
