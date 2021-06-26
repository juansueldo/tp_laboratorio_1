#include "menu.h"

void menu_principal (int* opcion)
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
void menu_editarEmpleado (int *opcion)
{
	printf("\n ");
	printf("\n |***********************************************************************************|\n");
	printf(" |                                  MENU EDCION                                      |\n");
	printf(" |***********************************************************************************|\n");
	printf(" |  [1] Editar nombre.                                                               |\n");
	printf(" |  [2] Editar horas trabajadas.                                                     |\n");
	printf(" |  [3] Editar sueldo.                                                               |\n");
	printf(" |  [4] Volver atras.                                                                |\n");
	printf(" |***********************************************************************************|\n\n");
utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 4, 3);

}
void menu_ordenamiento (int *opcion)
{
	printf("\n ");
	printf("\n |***********************************************************************************|\n");
	printf(" |                                  ORDENAR                                          |\n");
	printf(" |***********************************************************************************|\n");
	printf(" |  [1] Ordenar por ID.                                                              |\n");
	printf(" |  [2] Ordenar por nombre.                                                          |\n");
	printf(" |  [3] Ordenar por horas trabajadas.                                                |\n");
	printf(" |  [4] Ordenar por sueldo.                                                          |\n");
	printf(" |  [5] Volver atras.                                                                |\n");
	printf(" |***********************************************************************************|\n\n");
	utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 5, 3);
}
