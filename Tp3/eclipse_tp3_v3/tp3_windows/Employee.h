#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "utn.h"
#include "LinkedList.h"

#define EMPLOYEE_NOMBRE_MAX 60
#define EMPLOYEE_HORA_MAX 500
#define EMPLOYEE_SUELDO_MAX 900000

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
/** brief Constructor que obtiene el espacio en memoria para los empleados
 * @return retorna NULL sino se pudo reservar espacio
 */
Employee* employee_new();
/** \brief Nueva estructura de Empleado ingresando los valores por parametros.
 *
 * @param idStr puntero que recibe el ID a cargar.
 * @param nombreStr puntero que recibe el nombre a cargar.
 * @param horasTrabajadasStr  puntero que recibe las horas trabjadas a cargar.
 * @param sueldoStr  puntero que recibe el sueldo a cargar.
 * @return retora el Empleado con los datos que se recibieron por puntero, en caso contrario retorna NULL.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief Libera la memoria que se asingno a un empleado
 * @param this direccion de memoria de un Empleado.
 */
void employee_delete(Employee *this);
/** \brief Coloca el ID a una estructura Empleado.
 * @param this puntero a Empleado.
 * @param id valor que se colocara en el ID del empleado
 * @return retorna 0 si se pudo colocar el ID, y -1 si no se coloco
 */
int employee_setId(Employee* this,int id);
/** \brief Obtiene el ID de una estructura Empleado.
 * @param this puntero a Empleado.
 * @param ID puntero al ID del empleado
 * @return retorna 0 Si pudo obtener el ID y -1 si no pudo obtener el ID
 */
int employee_getId(Employee* this,int* id);
/** \brief Coloca el NOMBRE del empleado en una estructura Empleado.
 * @param this puntero a Empleado.
 * @param nombre cadena que se colocara el NOMBRE del empleado
 * @return retorna 0 si se pudo colocar el NOMBRE, y -1 si no se coloco
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief Obtiene el NOMBRE del empleado de la estructura Empleado.
 *
 * @param this puntero a Empleado.
 * @param nombre puntero a la cadena NOMBE del empleado
 * @return retorna 0 Si pudo obtener el NOMBRE y -1 si no pudo obtener el NOMBRE
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Coloca las HORAS TRABAJADAS del empleado en una estructura Empleado.
 *
 * @param this puntero a Empleado.
 * @param horasTrabajadas valor que se colocara en las HORAS TRABAJADAS del empleado
 * @return retorna 0 si se pudo colocar las HORAS TRABAJADAS, y -1 si no se coloco
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Obtiene las HORAS TRABAJADAS del empleado de la estructura Empleado.
 *
 * @param this puntero a Empleado.
 * @param horasTrabajadas puntero a las HORAS TRABAJADAS del empleado
 * @return retorna 0 Si pudo obtener las HORAS TRABAJADA y -1 si no pudo obtener las HORAS TRABAJADA
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Coloca el SUELDO del empleado en una estructura Empleado.
 * @param this puntero a Empleado.
 * @param sueldo valor que se colocara en el SUELDO del empleado
 * @return retorna 0 si se pudo colocar el SUELDO, y -1 si no se coloco
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Obtiene el SUELDO del empleado de la estructura Empleado.
 * @param this puntero a Empleado.
 * @param sueldo puntero al SUELDO del empleado
 * @return retorna 0 Si pudo obtener el SUELDO y -1 si no pudo obtener el SUELDO
 */
int employee_getSueldo(Employee* this,int* sueldo);
/**brief Muestra en pantalla un empleado
 *	@param this puntero a Empleado.
 *	@return retorna 0 Si se pudo mostrar el empleado y -1 si no se pudo mostrar
 */
int employee_print(Employee* this);
/**brief Modifica los datos que se tienen de un empleado
 *@param this puntero a Empleado.
 *@param opcion valor que determina que campo se va a modificar
 *@return retorna 0 si se modifico y -1 sino
 */
int employee_change (Employee* this, int opcion);
/**brief Compara dos elementos por el ID
 *@param pThis1 puntero a void
 *@param pThis2 puntero a void
 *@return retorna cero si los ID son iguales, -1 si el primero es mayor al segundo y 1 si el segundo es mayor al primero
 */
int employee_compareByID(void* pThis1, void* pThis2);
/**brief Compara dos elemetos por el nombre
 *@param pThis1 puntero a void
 *@param pThis2 puntero a void
 *@return retorna cero si los ID son iguales, -1 si el primero es mayor al segundo y 1 si el segundo es mayor al primero
 */
int employee_compareBynombre(void* pThis1, void* pThis2);
/**brief Compara dos elementos por las horas trabajadas
 *@param pThis1 puntero a void
 *@param pThis2 puntero a void
 *@return retorna cero si las horas trabajadas son iguales, -1 si el primero es mayor al segundo y 1 si el segundo es mayor al primero
 */
int employee_compareByhorasTrabajadas(void* pThis1, void* pThis2);
/**brief Compara dos elementos por el Sueldo
 *@param pThis1 puntero a void
 *@param pThis2 puntero a void
 *@return retorna cero si los sueldos son iguales, -1 si el primero es mayor al segundo y 1 si el segundo es mayor al primero
 */
int employee_compareBysueldo(void* pThis1, void* pThis2);


#endif // employee_H_INCLUDED
