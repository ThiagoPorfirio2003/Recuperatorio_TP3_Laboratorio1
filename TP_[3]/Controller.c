#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"

#define CANTIDAD_MAXIMA_CARACTERES_NOMBRE 50
#define CANTIDAD_MAXIMA_CARACTERES_APELLIDO 50
#define CANTIDAD_CARACTERES_NOMBRE 50
#define CANTIDAD_CARACTERES_APELLIDO 50
#define VUELO_PRECIO_MINIMO 10000
#define VUELO_PRECIO_MAXIMO 100000000
#define CANTIDAD_CIFRAS_PRECIO 30
#define TIPO_PASAJERO_OPCION_MINIMA 1
#define TIPO_PASAJERO_OPCION_MAXIMA 4
#define TIPO_VUELO_OPCION_MINIMA 1
#define TIPO_VUELO_OPCION_MAXIMA 4
#define CANTIDAD_MAXIMA_CIFRAS_ID 20
#define CANTIDAD_MINIMA_CARACTERES_CODIGOVUELO 7
#define CANTIDAD_MAXIMA_CARACTERES_CODIGOVUELO 7
#define CARACTERES_TOTALES_CODIGOVUELO 9
#define CARACTERES_MARCO_CODIGOVUELO 15
#define CARACTERES_CODIGOVUELO 8
#define CARACTERES_TIPO_PASAJERO_PALABRA 20
#define CARACTERES_ESTADO_VUELO_PALABRA 20
#define MINIMA_OPCION_MODIFICAR_PASAJERO 1
#define MAXIMA_OPCION_MODIFICAR_PASAJERO 6
#define MINIMA_OPCION_CRITERIO_ORDENAMIENTO 1
#define MAXIMA_OPCION_CRITERIO_ORDENAMIENTO 2


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivo;

	retorno =1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo=fopen(path,"r");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		retorno= parser_PassengerFromText(pArchivo, pArrayListPassenger);

		while(!fclose(pArchivo));
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	}
	return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pFile;



	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile=fopen(path,"rb");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		retorno=parser_PassengerFromBinary(pFile, pArrayListPassenger);

		while(!fclose(pFile));
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

	}
    return retorno;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, int *idNumerico)
{
	Passenger* nuevoPasajero;

	int retorno;
	char nombre[CANTIDAD_CARACTERES_NOMBRE];
	char apellido[CANTIDAD_CARACTERES_APELLIDO];
	float precioNumerico;
	int tipoPasajeroNumerico;
	char codigoVuelo[CARACTERES_CODIGOVUELO];
	int estadoVueloNumerico;

	char estadoVueloString[CARACTERES_CODIGOVUELO];
	char precioString[CANTIDAD_CIFRAS_PRECIO];
	char tipoPasajeroString[CARACTERES_TIPO_PASAJERO_PALABRA];
	char idString[CANTIDAD_MAXIMA_CIFRAS_ID+1];

	retorno=1;

	if(pArrayListPassenger != NULL && idNumerico != NULL)
	{
		if(!Passenger_askOnePassengerData(nombre, apellido, &precioNumerico, &tipoPasajeroNumerico, codigoVuelo, &estadoVueloNumerico))
		{
			if(!Passenger_transformarIDaString(idString, *idNumerico) &&
					!Passenger_transformarPrecioaString(precioString, precioNumerico) &&
					!Passenger_verificarYTransfomarTipoPasajeroIntAString(tipoPasajeroString, tipoPasajeroNumerico) &&
					!Passenger_verificarYTransfomarEstadoVueloIntAString(estadoVueloString,estadoVueloNumerico)
					)
			{
				nuevoPasajero = Passenger_newParametros(idString, nombre, apellido, precioString, tipoPasajeroString, codigoVuelo, estadoVueloString);
				if(nuevoPasajero !=NULL && !ll_add(pArrayListPassenger, nuevoPasajero))
				{
					retorno=0;
					(*idNumerico)++;
				}
			}
		}
	}

    return retorno;
}

int controller_findPassengerById(LinkedList* pArrayListPassenger, int idAEncontrar)
{
	int retorno;
	int idAuxiliar;
	int cantidadPasajeros;

	Passenger* pasajeroBusqueda;

	retorno=-1;

	if(pArrayListPassenger != NULL && idAEncontrar > -1)
	{
		cantidadPasajeros = ll_len(pArrayListPassenger);

		if(cantidadPasajeros != -1)
		{
			retorno=-2;
			for(int i=0;i<cantidadPasajeros;i++)
			{
				pasajeroBusqueda = (Passenger*) ll_get(pArrayListPassenger, i);
				if(pasajeroBusqueda != NULL && !Passenger_getId(pasajeroBusqueda ,&idAuxiliar) &&
						idAuxiliar == idAEncontrar)
				{
					retorno=i;
					break;
				}
			}
		}
	}

	return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pasajeroAMoidificar;

	int retorno;
	int idAEncontrar;
	int posicionPasajero;
	int opcionModificacion;

	retorno=1;

	if(pArrayListPassenger != NULL && !utn_GetIntRango(&idAEncontrar, "\nIngrese el id del pasajero cuyos datos desea modificar: ", "Dato invalido. Ingrese el id del pasajero cuyos datos desea modificar: ", 0, 2000, 30))
	{
		posicionPasajero = controller_findPassengerById(pArrayListPassenger, idAEncontrar);

		if(posicionPasajero != -1 && posicionPasajero != -2)
		{
			pasajeroAMoidificar = (Passenger*) ll_get(pArrayListPassenger, posicionPasajero);

			if(pasajeroAMoidificar != NULL)
			{
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				Passenger_MostrarUnPasajero(pasajeroAMoidificar);
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				if(!utn_GetIntRango(&opcionModificacion, "\nCaracteristicas a modificar:\n 1- Nombre\n 2- Apellido\n 3- Precio\n 4- Tipo de Pasajero \n 5- Codigo de vuelo\n 6- Estado de vuelo\nIngrese el numero del aspecto a modificar:  ", "Ingrese el numero del aspecto a modificar: ", MINIMA_OPCION_MODIFICAR_PASAJERO, MAXIMA_OPCION_MODIFICAR_PASAJERO, 3))
				{
					switch(opcionModificacion)
					{
						case 1:
							if(Passenger_modificarNombre(pasajeroAMoidificar, "\nIngrese el nuevo nombre del pasajero: ", "Dato invalido. Ingrese el nuevo NOMBRE del pasajero: ", "\n\nNo se puede realizar la operacion debido a que ya no hay memoria\n\n"))
							{
								retorno=-1;
							}
							break;

						case 2:
							if(Passenger_ModificarApellido(pasajeroAMoidificar, "\nIngrese el nuevo apellido del pasajero: ", "Dato invalido. Ingrese el nuevo APELLIDO del pasajero: ", "\n\nNo se puede realizar la operacion debido a que ya no hay memoria\n\n"))
							{
								retorno=-1;
							}
							break;

						case 3:
							if(Passenger_ModificarPrecioVuelo(pasajeroAMoidificar, "\nIngresa el nuevo precio del vuelo, debe estar entre $10000 y $100000000: ", "El dato ingresado es invalido. Ingresa el nuevo precio del vuelo, debe estar entre $10000 y $100000000: "))
							{
								retorno=-1;
							}
							break;

						case 4:
							if(Passenger_ModificarTipoPasajero(pasajeroAMoidificar, "\nTipo de pasajero:\n 1. FirstClass  \n 2. ExecutiveClass\n 3. EconomyClass\nIngrese el numero correspondiente al tipo: ", "Dato invalido. Ingrese el numero correspondiente al tipo: "))
							{
								retorno=-1;
							}
							break;

						case 5:
							if(Passenger_ModificarCodigoVuelo(pasajeroAMoidificar, "\nTeniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "Dato invalido. Teniendo como modelo \"AA1234A\", ingrese el codigo de vuelo: ", "\n\nNo se puede realizar la operacion debido a que ya no hay memoria\n\n", "\nEl codigo escrito no cumple con las condiciones\n"))
							{
								retorno=-1;
							}
							break;

						case 6:
							if(Passenger_ModificarEstadoVuelo(pasajeroAMoidificar, "\nEstado de vuelo:\n 1. Aterrizado\n 2. En horario\n 3. Demorado\n 4. En vuelo \nIngrese el numero que corresponda: ", "Dato ingresado invalido. Ingrese el numero que corresponda: "))
							{
								retorno=-1;
							}
							break;

						default:
							retorno=-1;
							break;
					}
					retorno=0;
				}
			}
		}
	}
    return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno;
    int posicionPasajeroAEliminar;
    int idAEncontrar;
    int preguntaDeConfirmacion;
    Passenger* pPasajeroAEliminar;

    retorno=-1;

	if(pArrayListPassenger != NULL && !utn_GetIntRango(&idAEncontrar, "\nIngrese el id del pasajero que desea eliminar: ", "Dato invalido. Ingrese el id del pasajero que desea eliminar: ", 0, 2000, 30))
    {
    	posicionPasajeroAEliminar = controller_findPassengerById(pArrayListPassenger, idAEncontrar);

    	if(posicionPasajeroAEliminar != -1 && posicionPasajeroAEliminar != -2)
    	{
    		pPasajeroAEliminar = (Passenger*) ll_get(pArrayListPassenger, posicionPasajeroAEliminar);
    		if(pPasajeroAEliminar != NULL )
			{
				printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
				Passenger_MostrarUnPasajero(pPasajeroAEliminar);
				printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

				if(!utn_GetIntRango(&preguntaDeConfirmacion, "Si esta seguro de querer eliminarlo presione 1, de lo contrario el 0: ", "Dato invalido. Si esta seguro de querer eliminarlo presione 1, de lo contrario el 0: ", 0, 1, 1))
				{
					if(preguntaDeConfirmacion && !Passenger_delete(pPasajeroAEliminar))
					{
						retorno=0;
						if(ll_remove(pArrayListPassenger,posicionPasajeroAEliminar))
						{
							retorno=1;
						}
					}
					else
					{
						retorno=2;
					}
				}
			}
    	}
    }

    return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int cantidadPasajeros;
	Passenger* pPasajeroAMostrar;

	retorno=1;

	if(pArrayListPassenger != NULL)
	{
		retorno=0;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		if(cantidadPasajeros != -1)
		{
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			for(int i=0;i<cantidadPasajeros;i++)
			{
				pPasajeroAMostrar = (Passenger*) ll_get(pArrayListPassenger, i);
				if(pPasajeroAMostrar == NULL || Passenger_MostrarUnPasajero(pPasajeroAMostrar))
				{
					retorno=2;
				}
			}
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		}
	}
    return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno;
    int CriterioDeOrdenamiento;
    int modoDeOrdenamiento;

    int (*pFuncionComparadora) (void*, void*);
    retorno =-1;

    if(pArrayListPassenger != NULL)
    {
    	retorno =1;
    	if(!utn_GetIntRango(&CriterioDeOrdenamiento, "\nOrdenar los pasajeros:\n 1 - Por Apellido y nombre\n 2 - Por ID\nElija alguna opcion: ", "El dato ingresado es invalido. Elija una opcion:", MINIMA_OPCION_CRITERIO_ORDENAMIENTO, MAXIMA_OPCION_CRITERIO_ORDENAMIENTO, 1))
    	{

    		switch(CriterioDeOrdenamiento)
    		{
    			case 1:
        	    	pFuncionComparadora = Passenger_CompararPorApellidoYNombre;
    				break;

    			case 2:
        	    	pFuncionComparadora = Passenger_CompararPorId;
    				break;
    		}

    		if(!utn_GetIntRango(&modoDeOrdenamiento, "\nOrdenar los pasajeros:\n 1 - De forma ascendente\n 0 - De forma descendente\nElija alguna opcion: ", "El dato ingresado es invalido. Elija una opcion:", 0, 1, 1))
    		{
    	    	retorno = ll_sort(pArrayListPassenger, pFuncionComparadora, modoDeOrdenamiento);
    		}
    	}
    }

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, int mostrarPasajeros)
{
	int retorno;
	FILE* pArchivo;

	retorno =1;

	if(path != NULL && pArrayListPassenger != NULL && (mostrarPasajeros == 0 || mostrarPasajeros == 1))
	{
		pArchivo=fopen(path,"w+");
		if(mostrarPasajeros)
		{
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		}

		retorno = Passenger_saveAsText(pArchivo, pArrayListPassenger,1,mostrarPasajeros);

		while(!fclose(pArchivo))
		{

		}
	}
	return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, int mostrarPasajeros)
{
	int retorno;
	FILE* pArchivo;

	retorno =1;

	if(path != NULL && pArrayListPassenger != NULL && (mostrarPasajeros == 1 || mostrarPasajeros == 0))
	{
		pArchivo=fopen(path,"wb");

		if(mostrarPasajeros)
		{
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		}
		retorno=Passenger_saveAsBinary(pArchivo, pArrayListPassenger,mostrarPasajeros);


		while(!fclose(pArchivo))
		{

		}
	}
	return retorno;
}

int controller_addAsText(char* path , LinkedList* pArrayListPassenger, int mostrarPasajeros)
{
	int retorno;
	FILE* pArchivo;

	retorno =-1;

	if(path != NULL && pArrayListPassenger != NULL && (mostrarPasajeros == 0 || mostrarPasajeros ==1))
	{
		pArchivo=fopen(path,"a");

		if(mostrarPasajeros)
		{
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		}

		retorno=Passenger_saveAsText(pArchivo, pArrayListPassenger,0,mostrarPasajeros);

		while(!fclose(pArchivo))
		{

		}
	}
	return retorno;
}

int controller_addAsBinary(char* path , LinkedList* pArrayListPassenger, int mostrarPasajeros)
{
	int retorno;
	FILE* pArchivo;

	retorno =-1;

	if(path != NULL && pArrayListPassenger != NULL && (mostrarPasajeros == 1 || mostrarPasajeros == 0))
	{
		pArchivo=fopen(path,"ab");

		if(mostrarPasajeros)
		{
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			printf("|%*s|%*s|%*s|$%*s|%*s|%*s|%*s|\n", -CANTIDAD_MAXIMA_CIFRAS_ID, "ID", -CANTIDAD_CARACTERES_NOMBRE, "Nombre", -CANTIDAD_CARACTERES_APELLIDO, "Apellido", -CANTIDAD_CIFRAS_PRECIO, "Precio", -CARACTERES_MARCO_CODIGOVUELO, "Codigo de vuelo", -CARACTERES_TIPO_PASAJERO_PALABRA, "Tipo de pasajero", -CARACTERES_ESTADO_VUELO_PALABRA, "Estado de vuelo");
			printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		}
		retorno=Passenger_saveAsBinary(pArchivo, pArrayListPassenger, mostrarPasajeros);

		while(!fclose(pArchivo));
	}
	return retorno;
}


int controller_loadFromBinaryContador(char* path , int* pIdContadorNumero)
{
	int retorno;
	FILE* pArchivo;

	retorno=1;

	if(path != NULL)
	{
		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL)
		{
			retorno= parser_contadorFromBinary(pArchivo, pIdContadorNumero);
		}

		while(!fclose(pArchivo));
	}
	return retorno;
}


int controller_saveAsBinaryContador(char* path , int* idContadorNumero)
{
	int retorno;
	FILE* pArchivo;

	retorno=1;

	if(path != NULL && idContadorNumero != NULL)
	{
		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL)
		{
			retorno= Passenger_saveContadorIdAdBinary(pArchivo , idContadorNumero);
		}

		while(!fclose(pArchivo));
	}

	return retorno;
}

int controller_saveTextAndBinary(char* pathCSV, char* pathBinario, LinkedList* pArrayListPassenger, int modoGuardado, int mostrarBin, int mostrarTxt)
{
	int retorno;
	int estadoGuardarTxt;
	int estadoGuardarBin;

	retorno=1;

	if(pathCSV != NULL && pathBinario != NULL && pArrayListPassenger != NULL && (modoGuardado == 0 || modoGuardado ==1) && (mostrarBin == 0 || mostrarBin == 1) && (mostrarTxt == 0 || mostrarTxt==1))
	{
		if(modoGuardado)
		{
			estadoGuardarBin = controller_saveAsBinary(pathBinario, pArrayListPassenger, mostrarBin);
			estadoGuardarTxt = controller_saveAsText(pathCSV, pArrayListPassenger, mostrarTxt);
		}
		else
		{
			estadoGuardarBin = controller_addAsBinary(pathBinario, pArrayListPassenger, mostrarBin);
			estadoGuardarTxt = controller_addAsText(pathCSV, pArrayListPassenger, mostrarTxt);
		}

		if(estadoGuardarBin == 0 || estadoGuardarTxt == 0)
		{
			retorno=0;
		}

		if(estadoGuardarBin == 2 || estadoGuardarTxt == 2)
		{
			retorno=2;
		}

		if(estadoGuardarBin == 1 || estadoGuardarTxt == 1)
		{
			retorno=1;
		}
	}

	return retorno;
}
