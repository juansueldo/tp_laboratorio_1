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
    int option;
    int flag = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	menu_principal (&option);
        switch(option)
        {
            case 1:
                if(flag && controller_loadFromText("data.csv",listaEmpleados) == 0)
                {
                	printf("\nSE LEYERON LOS DATOS\n");
                }
                else
                {
                	printf("\nNO SE LEYERON LOS DATOS\n");
                }
                break;
            case 2:
            	if(flag && controller_loadFromBinary("Prueba.bin",listaEmpleados) == 0)
            	{
            	   printf("\nSE LEYERON LOS DATOS\n");
            	}
            	else
            	{
            		printf("\nNO SE LEYERON LOS DATOS");
            	}
            	break;
            case 3:
            	if(flag && controller_addEmployee(listaEmpleados)==0)
            	{
            		printf("\nSE AGREGO UN EMPLEADO");
            	}
            	else
            	{
            		printf("\nNO SE AGREGARON EMPLEADOS");
            	}
            	break;
            case 4:
            	if(flag && controller_editEmployee(listaEmpleados)==0)
            	{
            		printf("\nSE MODIFICO UN EMPLEADO");
            	}
            	else
            	{
            		printf("\nNO SE MODIFICO NINGUN EMPLEADO");
            	}
                break;
            case 5:
            	if(flag && controller_removeEmployee(listaEmpleados)==0)
            	{
            		printf("\nELIMINO UN EMPLEADO");
		        }
		        else
		        {
		            printf("\nNO SE ELIMINO NINGUN EMPLEADO");
		        }
                break;
            case 6:
            	if(flag && controller_ListEmployee(listaEmpleados)!=0)
            	{
            		printf("\nNO HAY EMPLEADOS PARA LISTAR");
            	}
               break;
            case 7:
            	if(flag && controller_sortEmployee(listaEmpleados)==0)
            	{
            		printf("\nSE ORDENARON LOS EMPLEADOS");
            	}
               break;
            case 8:
            	if(flag && controller_saveAsText("Prueba.csv",listaEmpleados)==0)
            	{
            		printf("\nSE GUARDARON LOS DATOS");
            		flag = 0;
            	}
            	else
            	{
            		printf("\nNO SE GUARDARON LOS DATOS");
            	}
               break;
            case 9:
            	if(controller_saveAsBinary("Prueba.bin" , listaEmpleados)==0)
            	{
            		printf("\nSE GUARDARON LOS DATOS");
            		flag = 0;
            	}
            	else
            	{
            		printf("\nNO SE GUARDARON LOS DATOS");
            	}
               break;
            case 10:
            	printf("\nFIN");
            	ll_deleteLinkedList(listaEmpleados);
            	break;
        }
    }while(option != 10);
    return 0;
}
