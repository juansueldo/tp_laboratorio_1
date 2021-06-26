/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	/*startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort */

	system("cls");
	setbuf(stdout,NULL);
	int option;

	LinkedList* listaEmpleados = ll_newLinkedList();

	do{
		menu_principal (&option);
	    switch(option)
	    {
	         case 1:
	        	 printf("CARGANDO DATOS...\n");
	        	 printf("ESTO PUEDE DEMORAR UNOS MINUTOS...\n");
	             if(controller_loadFromText("data.csv",listaEmpleados) == 0)
	             {
	                printf("\nSE LEYERON LOS DATOS\n");
	             }
	             else
	             {
	            	 printf("\nNO SE LEYERON LOS DATOS\n");
	             }
	             break;
	           case 2:
	        	   printf("CARGANDO DATOS...\n");
	        	   printf("ESTO PUEDE DEMORAR UNOS MINUTOS...\n");
	        	   if(controller_loadFromBinary("data.bin",listaEmpleados) == 0)
	        	   {
	            	   printf("\nSE LEYERON LOS DATOS\n");
	        	   }
	        	   else
	        	   {
	        		   printf("\nNO SE LEYERON LOS DATOS");
	        	   }
	            	break;
	            case 3:
	            	if(controller_addEmployee(listaEmpleados)==0)
	            	{
	            		printf("\nSE AGREGO UN EMPLEADO");
	            	}
	            	else
	            	{
	            		printf("\nNO SE AGREGARON EMPLEADOS");
	            	}
	            	break;
	            case 4:
	            	if(controller_editEmployee(listaEmpleados)==0)
	            	{
	            		printf("\nSE MODIFICO UN EMPLEADO");
	            	}
	            	else
	            	{
	            		printf("\nNO SE MODIFICO NINGUN EMPLEADO");
	            	}
	                break;
	            case 5:
	            	if(controller_removeEmployee(listaEmpleados)==0)
	            	{
	            		printf("\nELIMINO UN EMPLEADO");
			        }
			        else
			        {
			            printf("\nNO SE ELIMINO NINGUN EMPLEADO");
			        }
	                break;
	            case 6:
	            	if(controller_ListEmployee(listaEmpleados)!=0)
	            	{
	            		printf("\nNO HAY EMPLEADOS PARA LISTAR");
	            	}
	               break;
	            case 7:
	            	if(controller_sortEmployee(listaEmpleados)==0)
	            	{
	            		printf("\nSE ORDENARON LOS EMPLEADOS");
	            	}
	               break;
	            case 8:
	            	if(controller_saveAsText("data.csv",listaEmpleados)==0)
	            	{
	            		printf("\nSE GUARDARON LOS DATOS");
	            	}
	            	else
	            	{
	            		printf("\nNO SE GUARDARON LOS DATOS");
	            	}
	               break;
	            case 9:
	            	if(controller_saveAsBinary("data.bin" , listaEmpleados)==0)
	            	{
	            		printf("\nSE GUARDARON LOS DATOS");
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


































