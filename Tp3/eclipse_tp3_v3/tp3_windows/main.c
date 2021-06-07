#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	system("cls");
	setbuf(stdout,NULL);
    int option = 0;
    int len;
    int lenBin;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	menu_principal (&option);
    	fflush(stdin);
        switch(option)
        {
            case 1:
            	len = controller_loadFromText("data.csv",listaEmpleados);
                if(len == 0)
                {
                	printf("\nSE LEYERON LOS DATOS");
                }
                else
                {
                	printf("\nNO SE LEYERON LOS DATOS");
                }
                system("pause");
                break;
            case 2:
            	lenBin = controller_loadFromBinary("data.bin",listaEmpleados);
            	if(lenBin == 0)
            	{
            	   printf("\nSE LEYERON LOS DATOS");
            	}
            	else
            	{
            		printf("\nNO SE LEYERON LOS DATOS");
            	}
            	system("pause");
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	system("pause");
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	system("pause");
                break;
            case 5:
                break;
            case 6:
               break;
            case 7:
               break;
            case 8:
               break;
            case 9:
               break;
            case 10:
            	printf("\nFIN");
            	break;
        }
    }while(option != 10);
    return 0;
}
