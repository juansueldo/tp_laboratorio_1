#include "utn.h"
#include "empleados.h"

int initEmployees (eEmployee arrayEmpleados[],int tamanio)
{
	int i;
	int ret;
	ret = -1;
	if(arrayEmpleados != NULL && tamanio >0)
	{

		for (i = 0; i < tamanio; ++i)
		{
			arrayEmpleados[i].id = 0;
			strcpy(arrayEmpleados[i].name," ");
			strcpy(arrayEmpleados[i].lastName," ");
			arrayEmpleados[i].salary = 0;
			arrayEmpleados[i].sector = 0;
			arrayEmpleados[i].isEmpty=1;
		}
		ret = 0;
	}
	return ret;
}
int initSector (eSector arraySector[],int tamanio)
{
	int i;
	int ret;
	ret = -1;
	if(arraySector != NULL && tamanio >0)
	{

		for (i = 0; i < tamanio; ++i)
		{
			arraySector[i].sector = 0;
			strcpy(arraySector[i].detalleSector," ");
			arraySector[i].isEmpty=1;
		}
		ret = 0;
	}
	return ret;
}
int getNameSector (eSector arraySector[],int cant,int sector,char detalleSector[20])
{
	int ret;
	ret = -1;
	int i;
	if(arraySector != NULL && cant > 0 && (isdigit(sector)) == 0  && detalleSector != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arraySector[i].sector == sector)
			{
				if(arraySector[i].sector== 1)
				{
				strcpy(detalleSector,"RRHH");
				ret = 0;
				break;
				}
				if(arraySector[i].sector== 2)
				{
					strcpy(detalleSector,"PROGRAMADOR");
				ret = 0;
				break;
				}
				if(arraySector[i].sector== 3)
				{
				strcpy(detalleSector,"DISENIADOR");
				ret = 0;
				break;
				}
				if(arraySector[i].sector== 4)
				{
					strcpy(detalleSector,"OTROS");
				ret = 0;
				break;
				}
			}
		}
	}

	return ret;
}

int findEmpty (eEmployee arrayEmpleados[],int tamanio)
{
	int ret;
	int i;
	ret = -1;
	if(arrayEmpleados != NULL && tamanio > 0)
	{
		for (i = 0; i < tamanio; ++i)
		{
			if(arrayEmpleados[i].isEmpty==1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
int findEmployeeById(eEmployee arrayEmpleados[],int tamanio,int id)
{
	int rtn = -1;
	int i;

	if (arrayEmpleados != NULL && tamanio > 0) {
		for (i = 0; i < tamanio; i++) {
			if (arrayEmpleados[i].id == id && arrayEmpleados[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
eEmployee addEmployee (void)
{
	eEmployee auxiliar;

		if((utn_getString(auxiliar.name,30,"\nINGRESE EL NOMBRE DEL EMPLEADO: ","\nERROR. INGRESE EL NOMBRE DEL EMPLEADO: ",3,3)) != 0)
		{
			printf("\nERROR AL INGRESAR EL NOMBRE.");
		}
		if((utn_getString(auxiliar.lastName,30,"\nINGRESE EL APELLIDO DEL EMPLEADO: ","\nERROR. INGRESE EL APELLIDO DEL EMPLEADO:  ",3,3)) != 0)
		{
			printf("\nERROR AL INGRESAR EL APELLIDO");
		}
		if(utn_getFloat(&auxiliar.salary,"\nINGRESE EL SUELDO DEL EMPLEADO[1000 A 999999.99]: ","\nERROR. INGRESE EL SUELDO DEL EMPLEADO[1000 A 999999.99]: ",1000,999999,3) != 0)
		{
			printf("\nERROR AL INGRESAR EL SUELDO");
		}
		if(utn_getNumero(&auxiliar.sector,"\nINGRESE EL SECTOR [1] RRHH [2] PROGRAMADOR [3] DISENIADOR [4] OTROS: ","\nERROR. INGRESE EL SECTOR [1] RRHH [2] PROGRAMADOR [3] DISENIADOR [4] OTROS: ",1,4,3) != 0)
		{
			printf("\nERROR AL INGRESAR EL SECTOR");
		}
	return auxiliar;
}
int addEmployees (eEmployee arrayEmpleados[], int tamanio, int *pIdEmpleado)
{
	int rtn = 0;
	eEmployee auxiliarEmpleados;

	int index = findEmpty (arrayEmpleados, tamanio);

	if (index != -1)
	{

		auxiliarEmpleados = addEmployee();

		auxiliarEmpleados.isEmpty = 0;

		arrayEmpleados[index] = auxiliarEmpleados;

		rtn = 1;
	}
	if(rtn == 1)
	{
		(*pIdEmpleado)++;
		auxiliarEmpleados.id = *pIdEmpleado;
		arrayEmpleados[index] = auxiliarEmpleados;
	}

	return rtn;
}
void printEmployee (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[],int cant)
{
	char detalleSector[20];
	getNameSector(arraySector,CANT,arrayEmpleados[tamanio].sector,detalleSector);
	utn_getMayusMin (arrayEmpleados[tamanio].name, TEXTO);
	utn_getMayusMin (arrayEmpleados[tamanio].lastName, TEXTO);
	printf("\n %d     %-5s         %-6s           %-6.2f        %-8d      %s\n"
			,arrayEmpleados[tamanio].id
			,arrayEmpleados[tamanio].name
			,arrayEmpleados[tamanio].lastName
			,arrayEmpleados[tamanio].salary
			,arrayEmpleados[tamanio].sector
			,detalleSector);
}
int printEmployees (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[], int cant)
{
	int i;
	int ret;
	ret = -1;
	if(arrayEmpleados != NULL && tamanio > 0)
	{
		printf("\n*****************************************************************************\n");
		printf("\n ID    NOMBRE      APELLIDO         SUELDO        ID SECTOR        DETALLE ");
		printf("\n*****************************************************************************\n");
		for (i = 0; i < tamanio; ++i)
		{

			if(arrayEmpleados[i].isEmpty == 0)
			{
				printEmployee(arrayEmpleados,i,arraySector,cant);
			}
		}
		ret = 0;
	}
	return ret;
}
eEmployee changeEmployee(eEmployee arrayEmpleados, int campoModificar)
{
	eEmployee auxiliar = arrayEmpleados;
			switch (campoModificar)
			{
				case 1:
					if((utn_getString(auxiliar.name,30,"\nINGRESE EL NOMBRE DEL EMPLEADO: ","\nERROR. INGRESE EL NOMBRE DEL EMPLEADO: ",3,3)) != 0)
					{
						printf("\nERROR AL INGRESAR EL NOMBRE.");
					}
					fflush(stdin);
					break;
				case 2:
					if((utn_getString(auxiliar.lastName,30,"\nINGRESE EL APELLIDO DEL EMPLEADO: ","\nERROR. INGRESE EL APELLIDO DEL EMPLEADO:  ",3,3)) != 0)
					{
						printf("\nERROR AL INGRESAR EL APELLIDO");
					}
					fflush(stdin);
					break;
				case 3:
					if(utn_getFloat(&auxiliar.salary,"\nINGRESE EL SUELDO DEL EMPLEADO[1000 A 999999.99]: ","\nERROR. INGRESE EL SUELDO DEL EMPLEADO[1000 A 999999.99]: ",1000,999999.99,3) != 0)
					{
						printf("\nERROR AL INGRESAR EL SUELDO");
					}
					break;
				case 4:
					if(utn_getNumero(&auxiliar.sector,"\nINGRESE EL SECTOR [1] RRHH [2] PROGRAMADOR [3] DISENIADOR [4] OTROS: ","\nERROR. INGRESE EL SECTOR [1] RRHH [2] PROGRAMADOR [3] DISENIADOR [4] OTROS: ",1,4,3) != 0)
					{
						printf("\nERROR AL INGRESAR EL SECTOR");
					}
					break;
					default:
						break;
				}

	return auxiliar;
}
int changeEmployees (eEmployee arrayEmpleados[], int tamanio, eSector arraySector[], int cant)
{
		int rtn = -1;
		int idGen;
		int index;
		int flag = 0;
		int auxMod;
		eEmployee auxiliar;

		if(arrayEmpleados != NULL && arraySector != NULL && tamanio > 0 && cant > 0 && arrayEmpleados[tamanio].isEmpty == 0)
		{
		if (printEmployees(arrayEmpleados, tamanio, arraySector, cant) == 0)
		{
			flag = 1;
		}

		if (flag) {
			printf("\n*****************************************************************\n");
			printf("INGRESE EL ID DEL EMPLEADO A MODIFICAR:");
			scanf("%d",&idGen);

			while (findEmployeeById(arrayEmpleados, tamanio, idGen) == -1)
			{
				printf("NO EXISTE ID. REINGRESE EL ID A MODIFICAR:");
				scanf("%d",&idGen);
			}


			index = findEmployeeById(arrayEmpleados, tamanio, idGen);
			printf("\n*****************************************************************\n");
			printf("INGRESE EL CAMPO A MODIFICAR\n1. NOMBRE \n2. APELLIDO \n3. SUELDO \n4. SECTOR");
			printf("\n*****************************************************************\n");
			printf("INGRESE:");
			scanf("%d",&auxMod);
			if(utn_getRespuesta ("\nDESEA DAR LA MODICAR EL EMPLEADO? [S] SI [N] NO: ","\nERROR. DESEA DAR LA MODICAR EL EMPLEADO? [S] SI [N] NO:", 3)==0)
			{
			auxiliar = changeEmployee(arrayEmpleados[index],auxMod);
			arrayEmpleados[index] = auxiliar;
			rtn = 0;
			}

		}
		}
		else
		{

		}
		return rtn;
}
int removeEmployee (eEmployee arrayEmpleados[], int tamanio, eSector arraySector[], int cant)
{
	int rtn = -1;
	int idGen;
	int index;
	int flag = 0;

	if (printEmployees(arrayEmpleados, tamanio, arraySector, cant) == 0)
	{
		flag = 1;
	}

	if (flag) {
		printf("\n*****************************************************************\n");
		printf("\nINGRESE EL ID A DAR DE BAJA: ");
		scanf("%d",&idGen);

		while (findEmployeeById(arrayEmpleados, tamanio, idGen) == -1)
		{
			printf("NO EXISTE ID. REINGRESE EL ID A DAR DE BAJA: ");
			scanf("%d",&idGen);
		}
		index = findEmployeeById(arrayEmpleados, tamanio, idGen);
		if(utn_getRespuesta ("\nDESEA DAR LA BAJA EL EMPLEADO? [S] SI [N] NO: ","\nERROR. DESEA DAR LA BAJA EL EMPLEADO? [S] SI [N] NO: ", 3)==0)
		{
			arrayEmpleados[index].isEmpty = 1;
			rtn = 0;
		}
		else
		{
			rtn = -1;
		}

	}

	return rtn;
}
int sortEmployees (eEmployee empleados[], int tamanio, int criterio)
{
	int i;
	int j;
	int rtn = -1;
	eEmployee aux;

	if(empleados != NULL && tamanio > 0)
	{
	switch(criterio)
	{
	case 1:
		for(i = 0; i < tamanio -1;i++)
		{
			for(j = i+1; j < tamanio; j++)
			{
			if((strcmp(empleados[i].lastName,empleados[j].lastName))>0)
			{
				aux = empleados[i];
				empleados[i] = empleados[j];
				empleados[j] = aux;
			}
			else if(empleados[i].lastName == empleados[j].lastName)
			{
				if(empleados[i].sector > empleados[j].sector)
				{
					aux = empleados[i];
					empleados[i]= empleados[j];
					empleados[j] = aux;
				}
			}
			}
		}
		rtn = 0;
		break;
	case 2:
		for(i = 0; i < tamanio -1;i++)
				{
					for(j = i+1; j < tamanio; j++)
					{
					if((strcmp(empleados[i].lastName,empleados[j].lastName))<0)
					{
						aux = empleados[i];
						empleados[i] = empleados[j];
						empleados[j] = aux;
					}
					else if(empleados[i].lastName == empleados[j].lastName)
					{
						if(empleados[i].sector < empleados[j].sector)
						{
							aux = empleados[i];
							empleados[i]= empleados[j];
							empleados[j] = aux;
						}
					}
					}
				}
		rtn = 0;
		break;
	}

	}
	return rtn;
}
void getPromedio (eEmployee empleados[], int tamanio, float* promedio)
{
	int i;
	float auxPromedio = 0;
	float total = 0;
	int contEmpleados = 0;

    for (i=0; i<tamanio; i++)
    {
        total+= empleados[i].salary;
        if(empleados[i].isEmpty == 0)
        {
        	contEmpleados++;
        }
    }

    auxPromedio = total/contEmpleados;
    printf("\nLA SUMA TOTAL DE LOS SUELDOS INGRESADOS ES: %.2f",total);
    printf("\nEL PROMEDIO DE LOS SUELDOS INGRESADOS ES: %.2f\n",auxPromedio);
    *promedio = auxPromedio;
}
int printEmployeesProm (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[], int cant)
{
	int i;
	int ret = -1;
	float referencia;

	if(arrayEmpleados != NULL && tamanio > 0)
	{
		getPromedio (arrayEmpleados, tamanio, &referencia);
		printf("\n*****************************************************************************\n");
		printf("\n ID    NOMBRE      APELLIDO         SUELDO        ID SECTOR        DETALLE ");
		printf("\n*****************************************************************************\n");
		for (i = 0; i < tamanio; ++i)
		{
			if(arrayEmpleados[i].isEmpty == 0 && arrayEmpleados[i].salary >= referencia)
			{
				printEmployee(arrayEmpleados,i,arraySector,cant);
				ret = 0;
			}
		}

	}
	return ret;
}


