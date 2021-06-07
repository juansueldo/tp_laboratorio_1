#include "menu.h"

void menu_principal (int *opcion)
{
	printf("\n ");
    printf("\n |***********************************************************************************|\n");
    printf(" |                                  MENU PRINCIPAL                                   |\n");
    printf(" |***********************************************************************************|\n");
    printf(" |  [1] Cargar los datos de los Empleados desde el archivo data.csv (modo texto).    |\n");
    printf(" |  [2] Cargar los datos de los Empleados desde el archivo data.bin (modo binario).  |\n");
    printf(" |  [3] Alta de Empleado.                                                            |\n");
    printf(" |  [4] Modificar datos de Empleado.                                                 |\n");
    printf(" |  [5] Baja de Empleado.                                                            |\n");
    printf(" |  [6] Listar Empleados.                                                            |\n");
    printf(" |  [7] Ordenar Empleados.                                                           |\n");
    printf(" |  [8] Guardar los datos de los Empleados en el archivo data.csv (modo texto).      |\n");
    printf(" |  [9] Guardar los datos de los Empleados en el archivo data.bin (modo binario).    |\n");
    printf(" | [10] Salir del programa                                                           |\n");
    printf(" |***********************************************************************************|\n\n");
	utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 10, 3);
}
