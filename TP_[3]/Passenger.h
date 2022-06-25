/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	int statusFlight;

}Passenger;

/// @brief Segun el contenido que reside en estadoVueloString que recibe asigna un valor a estadoVueloNumero, de la siguiente manera:
///- "Aterrizado" = 1
///- "En horario" = 2
///- "Demorado" = 3
///- "En vuelo" = 4
/// Si no corresponde a ninguna de estas opciones no asignara ningun valor
/// @pre
/// @post
/// @param estadoVueloString: Puntero a una cadena de caracteres que segun el estado de vuelo que contenga le asignara un valor u otro a estadoVueloNumero
/// @param estadoVueloNumero: Puntero a una variable de tipo int que almacenara un valor de acuerdo al contenido de estadoVueloString
/// @return int: 1 Si alguno de los 2 punteros son nulos o si estadoVueloString no corresponde a alguno de los estados validos,
/// de darse esto no le asignara ningun valor a estadoVueloNumero. Pero si nada de esto ocurre devuelve un 0
int Passenger_verificarYTransfomarEstadoVueloStringAInt(char* estadoVueloString, int* estadoVueloNumero);

/// @brief Segun el contenido que reside en tipoPasajeroString que recibe asigna un valor a tipoPasajeroNumero, de la siguiente manera:
///- "FirstClass" = 1
///- "ExecutiveClass" = 2
///- "EconomyClass" = 3
///
/// Si no corresponde a ninguna de estas opciones no asignara ningun valor
/// @pre
/// @post
/// @param tipoPasajeroString: Puntero a una cadena de caracteres que segun el tipo de pasajero que contenga le asignara un valor u otro a tipoPasajeroNumero
/// @param tipoPasajeroNumero: Puntero a una variable de tipo int que almacenara un valor de acuerdo al contenido de tipoPasajeroString
/// @return int: 1 Si alguno de los 2 punteros son nulos o si tipoPasajeroString no corresponde a alguno de los estados validos,
/// de darse esto no le asignara ningun valor a estadoVueloNumero. Pero si nada de esto ocurre devuelve un 0
int Passenger_verificarTtransfomarTipoPasajeroStringAInt(char* tipoPasajeroString, int* tipoPasajeroNumero);

/// @brief Segun el contenido que reside en estadoVueloNumero que recibe asigna un valor a estadoVueloString, de la siguiente manera:
///- 1 = "Aterrizado"
///- 2 = "En horario"
///- 3 = "Demorado"
///- 4 = "En vuelo"
/// Si no corresponde a ninguna de estas opciones no asignara ningun valor
/// @pre
/// @post
/// @param estadoVueloString: Puntero a una cadena de caracteres que segun el valor de estadoVueloNumero se le asignara un valor u otro
/// @param estadoVueloNumero: Puntero a una variable de tipo int que segun su valor se le asignara un dato u otro a estadoVueloString
/// @return int: 1 Si alguno de los 2 punteros son nulos o si estadoVueloNumero no corresponde a alguno de los estados validos,
/// de darse esto no le asignara ningun valor a estadoVueloNumero. Pero si nada de esto ocurre devuelve un 0
int Passenger_verificarYTransfomarEstadoVueloIntAString(char* estadoVueloString, int estadoVueloNumero);

/// @brief Segun el contenido que reside en tipoPasajeroNumero que recibe asigna un valor a tipoPasajeroString, de la siguiente manera:
///- 1 = "FirstClass"
///- 2 = "ExecutiveClass"
///- 3 = "EconomyClass"
/// Si no corresponde a ninguna de estas opciones no asignara ningun valor
///
/// @pre
/// @post
/// @param tipoPasajeroString: Puntero a una cadena de caracteres que segun el valor de tipoPasajeroNumero se le asignara un valor u otro
/// @param tipoPasajeroNumero: Puntero a una variable de tipo int que segun su valor se le asignara un dato u otro a tipoPasajeroString
/// @return int: 1 Si alguno de los 2 punteros son nulos o si tipoPasajeroNumero no corresponde a alguno de los estados validos,
/// de darse esto no le asignara ningun valor a estadoVueloNumero. Pero si nada de esto ocurre devuelve un 0
int Passenger_verificarYTransfomarTipoPasajeroIntAString(char* tipoPasajeroString, int tipoPasajeroNumero);


/// @brief Con esta funcion se puede transformar el idNumerico en en un string almacenandolo en la direccion a la que apunta el puntero idString
///
/// @pre
/// @post
/// @param idString: Es el puntero a la cadena de caracteres en donde se almacenara el id
/// @param idNumero: Es el numero a convertir en string
/// @return int: 1 si el puntero idString es nulo o si no se pudo convertir el numero en string
int Passenger_transformarIDaString(char* idString, int idNumero);

/// @brief Con esta funcion se puede transformar el valor de precioNumero en un string que sera almacenado en direccion a la apunta el puntero precioString
///
/// @pre
/// @post
/// @param precioString: Es el puntero a la cadena de caracteres en donde se almacenara el precio
/// @param precioNumero: Es el numero a convertir en string
/// @return int: 1 si el puntero precioString es nulo o si no se pudo convertir el numero en string
int Passenger_transformarPrecioaString(char* precioString, float precioNumero);

/// @brief Con esta funcion se podra verificar si una cadena alfanumerica es un codigo con el siguiente formato "AA1234A"
///
/// @pre
/// @post
/// @param cadenaAlfanumerica: Es el puntero a una cadenaAlfanumerica que sera analizada
/// @return int: 1 si la cadena es nula o no cumple con las condiciones para ser un codigo de vuelo aceptable,
/// de lo contrario devolvera un 0
int Passenger_verificarSerCodigoDeVuelo(char* cadenaAlfanumerica);

/// @brief Con esta funcion se puede eliminar a un pasajero
///
/// @pre
/// @post
/// @param pasajeroAEliminar: Puntero hacia la direccion de memoria del pasajero que se quiere eliminar
/// @return int: 1 si el puntero recibido es nulo o 0 si no lo es
int Passenger_delete(Passenger* pasajeroAEliminar);

/// @brief Esta funcion es el constructor de datos de tipo Passenger
///
/// @pre
/// @post
/// @return Puntero a Passenger: Nulo si no se pudo crear un nuevo pasajero, pero si se pudo devuelve el puntero a ese pasajero
Passenger* Passenger_new();

/// @brief Con esta funcion se crea una nueva variable de tipo Passenger ademas de cargarle datos que se le son pasados por parametros
///
/// @pre
/// @post
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param tipoPasajeroStr
/// @param codigoVueloStr
/// @param statusFlight
/// @return Puntero a Passenger: Nulo si no se pudo crear un nuevo pasajero, o si alguno de los punteros son nulos, o si alguno de los datos no cumplen con sus requisitos.
/// Si no hay problema con esto devuelve el puntero al nuevo pasajero
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlight);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*Todas las funciones de tipo set asignan el valor recibido en el campo correspondiente en caso de que no hubo inconvenientes
 *Devolviendo 1 si alguno de los punteros es nulo o 0 si todo salio bien
 *
 *Todas las funciones de tipo get depositan el valor de un campo en la variable correspondiente en caso de que no hubo inconvenientes
 *Devolviendo 1 si alguno de los punteros es nulo o 0 si todo salio bien
 *
 *this: Es el puntero al pasajero con el que vamos a trabajar
 *
 */


int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoDeVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoDeVuelo);

int Passenger_setAll(Passenger* pasajeroASetear, int id, char* nombre,char* apellido, char* codigoVuelo, int tipoPasajero, float precio, int estadoVuelo);
int Passenger_getAll(Passenger* pPasajeroAGetear, int* id, char* nombre,char* apellido, char* codigoVuelo, int* tipoPasajero, float* precio, int* estadoVuelo);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*Todas las funciones tipo "modificar": Asignan un valor al campo correspondiente, pidiendo este nuevo valor y validando que el nuevo dato sea valido
 *
 *mensaje: Es el mensaje que aparecera solo la primera vez que se pide el datos
 *mensajeError: Es el mensaje que aparecera cada vez que se ingrese un dato invalido. (En el caso del codigo de vuelo, este mensaje aparecera cuando se ingrese una cadena que no sea alfanumerica)
 * mensajeErrorSinMemoria: Es el mensaje que aparecera si no hay memoria suficiente para trabajar
 *pasajeroAManipular: Es un puntero hacia el pasajero con el que vamos a trabajar
 *mensajeCodigoInvalido: Es el mensaje que aparecera cuando el codigo de vuelo ingresado sea invalido
 *
 *retorno int: 1 si alguno de los punteros es nulo o si no hay espacio en memoria para trabajar o si no se pudo asignar el nuevo valor,
 *caso contrario a todo esto, se devolvera un 0
 */



int Passenger_modificarNombre(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);
int Passenger_ModificarApellido(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria);
int Passenger_ModificarCodigoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria, char* mensajeCodigoInvalido);
int Passenger_ModificarTipoPasajero(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);
int Passenger_ModificarPrecioVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);
int Passenger_ModificarEstadoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


/// @brief Con esta funcion se puede pedir todos los datos de un pasajero
///
/// @pre
/// @post
/// @param nombre: Puntero en donde se almacenara el nombre ingresado
/// @param apellido: Puntero en donde se almacenara el apellido ingresado
/// @param precio: Puntero en donde se almacenara el precio ingresado
/// @param tipoPasajero: Puntero en donde se almacenara el tipo de pasajero ingresado
/// @param codigoVuelo: Puntero en donde se almacenara el codigo de vuelo ingresado
/// @param statusFlight: Puntero en donde se almacenara el estado de vuelo ingresado
/// @return int: 1 si alguno de los punteros es nulo o si no hay espacio en memoria suficiente, de lo contrario de vuelve un 0
int Passenger_askOnePassengerData(char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoVuelo, int* statusFlight);

/// @brief Con esta funcion se puede mostrar los datos de un pasajero siempre y cuando haya salido todo bien
///
/// @pre
/// @post
/// @param pPasajeroAMostrar: Es el puntero al pasajero que se va a mostrar
/// @return int: 1 si el puntero el nulo o si el estado de vuelo o tipo de pasajero son invalidos, caso contrario devuelve un 0
int Passenger_MostrarUnPasajero(Passenger* pPasajeroAMostrar);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*Todas las funciones "saveAs" guardan todos los pasajeros presentes en la memoria ordendados en una linkedList al momento de ser llamadas
 * pFile: El puntero al archivo donde guardaran los datos
 * pArrayListPassenger: El puntero al linkedList en donde estan todos pasajeros presentes en la memoria
 * estadoGuardarTodo: Puede ser 1 si se quiere guardar el encabezado del archivo CSV o 0 si no se lo quiere guardar. (Exclusiva de saveAsText)
 * mostrarPasajeros: Puede ser 1 si se quiere mostrar los datos del pasajero guardado o 0 si no se desea hacer eso
 * return int: 1 si alguno de los punteros es nulo o si la opcion de guardado o mostrar poseen un valor que no sea 0 o 1, en otro caso devuelve
 * 2 si hubo un error en el guardado de al menos un dato, pero si no hubo ninguno de estos errores devuelve un 0
 */

int Passenger_saveAsText(FILE* pFile , LinkedList* pArrayListPassenger, int estadoGuardarTodo, int mostrarPasajeros);
int Passenger_saveAsBinary(FILE* pFile , LinkedList* pArrayListPassenger, int mostrarPasajero);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


/// @brief Con esta funcion se puede guardar el valor actual del contador de IDs
///
/// @pre
/// @post
/// @param pFile: Puntero hacia el archivo en donde se guardara el nuevo valor del contador
/// @param contadorIdAguardar: Puntero hacia el contador que se desea guardar
/// @return int: 1 si alguno de los punteros es nulo o si hubo un error a la hora de guardar al menos un dato en el archivo, caso contrario devuelve un 0
int Passenger_saveContadorIdAdBinary(FILE* pFile , int* contadorIdAguardar);



int Passenger_CompararPorApellidoYNombre(void* pPrimerPasajero, void* pSegundoPasajero);
int Passenger_CompararPorId(void* pPrimerPasajero, void* pSegundoPasajero);


#endif /* PASSENGER_H_ */
