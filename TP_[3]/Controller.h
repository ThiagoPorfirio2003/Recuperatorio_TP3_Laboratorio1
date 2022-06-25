#include "LinkedList.h"
#include "Passenger.h"

/// @brief Con esta funcion se puede cargar todos los usuarios, guardados en un archivo de texto tipo CSV, en una LinkedList.
/// Ademas va mostrando los datos de cada pasajero cargado
///
/// @pre
/// @post
/// @param path: Es el nombre del archivo del cual queremos obtener la informacion
/// @param pArrayListPassenger: Es el puntero a una LinkedList en la cual queremos guardar todos los datos obtenidos del archivo
/// @return int: 1 si alguno de los punteros es nulo, 2 si hubo un error en la lectura de almenos un dato, 0 si se pudieron obtener todos los datos
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/// @brief Con esta funcion se puede cargar todos los usuarios, guardados en un archivo binario, en una LinkedList
/// Ademas va mostrando los datos de cada pasajero cargado
/// @pre
/// @post
/// @param path: Es el nombre del archivo del cual queremos obtener la informacion
/// @param pArrayListPassenger: Es el puntero a una LinkedList en la cual queremos guardar todos los datos obtenidos del archivo
/// @return int: 1 si alguno de los punteros es nulo, 2 si hubo un error en la lectura de almenos un dato, 0 si se pudieron obtener todos los datos
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief Con esta funcion se puede agregar un nuevo pasajero, asigandole el ID de manera automatica
///
/// @pre
/// @post
/// @param pArrayListPassenger: Puntero hacia la estructura en donde se depositaran los datos del nuevo pasajero
/// @param contadorId: Es puntero hacia un contador que posee el numero correspondiente al id del nuevo pasajero
/// @return int: 1 si alguno de los punteros es nulo, si no hay espacio en memoria suficiente o si hubo un error en la toma de los datos,
/// caso contrario devuelve 0
int controller_addPassenger(LinkedList* pArrayListPassenger, int *contadorId);

/// @brief Con esta funcion se puede obtener la posicion de un pasajero en un array mediante su ID
///
/// @pre
/// @post
/// @param pArrayListPassenger: Es el puntero a la LinkedList en donde esta el pasajero que quiero encontrar
/// @param idAEncontrar: Es el id correspondiente al pasajero a encontrar
/// @return int: -1 Si el puntero es nulo, o si idAEncontrar es negativo. -2 si no se encuentra al pasajero correspondiente al id.
/// En caso de encontrar al pasajero devuelve su posicion
int controller_findPassengerById(LinkedList* pArrayListPassenger, int idAEncontrar);

/// @brief Con esta funcion se puede modificar alguno de los siguientes aspectos de un pasajero:
/// - Nombre
/// - Apellido
/// - Precio de vuelo
/// - Tipo de pasajero
/// - Codigo de vuelo
/// - Estado de vuelo
///
/// Ademas de mostrar todos sus datos antes de elegir cual modificar
/// @pre
/// @post
/// @param pArrayListPassenger: Es el puntero a la LinkedList en donde se encuentra el pasajero que queremos almacenar
/// @return int: 1 si el puntero es nulo, -1 si hubo un error en la modificacion del dato del pasajero o 0 si tuvo exito en la modificacion
int controller_editPassenger(LinkedList* pArrayListPassenger);

/// @brief Con esta funcion se puede eliminar a un pasajero teniendo su ID, pero antes apareceran los datos de este y una pregunta de confirmacion
///
/// @pre
/// @post
/// @param pArrayListPassenger: El puntero a la LinkedList en donde esta el pasajero que se desea eliminar
/// @return int: -1 si el puntero es nulo o no se encuentra al pasajero que se quiere eliminar, 0 si se ha logrado eliminar al pasajero,
///1 si ocurrio un error durante la eliminacion, o 2 si se cancelo la eliminacion del pasajero
int controller_removePassenger(LinkedList* pArrayListPassenger);

/// @brief Con esta funcion se puede mostrar un listado de todos los pasajeros cargados en el momento de la llamada
///
/// @pre
/// @post
/// @param pArrayListPassenger: Puntero hacia la LinkedList en donde estan cargados todos los pasajeros
/// @return int: 1 si el puntero es nulo, 0 si no hubo errores, 2 si no se pudo mostrar al menos un pasajero
int controller_ListPassenger(LinkedList* pArrayListPassenger);


/// @brief Con esta funcion se puede ordenar de manera ascendente o descendente a los pasajeros, segun su id o apellido y nombre
///
/// @pre
/// @post
/// @param pArrayListPassenger: Es el puntero a la LinkedList donde estan los pasajeros que se van a ordenar
/// @return int: -1 si el puntero es nulo, 0 si no hubo problemas y 1 si hubo un error al elejir los criterios de ordenamiento
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// @brief Con esta funcion se pueden guardar todos los pasajeros cargados en la memoria en un archivo de texto tipo CSV, reemplazando a los que ya estaban en el archivo
/// Ademas muestra todos los pasajeros que se van guardando si se activa la funcion
///
/// @pre
/// @post
/// @param path: El nombre del archivo en donde se guardaran todos los pasajeros
/// @param pArrayListPassenger: Es el puntero hacia la linkedList en donde estan todos los pasajeros cargados
/// @param mostrarPasajeros: Si es 1 muestra cada pasajero guardado, si es 0 no lo muestra
/// @return int: 1 si alguno de los punteros es nulo o si mostrarPasajero no es ni 1 ni 0. 2 Si hubo un error en el guardado de almenos un dato. 0 Si se guardo todo correctamente
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,int mostrarPasajeros);

/// @brief Con esta funcion se pueden guardar todos los pasajeros cargados en la memoria en un archivo binario, reemplazando a los que ya estaban en el archivo.
/// Ademas muestra todos los pasajeros que se van guardando si se activa la funcion
///
/// @pre
/// @post
/// @param path: El nombre del archivo en donde se guardaran todos los pasajeros
/// @param pArrayListPassenger: Es el puntero hacia la linkedList en donde estan todos los pasajeros cargados
/// @param mostrarPasajeros: Si es 1 muestra cada pasajero guardado, si es 0 no lo muestra
/// @return int: 1 si alguno de los punteros es nulo o si mostrarPasajero no es ni 1 ni 0. 2 Si hubo un error en el guardado de almenos un dato. 0 Si se guardo todo correctamente
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, int mostrarPasajeros);

/// @brief Con esta funcion se pueden guardar todos los pasajeros cargados en la memoria en un archivo de texto tipo CSV, agregandose a los que ya estaban en el archivo
/// Ademas muestra todos los pasajeros que se van guardando si se activa la funcion
/// @pre
/// @post
/// @param path: El nombre del archivo en donde se guardaran todos los pasajeros
/// @param pArrayListPassenger: Es el puntero hacia la linkedList en donde estan todos los pasajeros cargados
/// @param mostrarPasajeros: Si es 1 muestra cada pasajero guardado, si es 0 no lo muestra
/// @return int: 1 si alguno de los punteros es nulo o si mostrarPasajero no es ni 1 ni 0. 2 Si hubo un error en el guardado de almenos un dato. 0 Si se guardo todo correctamente
int controller_addAsText(char* path , LinkedList* pArrayListPassenger, int mostrarPasajeros);

/// @brief Con esta funcion se pueden guardar todos los pasajeros cargados en la memoria en un archivo binario, agregandose a los que ya estaban en el archivo
/// Ademas muestra todos los pasajeros que se van guardando si se activa la funcion
/// @pre
/// @post
/// @param path: El nombre del archivo en donde se guardaran todos los pasajeros
/// @param pArrayListPassenger: Es el puntero hacia la linkedList en donde estan todos los pasajeros cargados
/// @param mostrarPasajeros: Si es 1 muestra cada pasajero guardado, si es 0 no lo muestra
/// @return int: 1 si alguno de los punteros es nulo o si mostrarPasajero no es ni 1 ni 0. 2 Si hubo un error en el guardado de almenos un dato. 0 Si se guardo todo correctamente
int controller_addAsBinary(char* path , LinkedList* pArrayListPassenger, int mostrarPasajeros);

/// @brief Con esta funcion se consigue el id correspondiente al siguiente pasajero a ser ingresado, el cual se encuentra en un archivo binario,
/// con el fin de poseer id correspondiente sin importar de que se cierre o no el programa
///
/// @pre
/// @post
/// @param path: Es el nombre del archivo que se desea leer
/// @param pIdContadorNumero: Es un puntero hacia la variable int en donde se guardara el valor leido del archivo
/// @return int: 1 Si alguno de los punteros es nulo o su hubo un error en la carga del valor del id. En caso de exito devuele un 0
int controller_loadFromBinaryContador(char* path , int* pIdContadorNumero);

/// @brief Con esta funcion se guarda el id correspondiente al siguiente pasajero a ser ingresado, en un archivo binario, sirve para que se conserve el valor del contador de IDs a pesar
/// de que se cierre el programa. Reescribe todo el archivo
///
/// @pre
/// @post
/// @param path: Es el nombre del archivo que se desea escribir
/// @param pIdContadorNumero: Es un puntero hacia la variable int en donde esta valor que se desea escribir en el archivo
/// @return int: 1 Si alguno de los punteros es nulo o si hubo un error a la hora de escribir el archivo. Caso contrario devuele un 0
int controller_saveAsBinaryContador(char* path , int* idContadorNumero);

/// @brief Con esta funcion se pueden reescrirbir todos los datos de los archivos binario y de texto tipo CSV o solo agregar datos,
///  mostrando si se quiere o no los datos mientras de almacenan
///
/// @pre
/// @post
/// @param pathCSV: Es el nombre del archivo de texto tipo CSV
/// @param pathBinario: Es el nombre del archivo binario
/// @param pArrayListPassenger: Es el puntero hacia la LinkedList en donde estan todos los pasajeros a ser guardados
/// @param modoGuardado: Si es 1 se reescribiran todos los datos almacenados en cada archivo, si es un 0 solo se agregaran datos.
/// @param mostrarBin: Si es 1 se muestran los datos del archivo binario mientras se van guardando, si es un 0 no se muestran
/// @param mostrarTxt: Si es 1 se muestran los datos del archivo de texto tipo CSV mientras se van guardando, si es un 0 no se muestran
/// @return int: 1 Si todos los punteros son nulos o si los otros parametros reciben unt valor que no sea 1 o 0. 2 si hubo un error en almenos el guardado de un dato.
/// 0 si se tuvo exito en el guardado de todos los archivos
int controller_saveTextAndBinary(char* pathCSV, char* pathBinario, LinkedList* pArrayListPassenger, int modoGuardado, int mostrarBin, int mostrarTxt);


