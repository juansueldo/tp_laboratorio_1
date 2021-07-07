/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param path char* recibe el archivo de texto a leer
 * @param pArrayListEmployee LinkedList* array de tipo LinkedList
 * @return int retorna 0 si se pudo leer el archivo de texto, y -1 sino se leyo
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * @param path char* recibe el archivo de texto a leer
 * @param pArrayListEmployee LinkedList* array de tipo LinkedList
 * @return int retorna 0 si se pudo leer el archivo de texto, y -1 sino se leyo
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de Empleado en arreglo de LinkedList.
 *
 * @param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * @return int retorna 0 si se dio el alta de manera exitosa y -1 sino se dio el alta
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Modifica los datos del empleado
 *
 * @param pArrayListEmployee LinkedList*
 * @return int retorna 0 si se modifico el empleado y -1 sino se modifico
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de un empleado de la LinkedList
 *
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si se dio de baja el empleado y -1 sino se dio la baja
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Muestra en pantalla los empleados
 *
 * @param pArrayListEmployee LinkedList*
 * @return int retorna 0 si se mostraron los empleados y -1 sino hay empleados a mostrar
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordena a los empleados
 *
 * @param pArrayListEmployee LinkedList*
 * @return int retorna 0 si se ordeno y - 1 sino se ordeno
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de las estructuras en el archivo (modo texto).
 *
 * @param path char* Path archivo donde se guardaran los datos
 * @param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * @return int retorna 0 si se guardo el archivo y -1 sino se guardo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de las estructuras en el archivo (modo texto).
 *
 * @param path char* Path archivo donde se guardaran los datos
 * @param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * @return int retorna 0 si se guardo el archivo y -1 sino se guardo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Obtiene el id siguiente al ultimo empleado ingresado
 *
 * @param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * @return retorna el siguiente id al utlimo ingresado
 */
int controller_nextId(LinkedList* pArrayListEmployee);

