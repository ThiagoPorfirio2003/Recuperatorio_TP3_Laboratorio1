#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

#define CANTIDAD_MAXIMA_CARACTERES_NOMBRE 50
#define CANTIDAD_MAXIMA_CARACTERES_APELLIDO 50
#define CANTIDAD_CARACTERES_NOMBRE 50
#define CANTIDAD_CARACTERES_APELLIDO 50
#define VUELO_PRECIO_MINIMO 10000
#define VUELO_PRECIO_MAXIMO 100000000
#define CANTIDAD_CIFRAS_PRECIO 30
#define TIPO_PASAJERO_OPCION_MINIMA 1
#define TIPO_PASAJERO_OPCION_MAXIMA 3
#define ESTADO_VUELO_OPCION_MINIMA 1
#define ESTADO_VUELO_OPCION_MAXIMA 4
#define CANTIDAD_MAXIMA_CIFRAS_ID 20
#define CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO 7
#define CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO 7
#define CARACTERES_TOTALES_CODIGOVUELO 9
#define CARACTERES_MARCO_CODIGOVUELO 15
#define CARACTERES_CODIGOVUELO 10
#define CARACTERES_TIPO_PASAJERO_PALABRA 20
#define CARACTERES_ESTADO_VUELO_PALABRA 20
#define MINIMA_OPCION_MODIFICAR_PASAJERO 1
#define MAXIMA_OPCION_MODIFICAR_PASAJERO 5

int Passenger_verificarYTransfomarEstadoVueloStringAInt(char* estadoVueloString, int* estadoVueloNumero)
{
	int retorno;

	retorno=1;

	if(estadoVueloString != NULL && estadoVueloNumero != NULL)
	{
		retorno=0;
		if(!strcmp(estadoVueloString, "Aterrizado"))
		{
			*estadoVueloNumero=1;
		}
		else
		{
			if(!strcmp(estadoVueloString, "En Horario"))
			{
				*estadoVueloNumero=2;
			}
			else
			{
				if(!strcmp(estadoVueloString, "Demorado"))
				{
					*estadoVueloNumero=3;
				}
				else
				{
					if(!strcmp(estadoVueloString, "En Vuelo"))
					{
						*estadoVueloNumero=4;
					}
					else
					{
						retorno=1;
					}
				}
			}
		}
	}
	return retorno;
}

int Passenger_verificarYTransfomarTipoPasajeroStringAInt(char* tipoPasajeroString, int* tipoPasajeroNumero)
{
	int retorno;

	retorno=1;

	if(tipoPasajeroString != NULL && tipoPasajeroNumero != NULL)
	{
		retorno=0;
		if(!strcmp(tipoPasajeroString, "FirstClass"))
		{
			*tipoPasajeroNumero=1;
		}
		else
		{
			if(!strcmp(tipoPasajeroString, "ExecutiveClass"))
			{
				*tipoPasajeroNumero=2;
			}
			else
			{
				if(!strcmp(tipoPasajeroString, "EconomyClass"))
				{
					*tipoPasajeroNumero=3;
				}
				else
				{
					retorno=1;
				}
			}
		}
	}
	return retorno;
}


int Passenger_verificarYTransfomarEstadoVueloIntAString(char* estadoVueloString, int estadoVueloNumero)
{
	int retorno;

	retorno=1;

	if(estadoVueloString != NULL)
	{
		retorno=0;
		switch(estadoVueloNumero)
		{
			case 1:
				strcpy(estadoVueloString, "Aterrizado");
				break;

			case 2:
				strcpy(estadoVueloString, "En Horario");
				break;

			case 3:
				strcpy(estadoVueloString, "Demorado");
				break;

			case 4:
				strcpy(estadoVueloString, "En Vuelo");
				break;

			default:
				retorno=1;
				break;
		}
	}
	return retorno;
}

int Passenger_verificarYTransfomarTipoPasajeroIntAString(char* tipoPasajeroString, int tipoPasajeroNumero)
{
	int retorno;

	retorno=1;

	if(tipoPasajeroString != NULL)
	{
		retorno=0;
		switch(tipoPasajeroNumero)
		{
			case 1:
				strcpy(tipoPasajeroString, "FirstClass");
				break;

			case 2:
				strcpy(tipoPasajeroString, "ExecutiveClass");
				break;

			case 3:
				strcpy(tipoPasajeroString, "EconomyClass");
				break;

			default:
				retorno=1;
				break;
		}
	}
	return retorno;
}


int Passenger_transformarIDaString(char* idString, int idNumero)
{
	int retorno;

	retorno=1;

	if(idString != NULL)
	{
		sprintf(idString,"%d", idNumero);
		retorno=0;
	}
	return retorno;
}

int Passenger_transformarPrecioaString(char* precioString, float precioNumero)
{
	int retorno;

	retorno=1;

	if(precioString != NULL)
	{
		sprintf(precioString,"%.2f", precioNumero);
		retorno=0;
	}

	return retorno;
}

int Passenger_verificarSerCodigoDeVuelo(char* cadenaAlfanumerica)
{
	int retorno;
	int contadorLetras;
	int contadorNumeros;

	retorno =1;
	contadorLetras=0;
	contadorNumeros=0;

	if(cadenaAlfanumerica != NULL)
	{
		retorno=0;
		for(int i=0; i<7;i++)
		{
			if(isalpha(*(cadenaAlfanumerica+i)))
			{
				if((contadorNumeros == 0 && contadorLetras <2) || (contadorNumeros ==4 && contadorLetras ==2))
				{
					contadorLetras++;
				}
				else
				{
					retorno=1;
					break;
				}
			}
			else
			{
				if(isdigit(*(cadenaAlfanumerica+i)))
				{
					if(contadorNumeros<4 && contadorLetras == 2)
					{
						contadorNumeros++;
					}
					else
					{
						retorno=1;
						break;
					}
				}
				else
				{
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;
}

int Passenger_delete(Passenger* pasajeroAEliminar)
{
	int retorno;

	retorno=1;
	if(pasajeroAEliminar != NULL)
	{
		free(pasajeroAEliminar);
		pasajeroAEliminar =NULL;
		retorno=0;
	}

	return retorno;
}

Passenger* Passenger_new()
{
	Passenger* nuevoPasajero;

	nuevoPasajero = NULL;
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));
	if(nuevoPasajero != NULL)
	{
		Passenger_setId(nuevoPasajero, 0);
		Passenger_setNombre(nuevoPasajero,"");
		Passenger_setApellido(nuevoPasajero,"");
		Passenger_setCodigoVuelo(nuevoPasajero,"");
		Passenger_setTipoPasajero(nuevoPasajero,0);
		Passenger_setPrecio(nuevoPasajero,0);
		Passenger_setEstadoVuelo(nuevoPasajero,0);
	}
	return nuevoPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlight)
{
	Passenger* nuevoPasajero;
	int statusFlightNumero;
	int tipoPasajeroNumero;
	int idNumero;
	float precioNumero;
	int activarDelete;

	activarDelete=1;
	nuevoPasajero = Passenger_new();
	if(nuevoPasajero != NULL && nombreStr != NULL && idStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL &&
			codigoVueloStr != NULL && statusFlight != NULL &&
			!utn_verificarSerInt(idStr) && !utn_verificarSerNombre(nombreStr) && !utn_verificarSerNombre(apellidoStr) &&
			!utn_verificarSerFloat(precioStr) && !Passenger_verificarSerCodigoDeVuelo(codigoVueloStr))
	{
		idNumero = atoi(idStr);
		precioNumero = atof(precioStr);
		if(idNumero >= 0 && precioNumero >= VUELO_PRECIO_MINIMO  &&
				!Passenger_verificarYTransfomarEstadoVueloStringAInt(statusFlight, &statusFlightNumero) &&
				!Passenger_verificarYTransfomarTipoPasajeroStringAInt(tipoPasajeroStr, &tipoPasajeroNumero) &&
				!Passenger_setAll(nuevoPasajero, idNumero, nombreStr,apellidoStr, codigoVueloStr, tipoPasajeroNumero, precioNumero, statusFlightNumero))
		{
			activarDelete=0;
		}
	}

	if(activarDelete)
	{
		Passenger_delete(nuevoPasajero);
	}

	return nuevoPasajero;
}


int Passenger_setId(Passenger* this,int id)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->id = id;
		retorno=0;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno=1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno=0;
	}

	return retorno;
}


int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno=1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno=0;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno=1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=0;
	}

	return retorno;
}


int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno=1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno=0;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno=1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno=0;
	}

	return retorno;
}


int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno=0;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno=0;
	}

	return retorno;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->tipoPasajero = tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;

	retorno=1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno=0;
	}

	return retorno;
}


int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->precio = precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;

	retorno=1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno=0;
	}

	return retorno;
}


int Passenger_setEstadoVuelo(Passenger* this,int estadoDeVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL)
	{
		this->statusFlight = estadoDeVuelo;
		retorno=0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoDeVuelo)
{
	int retorno;

	retorno=1;

	if(this != NULL && estadoDeVuelo != NULL)
	{
		*estadoDeVuelo = this->statusFlight;
		retorno=0;
	}

	return retorno;
}

int Passenger_setAll(Passenger* pasajeroASetear, int id, char* nombre,char* apellido, char* codigoVuelo, int tipoPasajero, float precio, int estadoVuelo)
{
	int retorno;

	retorno=1;
	if(pasajeroASetear != NULL && nombre != NULL && apellido != NULL && codigoVuelo != NULL)
	{
		if(!Passenger_setId(pasajeroASetear, id) &&
				!Passenger_setNombre(pasajeroASetear, nombre) &&
				!Passenger_setApellido(pasajeroASetear, apellido) &&
				!Passenger_setTipoPasajero(pasajeroASetear, tipoPasajero) &&
				!Passenger_setPrecio(pasajeroASetear, precio) &&
				!Passenger_setEstadoVuelo(pasajeroASetear, estadoVuelo) &&
				!Passenger_setCodigoVuelo(pasajeroASetear, codigoVuelo))
		{
			retorno=0;
		}
	}
	return retorno;
}

int Passenger_getAll(Passenger* pPasajeroAGetear, int* id, char* nombre,char* apellido, char* codigoVuelo, int* tipoPasajero, float* precio, int* estadoVuelo)
{
	int retorno;

	retorno=1;

	if(pPasajeroAGetear != NULL && nombre != NULL && apellido != NULL && codigoVuelo != NULL &&
			id != NULL && tipoPasajero !=NULL && precio !=NULL && estadoVuelo !=NULL)
	{
		if(!Passenger_getId(pPasajeroAGetear, id) &&
				!Passenger_getNombre(pPasajeroAGetear, nombre) &&
				!Passenger_getApellido(pPasajeroAGetear, apellido) &&
				!Passenger_getTipoPasajero(pPasajeroAGetear, tipoPasajero)&&
				!Passenger_getPrecio(pPasajeroAGetear, precio)  &&
				!Passenger_getEstadoVuelo(pPasajeroAGetear, estadoVuelo) &&
				!Passenger_getCodigoVuelo(pPasajeroAGetear, codigoVuelo))
		{
			retorno=0;
		}
	}

	return retorno;
}



int Passenger_modificarNombre(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria)
{
	int retorno;
	char nombre[CANTIDAD_CARACTERES_NOMBRE];

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL && mensajeErrorSinMemoria !=NULL)
	{
		if(!utn_GetNombreRango(nombre, mensaje, mensajeError, mensajeErrorSinMemoria, 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE) &&
				!Passenger_setNombre(pasajeroAManipular, nombre))
		{
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_ModificarApellido(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria)
{
	int retorno;
	char apellido[CANTIDAD_CARACTERES_APELLIDO];

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL && mensajeErrorSinMemoria != NULL)
	{
		if(!utn_GetNombreRango(apellido, mensaje, mensajeError, mensajeErrorSinMemoria, 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE) &&
				!Passenger_setApellido(pasajeroAManipular, apellido))
		{
			retorno=0;
		}
	}
	return retorno;
}

int Passenger_ModificarCodigoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError, char* mensajeErrorSinMemoria, char* mensajeCodigoInvalido)
{
	int retorno;
	char codigoVuelo[CARACTERES_CODIGOVUELO];
	int pedirOtroCodigo;

	retorno=1;
	pedirOtroCodigo=1;

	if(pasajeroAManipular!=NULL && mensaje !=NULL && mensajeError != NULL && mensajeErrorSinMemoria != NULL && mensajeCodigoInvalido !=NULL)
	{
		do{
			utn_GetCadenaAlfanumericaRango(codigoVuelo, mensaje, mensajeError, mensajeCodigoInvalido, CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO, CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO, 9);

			if(Passenger_verificarSerCodigoDeVuelo(codigoVuelo))
			{
				printf("%s",mensajeCodigoInvalido);
			}
			else
			{
				pedirOtroCodigo=0;
			}

		}while(pedirOtroCodigo);

		/*
		while(utn_GetCadenaAlfanumericaRango(codigoVuelo, mensaje, mensajeError, mensajeCodigoInvalido, CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO, CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO, 9) ||
				Passenger_verificarSerCodigoDeVuelo(codigoVuelo))
		{
			printf("%s",mensajeCodigoInvalido);
		}
		*/
		utn_trasnformarCadenaAMayuscula(codigoVuelo);

		if(!Passenger_setCodigoVuelo(pasajeroAManipular, codigoVuelo))
		{
			retorno=0;
		}
	}
	return retorno;
}

int Passenger_ModificarTipoPasajero(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError)
{
	int retorno;
	int tipoPasajero;

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(!utn_GetIntRango(&tipoPasajero, mensaje, mensajeError, TIPO_PASAJERO_OPCION_MINIMA, TIPO_PASAJERO_OPCION_MAXIMA, 5) &&
				!Passenger_setTipoPasajero(pasajeroAManipular, tipoPasajero))
		{
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_ModificarPrecioVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError)
{
	int retorno;
	float precio;

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(!utn_GetFloatRango(&precio, mensaje, mensajeError, VUELO_PRECIO_MINIMO, VUELO_PRECIO_MAXIMO, CANTIDAD_CIFRAS_PRECIO) &&
				!Passenger_setPrecio(pasajeroAManipular, precio))
		{
			retorno=0;
		}
	}

	return retorno;
}

int Passenger_ModificarEstadoVuelo(Passenger* pasajeroAManipular, char* mensaje, char* mensajeError)
{
	int retorno;
	int estadoDeVuelo;

	retorno=1;

	if(pasajeroAManipular!=NULL && mensaje != NULL && mensajeError != NULL)
	{
		if(!utn_GetIntRango(&estadoDeVuelo, mensaje, mensajeError, ESTADO_VUELO_OPCION_MINIMA, ESTADO_VUELO_OPCION_MAXIMA, 5) &&
				!Passenger_setEstadoVuelo(pasajeroAManipular, estadoDeVuelo))
		{
			retorno=0;
		}
	}

	return retorno;
}


int Passenger_askOnePassengerData(char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoVuelo, int* statusFlight)
{
	int retorno;
	int pedirOtroCodigo;

	retorno=1;
	pedirOtroCodigo=1;

	if(nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && codigoVuelo != NULL && statusFlight != NULL &&
			!utn_GetNombreRango(nombre, "\nIngrese el nombre del pasajero: ", "Dato invalido. Ingrese el NOMBRE del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_NOMBRE, CANTIDAD_CARACTERES_NOMBRE) &&
			!utn_GetNombreRango(apellido, "\nIngrese el apellido del pasajero: ", "Dato invalido. Ingrese el APELLIDO del pasajero: ", "\nHubo un error debido a faltante de memoria", 2, CANTIDAD_MAXIMA_CARACTERES_APELLIDO, CANTIDAD_CARACTERES_APELLIDO) &&
			!utn_GetFloatRango(precio, "\nIngresa el precio del vuelo, debe estar entre $10000 y $100000000: ", "El dato ingresado es invalido. Ingresa el precio del vuelo, debe estar entre $10000 y $100000000:", VUELO_PRECIO_MINIMO, VUELO_PRECIO_MAXIMO, CANTIDAD_CIFRAS_PRECIO) &&
			!utn_GetIntRango(tipoPasajero, "\nTipo de pasajero:\n 1. FirstClass  \n 2. ExecutiveClass\n 3. EconomyClass\nIngrese el numero correspondiente al tipo: ", "Dato invalido. Ingrese el numero correspondiente al tipo: ", TIPO_PASAJERO_OPCION_MINIMA, TIPO_PASAJERO_OPCION_MAXIMA, 5) &&
			!utn_GetIntRango(statusFlight, "\nEstado de vuelo:\n 1. Aterrizado\n 2. En horario\n 3. Demorado\n 4. En vuelo \nIngrese el numero que corresponda: ", "Dato ingresado invalido. Ingrese el numero que corresponda: ", ESTADO_VUELO_OPCION_MINIMA, ESTADO_VUELO_OPCION_MAXIMA, 5))
	{

		do{
			utn_GetCadenaAlfanumericaRango(codigoVuelo, "\nTeniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "Dato invalido. Teniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "\nNo se puede realizar la operacion debido a que ya no hay memoria\n", CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO, CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO, CARACTERES_CODIGOVUELO);

			if(Passenger_verificarSerCodigoDeVuelo(codigoVuelo))
			{
				printf("%s","\nEl codigo ingresado no cumple con los requisitos\n");
			}
			else
			{
				pedirOtroCodigo=0;
			}

		}while(pedirOtroCodigo);
		utn_trasnformarCadenaAMayuscula(codigoVuelo);
		retorno=0;
	}
	return retorno;
}

int Passenger_MostrarUnPasajero(Passenger* pPasajeroAMostrar)
{
	int retorno;
	int id;
	char nombre[CANTIDAD_CARACTERES_NOMBRE];
	char apellido[CANTIDAD_CARACTERES_APELLIDO];
	float precio;
	char codigoVuelo[CARACTERES_CODIGOVUELO];
	int tipoPasajeroNumero;
	int estadoDeVueloNumero;
	char tipoPasajeroPalabra[CARACTERES_TIPO_PASAJERO_PALABRA];
	char estadoDeVueloPalabra[CARACTERES_ESTADO_VUELO_PALABRA];

	retorno=1;

	if(pPasajeroAMostrar != NULL &&
			!Passenger_getAll(pPasajeroAMostrar, &id, nombre, apellido, codigoVuelo, &tipoPasajeroNumero, &precio, &estadoDeVueloNumero) &&
			!Passenger_verificarYTransfomarEstadoVueloIntAString(estadoDeVueloPalabra, estadoDeVueloNumero) &&
			!Passenger_verificarYTransfomarTipoPasajeroIntAString(tipoPasajeroPalabra, tipoPasajeroNumero))
	{
		printf("|%*d|%*s|%*s|$%*.2f|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, id, -CANTIDAD_CARACTERES_NOMBRE, nombre, -CANTIDAD_CARACTERES_APELLIDO, apellido, -CANTIDAD_CIFRAS_PRECIO, precio, -CARACTERES_MARCO_CODIGOVUELO, codigoVuelo, -CARACTERES_TIPO_PASAJERO_PALABRA, tipoPasajeroPalabra, -CARACTERES_ESTADO_VUELO_PALABRA, estadoDeVueloPalabra);
		retorno=0;
	}
    return retorno;
}

int Passenger_saveAsText(FILE* pFile , LinkedList* pArrayListPassenger, int estadoGuardarTodo, int mostrarPasajeros)
{
	int retorno;
	int cantidadPasajerosAGuardar;
	int idAGuardar;
	char nombreAGuardar[CANTIDAD_CARACTERES_NOMBRE];
	char apellidoAGuardar[CANTIDAD_CARACTERES_APELLIDO];
	char codigoVueloAGuardar[CARACTERES_TOTALES_CODIGOVUELO];
	int tipoPasajero;
	float precioAGuardar;
	int estadoVueloNumero;
	char estadoVueloAGuardar[CARACTERES_ESTADO_VUELO_PALABRA];
	char tipoPasajeroAGuardar[CARACTERES_TIPO_PASAJERO_PALABRA];

	Passenger* pPasajeroAGuardar;

	retorno=1;


	if(pFile != NULL && pArrayListPassenger != NULL && (estadoGuardarTodo == 0 || estadoGuardarTodo==1) && (mostrarPasajeros == 0 || mostrarPasajeros ==1))
	{
		retorno=0;
		cantidadPasajerosAGuardar = ll_len(pArrayListPassenger);
		if(cantidadPasajerosAGuardar> 0)
		{
			if(estadoGuardarTodo)
			{
				fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			}
			for(int i=0; i<cantidadPasajerosAGuardar;i++)
			{
				pPasajeroAGuardar=(Passenger*) ll_get(pArrayListPassenger, i);

				if(!Passenger_getAll(pPasajeroAGuardar, &idAGuardar, nombreAGuardar, apellidoAGuardar, codigoVueloAGuardar, &tipoPasajero, &precioAGuardar, &estadoVueloNumero))
				{
					if(!Passenger_verificarYTransfomarEstadoVueloIntAString(estadoVueloAGuardar, estadoVueloNumero) &&
							!Passenger_verificarYTransfomarTipoPasajeroIntAString(tipoPasajeroAGuardar, tipoPasajero))
					{
						if(fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n", idAGuardar, nombreAGuardar, apellidoAGuardar, precioAGuardar, codigoVueloAGuardar, tipoPasajeroAGuardar, estadoVueloAGuardar) < 0)
						{
							retorno=2;
						}
						else
						{
							if(mostrarPasajeros)
							{
								Passenger_MostrarUnPasajero(pPasajeroAGuardar);
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}

int Passenger_saveAsBinary(FILE* pFile , LinkedList* pArrayListPassenger, int mostrarPasajero)
{
	int retorno;
	int cantidadPasajerosAGuardar;
	int pasajerosGuardadosPorIteracion;
	Passenger* pPasajeroAGuardar;

	retorno =1;
	pasajerosGuardadosPorIteracion=1;

	if(pFile != NULL && pArrayListPassenger != NULL && (mostrarPasajero == 0 || mostrarPasajero == 1))
	{
		retorno=0;
		cantidadPasajerosAGuardar = ll_len(pArrayListPassenger);
		if(cantidadPasajerosAGuardar > 0)
		{
			for(int i=0; i<cantidadPasajerosAGuardar;i++)
			{
				pPasajeroAGuardar = (Passenger*) ll_get(pArrayListPassenger, i);

				if(pPasajeroAGuardar != NULL)
				{
					if(pasajerosGuardadosPorIteracion<fwrite(pPasajeroAGuardar, sizeof(Passenger), pasajerosGuardadosPorIteracion, pFile))
					{
						retorno=2;
					}
					else
					{
						if(mostrarPasajero)
						{
							Passenger_MostrarUnPasajero(pPasajeroAGuardar);

						}
					}
				}
			}
		}
	}

	return retorno;
}

int Passenger_saveContadorIdAdBinary(FILE* pFile , int* contadorIdAguardar)
{
	int retorno;

	retorno=1;

	if(pFile != NULL && contadorIdAguardar != NULL)
	{
		if(fwrite(contadorIdAguardar, sizeof(int), 1, pFile) > 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int Passenger_CompararPorApellidoYNombre(void* pPrimerPasajero, void* pSegundoPasajero)
{
	int retorno;
	int estadoComparacionApellido;

	retorno =0;

	if(pPrimerPasajero != NULL && pSegundoPasajero != NULL)
	{
		estadoComparacionApellido = strcmp((((Passenger*)pPrimerPasajero)->apellido), (((Passenger*)pSegundoPasajero)->apellido));

		if(estadoComparacionApellido != 0)
		{
			retorno= estadoComparacionApellido;
		}
		else
		{
			retorno = strcmp((((Passenger*)pPrimerPasajero)->nombre), (((Passenger*)pSegundoPasajero)->nombre));
		}
	}
	return retorno;
}

int Passenger_CompararPorId(void* pPrimerPasajero, void* pSegundoPasajero)
{
	int retorno;

	retorno =0;

	if(pPrimerPasajero != NULL && pSegundoPasajero != NULL)
	{
		if(((Passenger*)pPrimerPasajero)->id == ((Passenger*)pSegundoPasajero)->id)
		{
			retorno=0;
		}
		else
		{
			if(((Passenger*)pPrimerPasajero)->id < ((Passenger*)pSegundoPasajero)->id)
			{
				retorno =-1;
			}
			else
			{
				retorno=1;
			}
		}
	}
	return retorno;
}
