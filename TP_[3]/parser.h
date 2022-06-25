
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*Con estas funciones podremos cargar todos los datos almacenados en los correspondientes archivos siempre y cuando los punteros no sean nulos
 *
 *pFile: Es el puntero a al archivo que queremos cargar en memoria
 *pArrayListPassenger: Es la lista en donde queremos guardar cada pasajero leido del archivo
 * return int: 1 si alguno de los puntero es nulo
 * 		2- Si hubo un error en la lectura de almenos un dato un pasajero
 * 		0- Si no hubo problemas en la lectura
 */

//Parsea los datos del archivo de texto "data.csv"
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

//Paresa los datos del archivo binario "data.bin"
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// @brief Con esta funcion se puede cargar en memoria el valor del contador almacenado en el puntero hacia archivo recibido
///
/// @pre
/// @post
/// @param pArchivo: Es el puntero a al archivo que queremos cargar en memoria
/// @param pContador: Es el puntero a una variable de tipo int en donde queremos almacenar el dato leido
/// @return int: 1 si alguno de los punteros es nulo o si hubo un error en la lectura del archivo. Si tiene exito devuelve 0
int parser_contadorFromBinary(FILE* pArchivo, int* pContador);
